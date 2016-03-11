#pragma once


/* Define la compilación de forma estática.
 * \todo Automatizar esto en el marco de trabajo ("FrameWork") para
 *       que pueda ser elegido desde "Game.cpp".

#define ALLEGRO_STATICLINK
*/

#include "Game.h"

class JuegoPrueba :	public Game
{
	public:
		void main();
};
