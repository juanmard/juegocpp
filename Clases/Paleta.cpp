#include "Paleta.h"

Paleta::Paleta(void)
{
    this->piel = new Suelo(this,4);    
    this->set_name (Nombres::paleta);
    this->set_x(0);
    this->set_y(SCREEN_H - 70);
    this->set_actor_graphic (piel);
	this->set_is_detected(true);
    this->set_collision_method(CollisionManager::PP_COLLISION);
}

Paleta::~Paleta(void)
{
}

void Paleta::do_action (ControllableObject::action_t act, int magnitude)
{
    switch (act)
    {
        case LEFT:
            x-=3;
            break;

        case RIGHT:
            x+=3;
            break;
    }
    if (x<0) x=0;
    if (x>SCREEN_W-get_w()) x=SCREEN_W-get_w();
}