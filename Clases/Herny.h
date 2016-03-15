#ifndef HERNY_H
#define HERNY_H

#include "ControllableActor.h"
#include "Sprite.h"
#include "DatFile.h"

class ControllableActor;

class Herny : public ControllableActor
{
    public:
        /**
         * Redefinimos las acciones para este actor.
         */
        typedef enum
        {
            DOWN,
            UP,
            LEFT,
            RIGHT,
            JUMP
        } action_t;

        /**
         * \todo    Generalizar los estados en una clase e incluirlos en la definicion general de "Actor".
         */
        typedef enum
        {
            de_pie,
            cayendo,
            saltando
        } Estados;

        /**
         * Constructor del actor principal ("Herny") sin parámetros.
         */
        Herny (void);
    
        void    do_action          (ControllableActor::action_t act, int magnitude);
        void    CambiarEstado      (void);
        void    ActualizarEstado   (void);
        void    hit                (Actor *who, int damage);

   
    protected:
        Sprite *skin;
        Estados actual, siguiente;
};


#endif