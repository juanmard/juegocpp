#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include "ControllableActor.h"

class AirCraft : public ControllableActor
{
    public:
        AirCraft();
    
        typedef enum
        {
            DOWN,
            UP,
            LEFT,
            RIGHT
        } action_t;

        void    do_action   (ControllableObject::action_t act, int magnitude);
        void    hit         (Actor *who, int damage);
   
    protected:
        BITMAP *image;
};

#endif