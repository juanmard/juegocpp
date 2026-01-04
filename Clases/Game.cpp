
#include "Game.h"
#include <allegro.h>
#include <iostream>
#include "ActorManager.h"
#include "StageManager.h"
#include "ControlManager.h"
#include "CollisionManager.h"
#include "SoundManager.h"
#include "StorageManager.h"
#include "AllegroTimer.h"

/// @brief  Constructor por omisión.
Game::Game ():
actor_manager(NULL),
stage_manager(NULL),
sound_manager(NULL),
control_manager(NULL),
collision_manager(NULL),
storage_manager(NULL),
timer (new AllegroTimer()),
paused (true)
{
}

/// @brief  Destructor por omisión.
Game::~Game () {
}

/// @brief  Inicia el juego.
/// @todo  Independizar de Allegro4 usando la clase IRenderer.
void Game::init (int gfx_mode, int w, int h, int col) {
  allegro_init ();
  install_keyboard ();
  install_mouse ();
  timer->install ();

  /* Entramos en modo gráfico. */
  set_color_depth(col);
  if (set_gfx_mode(gfx_mode, w, h, 0, 0) < 0)
  {
    shutdown("No se pudo inicializar modo gráfico.");
    return;
  }
  else
  {
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


/// @brief  Da por terminado el juego.
void Game::shutdown (std::string message = "Gracias por jugar.") {
  // Se borran y se liberan todos los controladores.
  if (actor_manager) delete actor_manager;
  if (stage_manager) delete stage_manager;
  // if (sound_manager) delete sound_manager;
  if (control_manager) delete control_manager;
  if (collision_manager) delete collision_manager;
  if (storage_manager) delete storage_manager;

  set_gfx_mode (GFX_TEXT,0,0,0,0);
  // Se muestran mensajes finales.
  std::cout << name << std::endl;
  std::cout << message << std::endl;
  allegro_exit ();
}

/// @brief  Crea el controlador de actores.
/// @warning  Comprobar que se ha creado el manejador correctamente.
void Game::create_actormanager () {
  actor_manager = new ActorManager (this);
}

/// @brief  Crea el controlador del escenario.
/// @warning  Comprobar que se ha creado el manejador correctamente.
void Game::create_stagemanager () {
  stage_manager = new StageManager (this, gfx_w, gfx_h);
}

///
/// @brief  Crea en el juego un controlador de sonidos.
/// @warning  Se debería pensar si este es el lugar apropiado para crearlo.
///           - ¿Forma parte del juego?
///           - ¿No es parte del controlador de escenario ("StageManager")?
///           - ¿Se debe crear un controlador de "efectos" independiente?
/// @warning  Comprobar que se ha creado el manejador correctamente.
///
void Game::create_soundmanager () {
  sound_manager = new SoundManager ();
}

/// @brief  Crea el controlador de controles.
/// @warning  Comprobar que se ha creado el manejador correctamente.
void Game::create_controlmanager () {
  control_manager = new ControlManager ();
}

/// @brief  Crea el controlador de colisiones.
/// @warning  Comprobar que se ha creado el manejador correctamente.
void Game::create_collisionmanager () {
  collision_manager = new CollisionManager (this);
}

/// @brief  Se inicia el juego.
void Game::start () {
  // Inicializamos la sincronización con el juego.
  timer->init ();

  // Se llama al procedimiento principal.
  mainGame ();

  // Cuando termine el procedimiento principal, apagamos el juego.
  shutdown ();
}

/// @brief  Procedimiento predeterminado "main" si no se sobreescribe en el hijo.
/// @todo  Independizar de Allegro4 usando IInput.
void Game::mainGame () {
  while (!key[KEY_ESC]);
}

/// @brief  Se cambia el nombre del juego.
void Game::set_name (std::string n) {
  name = n;
}

/// @brief  Se obtiene el nombre del juego.
std::string Game::get_name () {
  return name;
}

/// @brief  Se actualiza el estado del juego.
void Game::update () {
  // Si se ha cumplido el ciclo lógico en el timer: Se actualiza el ciclo lógico.
  if (timer->isCicloLogico()) {
    if (actor_manager) actor_manager->update ();
    if (collision_manager) collision_manager->update ();
    if (control_manager) control_manager->update ();
    timer->incTickActual ();
  }

  // Si se ha cumplido el ciclo gráfico o se han saltado muchos frames en el timer: Se actualiza el ciclo gráfico.
  // En otro caso: Se añade un salto de frame.
  if (timer->isCicloGrafico() || timer->isSkipFrame()) {
    stage_manager->set_ribete (Bloque(0,50,SCREEN_W,SCREEN_H));
    stage_manager->update ();
    timer->updateFrame ();
  } else {
    timer->incFrame ();
  }

  /// @todo Independizar de Allegro4 con IRenderer.
  // Si se ha cumplido un segundo, se actualizan los "fps" por pantalla.
  if (timer->isOneSecond())
  {
    rectfill (screen, 0, 0, SCREEN_W, 10, 0);
    textprintf_ex (screen, font, 0, 0, -1, makecol(255, 100, 200),
                   "fps: %u frameskip:%u", timer->getGraphicTick(), timer->getFrameSkip() );
    //blit (stage_manager->getBuffer(), screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    timer->resetGraphicTick ();
    timer->resetOldTick ();
  }
}

/// @brief  Se pausa el juego.
void Game::pause () {
  paused = true;
}

/// @brief  Se reanuda el juego.
void Game::play () {
  paused = false;
}

/// @brief  Se comprueba si el juego está en pausa.
/// @return  Booleano indicando si el juego está en modo pausa o no.
bool Game::is_paused (void) {
  return paused;
}

/// @brief  Se crea el almacén de recursos por omisión.
/// @todo  Comprobar que se ha creado correctamente.
void Game::create_storagemanager () {
    // Creamos el almacén de recursos.
    storage_manager = new StorageManager("sprites3.dat");
}
