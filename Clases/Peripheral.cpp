#include "Peripheral.h"

Peripheral::Peripheral(void)
{
};

Peripheral::state_t Peripheral::get_state(component_t comp)
{
    return 0;
};

Peripheral::component_t Peripheral::get_change()
{
    return 0;
};

string Peripheral::get_component_name(component_t comp)
{
    return "";
};

void Peripheral::reset()
{
};
