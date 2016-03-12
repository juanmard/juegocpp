#ifndef _ACTORGUI_H_
#define _ACTORGUI_H_

#include <allegro.h>
//#include "Actor.h"
#include <vector>

class Actor;

using namespace std;

/** 
 * \brief   GUI básica de los actores.
 */
class ActorGUI
{
  public:
    enum {navegador=0, nombre=10, posicion=11, tamano=12, grafico=13, tiempo=14, estado=15, slider=16, fin=17};

  public:
                    ActorGUI               (Actor &actor, vector<DIALOG> &gui_padre);
                    ActorGUI               ();
    virtual         ~ActorGUI              ();

  private:
    Actor &         actor;
    unsigned int    pto_inserccion;

  public:
    static DIALOG     dlg_plantilla[];
    static Actor *    actor_activo;

    /**
     * \brief   Callback de las coordenadas.
     */
    static int callback (int msg, DIALOG *d, int c)
    {
      // Se procesan los mensajes.
      switch (msg)
      {
        case MSG_LPRESS:
            set_dialog_color(d, gui_fg_color, gui_bg_color);
            int obj;
            return dialog_message (d, MSG_DRAW, 0, &obj);
      }
      return d_box_proc (msg, d, c);
    };

    /**
     * \brief   Getter de la lista de estados.
     */
    static char *  list_getter (int index, int *list_size)
    {
      if (actor_activo)
      {
        // Si 'index' es negativo debe devolver NULL e indicar el tamaño de la lista.
        // Si 'index' es cero o positivo debe devolver la cadena del nombre del actor.
        if (index < 0)
        {
          *list_size = 4;
          return NULL;
        }
        else
        {
          static char * prueba[] = {"uno", "dos", "tres", "cuatro"};
          return prueba[index];
        }
      }

    };
    /**
     * \brief   Callback del texto de gráfico.
     */
    static int callback_graf (int msg, DIALOG *d, int c)
    {
      switch (msg)
      {
        case MSG_LPRESS:
          break;
          
        case MSG_GOTMOUSE:
          d->fg = makecol8 (255,0,0);
          return D_REDRAWME;
          
        case MSG_LOSTMOUSE:
          d->fg = gui_fg_color;
          return D_REDRAWME;
      }
      return d_text_proc (msg, d, c);
    };

};

#endif
