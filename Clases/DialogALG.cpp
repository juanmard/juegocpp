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

// Se inicializa la variable estática que marca el fin de los controles.
DIALOG DialogALG::control_fin = {NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL};

DialogALG::DialogALG ()
{
	// Se pone el "control" terminador para Allegro.
	controles.push_back  (control_fin);	
};

DialogALG::~DialogALG ()
{
};

void	DialogALG::show ()
{
	// No podemos usar "do_dialog" y generamos nuestra propia función.
	// allegro_message ("prueba[0]: %d\nprueba[1]: %d\nprueba[2]: %d\n", prueba[0], prueba[1], prueba[2]);

//	for ( iter=controles.begin() ; iter < controles.end(); iter++ )
//	{
//		object_message (*iter, MSG_DRAW, 0);
//	}
//	allegro_message ("Pausa para pruebas.");

	allegro_message ("prueba[0]: %d\nprueba[1]: %d\nprueba[2]: %d\n", controles[0].proc, controles[1].proc, controles[2].proc);
	do_dialog (&controles[0],-1);
}

void DialogALG::add (ControlALG control)
{
	controles.pop_back ();
	controles.push_back (control);
	controles.push_back  (control_fin);
};
