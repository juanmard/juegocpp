///---------------------------------------------------------
/// @file       Control.h
/// @author     Juan Manuel Rico
/// @date       Octubre 2015
/// @version    1.0.0
///
/// @brief      Define un objeto de control.
///---------------------------------------------------------

#ifndef _CONTROL_H_
#define _CONTROL_H_

//#include "ControllableObject.h"
//#include "Peripheral.h"

#include <string>
#include <list>
#include "ControllableObject.h"
#include "Peripheral.h"

namespace fwg {

    /// Define la clase de los controles del juego.
    ///
    /// Cada control tiene como propietario a un objeto controlable (ControllableObject)
    /// que es el que recibe los mensajes de las acciones a realizar según las asociaciones entre
    /// eventos recibidos del control (Event) y acciones definidas en el objeto (Action).
    ///
    class Control
    {
        public:
            /// Estructura de asociaciones entre eventos del control y acciones
            /// del objeto.
            typedef struct
            {
              ControllableObject::Action act;   ///< Acción del objeto
              std::string name;                 ///< Nombre de la acción
              Peripheral* peri;                 ///< Puntero al periférico (p.j. teclado)
              Peripheral::Component comp;       ///< Componente del periférico (p.j. KEY_A)
              Peripheral::Event oldEvent;       ///< Evento anterior (p.j ON_PRESSING)
              Peripheral::Event newEvent;       ///< Evento actual
            } Association;

            /// Constructor.
            ///
            Control ();
 
            /// Añade un nombre a la acción.
            /// 
            /// @param act Acción a poner nombre.
            /// @param str Nombre de la acción.
            ///
            void addActionName (ControllableObject::Action act, std::string str);
            
            /// Añade una nueva asociación al control.
            /// 
            /// @param assoc Asociación añadida.
            ///
            void addAssociation (Association assoc);
            
            /// Asocia una acción con el periférico, componente y evento que la dispara.
            /// 
            /// @param act Acción que se asocia.
            /// @param peri Puntero a periférico (p.j. teclado).
            /// @param comp Componente del periférico. (p.j. KEY_ESC).
            /// @param e Evento del componente.
            ///
            void setActionPeripheral (ControllableObject::Action act, Peripheral* peri, Peripheral::Component comp, Peripheral::Event e);

            /// Asocia un objeto que será el propietario del control y el que recibirá las acciones a ejecutar
            /// ante el disparo de un evento.
            /// 
            /// @param owner  Puntero al objeto al que se le asigna el control.
            ///
            void setOwner (ControllableObject* owner);
            
            /// Devuelve el nombre de una acción determinada.
            /// 
            /// @param actAcción de la que se quiere obtener el nombre.
            /// @return Cadena de caracteres con el nombre de la acción.
            ///
            std::string getNameAction (ControllableObject::Action act);

            /// Actualiza el estado del control.
            ///
            void update ();
            
            /// Inicializa el control.
            ///
            void reset ();

        protected:
            ControllableObject* owner;                           ///< Objeto propietario del control.
            std::list<Association> associations;                 ///< Lista de asociaciones entre acciones y eventos.
            std::list<Association>::iterator associationsIter;   ///< Iterador para la lista de asociaciones.
    };
}

#endif
