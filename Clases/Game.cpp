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
#include "Timer.h"

namespace fwg {

    Game::Game ():
    state(CREATED)
    {
      actorManager = NULL;
      stageManager = NULL;
      soundManager = NULL;
      controlManager = NULL;
      collisionManager = NULL;
      storageManager = NULL;
    }

    Game::~Game ()
    {
    }

    void Game::init (int gfx_mode, int w, int h, int col)
    {
      state = INIT;
      /// @todo Agregar todas estas funciones en una única clase genérica.
      /// initGraphicMotor ()
      /// 
      allegro_init ();
      install_keyboard ();
      install_mouse ();
      timer->install ();

      // Entramos en modo gráfico.
      set_color_depth(col);
      if (set_gfx_mode(gfx_mode, w, h, 0, 0) < 0)
      {
        state = SHUTDOWN;
        shutdown("No se pudo inicializar modo gráfico");
        return;
      }
      else
      {
        gfx_w = w;
        gfx_h = h;
      }

      // Creamos manejadores del juego.
      createActorManager ();
      createStageManager ();
      createSoundManager ();
      createControlManager ();
      createCollisionManager ();
      createStorageManager ();

      // Se empieza el juego.
      start ();
    }

    void Game::shutdown (std::string message = "Gracias por jugar.")
    {
      // Se borrran los controladores.
      if (actorManager) delete actorManager;
      if (stageManager) delete stageManager;
      if (soundManager) delete soundManager;
      if (controlManager) delete controlManager;
      if (collisionManager) delete collisionManager;
      if (storageManager) delete storageManager;

      /// @todo Elimiar estas referencias a Allegro.
      ///       Cambiar por un "shutdownGraphicMotor"
      set_gfx_mode (GFX_TEXT,0,0,0,0);
      allegro_exit ();

      std::cout << name << std::endl;
      std::cout << message << std::endl;
    }

    void Game::createActorManager ()
    {
      actorManager = new ActorManager (this);
    }

    void Game::createStageManager ()
    {
      stageManager = new StageManager (this, gfx_w, gfx_h);
    }

    /// Crea en el juego un controlador de sonidos.
    /// @warning Se debería pensar si este es el lugar apropiado para crearlo.
    ///         - ¿Forma parte del juego?
    ///         - ¿No es parte del controlador de escenario ("StageManager")?
    ///         - ¿Se debe crear un controlador de "efectos" independiente?
    ///
    void Game::createSoundManager ()
    {
      // soundManager = new SoundManager (this);
      soundManager = new SoundManager ();
    }

    void Game::createControlManager ()
    {
        controlManager = new ControlManager ();
    }

    void Game::createCollisionManager ()
    {
        collisionManager = new CollisionManager (this);
    }

    void Game::start ()
    {
      // Iniciazamos la sincronización del temporizador con el juego.
      timer->start();

      // Se llama al procedimiento principal.
      state = RUNNING;
      mainGame ();

      // Se termina el juego.
      state = SHUTDOWN;
      shutdown ();
    }

    void Game::setTimer (Timer* temporizador)
    {
        timer = temporizador;
    }

    /// Método predeterminado "main" si no se sobreescribe en el hijo.
    /// 
    /// @todo Eliminar referencia a Allegro.
    /// 
    void Game::mainGame ()
    {
      while (!key[KEY_ESC]);
    }

    void Game::setName (std::string n)
    {
      name = n;
    }

    std::string Game::getName () const
    {
      return name;
    }

    void Game::update ()
    {
        // Se actualiza el ciclo lógico mientras no se supere
        // el quantum de tiempo (14ms).
        if (timer->updateLogic())
        {
            // Se actualiza el estado de la lista de actores.
            if (actorManager) actorManager->update ();
            if (collisionManager) collisionManager->update ();
            if (controlManager) controlManager->update ();
        }

        // Se actualiza el ciclo gráfico.
        if (timer->updateGraphic())
        {
            stageManager->update ();
        }

        // Si se ha cumplido un segundo, se actualizan los "fps"
        // por pantalla.
        // 
        /// @todo Eliminar la referencia a Allegro y dejar que sea
        ///       la clase 'StageManager' la que se encargue de
        ///       mostrar esta información por pantalla.
        ///       
        if (timer->has_new_second ())
        {
            stageManager->set_ribete(Bloque(0,20,SCREEN_W,SCREEN_H-20));
            rectfill (screen, 0, 0, SCREEN_W, 18, makecol(25,128,255));
            textprintf_ex (screen, font, 5, 5,-1, makecol(25,128,255),
                            "fps: %u frameskip:%u", timer->get_fps(), timer->get_frameskip());
            timer->reset_second ();
        }    
    }

    void Game::pause ()
    {
      state = PAUSED;
    }

    void Game::play ()
    {
      state = RUNNING;
    }

    bool Game::isPaused () const
    {
      return (state == PAUSED);
    }

    void Game::createStorageManager ()
    {
        // Creamos el almacén de recursos.
        // storageManager = new Almacen("sprites3.dat");
    }
};