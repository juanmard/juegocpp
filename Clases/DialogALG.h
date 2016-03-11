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

#ifndef _DIALOGALG_H_
#define _DIALOGALG_H_

#include  <allegro.h>
#include <vector>
#include "ControlALG.h"

using namespace std;

class ControlALG;

class DialogALG
{
public:
	DialogALG 		();
	~DialogALG  	();
	void		show 	();
	void     add		(ControlALG control);
	
protected:
	vector<DIALOG >::iterator 		iter;
	vector<DIALOG >						controles;
	static	DIALOG						control_fin;
};

#endif // _DIALOGALG_H_
