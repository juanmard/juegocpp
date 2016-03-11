/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * linux
 * Copyright (C) Juanma Rico 2010 <juanmard@gmail.com>
 * 
 */

#ifndef _MAGO_H_
#define _MAGO_H_

#include "ControllableActor.h"
#include "Almacen.h"
#include "Sprite.h"

class Mago : public ControllableActor 
{
  public:
	// Definición de acciones del Mago.
	typedef enum {DOWN, UP, LEFT, RIGHT, JUMP, SPELL} action_t;

  public:
			Mago		(Almacen &almacen);
	void	do_action	(ControllableActor::action_t act, int magnitude);

  protected:

  private:
		Sprite *skin;
};

#endif // _MAGO_H_
