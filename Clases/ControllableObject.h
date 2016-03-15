///
/// @file    ControllableObject.h
/// @brief   Fichero de cabecera de ControllableObject.
/// @author  Juan Manuel Rico
/// @date    Marzo 2015
/// @version 1.0.0
///

#ifndef CONTROLLABLEOBJECT_H
#define CONTROLLABLEOBJECT_H


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
    typedef int action_t;

    /// Realizar una acción concreta.
    /// @param action  Tipo de acción a realizar.
    /// @param magnitude  Intensidad con la que realizar dicha acción.
    ///
    virtual void do_action (action_t action, int magnitude){};
};

#endif
