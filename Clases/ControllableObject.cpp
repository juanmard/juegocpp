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
