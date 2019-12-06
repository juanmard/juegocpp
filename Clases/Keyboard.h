///
/// @file Keyboard.h
/// @brief Fichero de definición de la clase "Keyboard".
/// @author Juan Manuel Rico
/// @date Octubre 2015
/// @version 1.0.0
///

#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <allegro.h>
#include "Peripheral.h"

namespace fwg {
/// Define el comportamiento del teclado como un periférico.
///
class Keyboard : public Peripheral
{
public:
    /// Constructor por defecto.
    ///
    Keyboard ();

    /// Obtiene el estado de una tecla.
    /// @param comp  Tecla de la que se desea conocer el estado.
    /// @return Estado de la tecla.
    ///
    State getState (Component comp);

    /// Obtiene la tecla que ha cambiado en el teclado.
    /// @return Tecla que ha cambiado de estado.
    Component getChange ();

    /// Obtiene el nombre de una tecla.
    /// @param comp Tecla de la que se desea conocer su nombre.
    /// @return Cadena de caracteres con el nombre de la tecla.
    ///
    std::string getComponentName (Component comp);

    /// Inicializa el teclado.
    ///
    void reset ();

protected:
    int oldState[KEY_MAX];     ///< Mapa de teclado donde se guarda el estado anterior de las teclas.
};
}
#endif