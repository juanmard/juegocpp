#ifndef ACTORGRAPHIC_H
#define ACTORGRAPHIC_H

#include <string>
#include <allegro.h>

class Actor;
class Mask;

using namespace std;

/** 
 * \brief   Controla la parte gráfica del actor.
 * \details Esta clase define la parte gráfica del actor.
 */
class ActorGraphic
{
    public:
                                ActorGraphic    (Actor *a);
        virtual                 ~ActorGraphic   ();
        virtual void            init            ();
        virtual void            update          ();
        virtual void            draw            (BITMAP *bmp);
        virtual void            draw            (int x, int y, BITMAP *bmp);
        virtual int             get_w           ();
        virtual int             get_h           ();
        virtual int             get_x           ();
        virtual int             get_y           ();
        virtual Mask*           get_mask        ();
        virtual ActorGraphic *  clone           (Actor *propietario) const;
        virtual string          getString       () const;

    protected:
        Actor *owner;
};

#endif
