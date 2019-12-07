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
        protected:
            /// @note Encontrar una forma de representar toda la estructura de
            ///       posibles componentes de un joystick.
            /// int oldState[MAX_JOYSTICKS+MAX_JOYSTICK_AXIS+MAX_JOYSTICK_BUTTONS]
            int oldState[MAX_JOYSTICK_BUTTONS];
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