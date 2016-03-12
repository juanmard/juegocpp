///
/// @file StageManager.cpp
/// @brief Fichero de la clase "StageManager".
/// @author Juan Manuel Rico
/// @date Octubre 2010
/// @version 1.0.0
///

#include "StageManager.h"

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
};

StageManager::~StageManager ()
{
  destroy_bitmap (buffer);
};

unsigned int StageManager::get_w () const
{
  return marco.getW ();
};

unsigned int StageManager::get_h () const
{
  return marco.getH ();
};

unsigned int StageManager::get_x () const
{
  return marco.getX ();
};

unsigned int StageManager::get_y () const
{
  return marco.getY ();
};

BITMAP* StageManager::getBuffer () const
{
  return buffer;
};

void StageManager::update ()
{
  actualizar_seguimiento ();
  draw ();
};

void  StageManager::rellenar_buffer ()
{
  Actor* tmp;

  // Se sitúa la lista de actores al inicio.
  game->actor_manager->rewind ();

  // Dibujamos los decorados de fondo.
  // Coloreamos de azul el fondo.
  clear_to_color (buffer, makecol (25,100,255));

  // Se recorre la lista de actores y se dibujan en el buffer del escenario.
  // @todo  Comprobar los actores que se encuentran dentro del marco del
  //        escenario (intersección de un bloque con otro) y dibujar sólo esos
  //        actores.
  //
  // Si está activa la función de ver los bloques de los actores, se dibuja el actor y sus dimensiones;
  // en otro caso, se dibuja solo el actor.
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
};

void StageManager::draw ()
{
  // Rellena el buffer con los actores.
  rellenar_buffer ();

  // Se añade la línea superior de información.
  if (verInfo)
  {
     // Línea de prueba.
     *this << "Línea de información";
     textout_ex(screen, font, info.c_str(), 10, 10, makecol(0, 0, 255), -1);
     ribete.setY (20);
  }

  if (verRibete) rect (buffer, 0, 0, ribete.getW ()-1, ribete.getH()-1, colorRibete);
  
  // Vuelca todo en pantalla.
  blit (buffer, screen, 0, 0, 
        ribete.getX (), ribete.getY (),
        ribete.getW (), ribete.getH ());
};

void StageManager::mover_marco (int x, int y)
{
  marco.setXY (x, y);
};

void StageManager::actualizar_seguimiento ()
{
  if (actorSeguido != NULL)
  {
    marco.centrar (actorSeguido->getBloque ());
  }
};

void StageManager::set_seguimiento (Actor* paramActor)
{
  actorSeguido = paramActor;
};

void  StageManager::set_ver_bloques (bool activar)
{
  verBloques = activar;
};

bool StageManager::get_ver_bloques () const
{
  return verBloques;
};

void StageManager::dibujar_cuadro (Bloque cuadro, int color)
{
  rect (buffer, cuadro.getX (), cuadro.getY (), cuadro.getW (), cuadro.getH (), color); 
};

void StageManager::set_ribete (Bloque ribeteParam)
{
  ribete.setXY (ribeteParam.getX (), ribeteParam.getY ());
  ribete.setWH (ribeteParam.getW (), ribeteParam.getH ());
};

void StageManager::set_color_ribete (int color)
{
  colorRibete = color;
};

Bloque& StageManager::get_ribete ()
{
  return ribete;
};

Bloque& StageManager::get_marco ()
{
  return marco;
};

std::string& StageManager::operator<< (std::string cadena) 
{
    info.append (cadena);
    info.resize(100);
    return info;
};

