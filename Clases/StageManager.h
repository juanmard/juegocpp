#pragma once

#include <allegro.h>
#include "Game.h"
#include "Actor.h"
#include "ActorManager.h"

class Game;

/**
 * \class   StageManager
 * \brief   Controlador del escenario del juego.
 * \details Debe controlar como se representa el juego en pantalla y brindar
 *          los procedimientos necesarios para el juego. 
 */
class StageManager
{
  public:
              StageManager    (Game *g, int w, int h);
              ~StageManager   ();
    int       getW            ();
    int       getH            ();
    int       getX            ();
    int       getY            ();
    BITMAP *  getBuffer       ();
    void      update          ();
    void      draw            ();
    void      moverMarco      (int x, int y);
    void      setSeguimiento  (Actor *paramActor);

  protected:
    void      actualizarSeguimiento ();
  
  protected:
    Game      *game;
    BITMAP    *buffer;
    Bloque    marco;
    Actor     *actorSeguido;
};
