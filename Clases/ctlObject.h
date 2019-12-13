///
/// @file ctlObject.h
/// @brief Fichero de definición de la clase.
/// @author Juan Manuel Rico
/// @date Mayo 2016
/// @version 1.0.0
///

#ifndef _CTLOBJECT_H_
#define _CTLOBJECT_H_

class Object;

/// Control para un objeto.
/// Define la GUI de control para un objeto genérico que puede ser editable mediante
///  una interfaz gráfica.
///
class ctlObject
{
  public:
         ctlObject (Object* obj);
         ctlObject ();
         ~ctlObject ();
    virtual void update ();

  protected:
    Object* object;     ///< Referencia al objeto que se quiere editar.
    int x, y;           ///< Posición del control.
    int w, h;           ///< Tamaño del control.
};

#endif