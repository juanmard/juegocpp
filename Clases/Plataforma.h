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
#include <string>
#include "Vector2Di.h"
#include "Vector2Df.h"
#include "StageManager.h"

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

    /// Dibuja la plataforma.
    /// Para ello hereda de "Actor", lo ideal es que heredara de "DrawableObjectAllegro".
    /// @note Se utiliza a modo de prueba, independizar de Allegro.
    void draw (StageManager* stageManager);

private:
    /// Por ser objeto editable hereda el dibujo de control en pantalla.
    ///
    /// El control en la plataforma será fundamentalmente poder cambiar con el ratón los
    /// puntos de origen y destino para cambiar el camino que sigue la plataforma en su movimiento.
    /// Este procedimiento deberá dibujar una línea entre ambos puntos e indicar, con otra línea,
    /// la velocidad actual que lleva la plataforma.
    ///
    /// @note Se dibuja empleando funciones de Allegro, para independizar la clase de estas funciones
    ///       se debería utilizar una clase de objeto "DrawableObject" y de él un "DrawableObjectAllegro"
    ///       de esta forma nuestra clase heredaría de DrawableObject y usaría las mismas funciones pero
    ///       de forma transparente, algo como:
    ///       @code
    ///          line (Origen, Destino, color::rojo);
    ///          flecha (Velocidad, actor.cdg(), color::rojo);
    ///       @endcode
    ///       Donde "line" y "flecha" estarían definidos en "DrawableObject" y definidos con las bibliotecas
    ///       de Allegro en "DrawableObjectAllegro".
    ///
    void drawControl ();

private:
    Suelo* grafico;         ///< Gráfico a mostrar por la plataforma. @note Esto no es necesario, ya existe una referencia al gráfico en el actor.
    Vector2Di origen;       ///< Origen del movimiento de la plataforma.
    Vector2Di destino;      ///< Destino del movimiento de la plataforma.
    Vector2Df velocidad;    ///< Vector velocidad en el movimiento de la plataforma.
    bool activa;            ///< Indica si actualmente la plataforma está activa, en movimiento.
};

#endif _PLATAFORMA_H_
