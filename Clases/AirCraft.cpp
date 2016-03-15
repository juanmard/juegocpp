#include "AirCraft.h"

AirCraft::AirCraft()
{
	image=NULL;
}

void AirCraft::do_action (ControllableObject::action_t act, int magnitude)
{
    switch (act)
    {
        case DOWN:
            y+=4;
            break;

        case UP:
            y-=4;
            break;

        case LEFT:
            x-=4;
            break;

        case RIGHT:
            x+=4;
            break;
    }
    if (x<0) x=0;
    if (x>SCREEN_W-get_w()) x=SCREEN_W-get_w();
    if (y<0) y=0;
    if (y>SCREEN_H-get_h()) y=SCREEN_H-get_h();
}

void  AirCraft::hit  (Actor *who, int damage)
{
   switch (who->get_name())
   {
       default:
           //estado = AirCraft::eliminar;
           break;
   }
}