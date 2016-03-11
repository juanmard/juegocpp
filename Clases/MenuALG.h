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

#ifndef  _MenuALG_H_
#define _MenuALG_H_

#include <vector>
#include  "ControlALG.h"
#include  "ItemALG.h"

class ItemALG;

class MenuALG : public ControlALG
{
public:
						MenuALG 	();
						~MenuALG  ();
	operator 	DIALOG &() {return control;};
	operator 	MENU *() {return &items[0];};	
//	operator 	void *() {return &items[0];};
	void 			add (ItemALG item);

	virtual void		draw ();

protected:
	vector<MENU>::iterator 		iter;
	vector<MENU>				items;
	static	MENU				item_fin[];
	//static	MENU			item_fin;
	static	MENU				prueba_menu[];

    /**
     * Call back de la clase.
     */
    static  int callback (int msg, DIALOG *d, int c)
    {
        // Si ya está inicializado el objeto...
        if (d[0].dp3)
        {
            MenuALG *obj = static_cast<MenuALG *>(d[0].dp3);
            // Seleccionamos los mensajes.
            switch (msg)
            {
            case MSG_START:
                // Inicializamos el menu para enviar al procedimiento predeterminado.
                d[0].dp = &(obj->items[0]);
                break;
            }
        }
        return d_menu_proc (msg,d,c);
    };
};

#endif 
