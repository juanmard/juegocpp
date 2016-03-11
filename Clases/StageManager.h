#ifndef STAGEMANAGER_H
#define STAGEMANAGER_H

#include <allegro.h>

class Game;

/**
 * \brief   Controlador de la escena del juego.
 */
class StageManager
{
    public:
                StageManager(Game *g, int w, int h);
                ~StageManager();
        int     w();
        int     h();
        void    update();
        void    draw();

    protected:
        Game *game;
        BITMAP *buffer;
        int width, height;
};
#endif