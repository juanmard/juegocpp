/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * Juego++
 * Copyright (C) Juanma Rico 2009 <juanmard@gmail.com>
 * 
 * Juego++ is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Juego++ is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "BoxALG.h"

BoxALG::BoxALG ()
{
	control.proc = d_shadow_box_proc;
	control.x=control.y=100;
	control.h=control.w=100;
	control.fg = makecol(255,255,255);
	control.bg = makecol(128,128,128);
	control.dp = NULL;
	control.dp2 = NULL;
	control.dp3 = this;
	control.flags = 0;
};

BoxALG::~BoxALG ()
{
};

void	BoxALG::draw ()
{
	// Dibujar al padre (comprobar que tiene padre).
	// object_message (padre,MSG_DRAW,0);

	// Y luego te dibujas tú por encima de tu padre.
	object_message (&control,MSG_DRAW,0);
}
