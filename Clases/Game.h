#ifndef _GAME_H_
#define _GAME_H_

#include <string>

class ITimer;
class ActorManager;
class StageManager;
class SoundManager;
class ControlManager;
class CollisionManager;
class StorageManager;

///
/// @brief  Clase que recoge las funciones básicas de un juego.
/// @details  Esta clase inicializa todos los componentes necesarios para un juego.
///
class Game
{
public:
    ActorManager*      actor_manager;        ///< Referencia al manejador de actores dentro del juego.
    StageManager*      stage_manager;        ///< Referencia al manejador del escenario donde se desarrolla el juego.
    SoundManager*      sound_manager;        ///< Referencia al manejador de sonidos del juego.
    ControlManager*    control_manager;      ///< Referencia al control del juego.
    CollisionManager*  collision_manager;    ///< Referencia al manejador de colisiones entre actores del juego.
    StorageManager*    storage_manager;      ///< Referencia al manejador de los distintos recursos del juego.

protected:
    std::string name;     ///< Nombre del juego.
    ITimer* timer;        ///< Timer para controlar ciclos lógicos y gráficos.
    int gfx_w, gfx_h;     ///< Dimensiones de la ventana del juego en modo gráfico.

private:
    bool paused;        ///< Variable que indica el estado pausado o no del juego.

public:
    Game ();
    virtual ~Game ();
    virtual void init (int gfx_mode, int w, int h, int col);
    virtual void mainGame ();
    void pause ();
    void play ();
    bool is_paused ();
    void set_name (std::string name);
    std::string get_name ();
    void update ();

private:
    void start ();
    void shutdown (std::string message);
    virtual void create_actormanager ();
    virtual void create_stagemanager ();
    virtual void create_soundmanager ();
    virtual void create_controlmanager ();
    virtual void create_collisionmanager ();
    virtual void create_storagemanager ();
};

#endif //_GAME_H_
