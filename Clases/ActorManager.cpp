
#include "ActorManager.h"
#include "ActorGraphic.h"
#include "Actor.h"
#include "Ladrillo.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

ActorManager::ActorManager (Game *g):
game (g),
actorVisualizado (NULL)
{
}

/**
 * \brief   Devuelve el actor cuyas coordenadas en pantalla son (x,y).
 * \todo    Preveer que en un futuro debe devolver una lista de actores, pues
 *          el punto puede interseccionar a más de un actor.
 */
Actor * ActorManager::get_actor (int x, int y)
{
  Actor *encontrado = NULL;

  // Comprobar el bucle, es posible que el primero no lo compruebe si es el único de la lista.
  actors_iter = actors.begin();
  while (encontrado == NULL && actors_iter != actors.end()) 
  {
    if ( !(  (x <= (*actors_iter)->get_x())
    || (y <= (*actors_iter)->get_y())
    || (x >= ((*actors_iter)->get_x() + (*actors_iter)->get_w()))
    || (y >= ((*actors_iter)->get_y() + (*actors_iter)->get_h()))
    ))
    {
      encontrado = *actors_iter;
    }
    else
    {
      actors_iter++;
    }
  }

  return encontrado;
}

/**
 * \brief   Destructor.
 */
ActorManager::~ActorManager()
{
  for (actors_iter=actors.begin(); actors_iter!=actors.end(); actors_iter++)
  delete (*actors_iter);
}

/**
 * \brief   Añade un nuevo actor.
 * \details Se debe avisar de los actores que no tienen parte gráfica. 
 */
void ActorManager::add(Actor *a)
{
  // Se comprueba si el actor que se quiere añadir a la lista tiene parte gráfica.
  // Si no la tiene se emite un aviso por consola. Se añade pues pueden existir "actores invisibles" en el juego.
  to_create.push_back (a);
  if (a->get_actor_graphic () == NULL)
  {
    avisoActorSinGrafico (a);
  }
}

/**
 * \brief   Elimina el actor.
 */
void ActorManager::del(Actor *a)
{
  to_del.push_back (a);
}

/**
 * \brief   Elimina todos los actores de la lista de actores para borrar.
 */
void ActorManager::del_all_to_del ()
{
  if (to_del.size()==0) return;

  list<Actor*>::iterator tmp_iter;
  list<Actor*>::iterator tmp_actors_iter;

  for (tmp_iter=to_del.begin(); tmp_iter!=to_del.end(); tmp_iter++)
  {
    tmp_actors_iter=find(actors.begin(), actors.end(), *tmp_iter);
    if (tmp_actors_iter!=actors.end())
    {
      actors.erase(tmp_actors_iter);
      delete (*tmp_iter);
    }
  }
  to_del.clear();
}

/**
 * \brief   Añade todos los actores de la lista de actores para crear.
 */
void ActorManager::add_all_to_create()
{
  // Si no hay actores a crear se sale del procedimiento.
  if (to_create.size()==0) return;

  // Recorremos la lista a crear y añadimos los actores.
  list<Actor *>::iterator tmp_iter;
  for (tmp_iter=to_create.begin(); tmp_iter!=to_create.end(); tmp_iter++)
  {
    actors.push_back(*tmp_iter);
    (*tmp_iter)->init();
  }

  // Limpiamos la lista a crear para el siguiente ciclo.
  to_create.clear();
}

/**
 * \brief   Se vuelve al inicio de la lista.
 */
void ActorManager::rewind ()
{
  actors_iter = actors.begin ();
}

/**
 * \brief   Se obtiene el siguiente actor de la lista.
 */
Actor *ActorManager::next ()
{
  Actor *tmp_a = NULL;

  if (actors_iter != actors.end())
  {
    tmp_a = *actors_iter;
    actors_iter++;
  }
  return tmp_a;
}

/**
 * \brief   Se obtiene el actor actual de la lista.
 */
Actor *ActorManager::current ()
{
  if (actors_iter==actors.end())
  {
    return NULL;
  }
  else
  {
    return *actors_iter;
  }
}

/**
 * \brief   Se obtiene el número de actores.
 */
int ActorManager::num_actors ()
{
  return actors.size ();
}

/**
 * \brief   Actualiza la lista de actores.
 */
