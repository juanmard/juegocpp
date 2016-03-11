
#include "StageManager.h"

/**
 * \brief   Constructor de la clase.
 * \details Se guarda la referencia al juego, se inicializa ancho y alto del marco
 *          y se crea el buffer como bitmap de Allegro.
 */
StageManager::StageManager (Game *g, int w, int h):
game (g) 
{
  marco.x = 0;
  marco.y = 0;
	marco.w = w;
	marco.h = h;
	buffer = create_bitmap (SCREEN_W, SCREEN_H);
}

/**
 * \brief   Destructor de la clase.
 * \details Se libera la memoria del buffer creado como bitmap de Allegro.
 */
StageManager::~StageManager()
{
	destroy_bitmap(buffer);
}

/**
 * \brief   Devuelve el ancho del marco.
 */
int StageManager::GetW ()
{
	return marco.w;
}

/**
 * \brief   Devuelve el alto del marco.
 */
int StageManager::GetH ()
{
	return marco.h;
}

/**
 * \brief   Devuelve la posición x del marco.
 */
int StageManager::GetX()
{
	return marco.x;
}

/**
 * \brief   Devuelve la posición y del marco.
 */
int StageManager::GetY()
{
	return marco.y;
}

/**
 * \brief   Actualiza el escenario.
 * \details Actualmente al actualizar el escenario únicamnente lo vuelve a dibujar.
 */
void StageManager::update()
{
	draw ();
}

/**
 * \brief   Dibuja el escenario.
 * \details Para ello recorre la lista de actores y les manda dibujase en el buffer
 *          que posteriormente se vuelca en la pantalla ('screen' de Allegro).
 */
void StageManager::draw()
{
  Actor *tmp;

  // Se sitúa la lista de actores al inicio.
  game->actor_manager->rewind();

  // Dibujamos los decorados de fondo.
  // Coloreamos de azul (2 en la paleta) el fondo.
  clear_to_color (buffer, 129);

  // Se recorre la lista de actores y se dibuja en el buffer del escenario.
  // \todo  Comprobar los actores que se encuentran dentro del marco del
  //        escenario (intersección de un bloque con otro) y dibujar sólo esos
  //        actores.
  while ((tmp = game->actor_manager->next())!= NULL)
  {
    // Cuando se pide dibujar al actor y se le pasa el StageManager,
    //  debe dibujarse referido al marco del escenario.
    tmp->draw (this);

    // Si se le pasa el buffer se dibujará de manera absoluta, como si
    // el marco estuviera siempre en la posición 0,0.
    //tmp->draw (buffer);

    // Se dibujan los bloques de referencia del actor.
    tmp->draw_block (buffer);
  }

  /*
   * Volcamos el buffer en pantalla. Se dejan 14 pixel por arriba
   * para mostrar los fps.
   *
   * \todo Opción para mostrar los fps y dejar estos 14 pixels.
   */
  blit (buffer, screen, 0, 0, 0,14,SCREEN_W, SCREEN_H);
  //blit (buffer, screen, 0,0,0,0,SCREEN_W, SCREEN_H);
}

/** 
 * \brief  Mueve el marco del escenario a la posición especificada dentro de las
 *         coordenadas generalizadas del juego.
 */
void StageManager::MoverMarco (int x, int y)
{
  marco.x = x;
  marco.y = y;
}

/**
 * \brief Devuelve el buffer del escenario.
 */
BITMAP * StageManager::GetBuffer ()
{
  return buffer;
}
