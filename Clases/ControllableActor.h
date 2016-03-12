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

/// @class Define un actor controlable mediante herencia.
///
class ControllableActor : public Actor, public ControllableObject
{
public:
    /// Constructor por defecto.
    ///
    ControllableActor ();
    
    /// Constructor de copia.
    /// @param copia  Referencia al actor que se desea copiar.
    ///
    ControllableActor   (const ControllableActor &copia);
};

#endif
