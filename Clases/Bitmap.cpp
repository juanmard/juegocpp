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
nombre ("sin nombre"),
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
  fuente = almacenParam->getBitmap (nombreParam);
}

/**
 * \brief   Constructor de la clase. Utiliza únicamente el nombre del Bitmap.
 */
Bitmap::Bitmap (Actor *aowner, const string nombreParam):
ActorGraphic (aowner),
nombre (nombreParam),
almacen (NULL)
{
  fuente = almacenGlobal->getBitmap (nombreParam);
}

/**
 * \brief   Dibuja el 'bitmap' fuente (el 'bitmap' dado al crear el objeto), en el
 *          'bitmap' destino (pasado por parámetro), normalmente la pantalla
 *          o un 'buffer' intermedio.
 */
void  Bitmap::draw (BITMAP *destino)
{
  //draw_sprite (destino, fuente, get_x(), get_y());
  pivot_sprite_v_flip_lit(destino, fuente, get_x(), get_y(), 0, 0, 34, 128);
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
    return (new Bitmap(propietario,fuente,this->nombre));
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
      draw_sprite_h_flip (destino, almacenGlobal->getBitmap (nombre), x, y);
    }
    else
    {
      draw_sprite (destino, almacenGlobal->getBitmap (nombre), x, y);
    }
  }
  else
  {
    // Rota los sprites...
    //rotate_sprite(destino, fuente, x, y, ftofix(256.0/9));

    // Dibuja sombras...
    //draw_character_ex(destino, fuente, x+3, y+3, makecol(128, 128, 128), -1);

    // Rota y escala...
    //rotate_scaled_sprite(destino, fuente, x, y, ftofix(0.0), ftofix(2.0));

    //Rota con pivote...
    // pivot_sprite(destino, fuente, x, y, x+10, y-10, ftofix(10.0));
    
    draw_sprite (destino, fuente, x, y);
  }
}

/**
 * \brief   Devuelve la estructura básica del objeto en forma de cadena.
 * \todo    Hacer este procedimiento virtual y que los distintos gráficos hereden
 *          de una clase más genérica llamada "Gráfico" que es "Dibujable".
 */
std::string  Bitmap::getString () const
{
  return nombre;
};

/**
 * \brief   Devuelve la zona de memoria donde está la imagen.
 * \details También se podría utilizar el nombre y el almacén para obtener este mismo dato:
 *           - return almacen->getBitmap (nombre);
 *          Éste es el que debe quedar cuando eliminemos el resto de parámetros.
 */
BITMAP *  Bitmap::getImagen () const
{
  if (fuente)
  {
    return fuente;
  }
  else
  {
    if (almacenGlobal)
    {
      return almacenGlobal->getBitmap (nombre);
    }
	  else
	  {
	    return NULL;
	  }
  }
};