void ActorManager::update ()
{
  list<Actor*>::iterator tmp_iter;

  // Se actualiza el estado del actor (¿¿Lo que se visualiza es el bloque??).
  actualizarVisualizacion ();

  /*
   * \todo  Hacer un "move_all_to_stage" para pasar los actores en bambalinas a escena y así
   *        eliminar las dos funciones "add_all_to_create" y "del_all_to_del" por separado. 
   */

  /* Agrega al escenario a todos los actores en espera. */
  add_all_to_create();

  /* Actualiza ahora los actores en escena. */
  for (tmp_iter=actors.begin(); tmp_iter!=actors.end(); tmp_iter++)
  {
    // Se actualiza el actor actual del bucle.
    (*tmp_iter)->update ();

    /* Se comprueba el estado del actor tras actualizar. */
    switch ((*tmp_iter)->get_Estado())
    {
    case Actor::eliminar:
      /* Si quiere ser eliminado se añade a la lista para eliminarlo. */
      del ((*tmp_iter));
      break;

    case Actor::crear:
      /**
      * Si quiere crear algún objeto se le pregunta por el hijo y se añade
      * a la lista.
      * \warning    No se comprueba que el actor pueda hacer esto. Es decir,
      *             no se comprueba que sea de la clase "GeneratorActor".
      *             En teoría si puede mandar ese mensaje es que es de esta clase.
      */
      Actor *tmp = (*tmp_iter);
      //add (tmp->get_hijo());

      /* Se cambia el estado del padre para que siga actuando. */
      /* \todo Incluir un set_estado */
      //(*tmp_iter)->set_estado = Actor::actuar;
      break;
    }
  }

  /* Elimina todos los actores en espera. */
  /* \todo  La llamada a esta función no tiene sentido si ya están los actores en escena. */
  del_all_to_del();
}

/**
 * \brief   Obtiene el iterador apuntando al actor incial.
 */
list<Actor*>::iterator  ActorManager::get_begin_iterator ()
{
    return actors.begin ();
}

/**
 * \brief   Obtiene el iterador apuntando al último actor.
 */
list<Actor*>::iterator ActorManager::get_end_iterator()
{
    return actors.end();
}

/**
 * \brief   Devuelve una lista de punteros de actores que interseccionan con un bloque.
 */
list<Actor *>  ActorManager::GetActores (Bloque &bloque)
{
  list<Actor *>               listaInterseccion;
  list<Actor *>::iterator     indice;

  /* Actualiza ahora los actores en escena. */
  for (indice=actors.begin(); indice!=actors.end(); indice++)
  {
    // Comprobamos que el actor intersecciona con el bloque.
    if ((*indice)->isIntersectado (bloque))
    {
      // Añadimos el actor a la nueva lista a devolver.
      listaInterseccion.push_back (*indice);
    }
  }
  return listaInterseccion;
};

/**
 * \brief   Actualiza la visualización de un actor.
 * \details Actualiza la visualización en modo debug.
 * \param   paramActor  Puntero al actor al que se le hará la visualización.
 */
void  ActorManager::setVisualizar (Actor *paramActor)
{
  actorVisualizado = paramActor;
}

/**
 * \brief   Actualiza la visualización del actor.
 */
void ActorManager::actualizarVisualizacion ()
{
  if (actorVisualizado != NULL)
  {
    actorVisualizado->getCodigo ();
  }
}

/**
 * \brief   Devuelve la referencia del actor dado como índice de la lista.
 */
Actor *  ActorManager::getActor (unsigned int indice)
{
  Actor *                   actor = NULL;
  list<Actor*>::iterator    iter;
  
  // Si el índice dado no corresponde con el número de actores devuelve NULL.
  if (indice < actors.size())
  {
    iter = get_begin_iterator ();
    for (unsigned int  i = 0; i < indice; i++, iter++){};
    actor = *iter;
  }
  return actor;
}

/**
 * \brief   Muestra en consola el aviso de un actor sin parte gráfica.
 */
void  ActorManager::avisoActorSinGrafico (Actor *a) const
{
  string nombre;
  a->getNombre (nombre);
  cout << "AVISO: Añadido actor \"" << nombre << "\" sin componente gráfica." << endl;
}


/**
 * \brief   Obtiene cadena representativa del objeto.
 * \details Es un procedimiento global.
 */
