///
/// @file PhysicObject.h
/// @brief Fichero de definici�n de la clase "PhysicObject".
/// @author Juan Manuel Rico
/// @date Noviembre 2015
/// @version 1.0.0
///

#ifndef _PHYSICOBJECT_
#define _PHYSICOBJECT_

#include "Vector2Df.h"

/// Define un objeto f�sico-
///
/// Se trata de conseguir un objeto que se comporta f�sicamente en un entorno.
///
class PhysicObject
{
private:
    const static float g;       ///< Constante de gravedad, com�n para todos los objetos de la clase.
    Vector2Df velocidad;        ///< Vector velocidad del objeto.
    Vector2Df cdg;              ///< Posici�n del centro de gravedad referido a la posici�n del objeto.
    float masa;                 ///< Masa del objeto.
    float area;                 ///< �rea del objeto.
    float volumen;              ///< Volumen del objeto.
    float mto_inercia;          ///< Momento de inercia del objeto.

public:
    /// Constructor.
    ///
    PhysicObject ();

    /// Destructor.
    ///
    virtual ~PhysicObject ();
};

#endif
