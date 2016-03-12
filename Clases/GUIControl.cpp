/*
 * linux
 * Copyright (C) Juanma Rico 2010 <juanmard@gmail.com>
 * 
 */

#include "GUIControl.h"

/**
 * \brief   Constructor.
 */
GUIControl::GUIControl ()
{
};

/**
 * \brief   Comprueba las teclas en el control.
 * \param   msg   Mensaje.
 * \param   d     Puntero al dialogo Allegro que provoca la llamada.
 * \param   code  Código.
 * \return  El procesado de la tecla.
 */
int  GUIControl::Keyboard (int msg, DIALOG *d, int code)
{
  return D_O_K;
};

/**
 * \brief   Dibuja los valores en la GUI.
 * \return  El valor al dibujar.
 */
int  GUIControl::Draw (int msg, DIALOG *d, int code)
{
  return D_O_K;
};

/**
 * \brief   Comprueba la rueda del ratón.
 * \return  El procesado de la rueda.
 */
int  GUIControl::Wheel (int msg, DIALOG *d, int code)
{
  return D_O_K;
};

/**
 * \brief   Envía mensaje por omisión.
 * \return  Mensaje.
 */
int  GUIControl::Omision (int msg, DIALOG *d, int code)
{
  return D_O_K;
};
