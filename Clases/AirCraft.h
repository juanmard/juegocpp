#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include "ControllableActor.h"

/** 
 * \brief   Modela una nave espacial como actor controlable.
 * \details Esta clase modela una nave espacial para probar los actores controlables.
 */
class AirCraft : public ControllableActor
{
    public:
        AirCraft (const AirCraft &copia);
        AirCraft ();
    
        typedef enum
        {
            DOWN,
            UP,
            LEFT,
            RIGHT
        } action_t;

        void                do_action   (ControllableObject::action_t act, int magnitude);
        void                hit         (Actor *who, int damage);
        virtual AirCraft *  clone       () const;
        
    protected:
        BITMAP *image;
};

#endif
