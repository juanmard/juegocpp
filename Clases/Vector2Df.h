///
/// @file Vector2Df.h
/// @brief Fichero de definición de la clase "Vector2Df".
/// @author Juan Manuel Rico
/// @date Noviembre 2015
/// @version 1.0.1
///

#ifndef _VECTOR2DF_H_
#define _VECTOR2DF_H_

#include "PrintableObject.h"
#include "ReadableObject.h"
#include <string>

/// Modela un vector en 2D.
///
/// Se utilizan componentes con números en coma flotante.
/// Al contrario que las componentes de la posición que son posiciones de enteros con signo.
/// Este vector se usará para cálculos intermedios de dicha posición, para vectores de velocidad, aceleración, etc.
/// @note Queda por generalizar el concepto de vector (Vector2D) y generar otro para la posición y utilizarlo (Vector2Di).
///
class Vector2Df : public PrintableObject, public ReadableObject
{
public:
    float x, y;     ///< Componentes del vector. Se dejan públicas para un mejor acceso.

public:
    /// Constructor mínimo.
    ///
    Vector2Df ();

    /// Constructor básico.
    /// @param _x componente 'x' del vector.
    /// @param _y componente 'y' del vector.
    ///
    Vector2Df (float _x, float _y);

private:
    /// Escribe un vector en una cadena.
    /// @return Referencia a la cadena creada con los valores del vector.
    ///
    virtual std::string& print () const;

    /// Lee un vector representado en una cadena.
    ///
    /// La representación tendrá la forma: "<1.2345, 6.7890>"
    /// @param cadena  Referencia a la cadena de donde extraer los datos.
    /// @return Número de caracteres leídos.
    /// @note Se ignoran hasta diez caracteres al buscar el primer "<" que delimita la primera
    ///       componente del vector y otros diez al buscar el caracter "," que nos delimita la
    ///       segunda componente.
    ///
    virtual unsigned int read (const std::string& cadena);
};

#endif
