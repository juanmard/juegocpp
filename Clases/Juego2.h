#pragma once

/* Define la compilación de forma estática.
 * \todo Automatizar esto en el marco de trabajo ("FrameWork") para
 *       que pueda ser elegido desde "Game.cpp".

#define ALLEGRO_STATICLINK
*/

#include "Game.h"
#include "Mapa.h"

/** 
 * \brief   Juego de prueba heredado de Game.
 * \details Esta clase genera un simple juego para probar los distintos actores.
 */
class Juego2 : public Game
{
  public:
                  Juego2                  ();
    void          mainGame                ();
    void          create_storagemanager   ();
};
