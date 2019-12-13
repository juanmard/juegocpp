#pragma once

#include "Actor.h"

namespace fwg {
    
class ActorManager;

/**
 * \class   DirectorActor
 * \brief   Actor que puede generar o controlar otros actores.
 * \details Para generar y cotrolar otros actores necesita un acceso a la clase "ActorManager"
 *          que lo controla a él mismo.
 *  \TODO Eliminar ya que esta misma función se realiza mediante los estados de los actores
 *        usando "TO_DELETE" como siguiente estado se elimina el actor de la lista sin
 *        necesidad de crear una clase nueva.
 */
class DirectorActor : public Actor
{
public:
                                    DirectorActor      (const DirectorActor &copia);
                                    DirectorActor      ();
                                    DirectorActor      (ActorManager *actor_manager);
                                    ~DirectorActor     ();
        virtual DirectorActor *     clone              () const;
        void                        Elimina            (Actor *);

private:
    ActorManager *  manager;
};

}