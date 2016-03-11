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

#include "MenuALG.h"

MENU MenuALG::prueba_menu [] =
{
   { "&Mover",          NULL,   NULL,  0,   NULL  },
   { "&Tamaño",         NULL,   NULL,  0,   NULL  },
   { "&Propiedades",    NULL,   NULL,  0,   NULL  },
   { NULL,              NULL,   NULL,  0,   NULL  }
};

//MENU MenuALG::item_fin = {NULL, NULL, NULL, 0, NULL};


 MENU MenuALG::item_fin [] =
{
    { "&Fichero",  NULL, MenuALG::prueba_menu,  0,   NULL},
    { "&Editar",    NULL,  NULL,  0,   NULL},
    { "&Ayuda",    NULL,  NULL,  0,   NULL},
    { NULL,          NULL,  NULL,  0,   NULL}
};


MenuALG::MenuALG ()
{
	// Inicializamos la lista de items (opciones de menu).
	// items.push_back  (item_fin);	

	// Inicializamos la parte de menu.
	control.proc = d_menu_proc;
	control.x=control.y=100;
	control.h=control.w=100;
	control.fg = makecol(255,255,255);
	control.bg = makecol(128,128,128);

	// NO FUNCIONA --- Al contrario que en "do_dialog" en el enlace por puntero
	//                           dado por el "vector<MENU>" no funciona.
	// SI FUNCIONA -- Sin embargo sí funciona si hacemos un "do_menu" directamente.
	//                         Este puntero es el que no va... posiblemente porque necesita tener instanciado
	//                         el objeto. Sería mejor desviar el  "d_menu_proc" por un "MenuALg::callback"
	//                         estático y comprobar si el objeto está instanciado.
	control.dp =  item_fin; //&items[0]
	control.dp2 = NULL;
	control.dp3 = NULL;
	control.flags = 0;

	// De prueba
//	items.push_back  (item_fin[0]);	
//	items.push_back  (item_fin[1]);	
//	items.push_back  (item_fin[2]);	
	items.push_back  (item_fin[3]);
};

MenuALG::~MenuALG ()
{
};

void	MenuALG::draw ()
{
	// Dibujar al padre (comprobar que tiene padre).
	// object_message (padre,MSG_DRAW,0);

	// Y luego te dibujas tú por encima de tu padre.
	object_message (&control, MSG_DRAW, 0);
	//do_dialog (&control,-1);
}

void MenuALG::add (ItemALG item)
{
	items.pop_back ();
	items.push_back (item);
//	items.push_back (prueba_menu[3]);
//	items.push_back (prueba_menu[2]);
	items.push_back  (item_fin[3]);
}
