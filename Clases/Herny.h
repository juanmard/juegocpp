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

                            Herny               ();
                            Herny               (Almacen &almacen);
                            Herny               (const Herny &copia);    
        void                do_action           (ControllableActor::action_t act, int magnitude);
        void                CambiarEstado       ();
        void                CambiarEstado       (Almacen &almacen);
        void                ActualizarEstado    ();
        void                hit                 (Actor *who, int damage);
        virtual Herny *     clone               () const;

   
    protected:
        Sprite *skin;
        Estados actual, siguiente;
};


#endif
