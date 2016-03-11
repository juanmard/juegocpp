#pragma once

#include <allegro.h>

class Game;
class Actor;
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
        void    redibuja        ();
        void    ResaltarActor   (int x, int y);
        void    EditarActor     (int x, int y);
        void    MoverActor      (int x, int y);
        bool    EditandoActor   ();
        int     GetActorX       ();
        int     GetActorY       ();
        void    SetActorX       (int x);
        void    SetActorY       (int y);

    protected:
		Game *      game;
		Dialog *    gui;
        Actor *     actor_editado;
};
