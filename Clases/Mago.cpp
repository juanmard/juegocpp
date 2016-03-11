/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
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
 * \brief	Constructor por omisión.
 */
Mago::Mago (Almacen &almacen):
estado(andando),
estado_sig(andando),
timer(0)
{
	// Guardamos el sprite para cada estado.
    // ¡Cuidado! Esto falla si en el almacén no existe el bitmap que se pide.
	sprites[andando] = new Sprite(this);    
    sprites[andando]->add_frame(almacen.GetBitmap("sprite_088"), 0, 0, 10);
	sprites[andando]->init ();
	
	sprites[esperando] = new Sprite(this);    
    sprites[esperando]->add_frame(almacen.GetBitmap("sprite_084"), 0, 0, 10);
    sprites[esperando]->add_frame(almacen.GetBitmap("sprite_084"), 2, 0, 10);
	sprites[esperando]->init ();

	sprites[cayendo] = new Sprite(this);    
    sprites[cayendo]->add_frame(almacen.GetBitmap("sprite_089"), 0, 0, 10);
	sprites[cayendo]->init ();

	sprites[disparando] = new Sprite(this);    
    sprites[disparando]->add_frame(almacen.GetBitmap("sprite_085"), 0, 0, 2);
    sprites[disparando]->add_frame(almacen.GetBitmap("sprite_088"), 0, 0, 4);
	sprites[disparando]->init ();

	set_actor_graphic (sprites[estado]);
	set_name (Nombres::mago);
    set_x(SCREEN_W/3);
    set_y(SCREEN_H/2);
	set_is_detected (false);
    set_collision_method(CollisionManager::PP_COLLISION);
    set_wh (40,42);
};

/**
 * \brief	Acciones del mago.
 */
void Mago::do_action (ControllableActor::action_t act, int magnitude)
{
    switch (act)
    {
        case DOWN:
			y+=1;
			break;

		case UP:
		    if (estado==esperando) estado=andando;
			y-=1;
			break;

		case LEFT:
		  x-=1;
		  sprites[estado]->setMirror (true);
		  break;
			
        case RIGHT:
		  x+=1;
		  sprites[estado]->setMirror (false);
		  break;
			
        case JUMP:  
		  y-=4; 
		  estado=cayendo;
		  break;
			
        case SPELL:
		  estado = disparando;
		  break;
    }
}

/**
 * \brief	Actualizamos los estados del mago.
 */
void Mago::update ()
{
  // Actualiza la parte gráfica.
  agraph->update();

  // Actualiza los estados dependientes del temporizador.
  // \todo	Generalizar este proceso para la clase Actor.
  if (timer)
  {
    timer--;
    if (timer == 0)
    {
      estado = estado_sig;
    }
  }
  else
  {
	// Actualiza los estados dependientes de otros estados.
	switch (estado)
	{
		case cayendo:
			// Comprobar que no hay intersección con suelo.
			// Si hay intersección con suelo, alinear y cambiar a estado "esperando".
			// Si no hay intersección disminuir la posición en altura según la gravedad
			// existente.
			y+=1;
			if (y>360) estado = esperando;
			break;
			
		case esperando:
			// Se comprueba que hay suelo bajo él.
			// Si no hay suelo se cambia el estado a 'cayendo'.
			// Se activa un temporizador, si pasa el tiempo del temporizador se
			// cambia el estado a 'entretenido'.
			break;

		case andando:
			break;

		case disparando:
			timer = 100;
			estado_sig = andando;
			break;
	}
  }
		
  // Actualiza el sprite según el estado.
  set_actor_graphic (sprites[estado]);
}
