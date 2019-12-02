/*
 * linux
 * Copyright (C) Juanma Rico 2010 <juanmard@gmail.com>
 * 
 */

#include "GUIEscenario.h"
#include <sstream>

namespace alg4 {

/**
 * \brief   Constructor.
 */
GUIEscenario::GUIEscenario (fgm::EditorManager& editorParam, DIALOG* enlace):
editor (editorParam)
{
  enlazados.clear ();
  if (enlace) addEnlace (enlace);
};

/**
 * \brief   Comprueba las teclas en el control del vector.
 * \return  El procesado de la tecla.
 */
int  GUIEscenario::Keyboard (int msg, DIALOG* d, int code)
{
  int salida = D_O_K;

  // Se comprueba el 'scancode' y se obtiene el incremento.
  //int xInc = 0;
  //int yInc = 0;
  //switch (code >> 8)
  //{
  //  case KEY_UP:    yInc = -1; salida = D_USED_CHAR; break;
  //  case KEY_DOWN:  yInc = +1; salida = D_USED_CHAR; break;
  //  case KEY_LEFT:  xInc = -1; salida = D_USED_CHAR; break;
  //  case KEY_RIGHT: xInc = +1; salida = D_USED_CHAR; break;
  //}

  // Actualizamos los valores referenciados por el vector.
  //x = xInc;
  //y = yInc;

  // Actualizamos los valores en la gui.
  object_message (d, MSG_DRAW, 0);

  // Se devuelve el código de salida.
  return salida;
};

/**
 * \brief   Dibuja los valores en la GUI.
 * \return  El valor al dibujar.
 */
int  GUIEscenario::Draw (int msg, DIALOG* d, int code)
{
  // Se oculta el puntero del ratón.
  show_mouse (NULL);

  // Se actualiza el ribete y se dibuja.
  editor.set_color_ribete (d->fg);
  editor.dibujar_escenario ();

  // Se muestra el puntero del ratón.
  show_mouse (screen);

  return D_O_K;
};

/**
 * \brief   Comprueba la rueda del ratón.
 * \return  El procesado de la rueda.
 */
int  GUIEscenario::Wheel (int msg, DIALOG* d, int code)
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
int  GUIEscenario::MoveMouse (int msg, DIALOG* d, int code)
{
  // Calculamos las posiciones locales del puntero del ratón.
  int local_x = mouse_x - d->x;
  int local_y = mouse_y - d->y;

  // Si el editor nos dice que hay un actor atrapado por el ratón, movemos el actor.
  if ( editor.is_actor_atrapado () )
  {
    editor.mover_actor_2 (local_x, local_y);
    Draw (msg, d, code);
//    DrawEnlazados (msg, d, code);
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
  std::ostringstream os;
  os  << "Globales: " << mouse_x << "," << mouse_y;
  textout_ex (screen, font, os.str().c_str(), 0, 400, gui_fg_color, gui_bg_color);

  return D_O_K;
};

/**
 * \brief   Sigue los movimientos del ratón.
 * \return  El valor obtenido al dibujar y actualizar el escenario.
 */
int  GUIEscenario::LPressMouse (int msg, DIALOG* d, int code)
{
  // Si hay un actor atrapado, lo liberamos.
  // En otro caso, intentamos atrapar uno bajo el cursor.
  if ( editor.is_actor_atrapado () )
  {
    editor.liberar_actor ();
  }
  else
  {
    // Calculamos las posiciones locales del puntero del ratón.
    int local_x = mouse_x - d->x;
    int local_y = mouse_y - d->y;

    editor.atrapar_actor (local_x, local_y);
  }
  Draw (msg, d, code);
  return D_O_K;
};

/**
 * \brief   Sigue los movimientos del ratón.
 * \return  El valor obtenido al dibujar y actualizar el escenario.
 */
int  GUIEscenario::DClick (int msg, DIALOG* d, int code)
{
  // Calculamos las posiciones locales del puntero del ratón.
  int local_x = mouse_x - d->x;
  int local_y = mouse_y - d->y;

  editor.fijar_actor (local_x, local_y);
  Draw (msg, d, code);
  return D_O_K;
};

/**
 * \brief   Sigue los movimientos del ratón.
 * \return  El valor obtenido al dibujar y actualizar el escenario.
 */
int  GUIEscenario::Omision (int msg, DIALOG* d, int code)
{
  return d_text_proc (msg, d, code);
};

}