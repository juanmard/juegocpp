#pragma once
#include "Actor.h"

/**
 * \class   DirectorActor
 * \brief   Actor que puede generar otros actores.
 * \details Para generar otros actores necesita un acceso al "ActorManager"
 *          que lo controla.
 */
class DirectorActor : public Actor
{
public:
                        DirectorActor      (void);
                        ~DirectorActor     (void);
    ActorManager        *manager;

private:
    //Actor    *hijo;
};
