#include "Paleta.h"

/**
 * Constructor de copia.
 */
Paleta::Paleta (const Paleta &copia):
ControllableActor(copia),
piel(copia.piel),
do_action(copia.do_action)
{
}

/**
 * Constructor por omisión.
 */
Paleta::Paleta()
{
    this->piel = new Suelo(this,2);    
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

void Paleta::hit (Actor *who, int damage)
{
   switch (who->get_name())
   {
       /**
        * Si tropezamos con un ladrillo. Aumentamos el tamaño.
        */
       case Nombres::ladrillo:
           if (piel->Get_size () < 8)
           {
                piel->Set_size(piel->Get_size()+1);
                this->set_wh(32*piel->Get_size()+20,15);
           }
           break;

       case Nombres::pelota:
           if (piel->Get_size () > 2)
           {
              piel->Set_size(piel->Get_size()-1);
              set_wh (32*piel->Get_size() + 20, 15);
           }
          break;

       default:
           break;
   }
}

/**
 * Clona el objeto.
 */
Paleta *    Paleta::clone  () const
{
    return (new Paleta(*this));
};
