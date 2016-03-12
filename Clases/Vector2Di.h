///
/// @file Vector2Di.h
/// @brief Fichero cabecera de la clase "Vector2Di".
/// @author Juan Manuel Rico
/// @date Marzo 2015
/// @version 1.0.0
///

#ifndef _VECTOR2DI_H_
#define _VECTOR2DI_H_

//#include <string>

/// @class Vector2Di
/// Modela un vector en 2D.
///
/// Se utilizan componentes con números enteros con signo.
/// Este vector se usará para la posición y tamaño de los objetos.
/// @note Queda por generalizar el concepto de vector (Vector2D).
///
class Vector2Di
{
public:
    /// Constructor mínimo.
    Vector2Di ();

    /// Constructor básico.
    /// @param _x componente 'x' del vector.
    /// @param _y componente 'y' del vector.
    ///
    Vector2Di (int _x, int _y);

    /// Lee un vector desde fichero.
    ///

    /// Escribe un vector en fichero.
    ///

    /// Sobrecarga del operador '>>'.
    ///

    /// Sobrecarga del operador '>>'.
    ///
public:
    int x, y; ///< Componentes del vector. Se dejan públicas para un mejor acceso.
};

#endif _Vector2DI_H_
