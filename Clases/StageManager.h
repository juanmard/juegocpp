#pragma once

#include <allegro.h>
#include "Game.h"
#include "Actor.h"
#include "ActorManager.h"

class Game;

/**
 * \brief   Controlador de la escena del juego.
 */
class StageManager
{

    private:
        /* \brief	 Estructura para bloque.
         * \todo	 Generalizar esta estructura en una clase e incluirla en el resto de clases.
         */
        typedef struct {
            int  x, y;
            int  w, h;
        } Bloque;

    public:
                StageManager(Game *g, int w, int h);
                ~StageManager();
        int     w();
        int     h();
        void    update ();
        void    draw ();
        void    move (int x, int y);

    protected:
        Game       *game;
        BITMAP     *buffer;
        Bloque      marco;
};
