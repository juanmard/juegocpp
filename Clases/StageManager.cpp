
#include "StageManager.h"

/**
 * \brief   Constructor de la clase.
 * \details Se guarda la referencia al juego, se inicializa ancho y alto del marco
 *          y se crea el buffer como bitmap de Allegro.
 */
StageManager::StageManager (Game *g, int w = SCREEN_W, int h = SCREEN_H):
game (g),
marco (0, 0, w, h),
actorSeguido (NULL),
verBloques(true)
{
  buffer = create_bitmap (SCREEN_W, SCREEN_H);
}

/**
 * \brief   Destructor de la clase.
 * \details Se libera la memoria del buffer creado como bitmap de Allegro.
 */
StageManager::~StageManager ()
{
  destroy_bitmap(buffer);
}

/**
 * \brief   Devuelve el ancho del marco.
 */
int StageManager::getW ()
{
  return marco.getW ();
}

/**
 * \brief   Devuelve el alto del marco.
 */
int StageManager::getH ()
{
  return marco.getH ();
}

/**
 * \brief   Devuelve la posición x del marco.
 */
int StageManager::getX ()
{
  return marco.getX ();
}

/**
 * \brief   Devuelve la posición y del marco.
 */
int StageManager::getY ()
{
  return marco.getY ();
}

/**
 * \brief   Actualiza el escenario.
 * \details Actualmente al actualizar el escenario únicamnente lo vuelve a dibujar.
 */
void StageManager::update ()
{
  actualizarSeguimiento ();
  draw ();
}

/**
 * \brief   Dibuja el escenario.
 * \details Para ello recorre la lista de actores y les manda dibujase en el buffer
 *          que posteriormente se vuelca en la pantalla ('screen' de Allegro).
 */
void StageManager::draw ()
{
  Actor *tmp;

  // Se sitúa la lista de actores al inicio.
  game->actor_manager->rewind ();

  // Dibujamos los decorados de fondo.
  // Coloreamos de azul (2 en la paleta) el fondo.
  clear_to_color (buffer, 129);

  // Se recorre la lista de actores y se dibuja en el buffer del escenario.
  // \todo  Comprobar los actores que se encuentran dentro del marco del
  //        escenario (intersección de un bloque con otro) y dibujar sólo esos
  //        actores.
  if (verBloques)
  {
    while ((tmp = game->actor_manager->next()) != NULL)
    {
      tmp->draw (this);
      tmp->draw_block (this);
    }
  }
  else
  {
    while ((tmp = game->actor_manager->next()) != NULL)
    {
      tmp->draw (this);
    }
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
void StageManager::moverMarco (int x, int y)
{
  marco.setXY (x,y);
}

/**
 * \brief Devuelve el buffer del escenario.
 */
BITMAP * StageManager::getBuffer ()
{
  return buffer;
}

/**
 * \brief   Actualiza el seguimiento a un actor.
 * \details Actualiza el seguimiento del marco del escenario sobre un actor.
 */
void StageManager::actualizarSeguimiento ()
{
  if (actorSeguido != NULL)
  {
    marco.centrar (actorSeguido->getBloque ());
  }
}

/**
 * \brief   Actualiza el seguimiento a un actor.
 * \details Actualiza el seguimiento del marco del escenario sobre un actor.
 * \param   paramActor  Puntero al actor al que se le hará el seguimiento del
 *          escenario.
 */
void StageManager::setSeguimiento (Actor *paramActor)
{
  actorSeguido = paramActor;
}

/**
 * \brief   Cambia la activación de la visualización de los bloques.
 * \param   activar   Si es 'true' activamos la actualización de los bloques.
 */
void  StageManager::setVerBloques (bool activar)
{
  verBloques = activar;
}

/**
 * \brief   Obtiene el estado de la visualización de los bloques.
 * \return  Si es 'true' es que los bloques están activos.
 */
bool  StageManager::getVerBloques ()
{
  return verBloques;
}
