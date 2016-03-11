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

#include "DialogALG.h"

DialogALG::DialogALG (DIALOG *padre_rec)
{
	padre=padre_rec;
	yo.proc = d_shadow_box_proc;
	yo.x=yo.y=100;
	yo.h=yo.w=100;
	yo.fg = makecol(255,255,255);
	yo.bg = makecol(128,128,128);
	yo.dp = NULL;
	yo.dp2 = NULL;
	yo.dp3 = this;
	yo.flags = 0;
};

DialogALG::~DialogALG ()
{
};

void	DialogALG::show ()
{
	// Si no tiene padre, el hace de padre para el resto.
	if (!padre)
	{
		do_dialog (&yo,-1);
	}
	else
	{
		// Envía un mensaje para que el padre se dibuje.
			// objetct_message (padre, MSG_DRAW, 0);

		// Luego se dibuja él.
			// objetct_message (&yo, MSG_DRAW, 0);
	}
}
