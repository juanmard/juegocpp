/*
 * linux
 * Copyright (C) Juanma Rico 2010 <juanmard@gmail.com>
 *
 */

#pragma once

#include <allegro.h>
#include "Bloque.h"

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
/**
 * \brief  Estructura para bloque.
 * \todo   Generalizar esta estructura en una clase e incluirla en el resto de clases.
 *
typedef struct {
	int  x, y;
	int  w, h;
} Bloque;
*/

public:
			Escenario		();
			~Escenario		();
	void 	Mover			(int x, int y);
	void 	Draw 			(ActorManager actorManager);

private:
	Bloque  marco;
	BITMAP 	*pantalla;
};

