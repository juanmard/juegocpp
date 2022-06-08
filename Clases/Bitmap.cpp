///
/// @file Bitmap.cpp
/// @brief Fichero de implementación de la clase "Bitmap".
/// @author Juan Manuel Rico
/// @date Noviembre 2015
/// @version 1.0.0
///

#include <sstream>
#include "Bitmap.h"

// Inicializamos el almacén global de la clase.
Almacen* Bitmap::almacenGlobal = NULL;

Bitmap::Bitmap (Actor* aowner, BITMAP* bmp) :
ActorGraphic (aowner),
almacen (NULL),
fuente (bmp),
nombre ("sin nombre")
{
};

Bitmap::Bitmap (Actor* aowner, const std::string nombreParam):
ActorGraphic (aowner),
almacen (NULL),
nombre (nombreParam)
{
  fuente = almacenGlobal->get_bitmap (nombreParam);
};

Bitmap::Bitmap (Actor* aowner, BITMAP* bmp, std::string nombreParam) :
ActorGraphic (aowner),
almacen (NULL),
fuente (bmp),
nombre (nombreParam)
{
};

Bitmap::Bitmap (Actor* aowner, Almacen* almacenParam, const std::string nombreParam):
ActorGraphic (aowner),
almacen (almacenParam),
nombre (nombreParam)
{
//  fuente = almacenParam[nombreParam];
  fuente = almacenParam->get_bitmap (nombreParam);
};

void Bitmap::draw (BITMAP* destino)
{
  //draw_sprite (destino, fuente, get_x(), get_y());
  pivot_sprite_v_flip_lit(destino, fuente, get_x(), get_y(), 0, 0, 34, 128);
};

void Bitmap::draw (int x, int y, BITMAP* destino, bool mirror)
{
  if (almacenGlobal)
  {
    if (mirror)
    {
      draw_sprite_h_flip (destino, almacenGlobal->get_bitmap (nombre), x, y);
    }
    else
    {
      draw_sprite (destino, almacenGlobal->get_bitmap (nombre), x, y);
    }
  }
  else
  {
    // Rota los sprites...
    //rotate_sprite(destino, fuente, x, y, ftofix(256.0/9));

    // Dibuja sombras...
    //draw_character_ex(destino, fuente, x+3, y+3, makecol(128, 128, 128), -1);

    // Rota y escala...
    //rotate_scaled_sprite(destino, fuente, x, y, ftofix(0.0), ftofix(5.0));

    //Rota con pivote...
    // pivot_sprite(destino, fuente, x, y, x+10, y-10, ftofix(10.0));

    draw_sprite (destino, fuente, x, y);
  }
};

void Bitmap::draw (int x, int y, BITMAP* destino)
{
  draw (x, y, destino, false);
};

unsigned int Bitmap::get_w () const
{
  return fuente->w;
};

unsigned int Bitmap::get_h () const
{
  return fuente->h;
};

Bitmap* Bitmap::clone (Actor* propietario) const
{
  return (new Bitmap (propietario, fuente, this->nombre));
};


std::string& Bitmap::print () const
{
  // Se copia el nombre en una cadena nueva para no modificar el nombre del Bitmap
  // en un posible encadenamiento de cadenas.
  return *new std::string (nombre);
};

BITMAP* Bitmap::get_imagen () const
{
  if (fuente)
  {
    return fuente;
  }
  else
  {
    if (almacenGlobal)
    {
      return almacenGlobal->get_bitmap (nombre);
    }
      else
      {
        return NULL;
      }
  }
};

