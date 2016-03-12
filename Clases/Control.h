///
/// @file Control.h
/// @brief Fichero de definición de la clase "Control".
/// @author Juan Manuel Rico
/// @date Octubre 2015
/// @version 1.0.0
///

#ifndef _CONTROL_H_
#define _CONTROL_H_

#include "ControllableObject.h"
#include <string>
#include "Peripheral.h"
#include <list>

/// @class Define la clase de los controles del juego.
/// @detail Cada control tiene como propietario a un objeto controlable (ControllableObject)
///         que es el que recibe los mensajes de las acciones a realizar según las asociaciones entre
///         eventos recibidos del control (event_t) y acciones definidas en el objeto (action_t).
///
class Control
{
public:
    /// @struct Estructura de asociaciones entre eventos del control y acciones del objeto.
    typedef struct
    {
      ControllableObject::action_t act;     ///< Acción del objeto
      std::string name;                     ///< Nombre de la acción
      Peripheral *peri;                     ///< Puntero al periférico (p.j. teclado)
      Peripheral::component_t comp;         ///< Componente del periférico (p.j. KEY_A)
      Peripheral::event_t old_event;        ///< Evento anterior (p.j ON_PRESSING)
      Peripheral::event_t new_event;        ///< Evento actual
    } association_t;

    /// Añade un nombre a la acción.
    /// @param act  Acción a poner nombre.
    /// @param str  Nombre de la acción.
    ///
    void add_action_name (ControllableObject::action_t act, std::string str);
    
    /// Añade una nueva asociación al control.
    /// @param asoc  Asociación añadida.
    ///
    void add_association (association_t asoc);
    
    /// Asocia una acción con el periférico, componente y evento que la dispara.
    /// @param act  Acción que se asocia.
    /// @param peri  Puntero a periférico (p.j. teclado).
    /// @param comp  Componente del periférico. (p.j. KEY_ESC).
    /// @param e  Evento del componente.
    ///
    void set_actionperipheral (ControllableObject::action_t act, Peripheral* peri, Peripheral::component_t comp, Peripheral::event_t e);

    /// Asocia un objeto que será el propietario del control y el que recibirá las acciones a ejecutar
    /// ante el disparo de un evento.
    /// @param owner  Puntero al objeto al que se le asigna el control.
    ///
    void set_owner (ControllableObject* owner);
    
    /// Devuelve el nombre de una acción determinada.
    /// @param act  Acción de la que se quiere obtener el nombre.
    /// @return Cadena de caracteres con el nombre de la acción.
    ///
    std::string get_name_action (ControllableObject::action_t act);

    /// Actualiza el estado del control.
    ///
    void update ();
    
    /// Inicializa el control.
    ///
    void reset ();

protected:
    ControllableObject* owner;                              ///< Objeto propietario del control.
    std::list<association_t> associations;                  ///< Lista de asociaciones entre acciones y eventos.
    std::list<association_t>::iterator associations_iter;   ///< Iterador para la lista de asociaciones.
};

#endif
