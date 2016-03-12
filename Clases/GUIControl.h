/**
 * 
 * 
 */

#ifndef _GUICONTROL_H_
#define _GUICONTROL_H_

#include <allegro.h>
#include <vector>

using std::vector;

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
    virtual int   MoveMouse     (int msg, DIALOG *d, int code);
    virtual int   LPressMouse   (int msg, DIALOG *d, int code);
    virtual int   DClick        (int msg, DIALOG *d, int code);
    virtual int   Omision       (int msg, DIALOG *d, int code);
    void          addEnlace     (DIALOG *enlace);

  protected:
    vector<DIALOG *>    enlazados;
    bool                foco;
    int                 DrawEnlazados (int msg, DIALOG *d, int code);

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
          // Mensaje que se produce repetidamente mientras no exista otro.
          case MSG_IDLE:
                static int    mouse_ant_x, mouse_ant_y;

                // Se comprueba si se ha movido el ratón.
                if ( !((mouse_ant_x == mouse_x) && (mouse_ant_y == mouse_y)) )
                {
                    // El ratón se ha movido, se guarda el movimiento.
                    mouse_ant_x = mouse_x;
                    mouse_ant_y = mouse_y;

                    // Se llama al método dedicado al movimiento del ratón.
                    obj.MoveMouse (msg, d, c);
                }
                return D_O_K;

          case MSG_CHAR:
          case MSG_UCHAR:
          case MSG_XCHAR:
            return obj.Keyboard (msg, d, c);

          case MSG_START:
            break;

          case MSG_DRAW:
            // Se llama al dibujo propio.
            obj.Draw (msg, d, c);

            // Si tengo el foco, yo dibujo a los demás.
            if (obj.foco)
            {
              obj.DrawEnlazados (msg, d, c);
            }
            return D_O_K;

          case MSG_WANTFOCUS:
            return D_WANTFOCUS;

          case MSG_GOTFOCUS:
            d->fg = makecol (255,0,0);
            obj.foco = true;
            return D_O_K;

          case MSG_LOSTFOCUS:
            d->fg = gui_fg_color;
            obj.foco = false;
            return D_O_K;

          case MSG_LPRESS:
            return obj.LPressMouse (msg, d, c);

          case MSG_DCLICK:
            return obj.DClick (msg, d, c);

          case MSG_WHEEL:
            return obj.Wheel (msg, d, c);
        }
        return obj.Omision (msg, d, c);
      }
    };
};

#endif // _GUICONTROL_H_
