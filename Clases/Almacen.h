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

#ifndef _ALMACEN_H_
#define _ALMACEN_H_

#include <allegro.h>
#include <string>

using namespace std;

/**
 * \class   Almacen
 * \brief   Clase que maneja los recursos gráficos y de sonido.
 * \todo   
 *          - Crear métodos "GetSample" y "SetSample" para manejo de sonidos.
 */
class Almacen
{
public:
				Almacen		(string paramNombreFichero);
				Almacen		();
				~Almacen	();
	BITMAP *	GetBitmap	(string paramNombreRecurso);
	BITMAP *	GetBitmap	(int indice);
    RGB	*       GetPalette  (string nombrePaleta);

protected:

private:
    DATAFILE *  fichero;
    string      nombreFichero;
};

#endif // _ALMACEN_H_
