///
/// @file Bloque.cpp
/// @brief Fichero de la clase "Bloque".
/// @author Juan Manuel Rico
/// @date Noviembre 2015
/// @version 1.0.0
///

#include "Bloque.h"

Bloque::Bloque ():
x(0), y(0), w(0), h(0)
{
};

Bloque::Bloque (int paramX, int paramY, int paramW, int paramH):
x(paramX), y(paramY), w(paramW), h(paramH)
{
};

Bloque::~Bloque ()
{
};

void Bloque::set_xy (int paramX, int paramY)
{
  x = paramX;
  y = paramY;
};

void Bloque::set_wh (int paramW, int paramH)
{
  w = paramW;
  h = paramH;
};

int Bloque::get_x () const
{
  return x;
};

int Bloque::get_y () const
{
  return y;
};

unsigned int Bloque::get_w () const
{
  return w;
};

unsigned int Bloque::get_h () const
{
  return h;
};

void Bloque::set_y (int paramY)
{
  y = paramY;
};

void Bloque::centrar (const Bloque& bloque)
{
    int incx = (w - bloque.get_w())/2;
    int incy = (h - bloque.get_h())/2;
    x = bloque.get_x () - incx;
    y = bloque.get_y () - incy;
};

