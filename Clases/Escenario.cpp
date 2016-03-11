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

#include "Escenario.h"

/**
 * \brief		Constructor de la clase.
 */
Escenario::Escenario ()
{
	// Inicializamos el marco de prueba.
	marco.x = 0;
	marco.y = 0;
	marco.w = 320;
	marco.h = 200;
	
	// Tomamos la pantalla completa como escena del escenario.
	pantalla = screen;
};

/**
 * \brief		Destructor de prueba.
 */
Escenario::~Escenario()
{};

/**
 * \brief		Mueve el marco del escenario por el espacio del juego.
 */
void Escenario::Mover (int x, int y)
{
		marco.x = x;
		marco.y = y;
}

