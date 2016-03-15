///
/// @file    ControllableActor.h
/// @brief   Fichero de definiciones de "ControllableActor".
/// @author  Juan Manuel Rico
/// @date    Marzo 2015
/// @version 1.0.0
/// 

#include "ControllableActor.h"

ControllableActor::ControllableActor ():
control (NULL)
{
};

ControllableActor::ControllableActor (const ControllableActor &copia):
Actor (copia),
control (NULL)
{
};

Control* ControllableActor::get_control () const
{
    return control;
};
