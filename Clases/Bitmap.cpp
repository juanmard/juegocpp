#include "Bitmap.h"
#include <sstream>

/**
 *  Constructor de la clase.
 */
Bitmap::Bitmap (Actor *aowner, BITMAP *bmp) :
ActorGraphic (aowner),
fuente (bmp),
nombre ("Sin nombre")
{
}

/**
 *  Constructor de la clase.
 */
Bitmap::Bitmap (Actor *aowner, BITMAP *bmp, string nombreParam) :
ActorGraphic (aowner),
fuente (bmp),
nombre (nombreParam)
{
}

/**
 * \brief   Dibuja el 'bitmap' fuente (el 'bitmap' dado al crear el objeto), en el
 *          'bitmap' destino (pasado por parámetro), normalmente la pantalla
 *          o un 'buffer' intermedio.
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

void Bitmap::draw   (int x, int y, BITMAP *destino)
{
    draw_sprite (destino, fuente, x, y);
}

/**
 * \brief   Devuelve la estructura del objeto en forma de cadena.
 * \todo    Debemos referenciar todos los Bitmap del juego en una zona de memoria
 *          extraídos de un fichero de tipo DatFile mediante su nombre, ya que
 *          muchos objetos utilizan los mismos Bitmap's.
 */
string  Bitmap::getString () const
{
  ostringstream cadena;
  cadena  << "Bitmap >> " << nombre << "\n";
  return cadena.str();
}

