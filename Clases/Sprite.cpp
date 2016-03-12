#include <sstream>
#include "Sprite.h"
#include "Actor.h"
#include "Mask.h"

/**
 * Constructor de copia.
 */
Sprite::Sprite (const Sprite &copia, Actor *aowner):
ActorGraphic (aowner),
frames (copia.frames),
actual_tick (copia.actual_tick),
actual_frame (copia.actual_frame),
mirror (copia.mirror)
{
}

/**
 * Constructor pot omisión.
 */
Sprite::Sprite (Actor *aowner):
ActorGraphic(aowner),
actual_tick (0),
actual_frame (0),
mirror (false)
{
}

/**
 * Inicializa la parte gráfica del objeto.
 * Esto provoca que el objeto no se clone en su estado actual.
 * Se deja en blanco y se inicializa en los constructorores.
 */
void Sprite::init()
{
//    actual_frame=0;
//    actual_tick=0;
}

void Sprite::add_frame(BITMAP *bmp, int cx, int cy, int ticks)
{
    Frame tmp_frame;
  
    tmp_frame.bmp = bmp;
    tmp_frame.cx = cx;
    tmp_frame.cy = cy;
    tmp_frame.ticks = ticks;

    /* Crea la máscara. */
    tmp_frame.mask = new Mask;
    tmp_frame.mask->create(bmp);

    /* Guarda el marco (frame) en la lista. */
    frames.push_back(tmp_frame);
}

void Sprite::update()
{
    if (frames.size() <= 1) return;
    if (actual_tick > frames[actual_frame].ticks)
    {
        actual_tick = 0;
        actual_frame++;
        if (actual_frame >= (int)frames.size()) actual_frame=0;
    }
    else
    {
        actual_tick++;
    }
}

/**
 * draw - Dibuja en el BITMAP 
 */
void Sprite::draw(BITMAP *bmp)
{
  if (mirror)
  {
    draw_sprite_h_flip (bmp,  frames[actual_frame].bmp,
                        get_x() - frames[actual_frame].cx,
                        get_y() - frames[actual_frame].cy);
  }
  else
  {
    draw_sprite (bmp, frames[actual_frame].bmp,
                 get_x() - frames[actual_frame].cx,
                 get_y() - frames[actual_frame].cy);
  }
}

int Sprite::get_w()
{
    return frames[actual_frame].bmp->w;
}

int Sprite::get_h()
{
    return frames[actual_frame].bmp->h;
}

int Sprite::get_x()
{
  return ActorGraphic::get_x()-(frames[actual_frame].cx);
}

int Sprite::get_y()
{
  return ActorGraphic::get_y()-(frames[actual_frame].cy);
}

Mask *Sprite::get_mask()
{
  return frames[actual_frame].mask;
}

/**
 * Clona el objeto.
 */
Sprite * Sprite::clone (Actor *propietario) const
{
  // Al clonar usamos el constructor de copia de la clase.
  return (new Sprite (*this, propietario));
}

/**
 * \brief   draw - Dibuja en el BITMAP 
 * \details Según esté o no activo la variable 'mirror' se dibujará en espejo.
 */
void Sprite::draw (int x, int y, BITMAP *bmp)
{
  if (mirror)
  {
    draw_sprite_h_flip (bmp, frames[actual_frame].bmp, 
                        x - frames[actual_frame].cx,
                        y - frames[actual_frame].cy);
  }
  else
  {
    draw_sprite (bmp, frames[actual_frame].bmp, 
                 x - frames[actual_frame].cx,
                 y - frames[actual_frame].cy);
  }
}

/**
 * \brief   Cambia la variable de reflejo.
 * \todo  Sustituir la variable 'mirror' por un vector que haga el giro en cualquier ángulo
 *        y en cualquier dirección.
 */
void Sprite::setMirror (bool paramMirror)
{
  mirror = paramMirror;
}

/**
 * \brief   Obtine la variable de reflejo.
 */
bool Sprite::getMirror ()
{
  return mirror;
}

/**
 * \brief   Cambia la variable de reflejo al valor negado del existente.
 */
void Sprite::notMirror ()
{
    mirror = !mirror;
}

/**
 * \brief   Entrega una cadena con la estructura y propiedades del objeto.
 */
string  Sprite::getString () const
{
  ostringstream cadena;

  // Se incluye la estructura del padre.
  // cadena  << ActorGraphic::getString ();

  // Se incluyen las propiedades de Sprite.
  cadena  << "Sprite >> NumFrames: " << frames.size () \
          << " >> Frame actual: " << actual_frame \
          << " >> Tick actual: " << actual_tick \
          << " >> Ángulo: " << mirror << endl;

  // Se incluyen los valores de los Frames.
  for (unsigned int i=0; i<frames.size (); i++)
  {
    cadena << "Frame " << i << " {" << frames[i].getString () << "}\n";
  }

  return (cadena.str());
}
