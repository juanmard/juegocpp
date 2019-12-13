///---------------------------------------------------------
/// @file       ControllableActor.h
/// @author     Juan Manuel Rico
/// @date       Marzo 2015
/// @version    1.0.0
///
/// @brief      Define un actor que es controlable.
///---------------------------------------------------------
#ifndef _CONTROLLABLEACTOR_H_
#define _CONTROLLABLEACTOR_H_

#include "Actor.h"
#include "ControllableObject.h"

namespace fwg {
    
    /// Predefinición de clases.
    class Control;

    /// Define un actor controlable mediante herencia.
    ///
    class ControllableActor : public Actor, public ControllableObject
    {
        protected:
            Control* control;   ///< Control que se utiliza para el actor.

        public:
            /// Constructor por defecto.
            ///
            ControllableActor ();

            /// Constructor de copia.
            /// 
            /// @param copia Referencia al actor que se desea copiar.
            ///
            ControllableActor (const ControllableActor& copia);

            /// Obtiene el control del actor.
            /// 
            /// @return Puntero al control que utiliza actualmente el actor.
            ///
            Control* getControl () const;
    };

}

#endif
