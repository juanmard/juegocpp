/**
 *  \file     AlmacenGUI.h
 *  \brief    GUI (graphical user interface) de la clase Almacen.
 *
 *  \details  La clase instancia de momento sólo la GUI para Allegro.
 *            Genera un vector (array) de estructuras DIALOG de Allegro.
 *            La estructura es fundamentalmente una lista con todos los 
 *            recursos que tiene el almacén, estos pueden ser seleccionados
 *            y explorados en la misma ventana.
 *
 *  \author  Juan Manuel Rico
 *  \date     diciembre 2010
 *  \version  1.00
 *
 *  \todo     Poder distinguir y explorar los recursos sonoros y de paleta.
 */
#ifndef _ALMACENGUI_H_
#define _ALMACENGUI_H_

#include <allegro.h>
#include <vector>
#include "Almacen.h"

using namespace std;

/**
 * \class   AlmacenGUI
 * \brief   Clase que genera una GUI (Graphical User Interface) para la clase 'Almacen'.
 * \todo   
 *          - Posibilidad de explorar las paletas de colores.
 *          - Posibilidad de explorar sonidos.
 *          - Construirlo como una ventana independiente que se pueda mover por pantalla.
 */
class AlmacenGUI
{
  public:
                      AlmacenGUI     (Almacen &almacenParam);
                      AlmacenGUI     ();
                      ~AlmacenGUI    ();
    void              activarAlmacen (Almacen &almacenParam);
    vector<DIALOG> &  getGUI         ();

  private:
    Almacen &         almacen;
    vector<DIALOG>    dlg;
    int               indice_ant;

  public:
    static Almacen *almacen_activo;
    static DIALOG dlg_plantilla[];
    /**
     * \brief   Método para rellenar el diálogo de la lista.
     */
    static char *  list_getter (int index, int *list_size)
    {
      if (almacen_activo)
      {
        // Si 'index' es negativo debe devolver NULL e indicar el tamaño de la lista.
        // Si 'index' es cero o positivo debe devolver la cadena del nombre del actor.
        if (index < 0)
        {
          *list_size = almacen_activo->getSize ();
          return NULL;
        }
        else
        {
          return const_cast<char *>(almacen_activo->getNombre (index).c_str());
        }
      }
    };

    /**
     * \brief   Callback de la lista que es la que controla el resto del diálogo.
     * \details Aunque es una función estática de la clase, esta funcionaría para
     *          todos los objetos siempre que guardemos en d[0].dp3 el almacén al
     *          que hace referencia.
     */
    static int callback (int msg, DIALOG *d, int c)
    {
      // Se sitúa el puntero del manager en 'dp3' pues en 'dp' 
      // debe estar el 'getter' de la lista y en 'dp2' el array de la selección.
      if (d[0].dp3)
      {
        // Creamos una referencia temporal al objeto actual.
        AlmacenGUI &obj = *(static_cast<AlmacenGUI *>(d[0].dp3));

        // Se procesan los mensajes.
        switch (msg)
        {
          case MSG_START:
              obj.indice_ant = 0;
//              almacen_activo = &(obj.almacen);
              break;

          case MSG_DRAW:
              almacen_activo = &(obj.almacen);
              break;

          case MSG_IDLE:
             // Si cambia el índice es que debemos actualizar el bitmap
              // y mandarle un mensaje para que se refresque.
              if (d[0].d1 != obj.indice_ant)
              {
                // Limpiamos el fondo antes de volver a dibujar.
                // Este bitmap lo podríamos hacer global a toda la clase.
                BITMAP *fondo = create_bitmap (d[2].w,d[2].h);
                clear_to_color(fondo, 243);
                d[2].dp = fondo;
                object_message(&d[2], MSG_DRAW, 0);
                destroy_bitmap (fondo);
                
                // Asignamos el recurso si es un bitmap.
                BITMAP *bitmap = obj.almacen.getBitmap (d[0].d1);
                if (bitmap) d[2].dp = obj.almacen.getBitmap (d[0].d1);
                obj.indice_ant = d[0].d1;
                return object_message(&d[2], MSG_DRAW, 0);
              }
              break;

          case MSG_GOTFOCUS:
              // Si tenemos el foco, puesto que este callback va en la lista, actualizamos
              // el almacén activo que lo tenemos guardado en 'dp3'.
              almacen_activo = &(obj.almacen);
              d[0].bg = 250;
              break;

          case MSG_LOSTFOCUS:
              d[0].bg = 243;
              break;
        }
      }
      return d_list_proc (msg, d, c);
    }
};

#endif // _ALMACEN_H_
