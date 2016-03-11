
#include "StageManager.h"

StageManager::StageManager (Game *g, int w, int h):
game (g) 
{
    marco.x=0;
    marco.y=0;
	marco.w=w;
	marco.h=h;
	buffer=create_bitmap(SCREEN_W, SCREEN_H);
}

StageManager::~StageManager()
{
	destroy_bitmap(buffer);
}

int StageManager::w()
{
	return marco.w;
}

int StageManager::h()
{
	return marco.h;
}

void StageManager::update()
{
	draw();
}

void StageManager::draw()
{
	Actor *tmp;

    // Se sitúa la lista de actores al inicio.
    game->actor_manager->rewind();

    // Coloreamos de azul (2 en la paleta) el fondo.
    clear_to_color (buffer, 2);

    // Se recorre la lista de actores y se dibuja en el buffer del escenario.
    // \todo  Comprobar los actores que se encuentran dentro del marco del
    //        escenario (intersección de un bloque con otro) y dibujar sólo esos
    //        actores.
    while ((tmp = game->actor_manager->next())!= NULL)
	{
        tmp->draw (buffer);
        tmp->draw_block (buffer);
	}

	/*
	 * Volcamos el buffer en pantalla. Se dejan 14 pixel por arriba
	 * para mostrar los fps.
	 *
	 * \todo Opción para mostrar los fps y dejar estos 14 pixels.
	 */
	blit(buffer, screen, 0,0,0,14,SCREEN_W, SCREEN_H);
	//blit(buffer, screen, 0,0,0,0,SCREEN_W, SCREEN_H);
}

/* \brief   Mueve el marco del escenario a la posición especificada dentro de las
 *            coordenadas generalizadas del juego.
 */
void StageManager::move (int x, int y)
{
    marco.x=x;
    marco.y=y;
}
