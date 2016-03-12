/*
 * linux
 * Copyright (C) Juanma Rico 2010 <juanmard@gmail.com>
 * 
 */

#ifndef _VECTORGUI_H_
#define _VECTORGUI_H_

#include <vector>
#include <allegro.h>

using std::vector;

/**
 *
 */
class VectorGUI
{
  public:
          VectorGUI (int &xParam, int &yParam);
          VectorGUI (int &xParam, int &yParam, vector<DIALOG> &guiParam);
    int   Teclado   (int msg, DIALOG *d, int code);
    int   Draw      (int msg, DIALOG *d, int code);
    int   Wheel     (int msg, DIALOG *d, int code);

  protected:
    int &             x;
    int &             y;
    unsigned int      ptoInserccion;
    vector<DIALOG> *  guiPadre;
    
  private:
    enum  {inicio=0, fin=1};
    static DIALOG dlg_plantilla[];

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

        // Se procesan los mensajes.
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
      return d_text_proc (msg, d, c);
    };
};

#endif // _VECTORGUI_H_
