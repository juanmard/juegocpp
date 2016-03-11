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

#ifndef _ControlALG_H_
#define _ControlALG_H_

#include <allegro.h>
#include  "DialogALG.h"

class DialogALG;

class ControlALG
{
public:
								ControlALG 		(DialogALG *padre);
								ControlALG 		();
								~ControlALG  	();
								// Conversor de tipos para DIALOG.
									operator DIALOG &() {return control;};
	virtual void		draw				();
	void						set_xy (int x, int y);

// Pruebas para ControlALG terminador. Lo mejor sería que lo pusiera el diálogo que lo vaya a usar.
								 void		set_NULL (){control.proc=NULL;};

	
protected:
	DIALOG	    control;
	DialogALG     *padre;
};

#endif // _ControlALG_H_
