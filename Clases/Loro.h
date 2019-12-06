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
#include "Peripheral.h"

namespace fwg {
    
/// Loro que se mueve siguiendo una horizontal.
///
/// Los criterios que se pueden utilizar para el movimiento suelen ser varios, lo más
/// usual es un movimiento programado y temporizado, desde un punto de inicio hacia
/// un punto final y vuelta. El movimiento puede ser activado y desactivado por la
/// interacción de otros objetos.
///
/// @note En este caso el personaje del loro utiliza únicamente el teclado como periférico, pero en
///       general otro actor puede usar otro o incluso dos periféricos, es por ese motivo que este
///       objeto no se ha creado en la clase más general de 'ControllableActor'.
///
class Loro : public ControllableActor
{
private:
    Sprite *derecha, *izquierda, *giro_der, *giro_izq;     ///< Animaciones para el actor loro. @todo Inculir en una lista de animaciones.
    Peripheral *kboard;                                    ///< Periférico (teclado) que usará el personaje del loro.

public:
    /// Definición de acciones del loro.
    typedef enum {
                DOWN,   ///< El loro debe bajar.
                UP,     ///< El loro debe subir.
                LEFT,   ///< El loro debe moverse a la izquierda.
                RIGHT,  ///< El loro debe moverse a la derecha.
                JUMP    ///< El loro debe saltar.
                } action_t;

    /// Definición de estados del loro.
    typedef enum {
                VOLANDO_DER,    ///< El loro está volando hacia la derecha.
                VOLANDO_IZQ,    ///< El loro está volando hacia la izquierda.
                FLOTANDO_DER,   ///< El loro está flotando mirando a la derecha.
                FLOTANDO_IZQ,   ///< El loro está flotando mirando a la izquierda.
                GIRANDO_DER,    ///< El loro está girando hacia la derecha.
                GIRANDO_IZQ,    ///< El loro está girando hacia la izquierda.
                TROPEZANDO,     ///< El loro tropieza con un objeto de tipo ladrillo.
                KILL            ///< El loro se suicida eliminándose de la lista de actores.
                } state_t;

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

    /// Responde ante las acciones definidas para el loro.
    /// @param act  Acción a realizar por el loro.
    /// @param magnitude  Fuerza con la que se realiza la acción.
    ///
    /// @note Esto es parte de la descripción del autómata (control_manager), otra parte está en el 
    ///       'actor_manager' (temporizaciones de los estados) y la otra está en el 'collision_manager'
    ///       que responde a las interaciiones del entorno.
    ///       estado actual + control (inputs) + entorno (colisiones) = acciones + estado futuro
    ///
    void doAction (ControllableActor::Action act, int magnitude);

    /// Obtiene el nombre en forma de cadena de texto.
    /// @param strNombre Referencia a la cadena donde se guardará el nombre del loro.
    ///
    void getNombre (std::string &strNombre) const;

    /// Obtiene el nombre del loro.
    /// @return Nombre del loro en forma de cadea.
    ///
    /// @todo Poder asignar un nombre distinto a cada actor y poder actualizarlo.
    ///
    std::string getNombre () const;

    /// Obtiene el periférico que usa el loro para ejecutar el control.
    /// @return Periférico que usa el control del loro.
    ///
    Peripheral* getPeripheral () const;

    /// Actualiza el estado en función del estado actual.
    /// Se utiliza para implementar, junto con 'tiempo_estado', las transiciones epsilon
    /// del autómata.
    ///
    void actualizar_estado ();

    /// Reacciona antre una colisión con otro actor.
    /// Esta es la parte de la reacción del entorno que debe tener presente el autómata.
    /// @param who  Puntero del actor que provoca la colisión.
    /// @param damage  Intensidad con la que se produce la colisión.
    ///
    void hit (Actor* who, int damage);

};
}

#endif
