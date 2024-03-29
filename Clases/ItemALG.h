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

#ifndef _ItemALG_H_
#define _ItemALG_H_

#include <allegro.h>
#include <string>
#include  "MenuALG.h"

using std::string;

class MenuALG;

class ItemALG
{
public:
			    ItemALG 		(string texto);
			    ItemALG 		();
			    ~ItemALG  	    ();
                operator MENU & () {return item;};
    void        add             (MenuALG nuevo);

	
protected:
    string          texto;
	MenuALG     *menu_hijo;
    MENU		    item;

};

#endif // _ItemALG_H_
