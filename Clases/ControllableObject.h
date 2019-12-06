///---------------------------------------------------------
/// @file       ControllableObject.h
/// @author     Juan Manuel Rico
/// @date       Marzo 2015
/// @version    1.0.0
///
/// @brief      Define la interfaz de un objeto controlable.
///---------------------------------------------------------

#ifndef _CONTROLLABLEOBJECT_H_
#define _CONTROLLABLEOBJECT_H_

namespace fwg {

    /// Clase "completamente abstracta" que define el comportamiento de un objeto controlable.
    ///
    /// @note Al ser una clase "completamente abstracta" no debe tener ni constructores ni destructores
    ///       (ni es aconsejable que tenga constantes), lo que implica que no exista más que la definición
    ///       de la clase (solo fichero de cabecera ".h"), las definiciones de tipos (si son necesarios) y
    ///       todos los métodos sean virtuales.
    ///
    class ControllableObject
    {
        public:
            /// Definición del tipo para las acciones que controlan el objeto.
            /// 
            typedef int Action;

            /// Realizar una acción concreta.
            /// 
            /// @param action Tipo de acción a realizar.
            /// @param magnitude Intensidad con la que realizar dicha acción.
            ///
            virtual void doAction (Action action, int magnitude){};
    };
}

#endif
