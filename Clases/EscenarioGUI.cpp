/*
 * linux
 * Copyright (C) Juanma Rico 2010 <juanmard@gmail.com>
 * 
 */

#include "EscenarioGUI.h"
#include <sstream>

/**
 * \brief   Constructor.
 */
EscenarioGUI::EscenarioGUI (EditorManager &editorParam, DIALOG *enlace):
editor (editorParam),
enlaces (enlace)
{
};

/**
 * \brief   Comprueba las teclas en el control del vector.
 * \return  El procesado de la tecla.
 */
int  EscenarioGUI::Keyboard (int msg, DIALOG *d, int code)
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
  //x += xInc;
  //y += yInc;

  // Actualizamos los valores en la gui.
  object_message (d, MSG_DRAW, 0);

  // Se devuelve el código de salida.
  return salida;
};

/**
 * \brief   Dibuja los valores en la GUI.
 * \return  El valor al dibujar.
 */
int  EscenarioGUI::Draw (int msg, DIALOG *d, int code)
{
  show_mouse (NULL);
  // Actualizamos el ribete y dibujamos.
  editor.setColorRibete (d->fg);
  editor.dibujarEscenario ();

  // Actualizamos los enlaces.
  if (enlaces) object_message (enlaces, MSG_DRAW, 0);
  show_mouse (screen);
  return D_O_K;
};

/**
 * \brief   Comprueba la rueda del ratón.
 * \return  El procesado de la rueda.
 */
int  EscenarioGUI::Wheel (int msg, DIALOG *d, int code)
{
  int salida = D_O_K;

  // Actualizamos los valores referenciados por el vector según los clicks de la rueda.
  if (key[KEY_ALT])
  {
    //y += code;
  }
  else
  {
    //x += code;
  }

  // Actualizamos los valores en la gui.
  object_message (d, MSG_DRAW, 0);

  // Se devuelve el código de salida.
  return salida;
};

/**
 * \brief   Sigue los movimientos del ratón.
 * \return  El valor obtenido al dibujar y actualizar el escenario.
 */
int  EscenarioGUI::MoveMouse (int msg, DIALOG *d, int code)
{
  // Si el editor nos dice que hay un actor atrapado por el ratón, movemos el actor.
  if ( editor.isActorAtrapado () )
  {
    editor.moverActor (mouse_x, mouse_y);
    Draw (msg, d, code);
  }
  else
  {
    // Se activa el actor bajo el ratón.
    editor.activarActor (mouse_x, mouse_y);
    Draw (msg, d, code);

    // Si el atrapado es el decorado, se mueve el decorado.
    if ( editor.isDecoradoAtrapado () )
    {
      editor.moverDecorado (mouse_x, mouse_y);
      editor.actualizarDecorado ();
    }
  }

  // Se actualizan la coordenadas.
  // editor.setMensaje (os.str());
/*
  ostringstream os;
  os  << "Globales: " << mouse_x << "," << mouse_y;
  textout (screen, font, os.str().c_str(), 0, 300, gui_fg_color);
*/
  return D_O_K;
};

/**
 * \brief   Sigue los movimientos del ratón.
 * \return  El valor obtenido al dibujar y actualizar el escenario.
 */
int  EscenarioGUI::LMouse (int msg, DIALOG *d, int code)
{
  // Si hay un actor atrapado, lo liberamos.
  // En otro caso, intentamos atrapar uno bajo el cursor.
  if ( editor.isActorAtrapado () )
  {
    editor.liberarActor ();
  }
  else
  {
    editor.atraparActor (mouse_x, mouse_y);
  }
  Draw (msg, d, code);
  return D_O_K;
};

/**
 * \brief   Añade un enlace a otro diálogo.
 * \details Este enlace se utiliza para actualizar el aspecto de otro diálogo
 *          enlazado al cambio de éste.
 */
void  EscenarioGUI::addEnlace (DIALOG *enlace)
{
  enlaces = enlace;
};
