#include "AirCraft.h"

/**
 * Constructor de copia.
 */
AirCraft::AirCraft  (const AirCraft &copia):
ControllableActor (copia),
image(copia.image)
{
}

/**
 * Constructor por omisión.
 */
AirCraft::AirCraft()
{
  image = NULL;
}

/**
 * Acciones como actor controlado.
 */
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

/**
 * Definición de estados en colisiones.
 */
void  AirCraft::hit  (Actor *who, int damage)
{
}

/**
 * Clona el objeto.
 */
AirCraft * AirCraft::clone () const
{
    return (new AirCraft (*this));
}

std::ifstream& AirCraft::leer (std::ifstream &ifs)
{
    return ifs;
}

