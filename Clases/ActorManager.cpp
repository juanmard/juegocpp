
#include "ActorManager.h"
#include "ActorGraphic.h"
#include "Actor.h"
#include "Ladrillo.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
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
      //Actor *tmp = (*tmp_iter);
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
 * \details El formato del fichero debe ser el siguiente:
 * \code
 *
 *                  Actores 3
 *                  Actores 1
 *                  Ladrillo {
 *                       Nombre "Ladrillo-001"
 *                       Posición <120,40>
 *                       Bloque <32,15>
 *                       Bitmap "sprite_041"
 *                       }
 *                  Paleta {...}
 *                  Henry {...}
 *
 * \endcode
 */
 void  ActorManager::load (const string &file)
{
#ifdef _DEBUG
    cout << "Prueba de carga de actores desde fichero." << endl << "Fichero a cargar: \"" << file << "\"" << endl;
#endif

    /* Se crea un nuevo fichero de lectura y se añaden excepciones. */
    ifstream *fs = new ifstream();
    fs->exceptions ();

    /* Se intenta abrir el fichero. */
    try
    {
        fs->open(file);

        /* Si el fichero no se ha abierto, se intenta con el nombre por omisión. */
        if (!fs->is_open())
        {
            cout << "Fichero \"" << file << "\" no se ha podido abrir. Se intenta nombre por omisión." << endl;
            fs->open("actores.txt"); /* \todo Hacer de la cadena un literal. */
            if (fs->is_open())
            {
                cout << "Abierto fichero \"actores.txt\"" << endl;
            }
            else
            {
                /* Si finalmente no se puede abrir se da por terminado el intento y se lanza la excepción. */
                throw std::string("Fichero \"actores.txt\" no se ha podido abrir.");
            }
        }
    }
    catch (std::string error)
    {
        cout << error << endl;
        return;
    }
    catch (ifstream::failure e)
    {
        cout << "Error al abrir el fichero: \"" << file << "\"" << endl;
        cout << "Error: " << endl << e.what();
        return;
    }

    /* Si se consigue localizar y abrir el fichero se continua procesando. */
    cout << "Se procesa el fichero. " << endl;

    /// \todo   Una primera línea que compruebe la versión del fichero de datos.
    // string version;
    // getline(fs,version);
    // if (!version.compare("JUEGO v2.0")) {return "El fichero de datos no está en la versión correcta)};
    int pos = buscar_propiedad ("Actores", *fs);

    // Se obtiene del fichero el comando y el valor.
    buscar ("Actor", *fs);
    string comando, valor;
    *fs >> comando >> valor;
    cout << comando << "\t" << valor << "\t" << endl;
    *fs >> comando >> valor;
    cout << comando << "\t" << valor << "\t" << endl;
    *fs >> comando >> valor;
    cout << comando << "\t" << valor << "\t" << endl;
    *fs >> comando >> valor;
    cout << comando << "\t" << valor << "\t" << endl;
    *fs >> comando >> valor;
    cout << comando << "\t" << valor << "\t" << endl;

    // Si el comando es el correcto se utiliza el valor.

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
    for (std::size_t i=1; i<=actores; i++)
    {
        cout << "--- Actor " << i << " ---" << endl;
        *fs >> comando >> valor;
        if (!comando.compare ("Actor"))
        {
        *fs >> comando >> valor;
        cout << valor;
        }
    }

    fs->close();
}

 /**
  * \brief  Busca dentro del fichero la propiedad pasada por parámetro.
  * \param  propiedad   Referencia al nombre de la propiedad a buscar.
  * \param  inFile      Referencia al 'filestream' donde buscar.
  * \return Posición de la propiedadd encontrada dentro del fichero.
  *         Devuelve el valor "string::npos" si no encuentra la propiedad.
  *
  * \todo   Crear una clase de fichero heredada de 'ifstream' donde incluir este procedimiento
  *         de esta forma se evitaría enviar el 'ifstream' por parámetro.
  */
std::size_t  ActorManager::buscar_propiedad  (const std::string &propiedad, std::ifstream &inFile) const
{
    std::string busqueda;

    // Se crea el formato de la propiedad dentro del fichero.
    // ej. "[Actores]"
    busqueda += '[';
    busqueda += propiedad;
    busqueda += ']';

    // Se busca la palabra creada.
    return buscar (propiedad,inFile);
}

 /**
  * \brief  Busca dentro del fichero una palabra pasada por parámetro.
  * \param  palabra    Referencia al nombre de la propiedad a buscar.
  * \param  inFile     Referencia al 'filestream' donde buscar.
  * \return Posición de la palabra encontrada dentro del fichero.
  *         Devuelve el valor "string::npos" si no encuentra la palabra.
  * \todo   Crear una clase de fichero heredada de 'ifstream' donde incluir este procedimiento
  *         de esta forma se evitaría enviar el 'ifstream' por parámetro.
  */
std::size_t  ActorManager::buscar  (const std::string &palabra, std::ifstream &inFile) const
{
    std::size_t pos;
    std::string linea;

    // Se toma línea por línea y se busca la palabra.
    while (getline(inFile,linea))
    {
      cout << linea << endl;
      pos = linea.find(palabra);
      if (pos != string::npos) // string::npos is returned if string is not found
      {
        cout << "Found! in " << pos << endl;
        break;
      }
    }
    return pos;
}

