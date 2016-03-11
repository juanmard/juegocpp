#pragma once

#include <allegro.h>
#include "EditorManager.h"
#include "DlgActor.h"

class EditorManager;
class DlgActor;

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
        void        mouse_out       ();
        int         propiedades     ();

protected:
		EditorManager   *owner;
        DlgActor        *dlg_actor;

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
};


