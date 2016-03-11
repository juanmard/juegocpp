
#include "Bitmap.h"

/**
 *  Constructor de la clase.
 */
Bitmap::Bitmap(Actor *aowner, BITMAP *bmp) :
ActorGraphic(aowner),
fuente(bmp)
{
}

/**
 * \brief       Dibuja el 'bitmap' fuente (el 'bitmap' dado al crear el objeto), en el
 *                'bitmap' destino (pasado por parámetro), normalmente la pantalla
 *                o un 'buffer' intermedio.
 */
void Bitmap::draw   (BITMAP *destino)
{
    draw_sprite (destino, fuente, get_x(), get_y());
}

int Bitmap::get_w()
{
    return fuente->w;
}

int Bitmap::get_h()
{
    return fuente->h;
}

/**
 * \brief   Clona el objeto.
 */
Bitmap *  Bitmap::clone  (Actor *propietario) const
{
    return (new Bitmap(propietario,fuente));
}
