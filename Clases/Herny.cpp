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
    //DatFile *sprites = new DatFile("sprites3.dat");
    // ¡Cuidado! Esto falla si en el almacén no existe el bitmap que se pide.
    Sprite *skin = new Sprite(this);
/*
    skin->add_frame(almacen.getBitmap("sprite_058"), 10, 10, 10);
    skin->add_frame(almacen.getBitmap("sprite_059"), 10, 10, 30);
    skin->add_frame(almacen.getBitmap("sprite_060"), 0, 0, 10);
    skin->add_frame(almacen.getBitmap("sprite_061"), 0, 0, 10);
    skin->add_frame(almacen.getBitmap("sprite_062"), 0, 0, 20);
*/
    skin->add_frame(almacen.get_bitmap("sprite_097"), 0, 0, 10);
    skin->add_frame(almacen.get_bitmap("sprite_098"), 0, 0, 10);
    skin->add_frame(almacen.get_bitmap("sprite_099"), 0, 0, 10);
    skin->add_frame(almacen.get_bitmap("sprite_100"), 0, 0, 10);
    skin->add_frame(almacen.get_bitmap("sprite_101"), 0, 0, 10);
    skin->add_frame(almacen.get_bitmap("sprite_102"), 0, 0, 10);
    skin->add_frame(almacen.get_bitmap("sprite_103"), 0, 0, 10);
    skin->add_frame(almacen.get_bitmap("sprite_104"), 0, 0, 10);
    skin->add_frame(almacen.get_bitmap("sprite_105"), 0, 0, 10);
    skin->add_frame(almacen.get_bitmap("sprite_106"), 0, 0, 10);
    set_actor_graphic (skin);

    setCodigo (Nombres::herny);
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

/**
 * Constructor por omisión. Mantenemos por compatibilidad.
 */
Herny::Herny ()
{
  DatFile *sprites = new DatFile("sprites3.dat");
  // ¡Cuidado! Esto falla si en el almacén no existe el bitmap que se pide.
  Sprite *skin = new Sprite(this);
  skin->add_frame(sprites->GetBitmap("jugador_01"), 0, 0, 10);
  skin->add_frame(sprites->GetBitmap("jugador_02"), 0, 0, 30);
  skin->add_frame(sprites->GetBitmap("jugador_03"), 0, 0, 10);
  skin->add_frame(sprites->GetBitmap("jugador_04"), 0, 0, 10);
  skin->add_frame(sprites->GetBitmap("jugador_05"), 0, 0, 20);
  set_actor_graphic (skin);

  setCodigo (Nombres::herny);
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
            static_cast<Sprite *>(agraph)->setMirror (true);
            break;

        case RIGHT:
            x+=1;
            static_cast<Sprite *>(agraph)->setMirror (false);
            break;
    }
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
    //DatFile *sprites = new DatFile("sprites3.dat");
    actual = siguiente;
    switch (siguiente)
    {
    case de_pie:
            set_tiempo(400);
            siguiente = cayendo;
            set_color(6);
            this->set_actor_graphic (new Bitmap (this,almacen.get_bitmap("sprite_065")));
        break;

    case cayendo:
            set_tiempo(100);
            siguiente = de_pie;
            set_color(3);
            this->set_actor_graphic (new Bitmap (this,almacen.get_bitmap("sprite_069")));
         break;

    default:
        break;
    }
}

/**
 * \brief   Cambia el estado del jugador. Mantenemos por compatibilidad.
 */
void Herny::CambiarEstado ()
{
    DatFile *sprites = new DatFile("sprites3.dat");
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
   switch (who->getCodigo ())
   {
       case Nombres::pelota:
//           estado = Herny::eliminar;
           break;
       default:
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

/**
 * \brief   Obtiene el nombre en forma de cadena de texto.
 */
void  Herny::getNombre (string &strNombre) const
{
  strNombre = Nombres::Imprimir (nombre);
};

string  Herny::getNombre () const
{
  return Nombres::Imprimir (nombre);
};
