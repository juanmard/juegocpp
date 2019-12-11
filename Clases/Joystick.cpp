///---------------------------------------------------------
/// @file       Joystick.cpp
/// @author     Juan Manuel Rico
/// @date       Diciembre 2019
/// @version    1.0.0
///
/// @brief      Definición del joystick como periférico.
///---------------------------------------------------------

#include "Joystick.h"
#include <iostream>

namespace fwg {

    Joystick::Joystick()
    {
        /// @warning Puede que intente instalar más de una vez si se
        ///          crean más de un objeto de tipo joystick.
        install ();
    }

    void Joystick::install ()
    {
        if (install_joystick (JOY_TYPE_AUTODETECT) == 0)
        {
            activos = num_joysticks;
            std::cout << "Joystick instalado. Activos: " << activos << std::endl;
        }
    }
    
    Peripheral::State Joystick::getState(State comp)
    {
        poll_joystick();
        
        // Pruebas de stick.
        if (joy_up != 0) std::cout << "Stick UP - " << joy_up << std::endl; 
        if (joy_down != 0) std::cout << "Stick DOWN - " << joy_down << std::endl; 
        if (joy_left != 0) std::cout << "Stick LEFT - " << joy_left << std::endl; 
        if (joy_right != 0) std::cout << "Stick RIGHT - " << joy_right << std::endl; 
        
        /// Prueba de componente, damos prioridad al componente stick.
        if ((joy_up != 0) && (comp == UP)) return TRUE;
        if ((joy_down != 0) && (comp == DOWN)) return TRUE;
        if ((joy_left !=0) && (comp == LEFT)) return TRUE;
        if ((joy_right != 0) && (comp == RIGHT)) return TRUE;
        
        // Pruebas de botón.
        if (joy[0].button[comp].b)
        {
            std::cout << "Botón " << comp << " - " << joy[0].button[comp].name << std::endl;
            return TRUE;
        }
        else
            return INVALID_STATE;
    }

    Peripheral::Component Joystick::getChange()
    {
        for (int i=0;i<MAX_JOYSTICK_BUTTONS;i++)
        {
            if (joy[0].button[i].b != oldState[i])
            {
                oldState[i] = joy[0].button[i].b;
                return i;
            }
        }
        return INVALID_COMPONENT;
    }

    void Joystick::reset()
    {
        for (int i=0; i<MAX_JOYSTICK_BUTTONS;i++) oldState[i]=joy[0].button[i].b;
    }

    std::string Joystick::getComponentName (Component comp)
    {
        std::string ret;

        switch (comp)
        {
            default:       ret="Sin nombre"; break;
        }
        return ret;
    }
    
}