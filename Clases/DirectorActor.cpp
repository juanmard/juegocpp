#include "DirectorActor.h"
#include "ActorManager.h"

namespace fgm {
    
/**
 * \brief   Constructor de copia.
 */
DirectorActor::DirectorActor (const DirectorActor &copia):
Actor(copia),
manager(copia.manager)
{
}

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

/**
 * \brief   Clona el objeto.
 */
DirectorActor * DirectorActor::clone () const
{
    return NULL;
}

}