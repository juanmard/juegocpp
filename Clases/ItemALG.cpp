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

ItemALG::ItemALG (string text)
{
	item.text = const_cast<char *>(text.c_str());
	item.proc = NULL;
	item.child = NULL;
	item.flags = 0;
	item.dp = this;
};

ItemALG::ItemALG ()
{
	item.text = "&Menu prueba";
	item.proc = NULL;
	item.child = NULL;
	item.flags = 0;
	item.dp = this;
};

ItemALG::~ItemALG ()
{
};

