/*
 * linux
 * Copyright (C) Juanma Rico 2010 <juanmard@gmail.com>
 *
 */

#include "Mago.h"
#include "ControllableActor.h"
#include "Almacen.h"
#include "Sprite.h"

namespace fwg {

Mago::Mago ():
ControllableActor()
{
};

/**
 * \brief    Constructor por omisión.
 */
Mago::Mago (Almacen &almacen):
estado(andando),
estado_sig(andando),
timer(0),
gravedad (10),
sentido(1)
{
  // Guardamos el sprite para cada estado.
  // ¡Cuidado! Esto falla si en el almacén no existe el bitmap que se pide.
  sprites[andando_der] = new Sprite(this);
  sprites[andando_der]->addFrame(almacen.get_bitmap("ben10_002"), 0, 0, 10);
  sprites[andando_der]->addFrame(almacen.get_bitmap("ben10_003"), 0, 0, 10);
  sprites[andando_der]->addFrame(almacen.get_bitmap("ben10_004"), 0, 0, 10);
  sprites[andando_der]->addFrame(almacen.get_bitmap("ben10_005"), 0, 0, 10);
  sprites[andando_der]->init ();

  sprites[andando_izq] = new Sprite(this);
  sprites[andando_izq]->addFrame(almacen.get_bitmap("ben10_006"), 0, 0, 10);
  sprites[andando_izq]->addFrame(almacen.get_bitmap("ben10_007"), 0, 0, 10);
  sprites[andando_izq]->addFrame(almacen.get_bitmap("ben10_008"), 0, 0, 10);
  sprites[andando_izq]->addFrame(almacen.get_bitmap("ben10_009"), 0, 0, 10);
  sprites[andando_izq]->init ();

  sprites[esperando_der] = new Sprite(this);
  sprites[esperando_der]->addFrame(almacen.get_bitmap("ben10_000"), 0, 0, 10);
  sprites[esperando_der]->init ();

  sprites[esperando_izq] = new Sprite(this);
  sprites[esperando_izq]->addFrame(almacen.get_bitmap("ben10_001"), 0, 0, 10);
  sprites[esperando_izq]->init ();

  sprites[cayendo_der] = new Sprite(this);
  sprites[cayendo_der]->addFrame(almacen.get_bitmap("ben10_021"), 0, 0, 10);
  sprites[cayendo_der]->init ();

  sprites[cayendo_izq] = new Sprite(this);
  sprites[cayendo_izq]->addFrame(almacen.get_bitmap("ben10_020"), 0, 0, 10);
  sprites[cayendo_izq]->init ();

  sprites[disparando_der] = new Sprite(this);
  sprites[disparando_der]->addFrame(almacen.get_bitmap("ben10_010"), 15, -4, 10);
  sprites[disparando_der]->addFrame(almacen.get_bitmap("ben10_011"), 15, -4, 8);
  sprites[disparando_der]->addFrame(almacen.get_bitmap("ben10_012"), 15, -4, 10);
  sprites[disparando_der]->init ();

  sprites[disparando_izq] = new Sprite(this);
  sprites[disparando_izq]->addFrame(almacen.get_bitmap("ben10_013"), 15, -4, 10);
  sprites[disparando_izq]->addFrame(almacen.get_bitmap("ben10_014"), 15, -4, 8);
  sprites[disparando_izq]->addFrame(almacen.get_bitmap("ben10_015"), 15, -4, 10);
  sprites[disparando_izq]->init ();

  sprites[saltando_der] = new Sprite(this);
  sprites[saltando_der]->addFrame(almacen.get_bitmap("ben10_016"), 0, 0, 10);
  sprites[saltando_der]->init ();

  sprites[saltando_izq] = new Sprite(this);
  sprites[saltando_izq]->addFrame(almacen.get_bitmap("ben10_017"), 0, 0, 10);
  sprites[saltando_izq]->init ();

  Sprites_t sprite_act = estado2Sprite (estado);
  setActorGraphic (sprites[sprite_act]);
  setCodigo (Nombres::mago);
  setX (SCREEN_W/3);
  setY (SCREEN_H/2);
  setIsDetected (false);
  setCollisionMethod (CollisionManager::PP_COLLISION);
  setWH (21,60);
};

/**
 * \brief   Acciones del mago.
 */
void Mago::doAction (ControllableActor::Action act, int magnitude)
{
  switch (act)
  {
    case DOWN:
        break;

    case UP:
        if ((estado!=saltando) && (estado!=cayendo))
        {
          estado = saltando;
          timer = 50;
          estado_sig = cayendo;
          gravedad = 10;
        }
        break;

    case LEFT:
        if (estado == esperando)
        {
          estado = andando;
        }
        sentido = -1;
        x-=2;
        break;

    case RIGHT:
        if (estado == esperando)
        {
          estado = andando;
        }
        sentido = 1;
        x+=2;
        break;

    case JUMP:
        if ((estado!=saltando) && (estado!=cayendo))
        {
          estado = disparando;
        }
        break;

    case SPELL:
        break;
  }
}

/**
 * \brief   Actualizamos los estados del mago.
 */
void Mago::update ()
{
  // Actualiza el sprite según el estado.
  setActorGraphic (sprites[estado2Sprite(estado)]);

  // Actualiza la parte gráfica.
  agraph->update();

  // Actualiza los estados dependientes del temporizador.
  // \todo  Generalizar este proceso para la clase Actor.
  if (timer)
  {
    timer--;
    if (timer == 0)
    {
      estado = estado_sig;
    }
  }

  // Actualiza las propiedades según los estados.
  switch (estado)
  {
    case cayendo:
        y += gravedad/3;
        if (y > 1400)
        {
          y = 1400;
          estado = disparando;
          timer = 100;
          estado_sig = saltando;
        }
        // {
        // Comprobar que no hay intersección con suelo.
        //  - Creamos un bloque temporal por debajo del jugador.
        //Bloque debajo (x,y+h,w,10);
        //  - Comprobamos las intersecciones del bloque con los bloques de los
        //    actores.
        //if (debajo.isInterseccionado (actorManager, suelo));
        // Si hay intersección con suelo, alinear y cambiar a estado "esperando".
        // Si no hay intersección disminuir la posición en altura según la gravedad
        // existente.
        //}
        break;

    case esperando:
        // Se comprueba que hay suelo bajo él.
        // Si no hay suelo se cambia el estado a 'cayendo'.
        // Se activa un temporizador, si pasa el tiempo del temporizador se
        // cambia el estado a 'entretenido'.
        //break;

    case andando:
        if (gravedad != 0) estado = cayendo;
        gravedad = 10;
        break;

    case saltando:
        y -= 2;
        if (y < 0)
        {
          estado = cayendo;
          y = 0;
        }
        break;

    case disparando:
        break;
  }
}

/**
 * \brief   Intersección del mago con otro actor de la escena.
 * \param   who       Puntero al actor que provoca la colisión.
 * \param   damage    Daño que se produce en la colisión.
 */
void  Mago::hit  (Actor *who, int damage)
{
  switch (who->getCodigo ())
  {
    case Nombres::pelota:
    case Nombres::paleta:
    case Nombres::herny:
        if (estado == saltando)
        {
          estado = cayendo;
          gravedad = 10;
        }
        else
        {
          // El suelo anula la gravedad propia del mago.
          // \todo  Generalizar para todos los actores.
          gravedad = 0;
          y = who->getY () - h;
          estado = esperando;
        }
        break;
    default:
        break;
  }
}

/**
 * \brief   Transforma un estado en un tipo 'sprite' según el estado pasado como
 *          parámetro y las propiedades internas actuales de Ben.
 * \param   estado_act    Estado que se quiere convertir.
 * \return  Devuelve el enumerado sprite que corresponde actualmente a ese estado.
 */
Mago::Sprites_t  Mago::estado2Sprite (Estados_t estado_act) const
{
  Sprites_t sprite_act;

  switch (estado_act)
  {
    case esperando:
        if (sentido > 0) sprite_act = esperando_der; else sprite_act = esperando_izq;
        break;

    case andando:
        if (sentido > 0) sprite_act = andando_der; else sprite_act = andando_izq;
        break;

    case cayendo:
        if (sentido > 0) sprite_act = cayendo_der; else sprite_act = cayendo_izq;
        break;

    case disparando:
        if (sentido > 0) sprite_act = disparando_der; else sprite_act = disparando_izq;
        break;

    case saltando:
        if (sentido > 0) sprite_act = saltando_der; else sprite_act = saltando_izq;
        break;

    default:
        break;
  }
  return sprite_act;
}
}