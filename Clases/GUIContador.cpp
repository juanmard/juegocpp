/*
 * linux
 * Copyright (C) Juanma Rico 2011 <juanmard@gmail.com>
 * 
 */

#include "GUIContador.h"
#include <sstream>

using std::ostringstream;

/**
 * \brief   Constructor.
 */
GUIContador::GUIContador (unsigned int &contadorParam):
contador (contadorParam)
{
};

/**
 * \brief   Comprueba las teclas en el control del vector.
 * \return  El procesado de la tecla.
 */
int  GUIContador::Keyboard (int msg, DIALOG *d, int code)
{
  int salida = D_O_K;

  // Se comprueba el 'scancode' y se obtiene el incremento.
  int Inc = 0;
  switch (code >> 8)
  {
    case KEY_UP:    Inc = -1; salida = D_USED_CHAR; break;
    case KEY_DOWN:  Inc = +1; salida = D_USED_CHAR; break;
  }

  // Actualizamos los valores referenciados por el contador.
  contador += Inc;

  // Actualizamos los valores en la gui.
  object_message (d, MSG_DRAW, 0);

  // Se devuelve el código de salida.
  return salida;
};

/**
 * \brief   Dibuja los valores en la GUI.
 * \return  El valor al dibujar.
 */
int  GUIContador::Draw (int msg, DIALOG *d, int code)
{
  // Se borra el fondo.
  rectfill (screen, d->x, d->y, d->x + d->w, d->y + d->h, gui_bg_color);

  // Se actualizan los datos.
  ostringstream os;
  os << contador;
  d->dp = const_cast<char *>(os.str().c_str ());

  // Se escribe como un texto.
  return d_text_proc (msg, d, code);
};

/**
 * \brief   Comprueba la rueda del ratón.
 * \return  El procesado de la rueda.
 */
int  GUIContador::Wheel (int msg, DIALOG *d, int code)
{
  int salida = D_O_K;

  // Actualizamos los valores referenciados por el vector según los clicks de la rueda.
  contador += code;

  // Actualizamos los valores en la gui.
  object_message (d, MSG_DRAW, 0);

  // Se devuelve el código de salida.
  return salida;
};

/**
 * \brief   Comprueba la rueda del ratón.
 * \return  El procesado de la rueda.
 */
int  GUIContador::Omision (int msg, DIALOG *d, int code)
{
  return d_text_proc (msg, d, code);
}
