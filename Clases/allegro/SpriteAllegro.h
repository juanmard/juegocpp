///
/// @file SpriteAllegro.cpp
/// @brief Fichero de implementaci�n de la clase "SpriteAllegro".
/// @author Juan Manuel Rico
/// @date Junio 2016
/// @version 1.0.0
///
#pragma once

#include <allegro.h>
#include <guichan\image.hpp>
#include "..\Sprite.h"

/// Espacio de nombres para la adaptaci�n del juego con las bibliotecas Allegro.
namespace allegro
{

/// Clase para implementar la clase gr�fica "Sprite" en Allegro.
///
class SpriteAllegro : public Sprite
{
public:
    /// Constructor.
    /// @param  aowner  Propietario del "sprite" gr�fico.
    /// @note Se mantiene por cuestiones de compatibilidad con el c�digo escrito
    ///       hasta ahora, pero cualquier objeto gr�fico deber�a tener entidad por s� solo.
    SpriteAllegro (Actor* aowner);

    /// Constructor de copia.
    /// Se toma la base del "Sprite" y se le asigna un nuevo propietario.
    /// @param  copia  Referencia a un "Sprite" que se desea duplicar.
    /// @param  aowner  Propietario del "sprite" gr�fico.
    /// @note Se mantiene por cuestiones de compatibilidad con el c�digo escrito
    ///       hasta ahora, pero cualquier objeto gr�fico deber�a tener entidad por s� solo.
    ///       Se usa fundamentalmente para pruebas.
    SpriteAllegro (const Sprite& copia, Actor* aowner);

    /// Destructor.
    ~SpriteAllegro ();

    /// Heredadas de "Sprite".
    const gcn::Image* getImage (unsigned int ind) const;
};
}