ostream & operator<< (ostream &os, const ActorManager &am)
{
  list<Actor*>::iterator  i;
  list<Actor*>                lista;

  lista = am.actors;
  for (i = lista.begin(); i != lista.end(); i++)
  {
      os << (Actor &) **i << endl;
  }
  return os;
}

/**
 * \brief   Obtiene los objetos de un flujo de datos.
 * \details Según el nombre leido del flujo crea un objeto actor de ese tipo y
 *          lo añade a la lista activa de actores.
 */
istream&  operator>> (istream &is, ActorManager &am)
{
  string nombre;
  Actor *nuevo;
	
  // Se lee el nombre del actor y se crea el objeto de la clase de actor leido.
  // \todo  Cambiar esta forma de crear el tipo de actor pues implica que la clase ActorManager
  //        debe conocer todos los tipos de actores que se crean ahora y en un futuro.
  //        Posiblemente haya otra forma de plantear el problema... ¿Con plantillas (templates)?
  is >> nombre;
  if (!nombre.compare("Ladrillo"))
  {
	nuevo = new Ladrillo();
  }
  else
  {
	nuevo = new Actor();
  }
  //is >> *nuevo;
  nuevo->prueba_iostream (is, *nuevo);
  am.add (nuevo);

  // Se muestra en pantalla un resumen.
  cout << endl << *nuevo << endl;
  return is;
}


/**
 * \brief   Obtiene los distintos trajes de los actores.
 * \details Obtiene los distintos objetos gráficos (trajes) de los actores.
 *          Un traje para un mismo actor puede ser el mismo, luego lo ideal
 *          sería definir una clase "Armario" donde se encuentren todos los
 *          trajes a utilizar. En este caso se separaría en una clase distinta
 *          y en esta clase iría este procedimiento.
 * \todo    Crear una clase "Armario" donde se incluyeran todos los trajes que
 *          utilizarán actores y decorado a lo largo del juego (atrezzo del juego).
 */
string  ActorManager::getArmario ()
{
  list<Actor*>::iterator  i;
  list<Actor*>            lista;

  ActorGraphic *agp;
  lista = actors;
  for (i = lista.begin(); i != lista.end(); i++)
  {
      agp = (*i)->get_actor_graphic ();
      //cout << (*i)->getString () << endl;
      if (agp)
      {
        cout << agp->getString ();
      }
  }
  return "---";
}


/**
 * \brief   Carga los actores de un fichero.
 * \details El formato del fichero es tal que...
 *                  Actores 3
 *                  Actor {
 *                  Nombre "Ladrillo"
 *                  Posición <120,40>
 *                  Bloque <32,15>
 *                  Bitmap "sprite_041"
 *                  }
 *                  Actor {...}
 *                  Actor {...}
 * 
 * \todo   A eliminar, no es necesaria esta función.
void  ActorManager::load (string &file)
{
    // Si no hay nombre de fichero usamos el nombre por omisión.
    if (file.empty())
    {
      file = "actores.txt";
    }

    // Se intenta abrir el fichero.
    //fstream  fs(file, fstream::in | fstream::out);
    fstream fs ("actores.txt", fstream::in | fstream::out);
    cout << "Prueba de carga de actores desde fichero." << endl;

    // TODO: Una primera línea que compruebe la versión del fichero de datos.
    // string version;
    // getline(fs,version);
    // if (!version.compare("JUEGO v2.0")) {return "El fichero de datos no está en la versión correcta)};
    
    // Se obtiene del fichero el comando y el valor.
    string comando, valor;
    fs >> comando >> valor;

    // Si el comando es el correcto se utiliza el valor.
    cout << comando << "|" << endl << valor << "|" << endl;

    unsigned int actores=0;
    if (!comando.compare("Actores"))
    {
        // actores = stoi(valores); //C++11
        stringstream ss(valor); // Para C++98 se necesita stringstream.
        ss >> actores;   
    }
    else
    {
        cout << "El fichero no contiene lista de actores." << endl;
    }

    // Según la lista de actores se leen los actores y se agregan.
    for (int i=1; i<=actores; i++)
    {
        cout << "--- Actor " << i << " ---" << endl;
        fs >> comando >> valor;
        if (!comando.compare ("Actor"))
        {
	  fs >> comando >> valor;
	  cout << valor;
        }
    }
    
    fs.close();
}
*/
