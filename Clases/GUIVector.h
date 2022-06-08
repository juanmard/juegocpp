/*
 * linux
 * Copyright (C) Juanma Rico 2010 <juanmard@gmail.com>
 * 
 */

#ifndef _GUIVECTOR_H_
#define _GUIVECTOR_H_

#include <allegro.h>
#include "GUIControl.h"

/**
 * \class   GUIVector
 * \brief   Representa un vector en pantalla como dos números enteros en la misma línea y separados por una coma.
 *          Al pulsar las flechas del teclado derecha-izquierda o usar la rueda del ratón se modifica la posición x.
 *          Al pulsar las flechas del teclado arriba-abajo o usar la rueda del ratón junto con la tecla ALT se 
 *          modifica la posición y.
 */
class GUIVector : public GUIControl
{
  public:
          GUIVector (int &xParam, int &yParam);
    void  setVector (int &xParam, int &yParam);

  private:
    int   Keyboard  (int msg, DIALOG *d, int code);
    int   Draw      (int msg, DIALOG *d, int code);
    int   Wheel     (int msg, DIALOG *d, int code);
    int   Omision   (int msg, DIALOG *d, int code);

  private:
    int *     x;
    int *     y;
};

#endif // _GUIVECTOR_H_
