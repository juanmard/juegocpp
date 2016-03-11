#pragma once

/* Define la compilación de forma estática.
 * \todo Automatizar esto en el marco de trabajo ("FrameWork") para
 *       que pueda ser elegido desde "Game.cpp".
#define ALLEGRO_STATICLINK
*/
#include <allegro.h>
#include "AirCraft.h"
#include "Game.h"
#include "Actor.h"
#include "ActorManager.h"
#include "ControllableActor.h"
#include "Control.h"
#include "Keyboard.h"
#include <ctime>
#include <cstdlib>
#include "Bitmap.h"
#include "Sprite.h"
#include "DatFile.h"
#include "Herny.h"
#include "Mosaico.h"
#include "Suelo.h"
#include "Pelota.h"
#include "Paleta.h"
#include "Ladrillo.h"
#include "EditorManager.h"

class JuegoPrueba :	public Game
{
	public:
		void main();
};
