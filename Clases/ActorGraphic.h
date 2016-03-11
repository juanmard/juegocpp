#ifndef ACTORGRAPHIC_H
#define ACTORGRAPHIC_H

#include <allegro.h>

class Actor;
class Mask;

/** 
 * \brief   Controla la parte gráfica del actor.
 * \details Esta clase define la parte gráfica del actor.
 */
class ActorGraphic
{
    public:
                                ActorGraphic    (const ActorGraphic &agraph);
                                ActorGraphic    (Actor *a);
        virtual                 ~ActorGraphic   ();
        virtual void            init            ();
        virtual void            update          ();
        virtual void            draw            (BITMAP *bmp);
        virtual int             get_w           ();
        virtual int             get_h           ();
        virtual int             get_x           ();
        virtual int             get_y           ();
        virtual Mask*           get_mask        ();
        virtual ActorGraphic *  duplicar        (Actor *propietario);

    protected:
        Actor *owner;
};

#endif
