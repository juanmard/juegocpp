/**
 * \file    ControllableObject.cpp
 * \brief   Fichero de declaración de ControllableObject.
 * \author  Juan Manuel Rico
 * \date    Marzo 2015
 * \version 1.0.0
 * \todo    Este fichero no tiene sentido en una clase completamente abstracta.
 *          Se debería eliminar del proyecto.
 */

#include "ControllableObject.h"

/**
 * Constructor de copia.
 */
ControllableObject::ControllableObject  (const ControllableObject &copia)
{
};

/**
 * Constructor por omisión.
 */
ControllableObject::ControllableObject  ()
{
};

/**
 * Destructor.
 */
ControllableObject::~ControllableObject  ()
{
};

/**
 * Acciones virtuales.
 */
void ControllableObject::do_action  (action_t action, int magnitude)
{
};
