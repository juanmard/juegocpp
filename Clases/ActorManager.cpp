
#include "ActorManager.h"
#include "ActorGraphic.h"
#include "Actor.h"

// Se incluyen todos los actores posibles que puede manejar la clase.
#include "AirCraft.h"
#include "Ben.h"
#include "Herny.h"
#include "Ladrillo.h"
#include "Loro.h"
#include "Mago.h"
#include "Paleta.h"
#include "Pelota.h"
#include "Plataforma.h"
#define CMP_CLASE(cls) if (!clase.compare (#cls)) return (*new cls());   ///< Macro para comparar y crear el actor de clase "cls".

// Bibliotecas estándar.
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
    avisoActorSinGrafico (*a);
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

void ActorManager::update ()
{
    list<Actor*>::iterator tmp_iter;

    // Se actualiza el estado del actor (¿¿Lo que se visualiza es el bloque??).
    actualizarVisualizacion ();

    // Agrega al escenario a todos los actores en espera.
    add_all_to_create();

    // Actualiza ahora los actores en escena.
    for (tmp_iter=actors.begin(); tmp_iter!=actors.end(); tmp_iter++)
    {
        // Se actualiza el actor actual del bucle.
        (*tmp_iter)->update ();

        /// Se comprueba el estado del actor tras actualizar.
        /// @note Se sospecha que esta parte fue una prueba que "no llegó a cuajar".
        ///       Eliminar si se confirma.
        switch ((*tmp_iter)->get_Estado())
        {
        case Actor::eliminar:
            // Si quiere ser eliminado se añade a la lista para eliminarlo.
            del ((*tmp_iter));
            break;

        case Actor::crear:
            ///
            /// Si quiere crear algún objeto se le pregunta por el hijo y se añade a la lista.
            /// @warning    No se comprueba que el actor pueda hacer esto. Es decir,
            ///             no se comprueba que sea de la clase "GeneratorActor".
            ///             En teoría si puede mandar ese mensaje es que es de esta clase.
            ///
            /// Actor *tmp = (*tmp_iter);
            /// add (tmp->get_hijo());

            /// Se cambia el estado del padre para que siga actuando.
            /// @todo Incluir un set_estado 
            /// @code
            /// (*tmp_iter)->set_estado = Actor::actuar;
            /// @endcode
            break;
        }
    }

    /// Elimina todos los actores en espera.
    /// @note La llamada a esta función no tiene sentido si ya están los actores en escena.
    del_all_to_del();
};

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

void ActorManager::actualizarVisualizacion ()
{
  if (actorVisualizado != NULL)
  {
    actorVisualizado->getCodigo ();
  }
};

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

void  ActorManager::avisoActorSinGrafico (Actor& a) const
{
    cout << "AVISO: Añadido actor \"" << a.getNombre () << "\" sin componente gráfica." << endl;
};

/**
 * \brief   Obtiene cadena representativa del objeto.
 * \details Es un procedimiento global.
 */
