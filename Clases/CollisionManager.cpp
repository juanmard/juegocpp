///
/// @file CollisionManager.cpp
/// @brief Fichero de implementación de la clase "CollisionManager".
/// @author Juan Manuel Rico
/// @date Noviembre 2015
/// @version
///      - 1.0.0 Noviembre 2015
///

#include "Actor.h"
#include "ActorManager.h"
#include "CollisionManager.h"
#include <list>

namespace fwg {

CollisionManager::CollisionManager (Game* g)
{
  game = g;
};

void CollisionManager::update ()
{
  std::list<Actor *>::const_iterator iter1, iter2, end;

  // El bucle hace combinaciones dos a dos de todos los actores.
  iter1 = game->actorManager->getBeginIterator ();
  end = game->actorManager->getEndIterator ();
  while ( iter1 != end )
  {
    iter2 = iter1;
    iter2++;
    while ( iter2 != end )
    {
      // Comprueba la intersección.
      if ( Bounding ((*iter1), (*iter2)) )
      {
        // Ejecuta el procedimiento de choque en ambos actores.
        (*iter1)->hit ((*iter2), 1);
        (*iter2)->hit ((*iter1), 1);

        // Cambia el color de prueba de cada actor.
        (*iter1)->setColor (!(*iter1)->getColor());
        (*iter2)->setColor (!(*iter2)->getColor());
      }

      // Seguimos con el siguiente actor de la lista.
      iter2++;
    }
  iter1++;
  }
};

bool  CollisionManager::Bounding (Actor* actor1, Actor* actor2)
{
  return (!((actor1->getX() > actor2->getX() + actor2->getW())
         || (actor2->getX() > actor1->getX() + actor1->getW())
         || (actor1->getY() > actor2->getY() + actor2->getH())
         || (actor2->getY() > actor1->getY() + actor1->getH())));
}
}