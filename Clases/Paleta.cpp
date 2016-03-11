#include "Paleta.h"

/**
 * Constructor de copia.
 */
Paleta::Paleta (const Paleta &copia):
ControllableActor(copia)
{
    // Una vez copiada la parte gráfica del actor en la inicialización
    // la referenciamos en el parámetro 'piel'.
    piel = dynamic_cast<Suelo *>(agraph);
}

/**
 * Constructor por omisión.
 */
Paleta::Paleta()
{
    piel = new Suelo(this,2);    
    set_actor_graphic (piel);
    set_name (Nombres::paleta);
    set_x(0);
    set_y(SCREEN_H - 70);
	set_is_detected(true);
    set_collision_method(CollisionManager::PP_COLLISION);
}

/**
 * Destructor.
 */
Paleta::~Paleta(void)
{
}

/**
 * Acciones como actro controlable.
 */
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

/**
 * Acciones ante colisiones.
 */
void Paleta::hit (Actor *who, int damage)
{
   switch (who->get_name())
   {
       
       // Si tropezamos con un ladrillo. Aumentamos el tamaño.
       case Nombres::ladrillo:
           if (piel->Get_size () < 8)
           {
                piel->Set_size(piel->Get_size()+1);
                this->set_wh(32*piel->Get_size()+20,15);
           }
           break;

       // Si tropezamos con una pelota. Disminuímos el tamaño.
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
