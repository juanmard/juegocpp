///
/// @file Menu.cpp
/// @brief Fichero de implementación de la clase "Menu".
/// @author Juan Manuel Rico
/// @date Octubre 2015
/// @version 1.0.0
///

#include "Menu.h"

MENU Menu::fin_menu = {NULL, NULL, NULL, 0, NULL};

Menu::Menu ()
{
    items.push_back (fin_menu);
};

Menu::~Menu ()
{
};

void Menu::add (Menu nuevo)
{
//  items.pop_back ();
//  items.push_back (nuevo);
//  items.push_back  (item_fin[0]);
//  items.push_back  (fin_menu);
}

void Menu::add (const std::string& etiqueta, const int opciones, void* data_pointer, const MENU* hijo, int (*metodo)(void))
{
  // Se actualiza el item último con los nuevos valores.
  MENU& ultimo = items[items.size()-1];
  ultimo.text = const_cast<char*>((new std::string(etiqueta))->c_str());
  ultimo.flags = opciones;
  ultimo.dp = data_pointer;
  ultimo.child = const_cast<MENU*>(hijo);
  ultimo.proc = Menu::callback;

  // Se añade el item que simboliza el final del menú.
  items.push_back (fin_menu);
};

Menu::operator MENU* ()
{
  return &items[0];
};

