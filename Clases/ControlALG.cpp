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

#include "ControlALG.h"

ControlALG::ControlALG (DialogALG *padre_rec)
{
	padre=padre_rec;
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

ControlALG::ControlALG ()
{
	padre=NULL;
	control.flags=0;
	control.dp3=this;
};

ControlALG::~ControlALG ()
{
};

void	ControlALG::draw ()
{
}
