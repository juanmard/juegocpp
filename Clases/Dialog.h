#pragma once

#include <sstream>
#include <string>
#include <allegro.h>
#include "EditorManager.h"
#include "BoxALG.h"
#include "TextALG.h"
#include "MenuALG.h"
#include "Menu.h"

class DlgActor;
class VentanaALG;
class DialogALG;
class ItemALG;

/**
 * \brief       Muestra una pequeña GUI para editar los objetos del juego.
 * \details     Esta GUI utiliza funciones básicas de Allegro. Contiene funciones globales para los
 *              "callback" de las componentes. Las funciones de modificación y actualización de
 *              objetos deben ser encomendadas a la clase "EditorManager".
 * \todo        Compatibilizar los "callback" globales mediante funciones estáticas de la clase.
 *              Ej. "Dialog::d_pantalla_proc" en las definiciones de "dialog".
 * \todo        Generalizar este entorno para que sirviera para cualquier librería y no sólo para Allegro.
 *              Para esto necesitamos "Diálogos", "Ventanas" y "Menús" generales, evitando las funciones de
 *              Allegro en ellas.
 */
class Dialog
{
public:
    // Enumerado de los controles para el diálogo.
    enum {scr=0, pantalla=0, 
          menu=1, lista=4, bitmap=5, caja=6 ,estado=7, posicion=13,
          nombre=15, dimensiones=18, 
          ultimo=19};

public:
                Dialog          (EditorManager *editor);
                ~Dialog         ();
    void        show            ();
    void        draw            ();
    void        mouse_out       ();
    void        mouse_in        ();
    int         propiedades     ();
    void        setActor        (Actor *actor);

protected:
    void        menu_contextual         (int x, int y);
    int         comprobarTecla          (int code);
    void        prueba_click            ();
    void        mover_actor             ();
    void        duplicarActor           ();
    int         CambiarTraje            ();
    void        actualizarValoresActor  ();
    void        dibujarCuadrado         (Bloque cuadro, int color);
    void        centrarActor            (int indice);
    void        setColorRibete          (int color);
    void        tomarReferencia         ();
    void        moverEscenario          ();
    void        moverMouse              ();
    int         kdb_coordenadas         (DIALOG *d, int code);

    ///
    /// Lee la lista de actores desde un fichero.
    ///
    void leerActores ();

    ///
    /// Graba la lista de actores a un fichero.
    ///
    void grabarActores ();

    EditorManager *   manager;
    Actor *           actor;
    string            strNombre;
    string            strPosicion;
    string            strDimensiones;
    string            strEstado;

    //Prueba de menú dinámico.
    Menu menu_dinamico;

public:
    // Diálogo principal. 
    static DIALOG   dialog[];

    // Variables estáticas del menú principal.
    static MENU     mnu_fichero[];
    static MENU     mnu_ayuda[];
    static MENU     menu_editor[];
    static MENU     mnu_actor[];

    // Referencias para el movimiento del ratón.
    int   ref_x, ref_y;
    bool  moviendoActor;

    ///
    /// Creamos un callback para el menú de fichero de allegro.
    ///
    static int menu_fichero (void)
    {
        // Se comprueba que se ha inicializado correctamente el menú con el
        // puntero 'this' al objeto instanciado.
        if (active_menu->dp)
        {
            // Creamos una referencia temporal al objeto instanciado.
            Dialog &objeto = *(static_cast<Dialog *>(active_menu->dp));

            // Suponemos que es la opción de duplicar.
            std::string *comando = new std::string(active_menu->text);

            if (!comando->compare("&Leer mapa"))
            {
                objeto.leerActores ();
            };

            if (!comando->compare("&Grabar mapa"))
            {
                objeto.grabarActores ();
            };
        }
      return D_O_K;
    };

