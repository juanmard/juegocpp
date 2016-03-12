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
          VectorGUI (int &xParam, int &yParam, vector<DIALOG> &guiParam);
    int   Teclado (int msg, DIALOG *d, int code);
    int   Dibujar (int msg, DIALOG *d, int code);

  protected:
    int &             x;
    int &             y;
    unsigned int      ptoInserccion;
    vector<DIALOG> &  guiPadre;
    
  private:
    enum  {inicio=0, fin=1};
    static DIALOG dlg_plantilla[];

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
        static int color_ant;

        // Se procesan los mensajes.
        switch (msg)
        {
          case MSG_CHAR:
          case MSG_UCHAR:
          case MSG_XCHAR:
            return obj.Teclado (msg, d, c);

          case MSG_START:
                color_ant = d->fg;
//              d->dp3 = new VectorGUI (a.x, a.y, gui_padre);
              break;

          case MSG_DRAW:
            rect (screen, d->x, d->y, d->x + d->w, d->y + d->h, color_ant);
            return obj.Dibujar (msg, d, c);

          case MSG_WANTFOCUS:
            return D_WANTFOCUS;

          case MSG_GOTFOCUS:
            d->fg = makecol (255,0,0);
            return D_O_K;

          case MSG_LOSTFOCUS:
            d->fg = color_ant;
            return D_O_K;
        }
      }
      return d_text_proc (msg, d, c);
    };
};

#endif // _VECTORGUI_H_
