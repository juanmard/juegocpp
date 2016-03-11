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
 */
class Dialog
{
	public:
                    Dialog          (EditorManager *editor);
                    ~Dialog         ();
        void        show            ();
        void        draw            ();
        void        mouse_out       ();
        int         propiedades     ();

protected:
        void        mostrar_marco   ();
        void        menu_contextual ();
        void        mover_kbd       (int code);
        void        prueba_click    ();
        void        mostrar_actor   ();

		EditorManager   *owner;
        DlgActor        *dlg_actor;
        VentanaALG      *dlg_ventana;
        VentanaALG      *dlg_ventana2;

public:
        /*
         * \brief   Variable estática del menu de ficheros.
         */
        static MENU     mnu_fichero[];
        static MENU     mnu_ayuda[];

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
            // Si ya está inicializado el objeto...
            if (d[0].dp)
            {
                // Seleccionamos los mensajes.
                switch (msg)
                {
                case MSG_CHAR:
                case MSG_UCHAR:
                case MSG_XCHAR:
                    static_cast<Dialog *>(d[0].dp)->mover_kbd (c);
                    break;

                case MSG_DRAW:
                    static_cast<Dialog *>(d[0].dp)->mostrar_marco ();
                    break;

                case MSG_RPRESS:
                    static_cast<Dialog *>(d[0].dp)->menu_contextual ();
                    break;

                case MSG_CLICK:
                    static_cast<Dialog *>(d[0].dp)->prueba_click ();
                    break;

                case MSG_DCLICK:
                    static_cast<Dialog *>(d[0].dp)->mostrar_actor ();
                    break;

                }
            }
            // No funciona. Error de acceso.
            //return d_menu_proc (msg,d,c);
            return D_O_K;
        }
};


