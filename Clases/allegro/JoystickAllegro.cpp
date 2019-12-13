///---------------------------------------------------------
/// @file       JoystickAllegro.cpp
/// @author     Juan Manuel Rico
/// @date       Diciembre 2019
/// @version    1.0.0
///
/// @brief      Joystick usando bibliotecas de Allegro.
///---------------------------------------------------------

#include "JoystickAllegro.h"
#include <iostream>

namespace alg4 {

    JoystickAllegro::JoystickAllegro ()
    {
        Joystick::init();
    }
    
    bool JoystickAllegro::install ()
    {
        bool salida = false;
        if (install_joystick (JOY_TYPE_AUTODETECT) == 0)
        {
             activos++;
             std::cout << "Joystick instalado. Activos: " << activos << std::endl;
             salida = true;
        }
        return salida;
    }
       
    unsigned int JoystickAllegro::getNumAxis ()
    {
        return joy[0].stick[0].num_axis;
    }

    unsigned int JoystickAllegro::getNumButtons ()
    {
        return joy[0].num_buttons;
    }
    
    void JoystickAllegro::update ()
    {
        poll_joystick();
        
        /// Se actualizan los ejes.
        for (unsigned int i=0; i<numAxis; i++)
        {
            axis[i].d1 = joy[0].stick[0].axis[i].d1;
            axis[i].d2 = joy[0].stick[0].axis[i].d2;
        }

        /// Se actualizan los botones.
        for (unsigned int i=0; i<numButtons; i++)
        {
            buttons[i].b = joy[0].button[i].b;
        }
    }
}