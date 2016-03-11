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
  private:
    /**
    * \brief   Estructura para bloque.
    * \todo    Generalizar esta estructura en una clase e incluirla 
    *          en el resto de clases junto con métodos como la intersección
    *          entre bloques.
    */
    typedef struct {
    int  x, y;
    int  w, h;
    } Bloque;

public:
              StageManager    (Game *g, int w, int h);
              ~StageManager   ();
    int       GetW            ();
    int       GetH            ();
    int       GetX            ();
    int       GetY            ();
    BITMAP *  GetBuffer       ();
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
