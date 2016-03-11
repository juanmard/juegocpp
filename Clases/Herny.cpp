#include "Herny.h"
#include "Bitmap.h"

Herny::Herny (void)
{
    DatFile *sprites = new DatFile("sprites.dat");
    Sprite *skin = new Sprite(this);
    
    skin->add_frame(sprites->GetBitmap("jugador_01"), 0, 0, 10);
    skin->add_frame(sprites->GetBitmap("jugador_02"), 0, 0, 30);
    skin->add_frame(sprites->GetBitmap("jugador_03"), 0, 0, 10);
    skin->add_frame(sprites->GetBitmap("jugador_04"), 0, 0, 10);
    skin->add_frame(sprites->GetBitmap("jugador_05"), 0, 0, 20);

    this->set_name (Nombres::herny);
    this->set_x(SCREEN_W/2);
    this->set_y(SCREEN_H/2);
    this->set_actor_graphic (skin);
	this->set_is_detected(true);
    //this->set_team(ENEMY);
    this->set_collision_method(CollisionManager::PP_COLLISION);
    this->set_wh (26,36);

//    this->tiempo_estado = 400;
//    this->tiempo_estado = 0; //Desactivamos el jugador para pruebas.
    this->actual = Herny::de_pie;
    this->siguiente = Herny::cayendo;
}

void Herny::do_action (ControllableActor::action_t act, int magnitude)
{
    switch (act)
    {
        case DOWN:
            y+=1;
            break;

        case UP:
            y-=1;
            break;

        case LEFT:
            x-=1;
            break;

        case RIGHT:
            x+=1;
            break;
    }
    if (x<0) x=0;
    if (x>SCREEN_W-get_w()) x=SCREEN_W-get_w();
    if (y<0) y=0;
    if (y>SCREEN_H-get_h()) y=SCREEN_H-get_h();
}

//TODO: No me gusta tener duplicados los estados.
//      Sería conveniente unirlos en un solo procedimiento.
void Herny::ActualizarEstado (void)
{
    switch (actual)
    {
    case de_pie:
        break;

    case cayendo:
        set_y (get_y() + 1);
        break;

    default:    
        break;
    }
}

void Herny::CambiarEstado (void)
{
    DatFile *sprites = new DatFile("sprites.dat");

    actual = siguiente;
    switch (siguiente)
    {
    case de_pie:
            set_tiempo(400);
            siguiente = cayendo;
            set_color(6);
            this->set_actor_graphic (new Bitmap (this,sprites->GetBitmap("jugador_01")));
        break;

    case cayendo:
            set_tiempo(100);
            siguiente = de_pie;
            set_color(3);
            this->set_actor_graphic (new Bitmap (this,sprites->GetBitmap("jugador_15")));
         break;

    default:    
        break;
    }
}
/**
 * \brief   Intersección del herny con otro actor de la escena.
 * \param   who Puntero al actor que provoca la colisión.
 * \param   damage Daño que se produce en la colisión. 
 * \todo    Se necesita calcular no sólo la energía con la que colisionan los
 *          objetos(damage), sino con qué inclinación colisionan.
 */
void  Herny::hit  (Actor *who, int damage)
{
   switch (who->get_name())
   {
       case Nombres::pelota:
           estado = Herny::eliminar;
           break;
   }
}
