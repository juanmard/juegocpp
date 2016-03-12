/*
 * Juego++
 * Copyright (C) Juanma Rico 2009 <juanmard@gmail.com>
 */

#ifndef   MENU_H
#define   MENU_H

#include <allegro.h>
#include <vector>
#include <string>

using namespace std;

class Menu
{
  public:
            Menu              ();
            ~Menu             ();
            operator MENU *   ();
    void    add               (Menu nuevo);
//    void    add               (char * etiqueta);
    void    add               (char *etiqueta, int (*metodo)(void)=NULL, void *data_pointer=NULL, MENU *hijo=NULL, int opciones=0);

  protected:
    vector<MENU>::iterator    iter;
    vector<MENU>              items;
    static  MENU              item_fin[];

    /**
     * Call back de la clase.
     */
    static  int callback (int msg, DIALOG *d, int c)
    {
        // Si ya está inicializado el objeto...
        if (d[0].dp3)
        {
            //Menu *obj = static_cast<Menu *>(d[0].dp3);
            // Seleccionamos los mensajes.
            switch (msg)
            {
            case MSG_START:
                // Inicializamos el menu para enviar al procedimiento predeterminado.
//                d[0].dp = &(obj->items[0]);
                break;
            }
        }
        return d_menu_proc (msg,d,c);
    };
};

#endif
