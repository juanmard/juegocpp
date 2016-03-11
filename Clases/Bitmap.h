#pragma once

#include "ActorGraphic.h"

class Bitmap : public ActorGraphic
{
    public:
                    Bitmap    (Actor *aowner, BITMAP *bmp);
        void    draw        (BITMAP *destino);
        int       get_w      ();
        int       get_h      ();

    protected:
        BITMAP  *fuente;
};
