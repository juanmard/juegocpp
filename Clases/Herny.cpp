#include "Herny.h"
#include "Almacen.h"
#include "Bitmap.h"

namespace fwg {
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
    skin = dynamic_cast<Sprite*>(agraph);
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
    skin->addFrame(almacen.getBitmap("sprite_058"), 10, 10, 10);
    skin->addFrame(almacen.getBitmap("sprite_059"), 10, 10, 30);
    skin->addFrame(almacen.getBitmap("sprite_060"), 0, 0, 10);
    skin->addFrame(almacen.getBitmap("sprite_061"), 0, 0, 10);
    skin->addFrame(almacen.getBitmap("sprite_062"), 0, 0, 20);
*/
    skin->addFrame(almacen.get_bitmap("sprite_097"), 0, 0, 10);
    skin->addFrame(almacen.get_bitmap("sprite_098"), 0, 0, 10);
    skin->addFrame(almacen.get_bitmap("sprite_099"), 0, 0, 10);
    skin->addFrame(almacen.get_bitmap("sprite_100"), 0, 0, 10);
    skin->addFrame(almacen.get_bitmap("sprite_101"), 0, 0, 10);
    skin->addFrame(almacen.get_bitmap("sprite_102"), 0, 0, 10);
    skin->addFrame(almacen.get_bitmap("sprite_103"), 0, 0, 10);
    skin->addFrame(almacen.get_bitmap("sprite_104"), 0, 0, 10);
    skin->addFrame(almacen.get_bitmap("sprite_105"), 0, 0, 10);
    skin->addFrame(almacen.get_bitmap("sprite_106"), 0, 0, 10);
    setActorGraphic (skin);

    setCodigo (Nombres::herny);
    setX (SCREEN_W/2);
    setY (SCREEN_H/2);
	setIsDetected (true);
    //setTeam (ENEMY);
    setCollisionMethod (CollisionManager::PP_COLLISION);
    setWH (26,36);

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
  skin->addFrame(sprites->GetBitmap("jugador_01"), 0, 0, 10);
  skin->addFrame(sprites->GetBitmap("jugador_02"), 0, 0, 30);
  skin->addFrame(sprites->GetBitmap("jugador_03"), 0, 0, 10);
  skin->addFrame(sprites->GetBitmap("jugador_04"), 0, 0, 10);
  skin->addFrame(sprites->GetBitmap("jugador_05"), 0, 0, 20);
  setActorGraphic (skin);

  setCodigo (Nombres::herny);
  setX (SCREEN_W/2);
  setY (SCREEN_H/2);
  setIsDetected (true);
  //setTeam (ENEMY);
  setCollisionMethod (CollisionManager::PP_COLLISION);
  setWH (26,36);

  //    tiempoEstado = 400;
  //    tiempoEstado = 0; //Desactivamos el jugador para pruebas.
  actual = Herny::de_pie;
  siguiente = Herny::cayendo;
}

void Herny::doAction (ControllableActor::Action act, int magnitude)
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
            static_cast<Sprite*>(agraph)->setMirror (true);
            break;

        case RIGHT:
            x+=1;
            static_cast<Sprite*>(agraph)->setMirror (false);
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
        setY (getY () + 1);
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
            setTiempo (400);
            siguiente = cayendo;
            setColor (6);
            this->setActorGraphic (new Bitmap (this,almacen.get_bitmap("sprite_065")));
        break;

    case cayendo:
            setTiempo (100);
            siguiente = de_pie;
            setColor (3);
            this->setActorGraphic (new Bitmap (this,almacen.get_bitmap("sprite_069")));
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
            setTiempo (400);
            siguiente = cayendo;
            setColor (6);
            this->setActorGraphic (new Bitmap (this,sprites->GetBitmap("jugador_01")));
        break;

    case cayendo:
            setTiempo (100);
            siguiente = de_pie;
            setColor (3);
            this->setActorGraphic (new Bitmap (this,sprites->GetBitmap("jugador_15")));
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
void  Herny::getNombre (std::string& strNombre) const
{
  strNombre = Nombres::Imprimir (nombre);
};

std::string  Herny::get_nombre () const
{
  return Nombres::Imprimir (nombre);
};
}