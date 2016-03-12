/*
 * linux
 * Copyright (C) Juanma Rico 2010 <juanmard@gmail.com>
 * 
 */

#ifndef _VECTORGUI_H_
#define _VECTORGUI_H_

#include <vector>
#include <allegro.h>
#include "EditorManager.h"

using std::vector;

/**
 *
 */
class VectorGUI
{
  public:
          VectorGUI (int &xParam, int &yParam, DIALOG *enlacesParam=NULL);
    void  addEnlace (DIALOG *enlace);
    void  setVector (int &xParam, int &yParam);

  private:
    int   Teclado   (int msg, DIALOG *d, int code);
    int   Draw      (int msg, DIALOG *d, int code);
    int   Wheel     (int msg, DIALOG *d, int code);

  private:
    int *     x;
    int *     y;
    DIALOG *  enlaces;

  public:
    /**
     * \brief  Callback de las coordenadas.
     */
    static int callback (int msg, DIALOG *d, int c)
    {
      // Se sitúa el puntero del objeto instanciado en 'dp3'.
      if (d->dp3)
      {
        // Creamos una referencia temporal al objeto actual.
        VectorGUI &obj = *(static_cast<VectorGUI *>(d->dp3));

        // Se procesan los mensajes propios.
        switch (msg)
        {
          case MSG_CHAR:
          case MSG_UCHAR:
          case MSG_XCHAR:
            return obj.Teclado (msg, d, c);

          case MSG_START:
            break;

          case MSG_DRAW:
            return obj.Draw (msg, d, c);

          case MSG_WANTFOCUS:
            return D_WANTFOCUS;

          case MSG_GOTFOCUS:
            d->fg = makecol (255,0,0);
            return D_O_K;

          case MSG_LOSTFOCUS:
            d->fg = gui_fg_color;
            return D_O_K;

          case MSG_WHEEL:
            return obj.Wheel (msg, d, c);
        }
      }

      // El resto de mensajes se procesan como si fuese un texto.
      return d_text_proc (msg, d, c);
    };
};

#endif // _VECTORGUI_H_
