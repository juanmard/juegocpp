///---------------------------------------------------------
/// @file       Game.h
/// @author     Juan Manuel Rico
/// @date       Diciembre 2019
/// @version    1.0.0
///
/// @brief      FrameWork del juego.
///---------------------------------------------------------
#ifndef _GAME_H_
#define _GAME_H_

#include <string>
#include "ActorManager.h"
#include "Timer.h"

/// Espacio de nombre para el "Frame Work Game".
namespace fwg {

/// Predefiniciones de clases.
class ActorManager;
class StageManager;
class SoundManager;
class ControlManager;
class CollisionManager;
class Almacen;

/**
 * \brief   Clase que recoge las funciones básicas de un juego.
 * \todo   Definir el tipo 'team_t' como una clase externa.
 */
class Game
{
public:
    typedef enum {ALLY, ENEMY} team_t;
    enum {RUNNING, PAUSED} state;

    ActorManager        *actor_manager;
    StageManager        *stage_manager;
    SoundManager        *sound_manager;
    ControlManager      *control_manager;
    CollisionManager    *collision_manager;
    Almacen             *storage_manager;

protected:
    std::string     name;
    int             gfx_w, gfx_h;
    int             colors;

private:
    Timer*  timer;
    bool    paused;     ///< Indica el estado pausado del juego.

public:
                     Game       ();
    virtual         ~Game       ();
    virtual void    init        (int gfx_mode, int w, int h, int col);
    virtual void    mainGame    ();
    void            pause       ();
    void            play        ();
    bool            is_paused   ();
    void            set_name    (std::string name);
    std::string     get_name    ();
    void            update      ();
    void            setTimer    (Timer* temporizador);

private:
    void            start                   ();
    void            shutdown                (std::string message);
    virtual void    create_actormanager     ();
    virtual void    create_stagemanager     ();
    virtual void    create_soundmanager     ();
    virtual void    create_controlmanager   ();
    virtual void    create_collisionmanager ();
    virtual void    create_storagemanager   ();
};

};

#endif
