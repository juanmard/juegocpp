#include "Herny.h"
#include "Almacen.h"
#include "Bitmap.h"

/**
 * Constructor de copia.
 */
Herny::Herny (const Herny &copia):
ControllableActor(copia),
actual (copia.actual),
siguiente (copia.siguiente)
{
    // Una vez copiada la parte gráfica (ControllableActor),
    // la referenciamos en el objeto.
    skin = dynamic_cast<Sprite *>(agraph);
}

/**
 * Constructor por omisión.
 */
Herny::Herny (Almacen &almacen)
{
    //DatFile *sprites = new DatFile("sprites.dat");
    Sprite *skin = new Sprite(this);    
    skin->add_frame(almacen.GetBitmap("sprite_058"), 0, 0, 10);
    skin->add_frame(almacen.GetBitmap("sprite_059"), 0, 0, 30);
    skin->add_frame(almacen.GetBitmap("sprite_060"), 0, 0, 10);
    skin->add_frame(almacen.GetBitmap("sprite_061"), 0, 0, 10);
    skin->add_frame(almacen.GetBitmap("sprite_062"), 0, 0, 20);
    set_actor_graphic (skin);

    set_name (Nombres::herny);
    set_x(SCREEN_W/2);
    set_y(SCREEN_H/2);
	set_is_detected(true);
    //set_team(ENEMY);
    set_collision_method(CollisionManager::PP_COLLISION);
    set_wh (26,36);

//    tiempo_estado = 400;
//    tiempo_estado = 0; //Desactivamos el jugador para pruebas.
    actual = Herny::de_pie;
    siguiente = Herny::cayendo;
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

void Herny::CambiarEstado (Almacen &almacen)
{
    //DatFile *sprites = new DatFile("sprites.dat");
    actual = siguiente;
    switch (siguiente)
    {
    case de_pie:
            set_tiempo(400);
            siguiente = cayendo;
            set_color(6);
            this->set_actor_graphic (new Bitmap (this,almacen.GetBitmap("sprite_065")));
        break;

    case cayendo:
            set_tiempo(100);
            siguiente = de_pie;
            set_color(3);
            this->set_actor_graphic (new Bitmap (this,almacen.GetBitmap("sprite_069")));
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

/**
 * Clona el objeto.
 */
Herny *  Herny::clone () const
{
    return (new Herny (*this));
}
