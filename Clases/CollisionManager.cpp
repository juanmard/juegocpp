///
/// @file CollisionManager.cpp
/// @brief Fichero de implementación de la clase "CollisionManager".
/// @author Juan Manuel Rico
/// @date Noviembre 2015
/// @version 1.0.0
///

#include "CollisionManager.h"
#include "Actor.h"
#include <list>

CollisionManager::CollisionManager (Game* g)
{
  game = g;
};

void CollisionManager::update ()
{
  std::list<Actor *>::const_iterator iter1, iter2, end;

  // El bucle hace combinaciones dos a dos de todos los actores.
  iter1 = game->actor_manager->get_begin_iterator ();
  end = game->actor_manager->get_end_iterator ();
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
        (*iter1)->set_color (!(*iter1)->get_color());
        (*iter2)->set_color (!(*iter2)->get_color());
      }

      // Seguimos con el siguiente actor de la lista.
      iter2++;
    }
  iter1++;
  }
};

bool  CollisionManager::Bounding (Actor* actor1, Actor* actor2)
{
  return (!((actor1->get_x() > actor2->get_x() + actor2->get_w())
         || (actor2->get_x() > actor1->get_x() + actor1->get_w())
         || (actor1->get_y() > actor2->get_y() + actor2->get_h())
         || (actor2->get_y() > actor1->get_y() + actor1->get_h())));
};
