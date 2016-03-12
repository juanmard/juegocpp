/*
 * linux
 * Copyright (C) Juanma Rico 2010 <juanmard@gmail.com>
 * 
 */

#include "GUIControl.h"
#include <iostream>

/**
 * \brief   Constructor.
 */
GUIControl::GUIControl ()
{
  enlazados.clear ();
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
int  GUIControl::MoveMouse (int msg, DIALOG *d, int code)
{
  return D_O_K;
};

/**
 * \brief   Envía mensaje por omisión.
 * \return  Mensaje.
 */
int  GUIControl::LPressMouse (int msg, DIALOG *d, int code)
{
  return D_O_K;
};

/**
 * \brief   Envía mensaje por omisión.
 * \return  Mensaje.
 */
int GUIControl::DClick (int msg, DIALOG *d, int code)
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

/**
 * \brief   Dibuja los DIALOG de Allegro enlazados con el control.
 * \return  Mensaje.
 */
int  GUIControl::DrawEnlazados (int msg, DIALOG *d, int code)
{
  vector<DIALOG *>::iterator iter;

  for (iter = enlazados.begin(); iter != enlazados.end(); iter++)
  {
    object_message (*iter, MSG_DRAW, 0);
    std::cout << "Dibujado enlace. " << *iter << std::endl;
  }
};

/**
 * \brief   Añade un enlace a un DIALOG para refrescarlo al mismo tiempo que se dibuja el control.
 * \return  Mensaje.
 */
void  GUIControl::addEnlace (DIALOG *enlace)
{
  std::cout << "Añadido enlace." << std::endl;
  enlazados.push_back (enlace);
};
