#include "Sprite.h"
#include "Actor.h"
#include "Mask.h"

/**
 * Constructor de copia.
 */
Sprite::Sprite (const Sprite &copia, Actor *aowner):
ActorGraphic(aowner),
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
mirror (false)
{
}

void Sprite::init()
{
    actual_frame=0;
    actual_tick=0;
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
    return (new Sprite(*this, propietario));
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
    mirror != mirror;
}

