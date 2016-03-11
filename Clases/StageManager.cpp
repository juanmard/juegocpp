#include "Game.h"
#include "Actor.h"
#include "ActorManager.h"
#include "StageManager.h"

StageManager::StageManager(Game *g, int w, int h)
{
	game=g;
	width=w;
	height=h;
	buffer=create_bitmap(SCREEN_W, SCREEN_H);
}

StageManager::~StageManager()
{
	destroy_bitmap(buffer);
}

int StageManager::w()
{
	return width;
}

int StageManager::h()
{
	return height;
}

void StageManager::update()
{
	draw();
}

void StageManager::draw()
{
	Actor *tmp;
	game->actor_manager->rewind();
    // Coloreamos de azul (2 en la paleta) el fondo.
    clear_to_color (buffer, 2);
    while ((tmp = game->actor_manager->next())!= NULL)
	{
		tmp->draw (buffer);
        tmp->draw_block (buffer);
	}

	/*
	 * Volcamos el buffer en pantalla. Se dejan 14 pixel por arriba
	 * para mostrar los fps.
	 *
	 * TODO: Opción para mostrar los fps y dejar estos 14 pixels.
	 */
	blit(buffer, screen, 0,0,0,14,SCREEN_W, SCREEN_H);
}