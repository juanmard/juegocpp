///---------------------------------------------------------
/// @file       ControllableActor.cpp
/// @author     Juan Manuel Rico
/// @date       Marzo 2015
/// @version    1.0.0
///
/// @brief      Define un actor que es controlable.
///---------------------------------------------------------
#include "ControllableActor.h"
#include "Control.h"

namespace fwg {

    ControllableActor::ControllableActor ():
    control (NULL)
    {
    }

    ControllableActor::ControllableActor (const ControllableActor& copia):
    Actor (copia),
    control (NULL)
    {
    }

    Control* ControllableActor::getControl () const
    {
        return control;
    }
}