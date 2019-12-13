/*
 * linux
 * Copyright (C) Juanma Rico 2010 <juanmard@gmail.com>
 * 
 */

#include "EscenarioGUI2.h"
#include <sstream>

namespace alg4 {

// Variables locales para el mouse.
int EscenarioGUI2::local_x = 0;
int EscenarioGUI2::local_y = 0;

/**
 * \brief   Constructor.
 */
EscenarioGUI2::EscenarioGUI2 (fwg::EditorManager& editorParam, DIALOG* enlace):
editor (editorParam),
enlaces (enlace)
{
};

/**
 * \brief   Comprueba las teclas en el control del vector.
 * \return  El procesado de la tecla.
 */
int  EscenarioGUI2::Keyboard (int msg, DIALOG* d, int code)
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
  local_x += xInc;
  local_y += yInc;

  // Actualizamos los valores en la gui.
  object_message (d, MSG_DRAW, 0);

  // Se devuelve el código de salida.
  return salida;
};

/**
 * \brief   Dibuja los valores en la GUI.
 * \return  El valor al dibujar.
 */
int  EscenarioGUI2::Draw (int msg, DIALOG* d, int code)
{
  show_mouse (NULL);
  // Actualizamos el ribete y dibujamos.
  editor.set_color_ribete (d->fg);
  editor.dibujar_escenario ();

  // Actualizamos los enlaces.
  if (enlaces) object_message (enlaces, MSG_DRAW, 0);
  show_mouse (screen);
  return D_O_K;
};

/**
 * \brief   Comprueba la rueda del ratón.
 * \return  El procesado de la rueda.
 */
int  EscenarioGUI2::Wheel (int msg, DIALOG* d, int code)
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
int  EscenarioGUI2::MoveMouse (int msg, DIALOG* d, int code)
{
  // Si el editor nos dice que hay un actor atrapado por el ratón, movemos el actor.
  if ( editor.is_actor_atrapado () )
  {
    editor.mover_actor_2 (local_x, local_y);
    Draw (msg, d, code);
  }
  else
  {
    // Si no hay ningún actor fijo, se activa el actor bajo el cursor.
    if ( !editor.is_actor_fijo () )
    {
      editor.activar_actor (local_x, local_y);
      Draw (msg, d, code);
    }

    // Si el atrapado es el decorado, se mueve el decorado.
    if ( editor.is_decorado_atrapado () )
    {
      editor.mover_decorado (local_x, local_y);
      editor.actualizar_decorado ();
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
int  EscenarioGUI2::LPressMouse (int msg, DIALOG* d, int code)
{
  // Si hay un actor atrapado, lo liberamos.
  // En otro caso, intentamos atrapar uno bajo el cursor.
  if ( editor.is_actor_atrapado () )
  {
    editor.liberar_actor ();
  }
  else
  {
    editor.atrapar_actor (local_x, local_y);
  }
  Draw (msg, d, code);
  return D_O_K;
};

/**
 * \brief   Sigue los movimientos del ratón.
 * \return  El valor obtenido al dibujar y actualizar el escenario.
 */
int  EscenarioGUI2::DClick (int msg, DIALOG* d, int code)
{
  editor.fijar_actor (local_x, local_y);
  Draw (msg, d, code);
  return D_O_K;
};

/**
 * \brief   Añade un enlace a otro diálogo.
 * \details Este enlace se utiliza para actualizar el aspecto de otro diálogo
 *          enlazado al cambio de éste.
 */
void  EscenarioGUI2::addEnlace (DIALOG* enlace)
{
  enlaces = enlace;
};

}