///
/// @file Bloque.cpp
/// @brief Fichero de la clase "Bloque".
/// @author Juan Manuel Rico
/// @date Noviembre 2015
/// @version 1.0.0
///

#include "Bloque.h"
#include <sstream>

Bloque::Bloque ():
pos(new Vector2Di()), w(0), h(0)
{
};

Bloque::Bloque (int paramX, int paramY, int paramW, int paramH):
pos(new Vector2Di(paramX,paramY)), w(paramW), h(paramH)
{
};

Bloque::~Bloque ()
{
    delete pos;
};

void Bloque::set_xy (int paramX, int paramY)
{
  pos->x = paramX;
  pos->y = paramY;
};

void Bloque::set_wh (unsigned int paramW, unsigned int paramH)
{
  w = paramW;
  h = paramH;
};

int Bloque::get_x () const
{
  return pos->x;
};

int Bloque::get_y () const
{
  return pos->y;
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
  pos->y = paramY;
};

void Bloque::centrar (const Bloque& bloque)
{
    int incx = (w - bloque.get_w())/2;
    int incy = (h - bloque.get_h())/2;
    pos->x = bloque.get_x () - incx;
    pos->y = bloque.get_y () - incy;
};

std::string& Bloque::print() const
{
    std::ostringstream canal;

    canal << "{" << std::endl;
    canal << "<" << get_x () << ", " << get_y () << ">" << std::endl;
    canal << "<" << get_w () << ", " << get_h () << ">" << std::endl;
    canal << "}" << std::endl;
    return *new std::string (canal.str());
};

