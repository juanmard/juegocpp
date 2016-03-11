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
Mago::Mago (Almacen &almacen)
{
    // ¡Cuidado! Esto falla si en el almacén no existe el bitmap que se pide.
    skin = new Sprite(this);    
    skin->add_frame(almacen.GetBitmap("sprite_088"), 0, 0, 10);
    set_actor_graphic (skin);

    set_name (Nombres::herny);
    set_x(SCREEN_W/3);
    set_y(SCREEN_H/2);
	set_is_detected (true);
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
        case DOWN: 	y+=1; break;
		case UP: 	y-=1; break;
        case LEFT:
		  x-=1;
		  skin->setMirror (true);
		  break;
			
        case RIGHT:
		  x+=1;
		  skin->setMirror (false);
		  break;
			
        case JUMP:  y-=4; break;
        case SPELL: y-=4; break;
    }
}
