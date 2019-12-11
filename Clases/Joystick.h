///---------------------------------------------------------
/// @file       Joystick.h
/// @author     Juan Manuel Rico
/// @date       Diciembre 2019
/// @version    1.0.0
///
/// @brief      Definición del joystick como periférico.
///---------------------------------------------------------

#ifndef _JOYSTICK_H_
#define _JOYSTICK_H_

#include <allegro.h>
#include "Peripheral.h"

namespace fwg {
    
    /// Define el comportamiento del joystick como un periférico.
    /// 
    /// @todo Cosas por terminar en esta clase:
    ///        - Eliminar referencias de Allegro y hacer más genérica
    ///          la clase.
    ///        - Completar todos los nombres de los componentes del
    ///          teclado en el método 'getComponentName'.
    ///        - Establecer la numeración de los componentes y los estados
    ///          de todos los joysticks y ejes posibles, así como los 'oldState'
    ///          de todos. Actualmente el componente está definido como un entero,
    ///          así como sus estados.
    ///
    class Joystick : public Peripheral
    {
        public:
            enum {
                   UP = 20,      ///< Joystick up.
                   DOWN,         ///< Joystick down.
                   LEFT,         ///< Joystick left.
                   RIGHT,        ///< Joystick right.
                   BUTTON_1 = 0, ///< Button 1.
                   BUTTON_2,     ///< Button 2.
                   BUTTON_3,     ///< Button 3.
                   BUTTON_4,     ///< Button 4.
                   BUTTON_5,     ///< Button 5.
                   BUTTON_6,     ///< Button 6.
                   BUTTON_7,     ///< Button 7.
                   BUTTON_8,     ///< Button 8.
                   BUTTON_9,     ///< Button 9.
                   BUTTON_10,    ///< Button 10.                
                   BUTTON_11,    ///< Button 11.                
                   BUTTON_12     ///< Button 12.                
                 } joyState;
                 
        protected:
            /// @note Encontrar una forma de representar toda la estructura de
            ///       posibles componentes de un joystick.
            /// int oldState[MAX_JOYSTICKS+MAX_JOYSTICK_AXIS+MAX_JOYSTICK_BUTTONS]
            int oldState[MAX_JOYSTICK_BUTTONS+MAX_JOYSTICK_AXIS];
            int activos; ///< Número de joysticks activos.
            
        public:
            /// Constructor por defecto.
            ///
            Joystick ();
            
            /// Obtiene el estado de una tecla.
            /// 
            /// @param comp  Tecla de la que se desea conocer el estado.
            /// @return Estado de la tecla.
            ///
            State getState (Component comp);

            /// Obtiene la tecla que ha cambiado en el teclado.
            /// 
            /// @return Tecla que ha cambiado de estado.
            /// 
            Component getChange ();

            /// Obtiene el nombre de una tecla.
            /// 
            /// @param comp Tecla de la que se desea conocer su nombre.
            /// @return Cadena de caracteres con el nombre de la tecla.
            ///
            std::string getComponentName (Component comp);

            /// Inicializa el teclado.
            ///
            void reset ();
            
        private:
            /// Instala el joystick en el motor gráfico.
            /// 
            void install ();


    };
}

#endif