/*
 * linux
 * Copyright (C) Juanma Rico 2010 <juanmard@gmail.com>
 * 
 */

#ifndef _GUICONTADOR_H_
#define _GUICONTADOR_H_

#include <allegro.h>
#include "GUIControl.h"

namespace alg4 {
/**
 *
 */
class GUIContador : public GUIControl
{
  public:
          GUIContador   (unsigned int& contadorParam);
    int   Keyboard      (int msg, DIALOG* d, int code);
    int   Draw          (int msg, DIALOG* d, int code);
    int   Wheel         (int msg, DIALOG* d, int code);
    int   Omision       (int msg, DIALOG* d, int code);

  protected:
    unsigned int&    contador;

};

}
#endif // _GUICONTADOR_H_
