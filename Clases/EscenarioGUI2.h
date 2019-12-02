/*
 * linux
 * Copyright (C) Juanma Rico 2010 <juanmard@gmail.com>
 * 
 */

#ifndef _ESCENARIOGUI2_H_
#define _ESCENARIOGUI2_H_

#include <allegro.h>
#include "EditorManager.h"

namespace alg4 {

class EscenarioGUI2
{
  public:
          EscenarioGUI2  (fgm::EditorManager& editorParam, DIALOG* enlace=NULL);
    void  addEnlace     (DIALOG* enlace);

  private:
    int   Keyboard      (int msg, DIALOG* d, int code);
    int   Draw          (int msg, DIALOG* d, int code);
    int   Wheel         (int msg, DIALOG* d, int code);
    int   MoveMouse     (int msg, DIALOG* d, int code);
    int   LPressMouse   (int msg, DIALOG* d, int code);
    int   DClick        (int msg, DIALOG* d, int code);

  private:
    static int          local_x, local_y;
    fgm::EditorManager& editor;
    DIALOG*             enlaces;

  public:
    /**
     * \brief  Callback del escenario.
     */
    static int callback (int msg, DIALOG* d, int c)
    {
      // Se sitúa el puntero del objeto instanciado en 'dp3'.
      if (d->dp3)
      {
        // Creamos una referencia temporal al objeto actual.
        EscenarioGUI2& obj = *(static_cast<EscenarioGUI2*>(d->dp3));
        static int mouse_ant_x, mouse_ant_y;

        // Se procesan los mensajes.
        switch (msg)
        {
          // Mensaje que se produce repetidamente mientras no exista otro.
          case MSG_IDLE:
                // Se comprueba si se ha movido el ratón.
                if ( !((mouse_ant_x == mouse_x) && 
                       (mouse_ant_y == mouse_y)) )
                {
                    // El ratón se ha movido, se guarda el movimiento.
                    mouse_ant_x = mouse_x;
                    mouse_ant_y = mouse_y;

                    // Se calculan las coordenadas locales.
                    local_x = mouse_x - d->x;
                    local_y = mouse_y - d->y;

                    // Se llama al método dedicado al movimiento del ratón.
                    obj.MoveMouse (msg, d, c);
                }
                break;

          case MSG_CHAR:
          case MSG_UCHAR:
            return obj.Keyboard (msg, d, c);
/*
          case MSG_XCHAR:
            // Devolviendo D_USED_CHAR evitamos el 'broadcast' 
            // del código de teclado al resto de controles.
            return D_USED_CHAR;
*/
          case MSG_START:
            break;

          case MSG_DRAW:
            //return d_box_proc (msg,d,c);
            return obj.Draw (msg, d, c);

          case MSG_WANTFOCUS:
            return D_WANTFOCUS;

          case MSG_GOTFOCUS:
            d->fg = makecol (0,255,0);
            return D_REDRAWME;

          case MSG_LOSTFOCUS:
            d->fg = gui_fg_color;
            return D_REDRAWME;

          case MSG_WHEEL:
            //return obj.Wheel (msg, d, c);
            break;

          case MSG_LPRESS:
            return obj.LPressMouse (msg, d, c);

          case MSG_DCLICK:
            return obj.DClick (msg, d, c);
        }
      }
      return d_text_proc (msg, d, c);
    };
};
}

#endif // _ESCENARIOGUI2_H_
