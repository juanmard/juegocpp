///
/// @file SpriteAllegro.cpp
/// @brief Fichero de implementación de la clase "SpriteAllegro".
/// @author Juan Manuel Rico
/// @date Junio 2016
/// @version 1.0.0
///
#include "SpriteAllegro.h"
#include <guichan\allegro\allegroimage.hpp>

namespace allegro
{

SpriteAllegro::SpriteAllegro (Actor* aowner):
Sprite (aowner)
{
};

SpriteAllegro::SpriteAllegro (const Sprite& copia, Actor* aowner):
Sprite (copia, aowner)
{
};

SpriteAllegro::~SpriteAllegro ()
{
};

const gcn::Image* SpriteAllegro::getImage (unsigned int ind) const
{
    // Se obtiene el puntero a la imagen del Frame.
    BITMAP* frameBitmap = getFrame(ind)->getBitmap();

    // Se crea una copia para no modificar la imagen original al convertir el formato.
    BITMAP *bmp = create_bitmap(frameBitmap->w, frameBitmap->h);
    blit(frameBitmap, bmp, 0, 0, 0, 0, bmp->w, bmp->h);

    // Se crea la nueva imagen que se va a entregar.
    gcn::Image* img = new gcn::AllegroImage (bmp, true);

    // Se convierte el formato de la imagen y se entrega.
    img->convertToDisplayFormat();
    return img;
};

}
