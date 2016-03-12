/*
 * linux
 * Copyright (C) Juanma Rico 2010 <juanmard@gmail.com>
 * 
 */

#include "GUIVector.h"
#include <sstream>

using std::ostringstream;

/**
 * \brief   Constructor.
 */
GUIVector::GUIVector(int &xParam, int &yParam):
x (&xParam),
y (&yParam)
{
};

/**
 * \brief   Comprueba las teclas en el control del vector.
 * \return  El procesado de la tecla.
 */
int  GUIVector::Teclado (int msg, DIALOG *d, int code)
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

  // Se devuelve el código de salida.
  return salida;
};

/**
 * \brief   Dibuja los valores en la GUI.
 * \return  El valor al dibujar.
 */
int  GUIVector::Draw (int msg, DIALOG *d, int code)
{
  // Se borra el fondo.
  rectfill (screen, d->x, d->y, d->x + d->w, d->y + d->h, gui_bg_color);

  // Se actualizan los datos.
  ostringstream os;
  os << *x << "," << *y;
  d->dp = const_cast<char *>(os.str().c_str ());

  // Se dibuja como un texto.
  d_text_proc (msg, d, code);
  return D_O_K;
};

/**
 * \brief   Comprueba la rueda del ratón.
 * \return  El procesado de la rueda.
 */
int  GUIVector::Wheel (int msg, DIALOG *d, int code)
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
  return D_O_K;
};

/**
 * \brief   Se cambia el par de valores a los que se hace referencia en la GUI.
 */
void  GUIVector::setVector (int &xParam, int &yParam)
{
  x = &xParam;
  y = &yParam;
}

/**
 * \brief   Mensaje que se envía por omisión ante cualquier otro mensaje no procesado.
 * \details Los mensajes no procesados se tratan como un control de texto normal.
 * \param   msg   Mensaje enviado por Allegro.
 * \param   d     Puntero al diálogo que genera el mensaje.
 * \param   code  Código.
 * \return  El código obtenido por omisión.
 */
int  GUIVector::Omision (int msg, DIALOG *d, int code)
{
  return d_text_proc (msg, d, code);
};

