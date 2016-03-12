#ifndef _STAGEMANAGER_H_
#define _STAGEMANAGER_H_

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
    void      setVerBloques   (bool activar);
    bool      getVerBloques   ();
    void      rellenarBuffer  ();
    void      dibujarCuadrado (Bloque cuadro, int color);
    void      setRibete       (Bloque ribete);
    Bloque &  getRibete       ();
    void      setColorRibete  (int color);
    Bloque &  getMarco        ();
//    void      getXY           (string &posicion) const;

  protected:
    void      actualizarSeguimiento     ();

  protected:
    Game *    game;             // Referencia al juego.
    BITMAP *  buffer;           // Buffer principal a volcar en pantalla.
    Bloque    ribete;           // Marco dentro de las coordenadas de la pantalla.
    int       colorRibete;      // Color del ribete.
    Bloque    marco;            // Marco dentro de las coordenadas del juego.
    Actor *   actorSeguido;     // Actor al que se le realiza el seguimiento.
    bool      verBloques;       // Muestra los bloques de los actores.
    bool      verInfo;          // Muestra las informaciones del juego.
    bool      verRibete;        // Muestra el ribete en pantalla.
};

#endif
