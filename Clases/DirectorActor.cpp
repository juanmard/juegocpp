#include "DirectorActor.h"
#include "ActorManager.h"


DirectorActor::DirectorActor(void)
{
    manager = NULL;
}

DirectorActor::DirectorActor(ActorManager *actor_manager)
{
    manager = actor_manager;
}

DirectorActor::~DirectorActor(void)
{
}

/**
 * \brief Elimina un actor de la escena.
 */
void DirectorActor::Elimina  (Actor *who)
{
    manager->del(who);
}
