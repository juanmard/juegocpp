#ifndef ACTORGRAPHIC_H
#define ACTORGRAPHIC_H

#include <allegro.h>
#include "Actor.h"
#include "Mask.h"

class Actor;

class ActorGraphic
{
    public:
        ActorGraphic(Actor *a);
        virtual ~ActorGraphic();
        virtual void init();
        virtual void update();
        virtual void draw(BITMAP *bmp);
        virtual int get_w();
        virtual int get_h();
        virtual int get_x();
        virtual int get_y();
        virtual Mask* get_mask();

    protected:
        Actor *owner;
};
#endif
