#include "Game.h"
#include <allegro.h>
#include <iostream>
#include "ActorManager.h"
#include "StageManager.h"
#include "ControlManager.h"
#include "CollisionManager.h"
#include "SoundManager.h"
#include "Almacen.h"

/*------------------------------------------------------------------------------*/
/* Variables y funciones globales para sincronizar juego en distintas máquinas. */
/*------------------------------------------------------------------------------*/
/**
 * \todo    Integrar en la clase "Game" como funciones y variables estáticas.
 */
void tick_count();

/* Las variables que modifiquen las funciones timer de allegro tienen que
 *  ser de tipo "volatile".
 */
volatile int tick;

/**
 * \brief   Función definida como "timer" de Allegro.
 * \todo    Independizar de la biblioteca Allegro mediante clases.
 */
void tick_count()
{
	tick++;
}
END_OF_FUNCTION(tick_count);
/*------------------------------------------------------------------------------*/


Game::Game()
{
    actor_manager=NULL;
    stage_manager=NULL;
    sound_manager=NULL;
    control_manager=NULL;
    collision_manager=NULL;
    almacen=NULL;
}

Game::~Game()
{
}

void Game::init(int gfx_mode, int w, int h, int col)
{
	allegro_init();
	install_keyboard();
    install_mouse();
	install_timer();

	/* Protegemos variables e instalamos interrupción del "timer" (14 para ejecutar 70 veces por segundo).*/
	LOCK_VARIABLE(tick);
	LOCK_FUNCTION(tick_count);
	install_int(&tick_count, 14);
	
	/* Entramos en modo gráfico. */
	set_color_depth(col);
	if (set_gfx_mode(gfx_mode, w, h, 0, 0) < 0)
	{
		shutdown("No se pudo inicializar modo grafico");
		return;
	}

	/* Creamos manejadores del juego. */
	create_actormanager();
	create_stagemanager();
    create_soundmanager ();
    create_controlmanager();
    create_collisionmanager ();

    /* Creamos el almacén de recursos. */
    almacen = new Almacen("sprites.dat");
    
	/* Se empieza el juego. */
	start();
}

void Game::shutdown (string message="Gracias por jugar")
{
    /* Se borrran los controladores. */
    if (actor_manager) delete actor_manager;
    if (stage_manager) delete stage_manager;
//    if (sound_manager) delete sound_manager;
    if (control_manager) delete control_manager;
    if (collision_manager) delete collision_manager;

    set_gfx_mode(GFX_TEXT,0,0,0,0);
	cout << name << endl;
	cout << message << endl;
	allegro_exit();
}

void Game::create_actormanager()
{
	actor_manager = new ActorManager(this);
}

void Game::create_stagemanager()
{
	stage_manager = new StageManager(this, gfx_w, gfx_h);
}

/**
 * \brief   Crea en el juego un controlador de sonidos.
 * \warning Se debería pensar si este es el lugar apropiado para crearlo.
 *          - ¿Forma parte del juego?
 *          - ¿No es parte del controlador de escenario ("StageManager")?
 *          - ¿Se debe crear un controlador de "efectos" independiente?
 */
void Game::create_soundmanager()
{
//	sound_manager = new SoundManager(this);
	sound_manager = new SoundManager();
}

void Game::create_controlmanager()
{
    control_manager = new ControlManager();
}

void Game::create_collisionmanager ()
{
    collision_manager = new CollisionManager (this);
}


void Game::start()
{
	/* Inicializamos la sincronización con el juego. */
	actual_tick=tick;
	old_tick=tick;
	max_frame_skip=15;
    paused = false;

	/* Se llama al procedimiento principal. */
    main();
	shutdown();
}

/**
 * \brief   Procedimiento predeterminado "main" si no se sobreescribe en el hijo.
 */
void Game::main()
{
	while (!key[KEY_ESC]);
}

void Game::set_name(string n)
{
	name = n;
}

string Game::get_name   (void)
{
	return name;
}

void Game::update   (void)
{
	/* Se actualiza el ciclo lógico. */
    if (actual_tick<=tick)
    {
        actor_manager->update();

        /* Se comprueba la existencia de los controladores para actualizarlos. */
        if (collision_manager) collision_manager->update();
        if (control_manager) control_manager->update();
        actual_tick++;
    }

	/* Si se ha cumplido un segundo, se actualizan los "fps" por pantalla. */
	if (tick-old_tick >= 70)
	{
		rectfill (screen,0,0,400,14,0);
		textprintf (screen, font, 0,0,-1, "fps: %u frameskip:%u", graphic_tick, frame_skip);
		graphic_tick=0;
		old_tick=tick;
	}

	/* Se actualiza el ciclo gráfico. */
	if ((actual_tick>=tick) || (frame_skip>max_frame_skip))
	{
		stage_manager->update();
		if (frame_skip>max_frame_skip) actual_tick=tick;
		graphic_tick++;
		frame_skip=0;
	}
	else
	{
		frame_skip++;
	}
}

void Game::set_max_frame_skip (int max_fs)
{
	max_frame_skip = max_fs;
}

void Game::pause (void)
{
	paused = true;
}

void Game::play (void)
{
	paused = false;
}

bool Game::is_paused (void)
{
	return paused;
}
