/*
 * linux
 * Copyright (C) Juanma Rico 2010 <juanmard@gmail.com>
 * 
 */

#include "VectorGUI2.h"
#include "EscenarioGUI.h"
#include <sstream>

using std::ostringstream;

/**
 * \brief   Constructor.
 */
VectorGUI2::VectorGUI2(int &xParam, int &yParam, DIALOG *enlacesParam):
x (&xParam),
y (&yParam),
enlaces (enlacesParam)
{
};

/**
 * \brief   Comprueba las teclas en el control del vector.
 * \return  El procesado de la tecla.
 */
int  VectorGUI2::Teclado (int msg, DIALOG *d, int code)
{
  // Salida por omisión.
  int salida = D_O_K;

  // Incrementos por omisión.
  int xInc = 0;
  int yInc = 0;

  // Se comprueba el 'scancode' y se obtiene el incremento.
  switch (code >> 8)
  {
    case KEY_UP:    yInc = -1; salida = D_USED_CHAR; break;
    case KEY_DOWN:  yInc = +1; salida = D_USED_CHAR; break;
    case KEY_LEFT:  xInc = -1; salida = D_USED_CHAR; break;
    case KEY_RIGHT: xInc = +1; salida = D_USED_CHAR; break;
  }

  // Actualizamos los valores referenciados por el vector.
  *x += xInc;
  *y += yInc;

  // Actualizamos su representación en pantalla.
  object_message (d, MSG_DRAW, 0);

  // Se actualizan los enlaces.
  if (enlaces) object_message (enlaces, MSG_DRAW, 0);

  // Se devuelve el código de salida.
  return salida;
};

/**
 * \brief   Dibuja los valores en la GUI.
 * \return  El valor al dibujar.
 */
int  VectorGUI2::Draw (int msg, DIALOG *d, int code)
{
  // Se borra el fondo.
  rectfill (screen, d->x, d->y, d->x + d->w, d->y + d->h, gui_bg_color);

  // Se actualizan los datos.
  ostringstream os;
  os << *x << "," << *y;
  d->dp = const_cast<char *>(os.str().c_str ());

  // Se dibuja como un texto.
  d_text_proc (msg, d, code);

  // Se actualizan los diálogos enlazados.
  // \todo  Convertir en una lista de enlaces: while (enlaces.end())....
  //        No deben ir aquí la actualización de los enlaces para no crear un
  //        bucle con los enlazados.
//  if (enlaces) object_message (enlaces, MSG_DRAW, 0);
//  if (editor) editor->dibujarEscenario ();
  return D_O_K;
};

/**
 * \brief   Comprueba la rueda del ratón.
 * \return  El procesado de la rueda.
 */
int  VectorGUI2::Wheel (int msg, DIALOG *d, int code)
{
  // Actualizamos los valores referenciados por el vector según los clicks de la rueda.
  if (key[KEY_ALT])
  {
    *y += code;
  }
  else
  {
    *x += code;
  }

  // Actualizamos su representación en pantalla.
  object_message (d, MSG_DRAW, 0);

  // Se actualizan los enlaces.
  if (enlaces) object_message (enlaces, MSG_DRAW, 0);

  return D_O_K;
};

/**
 * \brief   Añade un enlace a otro diálogo.
 */
void  VectorGUI2::addEnlace (DIALOG *enlace)
{
  // enlaces.push_back (enlace);
  enlaces = enlace;
};

/**
 * \brief   Se cambia el par de valores a los que se hace referencia en la GUI.
 */
void  VectorGUI2::setVector (int &xParam, int &yParam)
{
  x = &xParam;
  y = &yParam;
}
