#ifndef SPRITE_H
#define SPRITE_H

#include "ActorGraphic.h"
#include <allegro.h>
#include <vector>

using namespace std;

class Actor;

/** 
 * \brief   Parte gráfica de un actor como un gráfico en movimiento.
 * \details Esta clase modela varias imágenes en movimiento como gráfico para un actor.
 */ 
class Sprite : public ActorGraphic
{
    public:
                            Sprite      (const Sprite &copia, Actor *aowner);
                            Sprite      (Actor *aowner);
        virtual Sprite *    clone       (Actor *propietario) const;
        void                draw        (BITMAP *bmp);
        void                update      ();
        void                init        ();
        int                 get_w       ();
        int                 get_h       ();
        int                 get_x       ();
        int                 get_y       ();
        void                add_frame   (BITMAP *bmp, int cx, int cy, int ticks);
        Mask *              get_mask    ();

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
