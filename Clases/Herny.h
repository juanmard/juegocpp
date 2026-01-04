#ifndef _HERNY_H_
#define _HERNY_H_

#include <string>
#include "ControllableActor.h"
#include "Sprite.h"
#include "DatFile.h"
#include "StorageManager.h"
#include "Bitmap.h"


class ControllableActor;

class Herny : public ControllableActor
{
    public:
        /**
         * Redefinimos las acciones para este actor.
         */
        typedef enum {DOWN, UP, LEFT, RIGHT, JUMP} action_t;

        /**
         * \todo    Generalizar los estados en una clase e incluirlos en la definicion general de "Actor".
         */
        typedef enum {de_pie, cayendo, saltando} Estados;

                            Herny               ();
                            Herny               (StorageManager &almacen);
                            Herny               (const Herny &copia);    
        void                do_action           (ControllableActor::action_t act, int magnitude);
        void                CambiarEstado       ();
        void                CambiarEstado       (StorageManager &almacen);
        void                ActualizarEstado    ();
        void                hit                 (Actor *who, int damage);
        virtual Herny *     clone               () const;
        void                getNombre           (std::string &strNombre) const;
        std::string              getNombre           () const;

  protected:
        Sprite *    skin;
        Estados     actual, siguiente;
};


#endif
