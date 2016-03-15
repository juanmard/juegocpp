#include "Keyboard.h"

Keyboard::Keyboard()
{
    for (int i=0; i<KEY_MAX;i++) old_state[i]=key[i];
}

Peripheral::state_t Keyboard::get_state(state_t comp)
{
    if (keyboard_needs_poll())
        poll_keyboard();
    if ((comp>=0) && (comp<KEY_MAX) && (key[comp])) return TRUE;
    else
        return INVALID_STATE;
}

Peripheral::component_t Keyboard::get_change()
{
    for (int i=0;i<KEY_MAX;i++)
    {
        if (key[i]!=old_state[i])
        {
            old_state[i]=key[i];
            return i;
        }
    }
    return INVALID_COMPONENT;
}

void Keyboard::reset()
{
    for (int i=0; i<KEY_MAX;i++) old_state[i]=key[i];
}

string Keyboard::get_component_name(component_t comp)
{
string ret;

/**
 * \todo Devolver un valor para cada tecla.
 */
switch (comp)
{
    case KEY_A:    ret="A";    break;
    case KEY_B:    ret="B";    break;
    case KEY_C:    ret="C";    break;
    case KEY_D:    ret="D";    break;
    default:       ret="Sin nombre"; break;
}

return ret;
}