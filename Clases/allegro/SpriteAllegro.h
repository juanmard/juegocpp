///
/// @file SpriteAllegro.cpp
/// @brief Fichero de implementación de la clase "SpriteAllegro".
/// @author Juan Manuel Rico
/// @date Junio 2016
/// @version 1.0.0
///

#ifndef GUI_SPRITEGUI_H
#define GUI_SPRITEGUI_H

#include <allegro.h>
#include <guichan/image.hpp>
#include "../Sprite.h"

/// Espacio de nombres para la adaptación del juego con las bibliotecas Allegro.
namespace alg4
{

/// Clase para implementar la clase gráfica "Sprite" en Allegro.
///
class SpriteAllegro : public fgm::Sprite
{
public:
    /// Constructor.
    /// @param  aowner  Propietario del "sprite" gráfico.
    /// @note Se mantiene por cuestiones de compatibilidad con el código escrito
    ///       hasta ahora, pero cualquier objeto gráfico debería tener entidad por sí solo.
    SpriteAllegro (fgm::Actor* aowner);

    /// Constructor de copia.
    /// Se toma la base del "Sprite" y se le asigna un nuevo propietario.
    /// @param  copia  Referencia a un "Sprite" que se desea duplicar.
    /// @param  aowner  Propietario del "sprite" gráfico.
    /// @note Se mantiene por cuestiones de compatibilidad con el código escrito
    ///       hasta ahora, pero cualquier objeto gráfico debería tener entidad por sí solo.
    ///       Se usa fundamentalmente para pruebas.
    SpriteAllegro (const fgm::Sprite& copia, fgm::Actor* aowner);

    /// Destructor.
    ~SpriteAllegro ();

    /// Heredadas de "Sprite".
    const gcn::Image* getImage (unsigned int ind) const;
};
}

#endif