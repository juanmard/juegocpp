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

/// @class EditableObject
/// Clase "completamente abstracta" que define el comportamiento de un objeto editable.
///
class EditableObject
{
public:
    ///
    /// Obtiene el menú con los comandos de edición del objeto.
    /// @return Menú con los comandos creados.
    virtual Menu& getMenu () const = 0;

    /// Obtiene un formulario donde poder modificar los parámetros del objeto.
    /// @return Formulario completado con los datos actuales del objeto.
    ///
    virtual Formulario& getFormulario () const = 0;

    /// Como objeto editable debe dibujar objetos de control y auxiliares que le permitan editarlo.
    ///
    /// Como ejemplo de situaciones de control para este tipo de objetos serían el tamaño,
    /// las tangentes en un camino, puntos de referencia, etc.
    /// @note Surge la duda si esta es la clase adecuada para este procedimiento, ya que está diciendo
    ///       implícitamente que el objeto debe ser dibujable ("DrawableObject"), con lo cual es posible
    ///       que su lugar más adecuado sea en la clase "DrawableObject", ya que un objeto puede ser
    ///       dibujable y no poder editable sus propiedades y viceversa, puede que se puedan editar sus
    ///       propiedades pero que no tenga una representación como dibujo.
    //virtual void drawControl () const = 0;
};

#endif
