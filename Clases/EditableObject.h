///
/// @file EditableObject.h
/// @brief Fichero de declaración de un objeto editable.
///
/// @author Juan Manuel Rico
/// @date Marzo 2015
/// @version 1.0.0
///

#ifndef _EDITABLEOBJECT_H_
#define _EDITABLEOBJECT_H_

class Menu;
class Formulario;

///
/// Clase "completamente abstracta" que define el comportamiento de un objeto editable.
///
class EditableObject
{
public:
    ///
    /// Obtiene el menú con los comandos de edición del objeto.
    /// @return Menú con los comandos creados.
    virtual Menu& getMenu () const = 0;

    ///
    /// Obtiene un formulario donde poder modificar los parámetros del objeto.
    /// @return Formulario completado con los datos actuales del objeto.
    ///
    virtual Formulario& getFormulario () const = 0;
};

#endif
