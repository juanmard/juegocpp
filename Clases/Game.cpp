///---------------------------------------------------------
/// @file       Game.cpp
/// @author     Juan Manuel Rico
/// @date       Diciembre 2019
/// @version    1.0.0
///
/// @brief      FrameWork del juego.
///---------------------------------------------------------
#include "Game.h"
#include <iostream>
#include "ActorManager.h"
#include "StageManager.h"
#include "ControlManager.h"
#include "CollisionManager.h"
#include "SoundManager.h"
#include "Almacen.h"

// Para pruebas...
#include "./allegro/TimerAllegro.h"

namespace fwg {
/**
 * \brief   Constructor por omisión.
 */
Game::Game ()
{
  actor_manager = NULL;
  stage_manager = NULL;
  sound_manager = NULL;
  control_manager = NULL;
  collision_manager = NULL;
  storage_manager = NULL;
}

/**
 * \brief   Destructor por omisión.
 */
Game::~Game ()
{
}

/**
 * \brief   Inicia el juego.
 */
void Game::init (int gfx_mode, int w, int h, int col)
{
  /// @todo Agregar todas estas funciones en una única clase genérica.
  /// init_graphic_motor ()

  allegro_init ();
  install_keyboard ();
  install_mouse ();
  
  /// Para pruebas...
  /// @todo Eliminar estas referencias de Allegro4
  ///       de la clase principal.
  alg4::TimerAllegro* tempo = new alg4::TimerAllegro (); 
  setTimer(tempo);
  ///---------------------------------------------
  
  timer->install ();

  /* Entramos en modo gráfico. */
  set_color_depth(col);
  if (set_gfx_mode(gfx_mode, w, h, 0, 0) < 0) {
    shutdown("No se pudo inicializar modo gráfico");
    return;
  } else {
    gfx_w = w;
    gfx_h = h;
  }

  /* Creamos manejadores del juego. */
  create_actormanager ();
  create_stagemanager ();
  create_soundmanager ();
  create_controlmanager ();
  create_collisionmanager ();
  create_storagemanager ();

  /* Se empieza el juego. */
  start ();
}

/**
 * \brief   Da por terminado el juego.
 */
void Game::shutdown (string message = "Gracias por jugar")
{
  /* Se borrran los controladores. */
  if (actor_manager) delete actor_manager;
  if (stage_manager) delete stage_manager;
  //    if (sound_manager) delete sound_manager;
  if (control_manager) delete control_manager;
  if (collision_manager) delete collision_manager;
  if (storage_manager) delete storage_manager;

  set_gfx_mode (GFX_TEXT,0,0,0,0);
  std::cout << name << std::endl;
  std::cout << message << std::endl;
  allegro_exit ();
}

/**
 * \brief   Crea el controlador de actores.
 */
void Game::create_actormanager ()
{
  actor_manager = new ActorManager (this);
}

/**
 * \brief   Crea el controlador del escenario.
 */
void Game::create_stagemanager ()
{
  stage_manager = new StageManager (this, gfx_w, gfx_h);
}

/**
 * \brief   Crea en el juego un controlador de sonidos.
 * \warning Se debería pensar si este es el lugar apropiado para crearlo.
 *          - ¿Forma parte del juego?
 *          - ¿No es parte del controlador de escenario ("StageManager")?
 *          - ¿Se debe crear un controlador de "efectos" independiente?
 */
void Game::create_soundmanager ()
{
  //sound_manager = new SoundManager (this);
  sound_manager = new SoundManager ();
}

/**
 * \brief   Crea el controlador de controles.
 */
void Game::create_controlmanager ()
{
    control_manager = new ControlManager ();
}

/**
 * \brief   Crea el controlador de colisiones.
 */
void Game::create_collisionmanager ()
{
    collision_manager = new CollisionManager (this);
}

/**
 * \brief   Se inicia el juego.
 */
void Game::start ()
{
  /* Inicializamos la sincronización con el juego. */
  timer->start();
  paused = false;

  /* Se llama al procedimiento principal. */
  mainGame ();
  shutdown ();
}

void Game::setTimer (Timer* temporizador) {
    timer = temporizador;
}

/**
 * \brief   Procedimiento predeterminado "main" si no se sobreescribe en el hijo.
 */
void Game::mainGame ()
{
  while (!key[KEY_ESC]);
}

/**
 * \brief   Se cambia el nombre del juego.
 */
void Game::set_name (string n) {
  name = n;
}

/**
 * \brief   Se obtiene el nombre del juego.
 */
std::string Game::get_name () {
  return name;
}

/**
 * \brief   Se actualiza el estado del juego.
 */
void Game::update () {
    /// Se actualiza el ciclo lógico mientras no se supere
    /// el quantum de tiempo (14ms).
    if (timer->updateLogic()) {
        // Se actualiza el estado de la lista de actores.
        if (actor_manager) actor_manager->update ();
        if (collision_manager) collision_manager->update ();
        if (control_manager) control_manager->update ();
    }

    /// Se actualiza el ciclo gráfico.
    if (timer->updateGraphic()) {
        stage_manager->update ();
    }

    /// Si se ha cumplido un segundo, se actualizan los "fps"
    /// por pantalla.
    if (timer->has_new_second ()) {
        stage_manager->set_ribete(Bloque(0,20,SCREEN_W,SCREEN_H-20));
        rectfill (screen, 0, 0, SCREEN_W, 18, makecol(25,128,255));
        textprintf_ex (screen, font, 5, 5,-1, makecol(25,128,255),
                        "fps: %u frameskip:%u", timer->get_fps(), timer->get_frameskip());
        timer->reset_second ();
    }    
}

/**
 * \brief   Se pausa el juego.
 */
void Game::pause () {
  paused = true;
}

/**
 * \brief   Se reanuda el juego.
 */
void Game::play () {
  paused = false;
}

/**
 * \brief   Se comprueba si el juego está en pausa.
 */
bool Game::is_paused (void) {
  return paused;
}

/**
 * \brief   Se crea el almacén por omisión.
 */
void Game::create_storagemanager () {
    // Creamos el almacén de recursos.
    storage_manager = new Almacen("sprites3.dat");
}

};