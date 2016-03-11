/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * linux
 * Copyright (C) Juanma Rico 2010 <juanmard@gmail.com>
 * 
 * linux is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * linux is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "DatFile.h"
#include "Almacen.h"

Almacen::Almacen (string nombreFichero):
fichero (nombreFichero)
{
};

Almacen::Almacen ()
{
};

Almacen::~Almacen ()
{
	// Liberar los recursos del fichero.
};

/*
 * \brief	Devuelve el bitmap dado por el nombre.
 */
BITMAP *Almacen::GetBitmap (string name)
{
	return (fichero.GetBitmap(name));
};

