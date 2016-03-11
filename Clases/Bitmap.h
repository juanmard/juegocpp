#pragma once

#include "ActorGraphic.h"
#include <string>

/** 
 * \brief   Parte gráfica de un actor como un gráfico fijo.
 * \details Esta clase modela una imagen fija como gráfico para un actor.
 */
class Bitmap : public ActorGraphic
{
    public:
                            Bitmap      (Actor *aowner, BITMAP *bmp);
                            Bitmap      (Actor *aowner, BITMAP *bmp, string nombreParam);
        void                draw        (BITMAP *destino);
        void                draw        (int x, int y, BITMAP *destino);
        int                 get_w       ();
        int                 get_h       ();
        virtual Bitmap *    clone       (Actor *propietario) const;
        string              getString   () const;

    protected:
        string      nombre;
        BITMAP *    fuente;
};
