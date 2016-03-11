#pragma once

#include <allegro.h>
#include "EditorManager.h"
#include "VentanaALG.h"
#include "DlgActor.h"
#include "DialogALG.h"
#include "BoxALG.h"
#include "TextALG.h"
#include "MenuALG.h"
#include "ItemALG.h"

class EditorManager;
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
 * \todo    Generalizar este entorno para que sirviera para cualquier librería y no sólo para Allegro.
 *              Para esto necesitamos "Diálogos", "Ventanas" y "Menús" generales, evitando las funciones de
 *              Allegro en ellas.
 */
class Dialog
{
	public:
                    Dialog          (EditorManager *editor);
                    ~Dialog         ();
        void        show            ();
        void        draw                ();
        void        mouse_out       ();
        void        mouse_in         ();
        int         propiedades      ();

protected:
        void        mostrar_marco   ();
        void        menu_contextual ();
        void        mover_kbd       (int code);
        void        prueba_click    ();
        void        prueba_dblclk    ();
        void        mostrar_actor   ();
        void        mover_actor     ();


		EditorManager   *manager;
        DlgActor        *dlg_actor;
        VentanaALG      *dlg_ventana;
        VentanaALG      *dlg_ventana2;

public:
        /*
         * \brief   Variable estática del menu de ficheros.
         */
        static MENU     mnu_fichero[];
        static MENU     mnu_ayuda[];
        static MENU     menu_editor[];
        static MENU     menu_objeto[];

        // Diálogo principal. 
        static DIALOG   dialog[];

        // Diálogo de objeto. Se muestran las propiedades del objeto.
        static DIALOG   dialog_objeto[];
    
        // Referencias para el movimiento del ratón.
        int                    ref_x, ref_y;


        /*
         * Menu de prueba.
         */
        static int menu_callback (void)
        {
                // Líneas de prueba.
                char str[256];
                ustrzcpy(str, sizeof str, active_menu->text);
                alert("Selected menu item:", "", ustrtok(str, "\t"), "Ok", NULL, 0, 0);

            do_dialog (dialog_objeto,-1);
            
             return D_O_K;
        }

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
        static int about ()
        {
           alert("* Editor - Juego ++ *",
                 "",
                 "Editor basado en Allegro - Juanma Rico 2009",
                 "Ok", 0, 0, 0); 
           return D_O_K;
        }

        /**
         * \brief   Mensaje de confirmación de salida del editor.
         */
        static int quit(void)
        {
           if (alert("¿Salir del editor?", NULL, NULL, "&Sí", "&No", 's', 'n') == 1)
              return D_CLOSE;
           else
              return D_O_K;
        }

        /**
         * \brief   Método "callback" de mensajes recibidos por el marco del diálogo.
         * \details Este método maneja todos los mensajes que se reciben dentro del marco que
         *          se dibuja sobre la pantalla actual.
         *          Es una función estática por compatibilidad con Allegro.
         *          El campo "dp" debe contener un puntero al objeto instanciado de la clase.
         *          Se procura que la parte estática sea mínima, pasando las llamadas a procesos
         *          protegidos de la clase.
         */
        static int marco_callback (int msg, DIALOG *d, int c)
        {
            // Si ya está inicializado el objeto (puntero existe), podemos crear una referencia  al objeto y utilizar sus métodos.
            // Si no está inicializado el objeto ignoramos el mensaje.
            if (d[0].dp)
            {
                // Creamos una referencia temporal al objeto actual.
                Dialog &objeto = *(static_cast<Dialog *>(d[0].dp));

                // Posición anterior del ratón antes de llamar.
                static int mouse_ant_x, mouse_ant_y;
                
                // Seleccionamos los mensajes.
                switch (msg)
                {
                 // En caso de que se pulse una tecla...
                case MSG_CHAR:
                case MSG_UCHAR:
                case MSG_XCHAR:
                    objeto.mover_kbd (c);
                    break;

                case MSG_DRAW:
                    objeto.draw ();
                    break;
                        
                // Mensaje cuando se presiona el botón derecho del ratón.
                case MSG_RPRESS:
                    objeto.menu_contextual ();
                    break;

                case MSG_CLICK:
                    //objeto.prueba_click ();
                    objeto.prueba_dblclk ();
                    break;

                case MSG_DCLICK:
                    //objeto.prueba_dblclk ();
                    break;

                // Mensaje que se produce repetidamente mientras no exista otro.
                case MSG_IDLE:
                        if ((mouse_ant_x == mouse_x) && (mouse_ant_y == mouse_y) )
                        {
                            // El ratón no se ha movido.
                        }
                        else
                        {
                            // El ratón se ha movido. Lo actualizamos y movemos el actor.
                            mouse_ant_x = mouse_x;
                            mouse_ant_y = mouse_y;
                            objeto.mover_actor ();
                            objeto.draw (); 
                        }
                        break;
                }
            }
            // No funciona. Error de acceso. No podemos enviar el mensaje al padre.
            //return d_menu_proc (msg,d,c);

            // Como no podemos enviar el mensaje al padre, damos el visto bueno y por procesados todos los mensajes.
            return D_O_K;
        }
};