ostream & operator<< (ostream &os, const ActorManager &am)
{
  list<Actor*>::iterator i;
  list<Actor*> lista;

  lista = am.actors;
  os << "[Actores]" << std::endl \
     << "Cantidad " << lista.size () << std::endl;
  for (i = lista.begin(); i != lista.end(); i++)
  {
      os << (Actor &) **i << std::endl;
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
    //nuevo = new Actor();
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
 * \brief   Carga la lista de actores desde un fichero de texto.
 * \details El formato del fichero debe ser el siguiente:
 * \code
 *                  [Actores]
 *                  Cantidad 3
 *                  Ladrillo {
 *                       Nombre "Ladrillo-001"
 *                       Posición <120,40>
 *                       Bloque <32,15>
 *                       Bitmap "sprite_041"
 *                       }
 *                  Paleta {...}
 *                  Henry {...}
 * \endcode
 * \param   file    Referencia al nombre del fichero de texto.
 */
 void ActorManager::load (const string& file)
{
#ifdef _DEBUG
    std::cout << "Prueba de carga de actores desde fichero." << std::endl \
              << "Fichero a cargar: \"" << file << "\"" << std::endl;
#endif

    // Se crea un nuevo fichero para lectura.
    std::ifstream& ifs = *new ifstream();

    // Se intenta abrir el fichero.
    try
    {
        //ifs.open(file);

        // Si el fichero no se ha abierto, se intenta con el nombre por omisión.
        if (!ifs.is_open())
        {
            std::cout << "Fichero \"" << file << "\" no se ha podido abrir. Se intenta nombre por omisión." << std::endl;
            ifs.open("actores.txt"); ///< \todo Hacer de la cadena un literal.
            if (ifs.is_open())
            {
                std::cout << "Abierto fichero \"actores.txt\"" << std::endl;
            }
            else
            {
                // Si finalmente no se puede abrir se da por terminado el intento y se lanza la excepción.
                throw std::string("Fichero \"actores.txt\" no se ha podido abrir.");
            }
        }
    }
    catch (std::string error)
    {
        std::cout << error << std::endl;
        return;
    }
    catch (ifstream::failure e)
    {
        std::cout << "Error al abrir el fichero: \"" << file << "\"" << std::endl;
        std::cout << "Error: " << std::endl << e.what();
        return;
    }

    // Si se consigue localizar y abrir el fichero se continua procesando.
    std::cout << "Se procesa el fichero. " << std::endl;

    /// @todo Una primera línea que compruebe la versión del fichero de datos.
    // string version;
    // getline(fs,version);
    // if (!version.compare("JUEGO v2.0")) {return "El fichero de datos no está en la versión correcta)};
    size_t pos = buscar_propiedad ("Actores", ifs);

    // Se obtiene del fichero el comando y el valor.
    string comando, valor, clase;
    int num;

    ifs >> std::skipws >> comando >> std::skipws >> num;
    // std::cout << "Comando: " << comando << "\tValor: " << num << "\t" << std::endl;

    // Se procesan el número de actores indicados (num).
    for (int i=0; i<num; i++)
    {
        // Leer la clase del actor.
        ifs >> clase;
        std::cout << "Clase: " << clase << std::endl;

        // Se intenta crear un nuevo actor (vacío) de la clase pasada por parámetro, pero devolviendo
        // la clase abstracta actor.
        try {
            Actor& actor = crearActor(clase);

            // Se leen los valores de las propiedades del actor desde el fichero de texto.
            ifs.ignore (100,'{');
            ifs >> actor;
            ifs.ignore (100,'}');

            // Se agrega el actor leído a la lista.
            this->add (&actor);
        }
        catch (std::string error)
        {
            std::cout << "Error: " << error << std::endl \
                      << "Se intentará con el siguiente comando.";
            ifs.ignore (200,'}');
        }
    }
    // Se preparan todos los actores agregados para actuar.
    this->add_all_to_create ();

    // Se cierra el fichero.
    ifs.close();
};

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
    // NOTA: Intentar hacerlo de manera más limpia ignorando los caracteres hasta encontrar el primer caracter '['
    //       con la función "ignore(256,'[');"
    busqueda += '[';
    busqueda += propiedad;
    busqueda += ']';

    std::cout << "Se busca la propiedad: " << busqueda << std::endl;

    // Se busca la palabra creada.
    std::size_t pos = buscar (busqueda,inFile);
    return pos;
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
      std::cout << linea << std::endl;
      pos = linea.find(palabra);
      if (pos != string::npos) // string::npos is returned if string is not found
      {
        std::cout << "Found! in " << pos << std::endl;
        break;
      }
    }
    return pos;
}

void ActorManager::deleteActors ()
{
    to_create.clear();
    to_del.clear();
    actors.clear();
};

Actor& ActorManager::crearActor (const std::string& clase) const
{
    CMP_CLASE(AirCraft);
    CMP_CLASE(Ben);
    CMP_CLASE(Herny);
    CMP_CLASE(Ladrillo);
    CMP_CLASE(Loro);
    CMP_CLASE(Mago);
    CMP_CLASE(Paleta);
    CMP_CLASE(Pelota);
    CMP_CLASE(Plataforma);
    throw std::string ("La clase \"" + clase + "\" no existe o no puede ser controlada por \"ActorManager\"");
};

