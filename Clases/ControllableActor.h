///
/// @file ControllableActor.h
/// @brief Fichero cabecera de la clase "ControllableActor".
/// @author Juan Manuel Rico
/// @date Marzo 2015
/// @version 1.0.0
///

#ifndef CONTROLLABLEACTOR_H
#define CONTROLLABLEACTOR_H

#include "Actor.h"
#include "ControllableObject.h"
#include "Control.h"

namespace fwg {

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
    /// @param copia  Referencia al actor que se desea copiar.
    ///
    ControllableActor (const ControllableActor& copia);

    /// Obtiene el control del actor.
    /// @return Puntero al control que utiliza actualmente el actor.
    ///
    Control* get_control () const;
};

}

#endif
