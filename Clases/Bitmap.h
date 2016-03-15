#ifndef BITMAP_H
#define BITMAP_H

#include "ActorGraphic.h"

class Bitmap : public ActorGraphic
{
    public:
        Bitmap(Actor *aowner, BITMAP *bmp);
        void draw(BITMAP *bmp);
        int get_w();
        int get_h();

    protected:
        BITMAP *bitmap;
};

#endif