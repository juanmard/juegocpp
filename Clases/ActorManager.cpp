///---------------------------------------------------------
/// @file       ActorManager.cpp
/// @author     Juan Manuel Rico
/// @date       Noviembre 2015
/// @version    1.0.0
///
/// @brief      Controlador de lista de actores.
///---------------------------------------------------------

#include "ActorManager.h"
#include <algorithm>
#include <sstream>
#include "PrintableObject.h"

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

namespace fwg {

    ActorManager::ActorManager (Game* g):
    game (g)
    {
    };

    Actor* ActorManager::getActor (int x, int y)
    {
        Actor* encontrado = NULL;

        // Comprobar el bucle, es posible que el primero no lo compruebe si es
        // el único de la lista.
        actorsIter = actors.begin();
        while ( (encontrado == NULL) && (actorsIter != actors.end()) )
        {
            /// @todo Cambiar toda este 'if' por una intersección entre bloques de
            ///       los actores y un punto.
            if (!(  (x <= (*actorsIter)->get_x())
                 || (y <= (*actorsIter)->get_y())
                 || (x >= ((*actorsIter)->get_x() + (*actorsIter)->get_w()))
                 || (y >= ((*actorsIter)->get_y() + (*actorsIter)->get_h()))
                 ))
            {
                encontrado = *actorsIter;
            }
            else
            {
                actorsIter++;
            }
        }
        return encontrado;
    }

    ActorManager::~ActorManager()
    {
        for (actorsIter = actors.begin(); actorsIter != actors.end(); actorsIter++)
        delete (*actorsIter);
    }

    void ActorManager::add (Actor* a)
    {
        // Se comprueba si el actor que se quiere añadir a la lista tiene parte gráfica.
        // Si no la tiene se emite un aviso por consola. Se añade pues pueden existir "actores invisibles" en el juego.
        toCreate.push_back (a);
        if (a->getActorGraphic () == NULL)
        {
            aviso_actor_sin_grafico (*a);
        }
    }

    void ActorManager::del (Actor* a)
    {
        toDel.push_back (a);
    }

    void ActorManager::delAllToDel ()
    {
        if (toDel.size()==0) return;

        std::list<Actor*>::iterator tmpIter;
        std::list<Actor*>::iterator tmpActorsIter;

        for (tmpIter = toDel.begin(); tmpIter != toDel.end(); tmpIter++)
        {
            tmpActorsIter = std::find (actors.begin(), actors.end(), *tmpIter);
            if (tmpActorsIter != actors.end())
            {
                actors.erase (tmpActorsIter);
                // No eliminamos el actor, simplemente lo borramos de la lista (el actor se queda en el limbo).
                // delete (*tmp_iter);
            }
        }
        toDel.clear();
    }

    void ActorManager::addAllToCreate()
    {
        // Si no hay actores a crear se sale del procedimiento.
        if (toCreate.size() == 0) return;

        // Recorremos la lista a crear y añadimos los actores.
        std::list<Actor*>::iterator tmpIter;
        for (tmpIter = toCreate.begin(); tmpIter != toCreate.end(); tmpIter++)
        {
            actors.push_back(*tmpIter);
            (*tmpIter)->init();
        }

        // Limpiamos la lista a crear para el siguiente ciclo.
        toCreate.clear();
    }

    void ActorManager::rewind ()
    {
        actorsIter = actors.begin ();
    }

    Actor* ActorManager::next ()
    {
        Actor* tmpA = NULL;

        if (actorsIter != actors.end())
        {
            tmpA = *actorsIter;
            actorsIter++;
        }
        return tmpA;
    }

    Actor* ActorManager::current () const
    {
        if (actorsIter == actors.end())
        {
            return NULL;
        }
        else
        {
            return *actorsIter;
        }
    }

    unsigned int ActorManager::numActors () const
    {
        return actors.size ();
    }

    void ActorManager::update ()
    {
        std::list<Actor*>::iterator tmpIter;

        // Agrega al escenario a todos los actores en espera.
        addAllToCreate();

        // Actualiza ahora los actores en escena.
        for (tmpIter = actors.begin(); tmpIter != actors.end(); tmpIter++)
        {
            if ((*tmpIter)->getState() != Actor::DISABLE)
            {
                // Se actualiza el actor actual del bucle.
                (*tmpIter)->update();
                
                // Si su estado es a borrar, se agrega en la lista de
                // actores para borrar.
                if ((*tmpIter)->getState() == Actor::TO_DELETE)
                {
                    this->del(*tmpIter);
                }
            }
        }

        // Elimina todos los actores que están en la lista de eliminados.
        delAllToDel();
    }

    std::list<Actor*>::const_iterator& ActorManager::getBeginIterator () const
    {
        return *new std::list<Actor*>::const_iterator (actors.begin());
    }

    std::list<Actor*>::const_iterator& ActorManager::getEndIterator () const
    {
        return *new std::list<Actor*>::const_iterator (actors.end());
    }

    std::list<Actor*>& ActorManager::getActores (const Bloque& bloque) const
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
    }

    Actor* ActorManager::getActor (unsigned int indice) const
    {
        Actor* actor = NULL;
        std::list<Actor*>::const_iterator iter;

        // Si el índice dado no corresponde con el número de actores devuelve NULL.
        if (indice < actors.size())
        {
            iter = getBeginIterator ();
            for (unsigned int i = 0; i < indice; i++, iter++){};
            actor = *iter;
        }
        return actor;
    }

    void ActorManager::aviso_actor_sin_grafico (const Actor& a) const
    {
        std::cout << "AVISO: Añadido actor \"" << a.getNombre () << "\" sin componente gráfica." << std::endl;
    }

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
    }

    std::istream& operator>> (std::istream& is, ActorManager& am)
    {
        std::string nombre;
        Actor* nuevo;

        /// Se lee el nombre del actor y se crea el objeto de la clase de actor leido.
        /// @todo  Cambiar esta forma de crear el tipo de actor pues implica que la clase ActorManager
        ///        debe conocer todos los tipos de actores que se crean ahora y en un futuro.
        ///        Posiblemente haya otra forma de plantear el problema... ¿Con plantillas (templates)?
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
        std::cout << std::endl << *nuevo << std::endl;
        return is;
    }

    std::string& ActorManager::getArmario () const
    {
        std::list<Actor*>::iterator i;
        std::list<Actor*> lista;

        ActorGraphic *agp;
        lista = actors;
        for (i = lista.begin(); i != lista.end(); i++)
        {
            agp = (*i)->getActorGraphic ();
            //cout << (*i)->getString () << endl;
            if (agp)
            {
                std::cout << agp->print ();
            }
        }
        return *new std::string("---");
    }

    void ActorManager::deleteActors ()
    {
        toCreate.clear();
        toDel.clear();
        actors.clear();
    }
}
