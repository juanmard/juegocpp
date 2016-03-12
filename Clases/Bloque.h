///
/// @file Bloque.h
/// @brief Fichero de definición de la clase "Bloque".
/// @author Juan Manuel Rico
/// @date Noviembre 2015
/// @version 1.0.0
///

#ifndef _BLOQUE_H_
#define _BLOQUE_H_

#include "PrintableObject.h"
#include <string>

/// Modela un bloque genérico representado por una posición, una anchura y una altura.
///
/// En el juego se usa para representar los límites de los actores en su parte física
/// como en su parte gráfica.
/// @todo Queda por utilizar la clase Vector2Di para representar mediante un vector,
///       al menos, la posición del bloque.
///
class Bloque : public PrintableObject
{
private:
    int x;              ///< Coordenada x de la posición que se representa en el bloque.
    int y;              ///< Coordenada y de la posición que se representa en el bloque.
    unsigned int w;     ///< Ancho de las dimensiones que se representan en el bloque.
    unsigned int h;     ///< Alto de las dimensiones que se representan en el bloque.

public:
    /// Constructor básico.
    ///
    /// Pone a cero tanto posición como las dimensiones del bloque.
    ///
    Bloque ();

    /// Constructor.
    /// @param x  Posición x que representa el bloque.
    /// @param y  Posición y que representa el bloque.
    /// @param w  Anchura que representa el bloque.
    /// @param h  Altura que representa el bloque.
    ///
    Bloque (int x, int y, int w = 0, int h = 0);

    /// Destructor del bloque.
    ///
    /// No hace nada, pero se declara virtual para los objetos que lo hereden.
    ///
    virtual ~Bloque ();

    /// Cambia la coordenada x de la posición del bloque.
    /// @param x  Nueva coordenada x del bloque.
    ///
    void set_x (int x);

    /// Cambia la coordenada y de la posición del bloque.
    /// @param y  Nueva coordenada y del bloque.
    ///
    void set_y (int y);

    /// Cambia la posición del bloque.
    /// @param x  Nueva posición x del bloque.
    /// @param y  Nueva posición y del bloque.
    ///
    void set_xy (int x, int y);

    /// Cambia las dimensiones del bloque.
    /// @param w  Nuevo ancho del bloque.
    /// @param h  Nuevo alto del bloque.
    ///
    void set_wh (unsigned int w, unsigned int h);

    /// Obtiene la coordenada x de la posición.
    /// @return Coordenada x de la posición.
    ///
    int get_x () const;

    /// Obtiene la coordenada y de la posición.
    /// @return Coordenada y de la posición.
    ///
    int get_y () const;

    /// Obtiene la anchura del bloque.
    /// @return Ancho del bloque.
    ///
    unsigned int get_w () const;

    /// Obtiene la altura del bloque.
    /// @return Alto del bloque.
    ///
    unsigned int get_h () const;

    /// Centra el bloque respecto a otro que se pasa por parámetro.
    /// @param bloque  Referencia al bloque que sirve para centrar.
    ///
    void centrar (const Bloque& bloque);

    /// Vuelca en una cadena las características del bloque.
    /// @return Cadena con las características del bloque.
    virtual std::string & print() const;
};

#endif
