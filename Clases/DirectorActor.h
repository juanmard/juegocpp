#pragma once

#include "Actor.h"
class ActorManager;

/**
 * \class   DirectorActor
 * \brief   Actor que puede generar o controlar otros actores.
 * \details Para generar y cotrolar otros actores necesita un acceso a la clase "ActorManager"
 *          que lo controla a él mismo.
 */
class DirectorActor : public Actor
{
public:
                DirectorActor      (void);
                DirectorActor      (ActorManager *actor_manager);
                ~DirectorActor     (void);
        void    Elimina            (Actor *);

private:
    ActorManager        *manager;
    //Actor    *hijo;
};
