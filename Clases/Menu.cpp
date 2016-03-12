/*
 * Juego++
 * Copyright (C) Juanma Rico 2009 <juanmard@gmail.com>
 */

#include "Menu.h"

/*
 MENU Menu::prueba_menu [] =
{
   { "&Mover",          NULL,   NULL,  0,   NULL  },
   { "&Tamaño",         NULL,   NULL,  0,   NULL  },
   { "&Propiedades",    NULL,   NULL,  0,   NULL  },
   { NULL,              NULL,   NULL,  0,   NULL  }
};
*/

//MENU Menu::item_fin = {NULL, NULL, NULL, 0, NULL};

MENU Menu::item_fin [] =
{
    {const_cast<char *>("&Fichero"),  NULL,  NULL,  0,   NULL},
    { const_cast<char *>("&Editar"),  NULL,  NULL,  0,   NULL},
    {  const_cast<char *>("&Ayuda"),  NULL,  NULL,  0,   NULL},
    {                          NULL,  NULL,  NULL,  0,   NULL}
};


Menu::Menu ()
{
  // Inicializamos la lista de items (opciones de menu).
  // Hacemos una prueba de menú.
  //items.push_back (item_fin[0]);
  //items.push_back (item_fin[1]);
  items.push_back (item_fin[3]);
};

Menu::~Menu ()
{
};

void Menu::add (Menu nuevo)
{
//  items.pop_back ();
//  items.push_back (nuevo);
//  items.push_back  (item_fin[0]);
//  items.push_back  (item_fin);
}

/**
 * \brief   Añade un nuevo item al menú.
 * \todo    Cambiar el "char *" por el tipo "string".
 *
void Menu::add (char * etiqueta)
{
  // Se elimina el item final.
  items.pop_back ();

  // Se añade el nuevo item.
  MENU *nuevo = new MENU;
  nuevo->text = etiqueta; //const_cast<char *>(etiqueta.c_str());
  nuevo->proc = NULL;
  nuevo->child = NULL;
  nuevo->flags =0;
  nuevo->dp = NULL;
  items.push_back (*nuevo);

  // Se añade el item final.
  items.push_back (item_fin[3]);
}
*/

/**
 * \brief   Añade un nuevo item al menú.
 * \todo    Cambiar el "char *" por el tipo "string".
 */
void Menu::add (char *etiqueta, int (*metodo)(void), void *data_pointer, MENU *hijo, int opciones)
{
  // Se actualiza el item último con los nuevos valores.
  MENU& ultimo = items[items.size()-1];
  ultimo.text = etiqueta; //const_cast<char *>(etiqueta.c_str());
  ultimo.proc = metodo;
  ultimo.child = hijo;
  ultimo.flags = opciones;
  ultimo.dp = data_pointer;

  // Se añade el item nulo que simboliza el final del menú.
  items.push_back (item_fin[3]);
}

/**
 * \ brief  Generamos un conversor de tipo para el tipo MENU de "Allegro".
 */
Menu::operator MENU * ()
{
  return &items[0];
};

