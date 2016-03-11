#include "Bitmap.h"
#include <sstream>


// Inicializamos el almacén global de la clase.
Almacen *  Bitmap::almacenGlobal = NULL;

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
 * \brief   Constructor de la clase. Utiliza únicamente el nombre del Bitmap.
 */
Bitmap::Bitmap (Actor *aowner, const string nombreParam):
ActorGraphic (aowner),
nombre (nombreParam)
{
}

/**
 * \brief   Dibuja el 'bitmap' fuente (el 'bitmap' dado al crear el objeto), en el
 *          'bitmap' destino (pasado por parámetro), normalmente la pantalla
 *          o un 'buffer' intermedio.
 */
void  Bitmap::draw (BITMAP *destino)
{
  draw_sprite (destino, fuente, get_x(), get_y());
}

/**
 * \brief   Entrega el valor de la anchura del Bitmap.
 */
int Bitmap::get_w()
{
  return fuente->w;
}

/**
 * \brief   Entrega el valor de la altura del Bitmap.
 */
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

/**
 * \brief   Dibuja el bitmap en la zona de memoria dada como destino.
 * \warning Se mantienen las dos formas de dibujar: Usando al almacén global y el BITMAP fuente.
 *          En un futuro la línea es mantener todos punteros BITMAP en el almacén y referenciarlos
 *          únicamente con su nombre. En ese momento se eliminará la propiedad 'fuente' de la clase.
 */

// Mantenemos este procedimiento por compatibilidad (No entiendo porqué no funciona el parámetro por omisión)
// Ahora lo entiendo... no funciona porque el procedimiento que se hereda de 'ActorGraphic' es sin el parámetro.
void  Bitmap::draw (int x, int y, BITMAP *destino)
{
  draw (x,y,destino,false);
}
//--------------------------------------------------

void  Bitmap::draw (int x, int y, BITMAP *destino, bool mirror)
{
  if (almacenGlobal)
  {
    if (mirror)
    {
      draw_sprite_h_flip (destino, almacenGlobal->GetBitmap (nombre), x, y);
    }
    else
    {
      draw_sprite (destino, almacenGlobal->GetBitmap (nombre), x, y);
    }
  }
  else
  {
    draw_sprite (destino, fuente, x, y);
  }
}

/**
 * \brief   Devuelve la estructura básica del objeto en forma de cadena.
 */
string  Bitmap::getString () const
{
  ostringstream cadena;
  cadena  << "Bitmap >> " << nombre << " >> Almacén general: " << almacenGlobal << endl;
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
