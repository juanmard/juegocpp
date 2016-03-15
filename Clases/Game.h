#ifndef _GAME_H_
#define _GAME_H_

#include <string>
#include "ActorManager.h"

// Predefiniciones de clases.
class ActorManager;
class StageManager;
class SoundManager;
class ControlManager;
class CollisionManager;
class Almacen;

//using namespace std;
using std::string;

/**
 * \brief   Clase que recoge las funciones básicas de un juego.
 * \todo   Definir el tipo 'team_t' como una clase externa.
 */
class Game
{
  public:
    typedef enum {ALLY, ENEMY} team_t;

    ActorManager        *actor_manager;
    StageManager        *stage_manager;
    SoundManager        *sound_manager;
    ControlManager      *control_manager;
    CollisionManager   *collision_manager;
    Almacen                *storage_manager;

                    Game        ();
    virtual         ~Game       ();
    virtual void    init        (int gfx_mode, int w, int h, int col);
    virtual void    mainGame    ();
    void            pause       ();
    void            play        ();
    bool            is_paused   ();
    void            set_name    (string name);
    string          get_name    ();
    void            update      ();

  protected:
    void        set_max_frame_skip  (int max_fs);

    string      name;
    int         gfx_w, gfx_h;
    int         colors;

  private:
    int     actual_tick;
    int     old_tick;
    int     graphic_tick;
    int     frame_skip;
    int     max_frame_skip;
    bool    paused;

    void            start                   ();
    void            shutdown                (string message);
    virtual void    create_actormanager     ();
    virtual void    create_stagemanager     ();
    virtual void    create_soundmanager     ();
    virtual void    create_controlmanager   ();
    virtual void    create_collisionmanager ();
    virtual void    create_storage_manager   ();
};

#endif
