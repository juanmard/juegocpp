#ifndef  SPRITE_H
#define SPRITE_H

#include "ActorGraphic.h"
#include <allegro.h>
#include <vector>

class Sprite : public ActorGraphic
{
    public:
                    Sprite         (Actor *aowner);
        void     draw          (BITMAP *bmp);
        void     update       ();
        void     init             ();
        int       get_w         ();
        int       get_h          ();
        int       get_x          ();
        int       get_y          ();
        void     add_frame  (BITMAP *bmp, int cx, int cy, int ticks);
        Mask *  get_mask    ();

    protected:
        typedef struct Frame
        {
            BITMAP *bmp;
            Mask *mask;
            int cx;
            int cy;
            int ticks;
        };
        
        vector<Frame> frames;
        int actual_tick, actual_frame;
};

#endif
