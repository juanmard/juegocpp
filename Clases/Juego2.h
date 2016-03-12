#pragma once

/* Define la compilación de forma estática.
 * \todo Automatizar esto en el marco de trabajo ("FrameWork") para
 *       que pueda ser elegido desde "Game.cpp".

#define ALLEGRO_STATICLINK
*/

#include "Game.h"
#include "Mapa.h"
#include  <allegro.h>
#include  "Control.h"
#include  "AirCraft.h"
#include  "Keyboard.h"
#include  "Paleta.h"
#include  "Sprite.h"
#include  "ActorManager.h"
#include  "Herny.h"
#include  "Pelota.h"
#include  "Ladrillo.h"
#include  "ControlManager.h"
#include  "EditorManager.h"
#include  "StageManager.h"
#include  "Almacen.h"
#include  "Loro.h"
#include  "Mago.h"
#include  "Ben.h"
#include <iostream>
#include <fstream>
#include <string>


/** 
 * \brief   Juego de prueba heredado de Game.
 * \details Esta clase genera un simple juego para probar los distintos actores.
 */
class Juego2 : public Game
{
  public:
                    Juego2                        ();
    void          mainGame                      ();
    void          create_storagemanager   ();
};
