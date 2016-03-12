///
/// @file Plataforma.h
/// @brief Fichero cabecera de la clase "Plataforma".
/// @author Juan Manuel Rico
/// @date Marzo 2015
/// @version 1.0.0
///

#ifndef _PLATAFORMA_H_
#define _PLATAFORMA_H_

#include "Actor.h"
#include "Suelo.h"
#include "Nombres.h"
#include "Almacen.h"
#include <string>

/// @class Plataforma
/// Suelo que se mueve bajo ciertos criterios.
///
/// Los criterios que se pueden utilizar para el movimiento suelen ser varios, lo más
/// usual es un movimiento programado y temporizado, desde un punto de inicio hacia
/// un punto final y vuelta. El movimiento puede ser activado y desactivado por la
/// interacción de otros objetos.
///
class Plataforma : public Actor
{
public:
    /// Constructor de copia.
    /// @param copia Referencia a la plataforma que quiere ser copiada.
    Plataforma (const Plataforma& copia);

    /// Constructor básico.
    /// @param almacen Almacen con los gráficos para crear la plataforma.
    /// @todo Este parámetro de almacen no tiene mucho sentido en esta clase.
    ///
    Plataforma (Almacen& almacen);

    /// Constructor básico.
    ///
    Plataforma ();

    /// Destructor.
    /// @todo Programar la liberación de recursos.
    ///
    ~Plataforma ();

    /// Resuelve las colisiones con los objetos.
    ///
    void hit (Actor* who, int damage);

    ///  Clona el objeto.
    /// @return Puntero a modo de referencia de la nueva plataforma creada.
    Plataforma* clone () const;

    /// Obtiene el nombre en forma de cadena de texto.
    /// @param strNombre Cadena que se modifica para incluir el nombre.
    /// @todo Comprobar que esto es necesario.
    ///
    void getNombre (std::string& strNombre) const;

    /// Obtiene el nombre en forma de cadena de texto.
    /// @return Cadena con el nombre.
    /// @todo Comprobar que esto es necesario.
    ///
    std::string getNombre () const;

    /// Obtiene una cadena representativa de las propiedades de la plataforma.
    /// @return Cadena formada con las propiedades.
    /// @note Reimplementa la función heredada de Actor.
    ///
    std::string getString () const;

    /// Lee las propiedades de la plataforma desde un fichero.
    /// @param ifs Fichero desde donde se hace la lectura.
    /// @return Puntero del fichero para concatenar lecturas.
    /// @note Reimplementa la función heredada de Actor.
    ///
    std::ifstream& leer (std::ifstream& ifs);

protected:
    Suelo* grafico;     ///< Gráfico a mostrar por la plataforma. @note Esto no es necesario, ya existe una referencia al gráfico en el actor.
};

#endif _PLATAFORMA_H_
