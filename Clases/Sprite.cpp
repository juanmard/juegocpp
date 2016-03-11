#include "Sprite.h"
#include "Actor.h"
#include "Mask.h"

Sprite::Sprite (Actor *aowner) : ActorGraphic(aowner)
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
    tmp_frame.bmp=bmp;
    tmp_frame.cx=cx;
    tmp_frame.cy=cy;
    tmp_frame.ticks=ticks;

    /* Crea la máscara. */
    tmp_frame.mask=new Mask;
    tmp_frame.mask->create(bmp);

    /* Guarda el marco (frame) en la lista. */
    frames.push_back(tmp_frame);
}

void Sprite::update()
{
    if (frames.size()<=1) return;
    if (actual_tick>frames[actual_frame].ticks)
    {
        actual_tick=0;
        actual_frame++;
        if (actual_frame>=(int)frames.size()) actual_frame=0;
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
    
    draw_sprite(bmp, frames[actual_frame].bmp, get_x(), get_y());
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
    return owner->get_x()-(frames[actual_frame].cx);
}

int Sprite::get_y()
{
    return owner->get_y()-(frames[actual_frame].cy);
}

Mask *Sprite::get_mask()
{
    return frames[actual_frame].mask;
}
