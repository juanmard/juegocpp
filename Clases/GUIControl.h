/**
 * 
 * 
 */

#ifndef _GUICONTROL_H_
#define _GUICONTROL_H_

#include <allegro.h>

/**
 * \brief   Clase que sirve como base a controles más complejos bajo C++.
 */
class GUIControl
{
  public:
                  GUIControl    ();
    virtual int   Keyboard      (int msg, DIALOG *d, int code);
    virtual int   Draw          (int msg, DIALOG *d, int code);
    virtual int   Wheel         (int msg, DIALOG *d, int code);
    virtual int   Omision       (int msg, DIALOG *d, int code);

  public:
    /**
     * \brief  Callback del control.
     */
    static int callback (int msg, DIALOG *d, int c)
    {
      // Se sitúa el puntero del objeto instanciado en 'dp3'.
      if (d->dp3)
      {
        // Creamos una referencia temporal al objeto actual.
        GUIControl &obj = *(static_cast<GUIControl *>(d->dp3));

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
        return obj.Omision (msg, d, c);
      }
    };
};

#endif // _GUICONTROL_H_
