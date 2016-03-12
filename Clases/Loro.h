///
/// @file Loro.h
/// @brief Fichero cabecera de la clase "Loro".
/// @author Juan Manuel Rico
/// @date Marzo 2010
/// @version 1.0.0
///

#ifndef _LORO_H_
#define _LORO_H_

#include "ControllableActor.h"
#include "Almacen.h"
#include "Sprite.h"

/// @class Loro
/// Loro que se mueve siguiendo una horizontal.
///
/// Los criterios que se pueden utilizar para el movimiento suelen ser varios, lo más
/// usual es un movimiento programado y temporizado, desde un punto de inicio hacia
/// un punto final y vuelta. El movimiento puede ser activado y desactivado por la
/// interacción de otros objetos.
///
class Loro : public ControllableActor
{
public:
    /// @typedef Definición de acciones del loro.
    typedef enum {
                DOWN,   ///< El loro debe bajar.
                UP,     ///< El loro debe subir.
                LEFT,   ///< El loro debe moverse a la izquierda.
                RIGHT,  ///< El loro debe moverse a la derecha.
                JUMP    ///< El loro debe saltar.
                } action_t;

public:
    /// Constructor básico.
    ///
    Loro ();

    /// Constructor mediante almacén de gráficos.
    /// @param almacen  Almacen con los gráficos para crear la animación del loro.
    /// @todo Este parámetro de almacen no tiene mucho sentido en esta clase, debería ser
    ///       más sencillo crear un actor del tipo Loro.
    ///
    Loro (Almacen &almacen);

    /// Realiza una acción del loro.
    /// @param act  Acción a realizar por el loro.
    /// @param magnitude  Fuerza con la que se realiza la acción.
    ///
    void do_action (ControllableActor::action_t act, int magnitude);

    /// Obtiene el nombre en forma de cadena de texto.
    /// @param strNombre Referencia a la cadena donde se guardará el nombre del loro.
    ///
    void getNombre (std::string &strNombre) const;

private:
    Sprite *derecha, *izquierda, *giro;     ///< Animaciones para el actor Loro.
};

#endif
