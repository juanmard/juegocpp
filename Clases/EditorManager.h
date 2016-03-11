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
            EditorManager   (Game *g);
            ~EditorManager  ();
    void    edit            ();
    void    set             (int indice);
    void    activate        ();
    void    redibuja        ();
    void    resaltarActor   (int x, int y);
    void    editarActor     (int x, int y);
    void    duplicarActor   (int x, int y);
    void    moverActor      (int x, int y);
    bool    editandoActor   () const;
    int     getActorX       () const;
    int     getActorY       () const;
    void    setActorX       (int x);
    void    setActorY       (int y);
    Actor * get_actor       (int x, int y) const;
    char *  getNombreTraje  (int indice) const;
    int     getNumTrajes    () const;
    void    cambiarTraje    (int indice);
    int     getEscenarioX   () const;
    int     getEscenarioY   () const;
    void    moverEscenario  (int x, int y);

  protected:
  Game *      game;
  Dialog *    gui;
  Actor *     actor_editado;
};
