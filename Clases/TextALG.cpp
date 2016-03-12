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

#include "TextALG.h"

TextALG::TextALG ()
{
	control.proc = d_text_proc;
	control.x=control.y=100;
	control.h=control.w=100;
	control.fg = makecol(255,255,255);
	control.bg = makecol(128,128,128);
	control.dp =  static_cast<char *>("Prueba");
	control.dp2 = NULL;
	control.dp3 = this;
	control.flags = 0;
};

TextALG::~TextALG ()
{
};

void	TextALG::draw ()
{
	// Dibujar al padre (comprobar que tiene padre).
	// object_message (padre,MSG_DRAW,0);

	// Y luego te dibujas tú por encima de tu padre.
	object_message (&control, MSG_DRAW, 0);
	//do_dialog (&control,-1);
}
