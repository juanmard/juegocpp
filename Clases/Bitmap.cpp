#include "Bitmap.h"

Bitmap::Bitmap(Actor *aowner, BITMAP *bmp) : ActorGraphic(aowner)
{
    bitmap=bmp;
}


void Bitmap::draw(BITMAP *bmp)
{
    draw_sprite(bmp, bitmap, get_x(), get_y());
}

int Bitmap::get_w()
{
    return bitmap->w;
}

int Bitmap::get_h()
{
    return bitmap->h;
}