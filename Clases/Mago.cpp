/*
 * linux
 * Copyright (C) Juanma Rico 2010 <juanmard@gmail.com>
 * 
 */

#include "Mago.h"
#include "ControllableActor.h"
#include "Almacen.h"
#include "Sprite.h"


/**
 * \brief    Constructor por omisión.
 */
Mago::Mago (Almacen &almacen):
estado(andando),
estado_sig(andando),
timer(0),
gravedad (10)
{
  // Guardamos el sprite para cada estado.
  // ¡Cuidado! Esto falla si en el almacén no existe el bitmap que se pide.
  sprites[andando] = new Sprite(this);
  sprites[andando]->add_frame(almacen.GetBitmap("ben10_002"), 0, 0, 10);
  sprites[andando]->add_frame(almacen.GetBitmap("ben10_003"), 0, 0, 10);
  sprites[andando]->add_frame(almacen.GetBitmap("ben10_004"), 0, 0, 10);
  sprites[andando]->add_frame(almacen.GetBitmap("ben10_005"), 0, 0, 10);
  sprites[andando]->init ();

  sprites[esperando] = new Sprite(this);
  sprites[esperando]->add_frame(almacen.GetBitmap("ben10_000"), 0, 0, 10);
  sprites[esperando]->init ();

  sprites[cayendo] = new Sprite(this);
  sprites[cayendo]->add_frame(almacen.GetBitmap("ben10_021"), 0, 0, 10);
  sprites[cayendo]->init ();

  sprites[disparando] = new Sprite(this);
  sprites[disparando]->add_frame(almacen.GetBitmap("ben10_010"), 15, -4, 10);
  sprites[disparando]->add_frame(almacen.GetBitmap("ben10_011"), 15, -4, 8);
  sprites[disparando]->add_frame(almacen.GetBitmap("ben10_012"), 15, -4, 10);
  sprites[disparando]->init ();

  sprites[saltando] = new Sprite(this);
  sprites[saltando]->add_frame(almacen.GetBitmap("ben10_016"), 0, 0, 10);
  sprites[saltando]->init ();

  set_actor_graphic (sprites[estado]);
  set_name (Nombres::mago);
  set_x(SCREEN_W/3);
  set_y(SCREEN_H/2);
  set_is_detected (false);
  set_collision_method(CollisionManager::PP_COLLISION);
  set_wh (21,60);
};

/**
 * \brief   Acciones del mago.
 */
void Mago::do_action (ControllableActor::action_t act, int magnitude)
{
  switch (act)
  {
    case DOWN:
      break;

    case UP:
      if ((estado!=saltando) && (estado!=cayendo))
      {
        sprites[saltando]->setMirror(sprites[estado]->getMirror ());
        estado = saltando;
        timer = 50;
        estado_sig = cayendo;
        gravedad = 10;
      }
      break;

    case LEFT:
      if (estado == esperando)
      {
        sprites[estado]->setMirror (true);
        estado = andando;
      }
      sprites[estado_sig]->setMirror (true);
      sprites[estado]->setMirror (true);
      x-=2;
      break;

    case RIGHT:
        if (estado == esperando)
        {
          sprites[estado]->setMirror (false);
          estado = andando;
        }
        sprites[estado_sig]->setMirror (false);
        sprites[estado]->setMirror (false);
        x+=2;
        break;

    case JUMP:
        if ((estado!=saltando) && (estado!=cayendo))
        {
          sprites[disparando]->setMirror(sprites[estado]->getMirror ());
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
  set_actor_graphic (sprites[estado]);

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

  // Actualiza los estados dependientes de otros estados.
  switch (estado)
  {
    case cayendo:
      y+=gravedad/3;
      if (y>1400)
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
      break;

    case andando:
      if (gravedad != 0) estado = cayendo;
      gravedad = 10;
      break;

    case saltando:
      y-=2;
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
  switch (who->get_name())
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
          y = who->get_y () - h;
          estado = esperando;
        }
        break;
  }
}

