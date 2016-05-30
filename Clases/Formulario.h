///
/// @file Formulario.h
/// @brief Fichero de definición de la clase "Formulario".
/// @author Juan Manuel Rico
/// @date Octubre 2015
/// @version 1.0.0
///

#ifndef _FORMULARIO_H_
#define _FORMULARIO_H_

#include <string>
#include <vector>
#include <allegro.h>

class Bitmap;

/// Formulario implementado como una lista de controles que interaccionan entre ellos.
/// @todo Crear los controles y dejar en los procedimientos add únicamente la posición y el
///       control para añadir al formulario:
///       @code
///       ctlPicture control1;
///       ctlTextBox control2;
///       formulario1.add (100,100,control1);
///       formulario1.add (120,100,control2);
///       @endcode
///
class Formulario
{
private:
    int root;                           ///< Raíz del formulario.
    std::vector<DIALOG> controles;      ///< Lista de controles del formulario. @todo Independizar de Allegro.
    static DIALOG fin_formulario;       ///< Constante para la clase que indica el final del formulario en Allegro.

public:
    /// Tipos de controles que puede albergar el formulario.
    typedef enum {
        PICTURE,    ///< Gráfico simple.
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

    /// Añade un control al formulario con cadena de texto asociada.
    /// @param tipo  Tipo de formulario a añadir.
    /// @param texto  Texto asociado del control.
    /// @param x  Posición x referida al formulario origen.
    /// @param y  Posición y referida al formulario origen.
    ///
    void add (const control_t tipo, const std::string& texto, const int x, const int y);

    /// Añade un control de tipo etiqueta.
    /// @param x  Posición x referida al formulario origen.
    /// @param y  Posición y referida al formulario origen.
    /// @param texto  Texto asociado de la etiqueta.
    ///
    /// @note Se define para que la llamada a la función sea más intuitiva.
    ///       Si solo se define testo y posición es una etiqueta.
    ///
    void add (const int x, const int y, const std::string& texto);

    /// Añade un control al formulario con cadena de texto asociada.
    /// @param tipo  Tipo de formulario a añadir.
    /// @param picture  Imagen a mostrar como diálogo.
    /// @param x  Posición x referida al formulario origen.
    /// @param y  Posición y referida al formulario origen.
    ///
    /// @todo Hacer una clase para dejar esto como un control y no como un BITMAP de Allegro.
    ///
    void add (control_t tipo, BITMAP* picture, int x, int y);

    /// Añade un gráfico al formulario.
    /// @param x  Posición x referida al formulario origen.
    /// @param y  Posición y referida al formulario origen.
    /// @param picture  Imagen a mostrar en el formulario.
    ///
    void add (const int x, const int y, const Bitmap* picture);

    /// Añade un control al formulario sin cadena de texto asociada.
    /// @param tipo  Tipo de control a añadir.
    /// @param x  Posición x referida al formulario origen.
    /// @param y  Posición y referida al formulario origen.
    /// @param w  Ancho del control.
    /// @param h  Alto del control.
    ///
    void add (control_t tipo, int x, int y, int w, int h);

    /// Muestra el formulario en pantalla.
    /// @note Esta debe ser redefinido por los formularios heredados.
    ///       La idea es que FormularioAllegro herede de Formulario y redefina
    ///       la forma de mostrarse. De momento directamente se hace todo en Allegro.
    ///
    virtual void show ();

    /// Desarrolla la lógica del formulario.
    /// Se debe definir la relación entre los controles, como cambian los valores
    ///   de las variables implicadas, acciones ante el ratón, teclado, etc.
    /// @note Esta lógica debe ser redefinida por los formularios heredados.
    ///
    virtual void logica ();
};

#endif
