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

#include "ItemALG.h"

ItemALG::ItemALG (string texto_rec)
{
    texto = texto_rec;
	item.text = const_cast<char *>(texto.data());
	item.proc = NULL;
	item.child = NULL;
	item.flags = 0;
	item.dp = this;
	menu_hijo = NULL;
};

ItemALG::ItemALG ()
{
	item.text = const_cast<char *>("&Menu prueba");
	item.proc = NULL;
	item.child = NULL;
	item.flags = 0;
	item.dp = this;
	menu_hijo = NULL;
};

ItemALG::~ItemALG ()
{
};

void ItemALG::add (MenuALG nuevo)
{
    // Esto falla, pues es posible que la variable "nuevo" se pierda.
    // Lo más lógico es crear un objeto de MenuALG nuevo con "new" e igualarlo al objeto
    // recibido como parámetro (al igual que pasaba con el texto del item).
    menu_hijo = &nuevo;
	item.child = *menu_hijo;
};
