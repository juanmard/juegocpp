///
/// @file ActorManager.cpp
/// @brief Fichero de implementación de la clase "ActorManager".
/// @author Juan Manuel Rico
/// @date Noviembre 2015
/// @version 1.0.0
///

#include "ActorManager.h"
#include <algorithm>
#include <sstream>

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

#define _DEBUG_

ActorManager::ActorManager (Game* g):
game (g)
{
};

Actor* ActorManager::get_actor (int x, int y)
{
  Actor* encontrado = NULL;

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
};

ActorManager::~ActorManager()
{
  for (actors_iter = actors.begin(); actors_iter != actors.end(); actors_iter++)
  delete (*actors_iter);
};

void ActorManager::add (Actor* a)
{
  // Se comprueba si el actor que se quiere añadir a la lista tiene parte gráfica.
  // Si no la tiene se emite un aviso por consola. Se añade pues pueden existir "actores invisibles" en el juego.
  to_create.push_back (a);
  if (a->get_actor_graphic () == NULL)
  {
    aviso_actor_sin_grafico (*a);
  }
};

void ActorManager::del (Actor* a)
{
  to_del.push_back (a);
};

void ActorManager::del_all_to_del ()
{
  if (to_del.size()==0) return;

  std::list<Actor*>::iterator tmp_iter;
  std::list<Actor*>::iterator tmp_actors_iter;

  for (tmp_iter=to_del.begin(); tmp_iter!=to_del.end(); tmp_iter++)
  {
    tmp_actors_iter = std::find (actors.begin(), actors.end(), *tmp_iter);
    if (tmp_actors_iter!=actors.end())
    {
      actors.erase (tmp_actors_iter);
      // No eliminamos el actor, simplemente lo borramos de la lista (el actor se queda en el limbo).
      // delete (*tmp_iter);
    }
  }
  to_del.clear();
};

void ActorManager::add_all_to_create()
{
  // Si no hay actores a crear se sale del procedimiento.
  if (to_create.size()==0) return;

  // Recorremos la lista a crear y añadimos los actores.
  std::list<Actor*>::iterator tmp_iter;
  for (tmp_iter=to_create.begin(); tmp_iter!=to_create.end(); tmp_iter++)
  {
    actors.push_back(*tmp_iter);
    (*tmp_iter)->init();
  }

  // Limpiamos la lista a crear para el siguiente ciclo.
  to_create.clear();
};

void ActorManager::rewind ()
{
  actors_iter = actors.begin ();
};

Actor* ActorManager::next ()
{
  Actor* tmp_a = NULL;

  if (actors_iter != actors.end())
  {
    tmp_a = *actors_iter;
    actors_iter++;
  }
  return tmp_a;
};

Actor* ActorManager::current ()
{
  if (actors_iter == actors.end())
  {
    return NULL;
  }
  else
  {
    return *actors_iter;
  }
};

unsigned int ActorManager::num_actors () const
{
  return actors.size ();
};

void ActorManager::update ()
{
    list<Actor*>::iterator tmp_iter;

    // Agrega al escenario a todos los actores en espera.
    add_all_to_create();

    // Actualiza ahora los actores en escena.
    for (tmp_iter=actors.begin(); tmp_iter!=actors.end(); tmp_iter++)
    {
        // Se actualiza el actor actual del bucle.
        (*tmp_iter)->update ();

        // Prueba de suicidio de loro.
        if ((*tmp_iter)->get_Estado() == Loro::KILL)
        {
          this->del((Actor*)(*tmp_iter));
        }
    }

    // Elimina todos los actores que están en la lista de eliminados.
    del_all_to_del();
};

std::list<Actor*>::const_iterator& ActorManager::get_begin_iterator () const
{
    return *new std::list<Actor*>::const_iterator (actors.begin());
};

std::list<Actor*>::const_iterator& ActorManager::get_end_iterator () const
{
    return *new std::list<Actor*>::const_iterator (actors.end());
};

std::list<Actor*>& ActorManager::get_actores (const Bloque& bloque) const
{
  std::list<Actor*>& listaInterseccion = *new std::list<Actor*>();
  std::list<Actor*>::const_iterator indice;

  /* Actualiza ahora los actores en escena. */
  for (indice = actors.begin(); indice != actors.end(); indice++)
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

Actor* ActorManager::get_actor (unsigned int indice) const
{
  Actor* actor = NULL;
  list<Actor*>::const_iterator iter;

  // Si el índice dado no corresponde con el número de actores devuelve NULL.
  if (indice < actors.size())
  {
    iter = get_begin_iterator ();
    for (unsigned int i = 0; i < indice; i++, iter++){};
    actor = *iter;
  }
  return actor;
};

void ActorManager::aviso_actor_sin_grafico (const Actor& a) const
{
  cout << "AVISO: Añadido actor \"" << a.getNombre () << "\" sin componente gráfica." << endl;
};

std::string& ActorManager::print () const
{
  std::ostringstream oss;
  std::list<Actor*>::const_iterator i;

  oss << "[Actores]" << std::endl \
      << "Cantidad " << actors.size () << std::endl;
  for (i = actors.begin(); i != actors.end(); i++)
  {
      oss << (Actor&) **i << std::endl;
  }

  return *new std::string(oss.str());
};

std::istream& operator>> (std::istream& is, ActorManager& am)
{
  std::string nombre;
  Actor* nuevo;

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
};

std::string& ActorManager::get_armario () const
{
  std::list<Actor*>::iterator i;
  std::list<Actor*> lista;

  ActorGraphic *agp;
  lista = actors;
  for (i = lista.begin(); i != lista.end(); i++)
  {
      agp = (*i)->get_actor_graphic ();
      //cout << (*i)->getString () << endl;
      if (agp)
      {
        cout << agp->print ();
      }
  }
  return *new std::string("---");
};

void ActorManager::load (const std::string& file)
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
        ifs.open(file.c_str());

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
    catch (std::ifstream::failure e)
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
    //size_t pos = buscar_propiedad ("Actores", ifs);
    buscar_propiedad ("Actores", ifs);

    // Se obtiene del fichero el comando y el valor.
    std::string comando, valor, clase;
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
            Actor& actor = crear_actor(clase);

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
    add_all_to_create ();

    // Se cierra el fichero.
    ifs.close();
};

std::size_t ActorManager::buscar_propiedad (const std::string& propiedad, std::ifstream& inFile) const
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
    std::size_t pos = buscar (busqueda, inFile);
    return pos;
};

std::size_t ActorManager::buscar (const std::string& palabra, std::ifstream& inFile) const
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
};

void ActorManager::delete_actors ()
{
    to_create.clear();
    to_del.clear();
    actors.clear();
};

Actor& ActorManager::crear_actor (const std::string& clase) const
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

