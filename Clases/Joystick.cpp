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

    /// Se inicializa la variable de clase.
    /// 
    int Joystick::activos = 0;
    
    Joystick::Joystick():
    joyId(0)
    {
    }
    
    void Joystick::init ()
    {
        if (install ())
        {
            /// @todo Comprobar que el joystick se a instalado correctamente.
            /// 
            numAxis = getNumAxis();
            numButtons= getNumButtons();
            
            /// Redimensionamos vectores según el tipo de joystick.
            /// 
            axis.resize(numAxis);
            buttons.resize(numButtons);
            oldStateAxis.resize(numAxis);
            oldStateButtons.resize(numButtons);
            
            /// Se resetea los valores de los vectores.
            /// @todo Definir un reset individual como método para las
            ///       clases "JoyAxis" y "JoyButtons"
            ///       
            reset();
        }
    }

    Peripheral::State Joystick::getState(State comp)
    {
        update ();
        
        if (axis[1].d1 != 0) std::cout << "Joy" << joyId << " - UP" << std::endl;
        if (axis[1].d2 != 0) std::cout << "Joy" << joyId << " - DOWN" << std::endl; 
        if (axis[0].d2 != 0) std::cout << "Joy" << joyId << " - RIGHT" << std::endl; 
        if (axis[0].d1 != 0) std::cout << "Joy" << joyId << " - LEFT" << std::endl; 
        
        /// Prueba de componente, damos prioridad al componente stick.
        if ((axis[1].d1 != 0) && (comp == UP)) return true;
        if ((axis[1].d2 != 0) && (comp == DOWN)) return true;
        if ((axis[0].d2 != 0) && (comp == RIGHT)) return true;
        if ((axis[0].d1 != 0) && (comp == LEFT)) return true;
        
        // Pruebas de botón.
        if ( (buttons[comp].b) && (comp < static_cast<int>(numButtons)) )
        {
            std::cout << "Joy" << joyId << " - Botón " << comp << std::endl;
            return true;
        }
        else
            return INVALID_STATE;
    }

    Peripheral::Component Joystick::getChange()
    {
        for (unsigned int i=0; i < numButtons; i++)
        {
            if (buttons[i].b != oldStateButtons[i])
            {
                oldStateButtons[i] = buttons[i].b;
                return i;
            }
        }
        return INVALID_COMPONENT;
    }

    void Joystick::reset()
    {
        for (unsigned int i=0; i<numAxis; i++)
        {
            axis[i].d1=0;
            axis[i].d2=0;
        }
        for (unsigned int i=0; i<numButtons; i++)
        {
            buttons[i].b = false;
            buttons[i].value = 0;
        }
        for (unsigned int i=0; i<numAxis; i++) oldStateAxis[i]=0;
        for (unsigned int i=0; i<numButtons; i++) oldStateButtons[i]=false;
    }

    std::string Joystick::getComponentName (Component comp)
    {
        std::string ret;

        switch (comp)
        {
            case NONE:     ret="None"; break;
            case UP:       ret="Up"; break;
            case DOWN:     ret="Down"; break;
            case LEFT:     ret="Left"; break;
            case RIGHT:    ret="Right"; break;
            case BUTTON_1: ret="Button 1"; break;
            case BUTTON_2: ret="Button 2"; break;
            case BUTTON_3: ret="Button 3"; break;
            case BUTTON_4: ret="Button 4"; break;
            case BUTTON_5: ret="Button 5"; break;
            case BUTTON_6: ret="Button 6"; break;
            default:       ret="Sin nombre"; break;
        }
        return ret;
    }
}