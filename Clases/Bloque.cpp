/*
 * Copyright (C) Juanma Rico 2010 <juanmard@gmail.com>
 * 
 */

#include "Bloque.h"

/**
 * \brief   Constructor por omisión.
 */
Bloque::Bloque ():
x(0), y(0), w(0), h(0)
{
};

/**
 * \brief   Constructor por omisión.
 */
Bloque::Bloque (int paramX, int paramY, int paramW=0, int paramH=0):
x(paramX), y(paramY), w(paramW), h(paramH)
{
};

/**
 * \brief   Destructor por omisión.
 */
Bloque::~Bloque (){};

/**
 * \brief   Cambia posición del bloque.
 */
void Bloque::setXY (int paramX, int paramY)
{
  x = paramX;
  y = paramY;
};

/**
 * \brief   Cambia las dimensiones del bloque.
 */
void Bloque::setWH (int paramW, int paramH)
{
  w = paramW;
  h = paramH;
};

/**
 * \brief   Devuelve la coordenada X de la posición.
 */
int Bloque::getX () const
{
  return x;
};

/**
 * \brief   Devuelve la coordenada Y de la posición.
 */
int Bloque::getY () const
{
  return y;
};

/**
 * \brief   Devuelve el ancho del bloque.
 */
int Bloque::getW () const
{
  return w;
};

/**
 * \brief   Devuelve el alto del bloque.
 */
int Bloque::getH () const
{
  return h;
};

/**
 * \brief   Centra el bloque respecto a otro.
 * \param   bloque  Bloque que sirve de referencia para centrar.
 */
void Bloque::centrar (const Bloque &bloque)
{
    int incx = (w - bloque.getW())/2;
    int incy = (h - bloque.getH())/2;
    x = bloque.getX () - incx;
    y = bloque.getY () - incy;
}
