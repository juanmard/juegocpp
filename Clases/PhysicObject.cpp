///
/// @file PhysicObject.cpp
/// @brief Fichero de implementación de la clase "PhysicObject".
/// @author Juan Manuel Rico
/// @date Noviembre 2015
/// @version
///      - 1.0.0 Noviembre 2015.
///

#include "PhysicObject.h"

namespace fwg {
    
const float PhysicObject::g = 9.8f;

PhysicObject::PhysicObject ():
velocidad (0.0f, 0.0f),
cdg (0.0f, 0.0f),
masa (0.0f),
area (0.0f),
volumen (0.0f),
mto_inercia (0.0f)
{
};

PhysicObject::~PhysicObject ()
{
};

}