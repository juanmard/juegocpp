///
/// @file PhysicObject.h
/// @brief Fichero de definición de la clase "PhysicObject".
/// @author Juan Manuel Rico
/// @date Noviembre 2015
/// @version 1.0.0
///

#ifndef _PHYSICOBJECT_
#define _PHYSICOBJECT_

#include "Vector2Df.h"

namespace fwg {

/// Define un objeto físico.
///
/// Se trata de conseguir un objeto que se comporta físicamente en un entorno.
///
class PhysicObject
{
private:
    const static float g;       ///< Constante de gravedad, común para todos los objetos de la clase.
    Vector2Df velocidad;        ///< Vector velocidad del objeto.
    Vector2Df cdg;              ///< Posición del centro de gravedad referido a la posición del objeto.
    float masa;                 ///< Masa del objeto.
    float area;                 ///< Área del objeto.
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
}

#endif
