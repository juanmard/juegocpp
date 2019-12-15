///---------------------------------------------------------
/// @file       AirCraft.cpp
/// @author     Juan Manuel Rico
/// @date       Diciembre 2019
/// @version    1.0.0
///
/// @brief      Nave como actor controlable.
///---------------------------------------------------------

#include "AirCraft.h"
#include <allegro.h>
#include "StageManager.h"

namespace fwg {

    AirCraft::AirCraft():
    color1(makecol(20,127,34)),
    color2(makecol(255,127,34))
    {
      image = NULL;
      this->setWH (20,60);
      this->setX (100);
      this->setY (200);
      this->setState (Actor::ENABLE);
    }

    AirCraft::AirCraft  (const AirCraft& copia):
    ControllableActor (copia),
    image(copia.image)
    {
    }

    void AirCraft::doAction (ControllableObject::Action act, int magnitude)
    {
        switch (act)
        {
            case DOWN:
                y += 4;
                break;

            case UP:
                y -= 4;
                break;

            case LEFT:
                x -= 4;
                break;

            case RIGHT:
                x += 4;
                break;
            case 4: color1++; break;
            case 5: color2++; break;
        }
        if (x < 0) x = 0;
        if (x > SCREEN_W - getW ()) x = SCREEN_W - getW ();
        if (y < 0) y = 0;
        if (y > SCREEN_H - getH ()) y = SCREEN_H - getH ();
    }

    void  AirCraft::hit (Actor* who, int damage)
    {
    }

    void AirCraft::draw (StageManager* stageManager)
    {
        rectfill (stageManager->getBuffer(), x, y, x+w, y+h, color1);
        ellipse (stageManager->getBuffer(), x+(w/2), y+(h/2),
                 y/3, x/3, color2);
    }
    
    AirCraft* AirCraft::clone () const
    {
        return (new AirCraft (*this));
    }

    std::ifstream& AirCraft::leer (std::ifstream& ifs)
    {
        return ifs;
    }
}