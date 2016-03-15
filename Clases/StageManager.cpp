
#include "StageManager.h"


/**
 * \brief   Constructor de la clase.
 * \details Se guarda la referencia al juego, se inicializa ancho y alto del marco
 *          y se crea el buffer como bitmap de Allegro.
 */
StageManager::StageManager (Game *g, int w = SCREEN_W, int h = SCREEN_H):
game (g),
marco (0, 0, w, h),
ribete (0, 0, w, h),
colorRibete (makecol (255, 0, 0)),
actorSeguido (NULL),
verBloques (true),
verInfo (true),
verRibete (true)
{
  buffer = create_bitmap (SCREEN_W, SCREEN_H);
}

/**
 * \brief   Destructor de la clase.
 * \details Se libera la memoria del buffer creado como bitmap de Allegro.
 */
StageManager::~StageManager ()
{
  destroy_bitmap (buffer);
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
void  StageManager::rellenarBuffer ()
{
  Actor *tmp;

  // Se sitúa la lista de actores al inicio.
  game->actor_manager->rewind ();

  // Dibujamos los decorados de fondo.
  // Coloreamos de azul (2 en la paleta) el fondo.
  clear_to_color (buffer, 129);

  // Se recorre la lista de actores y se dibuja en el buffer del escenario.
  // @todo  Comprobar los actores que se encuentran dentro del marco del
  //        escenario (intersección de un bloque con otro) y dibujar sólo esos
  //        actores.
  if (verBloques)
  {
    while ((tmp = game->actor_manager->next()) != NULL)
    {
      tmp->draw (this);
      tmp->setMostrarBloque(true);
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
}

/**
 * \brief   Dibuja el escenario.
 * \details Para ello recorre la lista de actores y les manda dibujarse en el buffer
 *          que posteriormente se vuelca en la pantalla ('screen' de Allegro).
 */
void StageManager::draw ()
{
  // Rellena el buffer con los actores.
  rellenarBuffer ();

  // Se añade la línea superior de información.
  if (verInfo)
  {
     *this << "Línea de información";
     textout_ex(screen, font, info.c_str(), 10, 10, makecol(0, 0, 255), -1);
     ribete.setY (20);
  }

  if (verRibete) rect (buffer, 0, 0, ribete.getW () - 1, ribete.getH () -1, colorRibete);
  
  // Vuelca todo en pantalla.
  blit (buffer, screen, 0, 0, 
        ribete.getX (), ribete.getY (),
        ribete.getW (), ribete.getH ());
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

/**
 * \brief   Dibuja un cuadrado
 * \details Dibuja un cuadrado referido al inicio del buffer. En coordenadas del juego,
 *          referido a la posición actual del escenario.
 * \param   cuadro  cuadro
 * \param   color   color
 */
void  StageManager::dibujarCuadrado (Bloque cuadro, int color)
{
  rect (buffer, cuadro.getX (), cuadro.getY (), cuadro.getW (), cuadro.getH (), color); 
}

/**
 * \brief   Define la zona límite del ribete a dibujar en pantalla.
 * \param   ribeteParam     Bloque que define posición y tamaño a dibujar en pantalla.
 */
void  StageManager::setRibete (Bloque ribeteParam)
{
  ribete.setXY (ribeteParam.getX (), ribeteParam.getY ());
  ribete.setWH (ribeteParam.getW (), ribeteParam.getH ());
}

/**
 * \brief   Obtiene la referencia al marco del escenario.
 * \return  Devuelve el bloque que define al marco.
 */
Bloque &  StageManager::getMarco ()
{
  return marco;
}

/**
 * \brief   Obtiene la referencia al ribete del escenario.
 * \return  Devuelve el bloque que define al ribete.
 */
Bloque &  StageManager::getRibete ()
{
  return ribete;
}

/**
 * \brief   Cambia el color del ribete.
 * \param   color   Color del ribete.
 */
void  StageManager::setColorRibete (int color)
{
  colorRibete = color;
}

/**
 * \brief   Obtiene la posición del marco y la vuelca en la cadena.
 * \param   posicion    Cadena donde se guarda la posición marco del escenario.
 *
void  StageManager::getXY (string &posicion) const
{
  stringstream  ss;

  ss << "(" << marco.getX() << ", " << marco.getY () << ")";
  posicion = ss.str ();
}
*/

std::string& StageManager::operator<< (std::string cadena) 
{
    info.append (cadena);
    info.resize(100);
    return info;
}

