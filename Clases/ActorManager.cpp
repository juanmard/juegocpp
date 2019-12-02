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

#define _DEBUG_

namespace fgm {

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
    std::list<Actor*>::iterator tmp_iter;

    // Agrega al escenario a todos los actores en espera.
    add_all_to_create();

    // Actualiza ahora los actores en escena.
    for (tmp_iter=actors.begin(); tmp_iter!=actors.end(); tmp_iter++)
    {
        
        /// ---------------------------------
        /// 2019-12-01 - Prueba de control en lista según estado del actor.
        if ((*tmp_iter)->get_state () != Actor::DISABLE) {
            // Se actualiza el actor actual del bucle.
            (*tmp_iter)->update ();
            
            /// ---------------------------------
            /// 2019-12-01 - Prueba de control en lista según estado del actor.
            if ((*tmp_iter)->get_state () == Actor::TO_DELETE) {
                this->del((*tmp_iter));
            }
            /// ---------------------------------

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
  std::list<Actor*>::const_iterator iter;

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
  std::cout << "AVISO: Añadido actor \"" << a.getNombre () << "\" sin componente gráfica." << std::endl;
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
///  nuevo->prueba_iostream (is, *nuevo);
  am.add (nuevo);

  // Se muestra en pantalla un resumen.
  std::cout << std::endl << *nuevo << std::endl;
  return is;
};

std::string& ActorManager::get_armario () const {
  std::list<Actor*>::iterator i;
  std::list<Actor*> lista;

  ActorGraphic *agp;
  lista = actors;
  for (i = lista.begin(); i != lista.end(); i++) {
      agp = (*i)->get_actor_graphic ();
      //cout << (*i)->getString () << endl;
      if (agp) {
        std::cout << agp->print ();
      }
  }
  return *new std::string("---");
};

void ActorManager::delete_actors () {
    to_create.clear();
    to_del.clear();
    actors.clear();
};

}
