///
/// @file Vector2Df.h
/// @brief Fichero cabecera de la clase "Vector2Df".
/// @author Juan Manuel Rico
/// @date Marzo 2015
/// @version 1.0.0
///

#ifndef _VECTOR2DF_H_
#define _VECTOR2DF_H_

//#include <string>

/// @class Vector2Df
/// Modela un vector en 2D.
///
/// Se utilizan componentes con números en coma flotante.
/// Al contrario que las componentes de la posición que son posiciones de enteros con signo.
/// Este vector se usará para cálculos intermedios de dicha posición, para vectores de velocidad, aceleración, etc.
/// @note Queda por generalizar el concepto de vector (Vector2D) y generar otro para la posición y utilizarlo (Vector2Di).
///
class Vector2Df
{
public:
    /// Constructor mínimo.
    Vector2Df ();

    /// Constructor básico.
    /// @param _x componente 'x' del vector.
    /// @param _y componente 'y' del vector.
    ///
    Vector2Df (float _x, float _y);

    /// Lee un vector desde fichero.
    ///

    /// Escribe un vector en fichero.
    ///

    /// Sobrecarga del operador '>>'.
    ///

    /// Sobrecarga del operador '>>'.
    ///
public:
    float x, y; ///< Componentes del vector. Se dejan públicas para un mejor acceso.
};

#endif //_Vector2DF_H_
