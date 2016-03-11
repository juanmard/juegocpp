#pragma once

#include <allegro.h>
#include "Game.h"
#include "Actor.h"
#include "Dialog.h"

class Dialog;

/**
 *  \brief      Edita las listas de objetos involucrados en un juego.
 *  \details    Edita las listas de objetos involucrados en un juego y permite modificar, guardar
 *              y recuperar dichos objetos. Esta edición puede realizarse en la misma ventana donde
 *              se desarrolla el juego o en una ventana aparte. Debe permitir editar todas y cada una
 *              de las animaciones de los objetos, así como modificar el estado de los mismos.
 *              Aunque se podría incluir en la clase "ActorManager" se decide crear una clase 
 *              independiente puesto que la edición no es un proceso normal del juego una vez terminado.
 */
class EditorManager
{
	public:
                EditorManager	(Game *g);
                ~EditorManager	();
        void    edit            ();
        void    set             (int indice);
        void    activate        ();
        Game   *get_game        ();
        void    redibuja        ();
        void    resaltar         (int x, int y);
        void    editar            (int x, int y);
        void    mover           (int x, int y);
        Actor  *get_actor       ();
        bool    is_editando     ();


protected:
		Game    *game;
		Dialog   *gui;
        Actor    *editando;
};
