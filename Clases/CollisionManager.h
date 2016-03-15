#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "Game.h"

//class Actor;

class CollisionManager
{
    public:
        typedef enum
        {
            BOUNDING_BOX,
            PP_COLLISION
        }collision_method_t;

                CollisionManager    (Game *g);        
        void    update              ();
        bool    Bounding            (Actor *actor1, Actor *actor2);

    protected:
        Game *game;
};

#endif