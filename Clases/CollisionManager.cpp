#include "CollisionManager.h"
#include "Game.h"
#include "Actor.h"
#include "ActorManager.h"
#include <list>

CollisionManager::CollisionManager(Game *g)
{
	game = g;
}

void CollisionManager::update ()
{
    list<Actor *>::iterator iter1,iter2,end;

    iter1 = game->actor_manager->get_begin_iterator ();
    end = game->actor_manager->get_end_iterator ();
    while ( iter1 != end )
    {
        iter2 = iter1;
        iter2++;
        while ( iter2 != end )
        {
            // Comprueba la intersección.
            if ( Bounding((*iter1), (*iter2)) )
            {
                (*iter1)->hit ((*iter2),1);
                (*iter2)->hit ((*iter1),1);
                 
                // Color de prueba.
                (*iter1)->set_color (!(*iter1)->get_color());
                (*iter2)->set_color (!(*iter2)->get_color());
            }

            // Seguimos con la siguiente.
            iter2++;       
        }
        iter1++;
    }
};

bool  CollisionManager::Bounding (Actor *actor1, Actor *actor2)
{
    return (!((actor1->get_x() > actor2->get_x() + actor2->get_w())
           || (actor2->get_x() > actor1->get_x() + actor1->get_w())
           || (actor1->get_y() > actor2->get_y() + actor2->get_h())
           || (actor2->get_y() > actor1->get_y() + actor1->get_h())));
};
