///
/// @file Nombres.cpp
/// @brief Fichero de implementación de la clase "Nombres".
/// @author Juan Manuel Rico
/// @date Noviembre 2015
/// @version
///      - 1.0.0 Noviembre 2015
///

#ifndef _NOMBRES_H_
#define _NOMBRES_H_

#include <string>
#include <iostream>

/// Clase que reúne todos los nombres de objetos del juego.
///
/// @todo Permitir añadir nombres en tiempo de ejecución.
///       Para ello una variable global debería llevar la cuenta de los códigos generados por
///       la clase y emparejar con la cadena 'string' que se le pase por referencia.
///       @code
///          Nombre::codigo = AñadirNombre ("Pelota");
///       @endcode
///       El codigo sería el mismo para todos los actores del mismo tipo, luego sería una variable
///       estática de la clase ("Pelota", "Paleta", etc...)
///       @code
///          if (who->getCodigo() == Pelota::codigo) {} else {};
///       @endcode
/// @attention Igual es más conveniente utilizar una clase STL como 'map' para modelar los nombres.
///
class Nombres
{
public:
    /// Código de cada actor del juego.
    enum codigo {
        pelota,     ///< Pelota que rebota por pantalla.
        paleta,     ///< Paleta que golpea a la pelota y la desvía.
        herny,      ///< Troglodita de prueba.
        jugador,    ///< Jugador de prueba.
        enemigo,    ///< Enemigo de prueba.
        ladrillo,   ///< Ladrillo para ser golpeado por la pelota.
        mago,       ///< Prueba simple sin desarrollar.
        ben,        ///< Prueba de un personaje completo con Ben10.
        camello,    ///< Un actor de prueba más.
        plataforma  ///< Actor de prueba con movimiento automático.
    };

public:
    /// Constructor.
    ///
    Nombres ();

    /// Destructor.
    ///
    ~Nombres ();

    /// Convierte el código de un nombre en una cadena imprimible de caracteres.
    /// @todo Utilizar un operador de conversión de tipos para este método.
    ///       En lugar de usar el 'switch' utilizar una estructura 'stl' tipo 'map'.
    ///       Esto mismo se hizo para referenciar los punteros y los nombres de los Bitmaps en la clase 'Almacen'.
    ///
    static std::string& Imprimir (const codigo cod_nombre)
    {
        std::string &cadena = *new std::string();
        switch (cod_nombre)
        {
            case pelota:     cadena = "Pelota";      break;
            case paleta:     cadena = "Suelo";       break;
            case herny:      cadena = "Herny";       break;
            case jugador:    cadena = "Jugador";     break;
            case enemigo:    cadena = "Enemigo";     break;
            case ladrillo:   cadena = "Ladrillo";    break;
            case mago:       cadena = "Mago";        break;
            case ben:        cadena = "Ben";         break;
            case camello:    cadena = "Camello";     break;
            case plataforma: cadena = "Plataforma";  break;
            default:         cadena = "Sin nombre";  break;
        }
        return cadena;
    };

    /// Obtiene cadena representativa del objeto como un insertor en el flujo.
    /// @todo Cambiar por herencia con PrintableObject
    ///
    friend std::ostream& operator<< (std::ostream& os, const Nombres::codigo cod);
};

#endif
