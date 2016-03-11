#pragma once

#include "ActorGraphic.h"

/** 
 * \brief   Parte gráfica de un actor como un gráfico fijo.
 * \details Esta clase modela una imagen fija como gráfico para un actor.
 */
class Bitmap : public ActorGraphic
{
    public:
                Bitmap  (Actor *aowner, BITMAP *bmp);
        void    draw    (BITMAP *destino);
        int     get_w   ();
        int     get_h   ();
        Bitmap *    duplicar (Actor *propietario);

    protected:
        BITMAP *    fuente;
};
