/**
 * \file    ControllableObject.h
 * \brief   Fichero de cabecera de ControllableObject.
 * \author  Juan Manuel Rico
 * \date    Marzo 2015
 * \version 1.0.0
 */
#ifndef CONTROLLABLEOBJECT_H
#define CONTROLLABLEOBJECT_H

/**
 * \class   ControllableObject
 * \brief   Clase "completamente abstracta" que define el comportamiento de un objeto controlable.
 * \todo    Al ser una clase "completamente abstracta" no debería tener ni constructores ni destructores
 *          (ni es aconsejable que tenga constantes), lo que implica que no exista más que la definición
 *          (solo fichero de cabecera ".h") y los métodos virtuales indiquen este hecho.
 *          Debería definirse de la siguiente forma:
 *          \code
 *                  class ControllableObject
 *                  {
 *                      public:
 *                          virtual  void  do_action  (action_t action, int magnitude);
 *                  };
 *          \endcode
 *          Por tanto debemos eliminar el fichero "ControllableObject.cpp" del proyecto y modificar la 
 *          clase para que el tipo "action_t" se encuentre definido en otra clase.
 */
class ControllableObject
{
    public:
    typedef int action_t;

                        ControllableObject      (const ControllableObject &copia);
                        ControllableObject      ();
                        ~ControllableObject     ();
        virtual void    do_action               (action_t action, int magnitude);
};

#endif