    /**
     * \brief   Procedimiento callback del menú contextual.
     */
    static int cb_menu_opciones (void)
    {
      // Dialogo de prueba.
      //alert("Selected menu item:", "", active_menu->text, "Ok", NULL, 0, 0);

      // Se comprueba que se ha inicializado correctamente el menú con el
      // puntero 'this' al objeto instanciado.
      if (active_menu->dp)
      {
        // Creamos una referencia temporal al objeto instanciado.
        Dialog &objeto = *(static_cast<Dialog *>(active_menu->dp));

        // Si usamos este mismo método para todas las opciones del
        // menú contextual tenemos que seleccionar qué tipo de opción es.
        // Comparando 'active_menu->text' con la opción.

        // Suponemos que es la opción de duplicar.
        objeto.duplicarActor ();
      }
      return D_O_K;
    };

    /**
     * \brief   Rellenador de lista de actores.
     */
    static char *  getterListaActores (int index, int *list_size)
    {
      char * salida = NULL;
      if (dialog[lista].dp3)
      {
        // Creamos una referencia temporal al objeto.
        Dialog &objeto = *(static_cast<Dialog *>(dialog[lista].dp3));
        
        // Si 'index' es negativo debe devolver NULL e indicar el tamaño de la lista.
        // Si 'index' es cero o positivo debe devolver la cadena del nombre del actor.
        if (index < 0)
        {
          *list_size = objeto.manager->getNumActores ();
        }
        else
        {
          string *cadena = new string(objeto.manager->getNombreActor (index));
          salida = const_cast<char *>(cadena->c_str());
        }
      }
      return salida;
};

    /**
     * \brief   Función estática de prueba para englobar las funciones en la clase.
     * \details Necesita inicializar los menús donde se utiliza en el constructor de la clase.
     *          Pj:     mnu_ayuda[0].proc = &Dialog::about;
     *          O bien declarar pública para acceso externo y definir directamente en la variable
     *          global. P.j:
     *              MENU mnu_ayuda[] = 
     *              {
     *                  { "&About \tF1",     Dialog::about,  NULL,      0,  NULL  },
     *                  { NULL,                       NULL,  NULL,      0,  NULL  }
     *              };
     *          Otra opción de integración es definir también los menús como estáticos dentro
     *          de la definición de la clase. Ej:
     *              static MENU mnu_ayuda[];
     *          e inicializarlo en el fichero cpp. Ej:
     *              MENU Dialog::mnu_ayuda[] = { ... };
     *          en ese caso las variables si pueden ser protected o private.
     *
     */
    static int about (void)
    {
       alert("* Editor - Juego ++ *",
             "",
             "Editor basado en Allegro - Juanma Rico 2009",
             "Ok", 0, 0, 0); 
       return D_O_K;
    };

    /**
     * \brief   Mensaje de confirmación de salida del editor.
     */
    static int quit(void)
    {
       if (alert("¿Salir del editor?", NULL, NULL, "&Sí", "&No", 's', 'n') == 1)
          return D_CLOSE;
       else
          return D_O_K;
    };

