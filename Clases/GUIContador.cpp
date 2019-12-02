/*
 * linux
 * Copyright (C) Juanma Rico 2011 <juanmard@gmail.com>
 * 
 */

#include "GUIContador.h"
#include <sstream>

namespace alg4 {
/**
 * \brief   Constructor.
 */
GUIContador::GUIContador (unsigned int& contadorParam):
contador (contadorParam)
{
};

/**
 * \brief   Comprueba las teclas en el control y modifica el contador asociado.
 * \param   msg   Mensaje enviado por Allegro (MSG_CHAR, MSG_UCHAR, MSG_XCHAR).
 * \param   d     Puntero al diálogo que genera el mensaje.
 * \param   code  Código de la tecla que genera el mensaje.
 * \return  El procesado de la tecla.
 */
int  GUIContador::Keyboard (int msg, DIALOG* d, int code)
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
 * \param   msg   Mensaje enviado por Allegro (MSG_DRAW).
 * \param   d     Puntero al diálogo que genera el mensaje.
 * \param   code  Código no usado en este mensaje.
 * \return  El valor al dibujar.
 */
int  GUIContador::Draw (int msg, DIALOG* d, int code)
{
  // Se borra el fondo.
  rectfill (screen, d->x, d->y, d->x + d->w, d->y + d->h, gui_bg_color);

  // Se actualizan los datos.
  std::ostringstream os;
  os << contador;
  d->dp = const_cast<char *>(os.str().c_str ());

  // Se escribe como un texto.
  return d_text_proc (msg, d, code);
};

/**
 * \brief   Comprueba la rueda del ratón.
 * \param   msg   Mensaje enviado por Allegro (MSG_WHEEL).
 * \param   d     Puntero al diálogo que genera el mensaje.
 * \param   code  Código que representa los 'ticks' de la rueda.
 * \return  El procesado de la rueda.
 */
int  GUIContador::Wheel (int msg, DIALOG* d, int code)
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
 * \brief   Mensaje que se envía por omisión ante cualquier otro mensaje no procesado.
 * \details Los mensajes no procesados se tratan como un control de texto normal.
 * \param   msg   Mensaje enviado por Allegro.
 * \param   d     Puntero al diálogo que genera el mensaje.
 * \param   code  Código.
 * \return  El código obtenido por omisión.
 */
int  GUIContador::Omision (int msg, DIALOG* d, int code)
{
  return d_text_proc (msg, d, code);
};

}