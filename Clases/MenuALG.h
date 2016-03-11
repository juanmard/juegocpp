/*
 * Juego++
 * Copyright (C) Juanma Rico 2009 <juanmard@gmail.com>
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