    /**
     * \brief   Método "callback" de mensajes recibidos por el marco del diálogo.
     * \details Este método maneja todos los mensajes que se reciben dentro del marco que
     *          se dibuja sobre la pantalla actual.
     *          Es una función estática por compatibilidad con Allegro.
     *          El campo "dp" debe contener un puntero al objeto instanciado de la clase.
     *          Se procura que la parte estática sea mínima, pasando las llamadas a procesos
     *          protegidos de la clase.
     */
    static int callback_scr (int msg, DIALOG *d, int c)
    {
      // Si ya está inicializado el objeto (puntero existe), podemos crear 
      // una referencia  al objeto y utilizar sus métodos.
      // Si no está inicializado el objeto ignoramos el mensaje.
      if (d[0].dp)
      {
        // Creamos una referencia temporal al objeto actual.
        Dialog &objeto = *(static_cast<Dialog *>(d[0].dp));

        // Posición anterior del ratón antes de llamar.
        static int      mouse_ant_x, mouse_ant_y;

        // Se procesan los mensajes.
        switch (msg)
        {
           // En caso de que se pulse una tecla...
          case MSG_XCHAR:
              // Devolviendo D_USED_CHAR evitamos el 'broadcast' 
              // del código de teclado al resto de controles.
              return D_USED_CHAR;

          case MSG_CHAR:
          case MSG_UCHAR:
              return objeto.comprobarTecla (c);

          case MSG_WANTFOCUS:
              // Devolviendo D_WANTFOCUS indicamos que queremos el foco.
              return D_WANTFOCUS;

          case MSG_GOTFOCUS:
              // Si tenemos el foco cambiamos el color del ribete a verde.
              objeto.setColorRibete (makecol (0, 255, 0));
              return D_O_K;

          case MSG_LOSTFOCUS:
              // Si perdemos el foco cambiamos el color del ribete a gris.
              objeto.setColorRibete (makecol (100, 100, 100));
              return D_O_K;

          // El mensaje nos indica que debemos dibujar el control.
          case MSG_DRAW:
              objeto.draw ();
              return D_O_K;

          // Mensaje cuando se presiona el botón derecho del ratón.
          case MSG_RPRESS:
              objeto.prueba_click ();
              objeto.menu_contextual (mouse_x, mouse_y);
              break;

          case MSG_LPRESS:
              objeto.moviendoActor = true;
              objeto.prueba_click ();
              break;

          case MSG_LRELEASE:
              objeto.moviendoActor = false;
              break;

          case MSG_CLICK:
              break;

          case MSG_DCLICK:
              break;

          // Mensaje que se produce repetidamente mientras no exista otro.
          case MSG_IDLE:
                // Se comprueba si se ha movido el ratón.
                if ( !((mouse_ant_x == mouse_x) && 
                       (mouse_ant_y == mouse_y)) )
                {
                    // El ratón se ha movido.
                    mouse_ant_x = mouse_x;
                    mouse_ant_y = mouse_y;
                    objeto.moverMouse ();
                }
                break;
        }
      }
      return d_box_proc (msg,d,c);
    };

    /**
     * \brief   Callback de la lista de actores.
     */
    static int callback_lista (int msg, DIALOG *d, int c)
    {
      // Se sitúa el puntero del manager en 'dp3' pues en 'dp' 
      // debe estar el 'getter' de la lista y en 'dp2' el array de la selección.
      if (d[0].dp3)
      {
        // Creamos una referencia temporal al objeto actual.
        Dialog &objeto = *(static_cast<Dialog *>(d[0].dp3));
        //EditorManager &manager = *(static_cast<EditorManager *>(d[0].dp3));

        // Se guarda el índice para comprobar cuando cambia.
        static int indice_ant = d[0].d1;

        // Se procesan los mensajes.
        switch (msg)
        {
          case MSG_IDLE:
              if (d[0].d1 != indice_ant)
              {
                objeto.centrarActor (d[0].d1);
                indice_ant = d[0].d1;
              }
              return D_O_K;

          case MSG_GOTMOUSE:
          case MSG_LOSTMOUSE:
                objeto.centrarActor (d[0].d1);
                indice_ant = d[0].d1;
                break;
        }
      }
      return d_list_proc (msg, d, c);
    };

    /**
     * \brief   Callback de las coordenadas.
     */
    static int callback_coordenadas (int msg, DIALOG *d, int c)
    {
      // Se sitúa el puntero del objeto instanciado en 'dp3'.
      if (d[0].dp3)
      {
        // Creamos una referencia temporal al objeto actual.
        Dialog &objeto = *(static_cast<Dialog *>(d[0].dp3));
        static int color_ant = d[0].fg;

        // Se procesan los mensajes.
        switch (msg)
        {
          case MSG_CHAR:
          case MSG_UCHAR:
          case MSG_XCHAR:
                objeto.kdb_coordenadas (d, c);
                objeto.draw ();
                break;

          case MSG_WANTFOCUS:
              return D_WANTFOCUS;

          case MSG_GOTFOCUS:
                d[0].fg = makecol (255,0,0);
                return D_O_K;

          case MSG_LOSTFOCUS:
                d[0].fg = color_ant;
                return D_O_K;
        }
      }
      return d_text_proc (msg, d, c);
    };
};

