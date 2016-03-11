#include "Bitmap.h"
#include <sstream>

/**
 *  Constructor de la clase.
 */
Bitmap::Bitmap (Actor *aowner, BITMAP *bmp) :
ActorGraphic (aowner),
fuente (bmp),
nombre ("Sin nombre"),
almacen (NULL)
{
}

/**
 *  Constructor de la clase.
 */
Bitmap::Bitmap (Actor *aowner, BITMAP *bmp, string nombreParam) :
ActorGraphic (aowner),
fuente (bmp),
nombre (nombreParam),
almacen (NULL)
{
}

/**
 * \brief   Constructor de la clase. Utiliza el almacén de recursos.
 */
Bitmap::Bitmap (Actor *aowner, Almacen *almacenParam, const string nombreParam):
ActorGraphic (aowner),
almacen (almacenParam),
nombre (nombreParam)
{
//  fuente = almacenParam[nombreParam];
  fuente = almacenParam->GetBitmap (nombreParam);
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
 * \brief   Devuelve la estructura básica del objeto en forma de cadena.
 */
string  Bitmap::getString () const
{
  ostringstream cadena;
  cadena  << "Bitmap >> " << nombre << endl;
  return cadena.str();
}

/**
 * \brief   Devuelve la zona de memoria donde está la imagen.
 * \details También se podría utilizar el nombre y el almacén para obtener este mismo dato:
 *          return almacen->GetBitmap (nombre);
 */
BITMAP *  Bitmap::getImagen () const
{
  return fuente;
};