
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

#include <list>
#include "Escenario.h"
#include "ActorManager.h"

/**
 * \brief		Constructor de la clase. Esta clase NO ES NECESARIA, esta función la realiza y la debe realizar la clase StageManager.
 */
Escenario::Escenario ()
{
	// Inicializamos el marco de prueba.
	marco.set_xy (0,0);
	marco.set_wh (320,200);

	// Tomamos la pantalla completa como escena del escenario.
	// \todo "screen" es una variable global de allegro, no se debería utilizar
	//          aquí, sino en la inicialización de las variables de allegro,
	//          de esta forma se independiza la clase de las bibliotecas de Allegro.
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
		marco.set_xy (x,y);
}

/**
 * \brief	Dibuja los actores y los decorados que se encuentran en ese momento
 *			dentro del escenario.
 */
void Escenario::Draw (ActorManager actorManager)
{
	std::list<Actor*>  listaActoresDibujar;

	// Se comprueba la intersección del bloque del escenario con los bloques
	// de los actores. Esta acción se le pide que la realice el actorManager y éste devuelve una
	// lista de actores a dibujar.
	listaActoresDibujar = actorManager.get_actores (marco);

	// Se recorre la lista de actores y se dibuja en la pantalla.
	// 		Si listaActoresDibujar fuera una clase se usaría la acción: listaActoresDibujar.Draw (pantalla);
	// 		En este caso debemos realizar el bucle la clase Escenario.

}
