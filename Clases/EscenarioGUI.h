/*
 * linux
 * Copyright (C) Juanma Rico 2010 <juanmard@gmail.com>
 * 
 */

#ifndef _ESCENARIOGUI_H_
#define _ESCENARIOGUI_H_

class EscenarioGUI
{
public:
          EscenarioGUI  (StageManager &escenarioParam);
    int   Keyboard      (int msg, DIALOG *d, int code);
    int   Draw          (int msg, DIALOG *d, int code);
    int   Wheel         (int msg, DIALOG *d, int code);

protected:

  public:
    /**
     * \brief  Callback del escenario.
     */
    static int callback (int msg, DIALOG *d, int c)
    {
      // Se sitúa el puntero del objeto instanciado en 'dp3'.
      if (d->dp3)
      {
        // Creamos una referencia temporal al objeto actual.
        EscenarioGUI &obj = *(static_cast<EscenarioGUI *>(d->dp3));

        // Se procesan los mensajes.
        switch (msg)
        {
          case MSG_CHAR:
          case MSG_UCHAR:
          case MSG_XCHAR:
            return obj.Keyboard (msg, d, c);

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

#endif // _ESCENARIOGUI_H_
