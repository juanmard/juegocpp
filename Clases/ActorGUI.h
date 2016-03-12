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
            set_dialog_color(&d[0], 192, 242);
            int obj;
            return dialog_message (&d[0], MSG_DRAW, 0, &obj);
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
};

#endif
