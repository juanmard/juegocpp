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

#pragma once

#include <allegro.h>
#include <list>
using namespace std;

class Actor;
class ActorManager;

/**
 * \brief		Clase que implementa la estructura del escenario en el juego.
 * \details		Se trata de generalizar el concepto de Bitmap de Allegro para la
 *				pantalla. Disponemos de un marco que nos sitúa el escenario en
 *				una posición del plano del juego (el espacio de un 'int'). Y de un
 *			    BITMAP que nos indica la zona de la pantalla que se verá finalmente.
 *				Este BITMAP es una clase de allegro y será toda o una parte del
 *              del BITMAP 'screen' de Allegro (sería la escena que ve el público).
 */
class Escenario
{

public:
/* \brief	Estructura para bloque.
 * \todo	Generalizar esta estructura en una clase e incluirla en el resto de clases.
 */
typedef struct {
	int  x, y;
	int  w, h;
} Bloque;
	
public:
			Escenario		();
			~Escenario		();
	void 	Mover			(int x, int y);
	void 	Draw 			(ActorManager actorManager);

private:
	Bloque 		marco;
	BITMAP 	*pantalla;
};

