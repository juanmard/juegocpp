///
/// @file AlmacenGUI.h
/// @brief Fichero de definición de la clase "AlmacenGUI".
/// @author Juan Manuel Rico
/// @date Marzo 2010
/// @version
///      - 1.0.0 Marzo 2010
///      - 1.0.1 Diciembre 2010
///      - 1.0.2 Noviembre 2015
///

#ifndef _ALMACENGUI_H_
#define _ALMACENGUI_H_

#include <allegro.h>
#include <vector>
#include "Almacen.h"

namespace alg4 {

/// Clase que genera una GUI (Graphical User Interface) para la clase 'Almacen'.
///
/// La clase instancia de momento sólo la GUI para Allegro.
/// Genera un vector (array) de estructuras DIALOG de Allegro.
/// La estructura es fundamentalmente una lista con todos los 
/// recursos que tiene el almacén, estos pueden ser seleccionados
/// y explorados en la misma ventana.
/// Esta clase intenta dar cobertura GUI al almacén donde se guardan los recursos, se debe
/// buscar una forma de independizar de Allegro. Hasta ahora se estaba usando el heredarlo
/// de la clase Formulario, pero en este caso no se hizo. También existe la opción de hacerlo
/// heredar de un AllegroObject, que traduzca los procedimientos virtuales para mostrar y
/// controlar de la forma particular en que lo hace Allegro.
///
/// @todo Por hacer:
///          - Posibilidad de explorar las paletas de colores.
///          - Posibilidad de explorar sonidos.
///          - Construirlo como una ventana independiente que se pueda mover por pantalla.
///          - Independizarlo de Allegro.
///
class AlmacenGUI
{
  private:
    fgm::Almacen& almacen;
    unsigned int pto_inserccion;
    std::vector<DIALOG> dlg;

    // Estas propiedades no deberían pertenecer a esta clase, sino
    // a unas subclases de tipo 'lista' y 'ventana'.
    int indice_ant;
    int x_ant, y_ant;
    bool activado;
    bool atrapado;

public:
    /// Constructor de la GUI para el almacén dado por parámetro.
    /// @param almacen  Referencia al almacén que se le asocia esta GUI.
    ///
    AlmacenGUI (fgm::Almacen& almacenParam);

    /// Constructor de la GUI para el almacén dado por parámetro.
        AlmacenGUI ();
        AlmacenGUI (fgm::Almacen& almacen, std::vector<DIALOG>& dlg_padre);
        ~AlmacenGUI ();
    void activar_almacen (fgm::Almacen& almacen);
    std::vector<DIALOG>& get_GUI ();
    void add_GUI (std::vector<DIALOG>& padre);

private:
    void mover_mouse (DIALOG* dlg);

  public:
    static fgm::Almacen* almacen_activo;
    static DIALOG dlg_plantilla[];
    
    /**
     * \brief   Método para rellenar el diálogo de la lista.
     */
    static char* list_getter (int index, int *list_size)
    {
      char* salida = NULL;
      if (almacen_activo)
      {
        // Si 'index' es negativo debe devolver NULL e indicar el tamaño de la lista.
        // Si 'index' es cero o positivo debe devolver la cadena del nombre del actor.
        if (index < 0)
        {
          *list_size = almacen_activo->get_size ();
        }
        else
        {
          std::string* cadena = new std::string(almacen_activo->get_nombre (index));
          salida = const_cast<char*>(cadena->c_str());
        }
      }
      return salida;
    };

    /**
     * \brief   Callback de la lista. Es la que controla el resto del diálogo.
     * \details Aunque es una función estática de la clase, esta funcionaría para
     *          todos los objetos siempre que guardemos en d[0].dp3 el objeto al
     *          que hace referencia.
     */
    static int callback (int msg, DIALOG* d, int c)
    {
      // Se sitúa el puntero del manager en 'dp3' pues en 'dp' 
      // debe estar el 'getter' de la lista y en 'dp2' el array de la selección.
      if (d[0].dp3)
      {
        // Creamos una referencia temporal al objeto actual.
        AlmacenGUI& obj = *(static_cast<AlmacenGUI*>(d[0].dp3));

        // Se procesan los mensajes.
        switch (msg)
        {
          case MSG_START:
              obj.indice_ant = 0;
              break;

          case MSG_DRAW:
              // Activamos el almacén correcto para dibujarlo.
             // almacen_activo = &(obj.almacen);
              break;

          case MSG_IDLE:
             // Si cambia el índice es que debemos actualizar el bitmap
              // y mandarle un mensaje para que se refresque.
              if (d[0].d1 != obj.indice_ant)
              {
                // Limpiamos el fondo antes de volver a dibujar.
                // Este bitmap lo podríamos hacer global a toda la clase.
                BITMAP* fondo = create_bitmap (d[2].w,d[2].h);
                clear_to_color (fondo, gui_bg_color);
                d[2].dp = fondo;
                object_message (&d[2], MSG_DRAW, 0);
                destroy_bitmap (fondo);
                
                // Asignamos el recurso si es un bitmap.
                BITMAP* bitmap = obj.almacen.get_bitmap (d[0].d1);
                if (bitmap) d[2].dp = bitmap;
                obj.indice_ant = d[0].d1;
                return object_message(&d[2], MSG_DRAW, 0);
              }
              break;

          case MSG_GOTFOCUS:
//              d->bg = gui_fg_color;
//              return D_REDRAWME;

          case MSG_LOSTFOCUS:
//              d->bg = gui_bg_color;
//              return D_REDRAWME;
            break;
        }
      }

      // El resto de mensajes se tratan como una lista estándar.
      return d_list_proc (msg, d, c);
    };

    /**
     * \brief   Callback del contenedor (box).
     * \details Este 'callback' debería ir en otra clase como de tipo 'ventana'
     *          que reflejara el movimiento de una ventana estándar. Este
     *          contenedor se usa para mover el diálogo completo.
     *
     * \todo    Separar este control como una ventana.
     */
    static int callback_mov (int msg, DIALOG* d, int c)
    {
      // Se comprueba si el puntero del objeto está ya en 'dp3.
      if (d[0].dp3)
      {
        // Creamos una referencia temporal al objeto actual.
        AlmacenGUI &obj = *(static_cast<AlmacenGUI *>(d[0].dp3));

        // Se procesan los mensajes.
        switch (msg)
        {
          case MSG_START:
              obj.activado = false;
              obj.atrapado = false;
              break;

          case MSG_IDLE:
              // Se comprueba si se ha movido el ratón.
              if ( (obj.x_ant != mouse_x) || 
                   (obj.y_ant != mouse_y) )
               {
                // El ratón se ha movido.
                obj.x_ant = mouse_x;
                obj.y_ant = mouse_y;
                obj.mover_mouse (d);
              }
            break;

          case MSG_DRAW:
              break;

          case MSG_LPRESS:
              obj.atrapado = true;
              d[0].bg = 250;
              return D_REDRAW;

          case MSG_LRELEASE:
              obj.atrapado = false;
              d[0].bg = 243;
              return D_REDRAW;

          case MSG_GOTMOUSE:
              obj.activado = true;
              break;

          case MSG_LOSTMOUSE:
              obj.activado = false;
              break;
         }
      }
      return d_box_proc (msg, d, c);
    }
};

}

#endif
