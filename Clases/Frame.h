/**
 *  \file     Frame.h
 *  \brief    Prueba del "framework" de un juego.
 *
 *  \details  La clase instancia un tipo de juego de prueba con todos los controladores posibles.
 *            La primera versión de la instancia se utiliza para actualizar el juego de plataformas
 *            programado antiguamente en C "puro y duro".
 *
 *  \author   Juan Manuel Rico
 *  \date     diciembre 2010
 *  \version  1.00
 *
 *  \todo     Comentar todas estas clases y funciones más detalladamente.
 */
#ifndef _FRAME_H_
#define _FRAME_H_

#include <allegro.h>
#include "Mask.h"
#include <string>

using namespace std;

class Frame
{
public:
          Frame       ();
          ~Frame      ();
  string  getString   () const;

public:
  BITMAP *bmp;
  Mask *mask;
  int cx;
  int cy;
  int ticks;

private:

};

#endif // _FRAME_H_
