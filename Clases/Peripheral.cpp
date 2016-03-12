///
/// @file Peripheral.cpp
/// @brief Fichero de implementación de la clase "Peripheral".
/// @author Juan Manuel Rico
/// @date Octubre 2015
/// @version 1.0.0
///

#include "Peripheral.h"

Peripheral::Peripheral ()
{
};

Peripheral::~Peripheral ()
{
};

Peripheral::state_t Peripheral::get_state (component_t comp)
{
    return 0;
};

Peripheral::component_t Peripheral::get_change ()
{
    return 0;
};

std::string Peripheral::get_component_name (component_t comp)
{
    return "";
};

void Peripheral::reset ()
{
};
