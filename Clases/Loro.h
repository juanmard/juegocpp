/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * linux
 * Copyright (C) Juanma Rico 2010 <juanmard@gmail.com>
 * 
 */

#ifndef _LORO_H_
#define _LORO_H_

#include "ControllableActor.h"
#include "Almacen.h"

class Loro : public ControllableActor 
{
  public:
	// Definición de acciones del loro.
	typedef enum {DOWN, UP, LEFT, RIGHT, JUMP} action_t;

  public:
			Loro		(Almacen &almacen);
	void	do_action	(ControllableActor::action_t act, int magnitude);

  protected:

  private:
	
};

#endif // _LORO_H_
