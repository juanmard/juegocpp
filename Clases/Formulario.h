///
/// @file Formulario.h
/// @brief Fichero de definici�n de la clase "Formulario".
/// @author Juan Manuel Rico
/// @date Octubre 2015
/// @version 1.0.0
///

#ifndef _FORMULARIO_H_
#define _FORMULARIO_H_

#include <string>
#include <vector>
#include <allegro.h>

/// Formulario implementado como una lista de controles que interaccionan entre ellos.
///
class Formulario
{
private:
    int root;                           ///< Ra�z del formulario.
    std::vector<DIALOG> controles;      ///< Lista de controles del formulario. @todo Independizar de Allegro.
    static DIALOG fin_formulario;       ///< Constante para la clase que indica el final del formulario en Allegro.

public:
    /// Tipos de controles que puede albergar el formulario.
    typedef enum {
        LABEL,      ///< Etiqueta simple con texto.
        BOX,        ///< Caja simple con bordes.
        SLIDER      ///< Deslizador.
    } control_t;

public:
    /// Constructor.
    ///
    Formulario ();

    /// Destructor.
    ///
    ~Formulario ();

    /// A�ade un control al formulario con cadena de texto asociada.
    /// @param tipo  Tipo de formulario a a�adir.
    /// @param texto  Texto asociado del control.
    /// @param x  Posici�n x referida al formulario origen.
    /// @param y  Posici�n y referida al formulario origen.
    ///
    void add (control_t tipo, std::string texto, int x, int y);

    /// A�ade un control al formulario sin cadena de texto asociada.
    /// @param tipo  Tipo de control a a�adir.
    /// @param x  Posici�n x referida al formulario origen.
    /// @param y  Posici�n y referida al formulario origen.
    /// @param w  Ancho del control.
    /// @param h  Alto del control.
    ///
    void add (control_t tipo, int x, int y, int w, int h);

    /// Muestra el formulario en pantalla.
    void show ();
};

#endif
