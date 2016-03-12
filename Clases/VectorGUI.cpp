/*
 * linux
 * Copyright (C) Juanma Rico 2010 <juanmard@gmail.com>
 * 
 */

#include "VectorGUI.h"
#include <sstream>

using std::ostringstream;

DIALOG VectorGUI::dlg_plantilla[] =
{
   /* (proc)              (x) (y)  (w)  (h) (fg) (bg) (key) (flags) (d1) (d2) (dp)  (dp2) (dp3) */
   { VectorGUI::callback, 40, 204, 108, 24, 67,  243, 0,    0,      0,   0,   NULL, NULL, NULL },
   { NULL,                0,  0,   0,   0,  0,   0,   0,    0,      0,   0,   NULL, NULL, NULL }
};

/**
 * \brief   Constructor.
 */
VectorGUI::VectorGUI(int &xParam, int &yParam, vector<DIALOG> &guiParam):
x (xParam),
y (yParam),
guiPadre (guiParam)
{
  // Modificamos la plantilla.
  dlg_plantilla[inicio].dp3 = this;

  // Se guarda el punto de insercción y añadimos la plantilla de la GUI al padre.
  ptoInserccion = guiPadre.size ()-1;
  guiPadre.insert (guiPadre.end()-1, &dlg_plantilla[inicio], &dlg_plantilla[fin]);
};

/**
 * \brief   Comprueba las teclas en el control del vector.
 * \return  El procesado de la tecla.
 */
int  VectorGUI::Teclado (int msg, DIALOG *d, int code)
{
  int salida = D_O_K;

  // Se comprueba el 'scancode' y se obtiene el incremento.
  int xInc = 0;
  int yInc = 0;
  switch (code >> 8)
  {
    case KEY_UP:    yInc = -1; salida = D_USED_CHAR; break;
    case KEY_DOWN:  yInc = +1; salida = D_USED_CHAR; break;
    case KEY_LEFT:  xInc = -1; salida = D_USED_CHAR; break;
    case KEY_RIGHT: xInc = +1; salida = D_USED_CHAR; break;
  }

  // Actualizamos los valores referenciados por el vector.
  x += xInc;
  y += yInc;

  // Actualizamos los valores en la gui.
  object_message(d, MSG_DRAW, 0);

  // Enviamos el código
  return salida;
};

/**
 * \brief   Dibuja los valores en la GUI.
 * \return  El valor al dibujar.
 */
int  VectorGUI::Dibujar (int msg, DIALOG *d, int code)
{
  ostringstream os;

  os << x << "," << y;
  d->dp = const_cast<char *>(os.str().c_str ());
  return d_text_proc (msg, d, code);
};

