///---------------------------------------------------------
/// @file       Keyboard.h
/// @author     Juan Manuel Rico
/// @date       Octubre 2015
/// @version    1.0.0
///
/// @brief      Definición del teclado como un periférico.
///---------------------------------------------------------

#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include <allegro.h>
#include "Peripheral.h"

namespace fwg {
    
    /// Define el comportamiento del teclado como un periférico.
    /// 
    /// @todo Cosas por terminar en esta clase:
    ///        - Eliminar referencias de Allegro y hacer más genérica
    ///          la clase.
    ///        - Completar todos los nombres de los componentes del
    ///          teclado en el método 'getComponentName'.
    ///
    class Keyboard : public Peripheral
    {
        protected:
            int oldState[KEY_MAX];     ///< Mapa de teclado donde se guarda el estado anterior de las teclas.

        public:
            /// Constructor por defecto.
            ///
            Keyboard ();

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
    };
}

#endif