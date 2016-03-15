#include "ActorGraphic.h"

ActorGraphic::ActorGraphic(Actor *a)
{
    owner=a;
}

ActorGraphic::~ActorGraphic()
{
}

void ActorGraphic::update()
{
}

void ActorGraphic::init()
{
}

/** Dibuja la parte gráfica del actor en "bmp".
 *  
 *  Normalmente esta función es sobreescrita por el 
 *  hijo que hereda (Sprite, Bitmap, pixel...).
 *
 *  @param bmp - BITMAP en donde se dibuja la parte gráfica del actor.
 *
 */
void ActorGraphic::draw(BITMAP *bmp)
{
}

int ActorGraphic::get_w()
{
    return 0;
}

int ActorGraphic::get_h()
{
    return 0;
}

int ActorGraphic::get_x()
{
    return (int)(owner->get_x());
}

int ActorGraphic::get_y()
{
    return (int)(owner->get_y());
}

Mask * ActorGraphic::get_mask ()
{
    return NULL;
}

