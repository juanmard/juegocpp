/*
 * linux
 * Copyright (C) Juanma Rico 2010 <juanmard@gmail.com>
 * 
 */

#ifndef _GUIESCENARIO_H_
#define _GUIESCENARIO_H_

#include <allegro.h>
#include "GUIControl.h"
#include "EditorManager.h"

namespace alg4 {

class GUIEscenario : public GUIControl
{
  public:
          GUIEscenario  (fwg::EditorManager& editorParam, DIALOG* enlace=NULL);

  private:
    int   Keyboard      (int msg, DIALOG* d, int code);
    int   Draw          (int msg, DIALOG* d, int code);
    int   Wheel         (int msg, DIALOG* d, int code);
    int   MoveMouse     (int msg, DIALOG* d, int code);
    int   LPressMouse   (int msg, DIALOG* d, int code);
    int   DClick        (int msg, DIALOG* d, int code);
    int   Omision       (int msg, DIALOG* d, int code);

  private:
    fwg::EditorManager& editor;
};

}

#endif // _GUIESCENARIO_H_
