#pragma once

// Para pruebas... eliminar en un futuro.
#include <typeinfo>

#include <sstream>
#include <string.h>
#include <allegro.h>
#include "EditorManager.h"
#include "BoxALG.h"
#include "TextALG.h"
#include "MenuALG.h"

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
        void        draw            ();
        void        mouse_out       ();
        void        mouse_in        ();
        int         propiedades     ();

protected:
        void        mostrar_marco       ();
        void        menu_contextual     (int x, int y);
        void        mover_kbd           (int code);
        void        mover_kbd_escenario (int code);
        void        prueba_click        ();
        void        prueba_dblclk       ();
        void        mostrar_actor       ();
        void        mover_actor         ();
        int         DuplicarActor       (int x, int y);
        int         CambiarTraje        ();
    
		EditorManager   *manager;
        DlgActor        *dlg_actor2;
        VentanaALG      *dlg_ventana;
        VentanaALG      *dlg_ventana2;

public:
        /*
         * \brief   Variables estáticas del menú principal.
         */
        static MENU     mnu_fichero[];
        static MENU     mnu_ayuda[];
        static MENU     menu_editor[];
        static MENU     mnu_actor[];

        // Diálogo principal. 
        static DIALOG   dialog[];

        // Diálogo de actor. Se muestran las propiedades del actor.
        static DIALOG   dlg_actor[];
    
        // Referencias para el movimiento del ratón.
        int     ref_x, ref_y;
        int     prb_x, prb_y;


        /*
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
                objeto.DuplicarActor (objeto.prb_x, objeto.prb_y);

                // Si fuera la opción de cambiar traje.
                objeto.CambiarTraje ();
            }
            return D_O_K;
        }


        /*
         * Menu de prueba.
         */
        static int menu_callback (void)
        {
            // Líneas de prueba.
            char str[256];
            ustrzcpy(str, sizeof str, active_menu->text);
            alert("Selected menu item:", "", ustrtok(str, "\t"), "Ok", NULL, 0, 0);

            // Mostramos el diálogo del actor a modo de prueba.
            do_dialog (dlg_actor,-1);

            /* Pruebas para mostrar todos los controles.
            for (int i=0; dlg_actor[i].proc != NULL; i++)
            {
                object_message(&dlg_actor[i], MSG_DRAW, 0);
            }
            alert("Selected menu item:", "", ustrtok(str, "\t"), "Ok", NULL, 0, 0);
            broadcast_dialog_message (MSG_DRAW, 0);
            */
            return D_O_K;
        }

        /*
         * Prueba lista. Debe tener la forma del d_list_proc: char *foobar(int index, int *list_size);
         */
        static char *cb_prueba_lista (int index, int *list_size)
        {
            if (dlg_actor[3].dp3)
            {
                // Creamos una referencia temporal al manager del objeto actual.
                EditorManager &manager = *(static_cast<EditorManager *>(dlg_actor[3].dp3));

                // Si index es negativo debe devolver NULL e indicar el tamaño de la lista.
                // Si index es cero o positivo debe devolver la cadena del nombre del traje.
                if (index < 0)
                {
                    *list_size = manager.getNumTrajes ();
                    return NULL;
                }
                else
                {
                    return manager.getNombreTraje (index);
                }
            }
        }

    // Desvio del procedimiento de lista para implementar una lista de trajes.
    static int mi_list_proc (int msg, DIALOG *d, int c)
    {
        int ret = d_list_proc (msg, d, c);

        // Si ya se ha inicializado el nuevo objeto.
        if (d->dp3)
        {
            // Creamos una referencia temporal al manager del objeto actual.
            EditorManager &manager = *(static_cast<EditorManager *>(d->dp3));

            static int ant_d1 = 0;
            // Si se ha cambiado el traje en la lista, pedir que lo cambie al EditorManager.
            if (d->d1 != ant_d1)
            {
                //Cambia el traje del actor actualmente activo.
                manager.cambiarTraje (d->d1);
                manager.redibuja ();
                ant_d1 = d->d1;

                // Modo de prueba para probar que se actualiza lo seleccionado.
                int prb;
                dlg_actor[4].dp = const_cast<char *>(cb_prueba_lista (d->d1,&prb));
                object_message(&dlg_actor[4], MSG_DRAW, 0);
             }
            
            /* Captura el mensaje de cierre. 
             if (ret == D_CLOSE && d->dp3)
                return ((int (*)(void))d->dp3)();
            */
        }        
        return ret;
    }


        /*
         * Prueba slider.
         */
        static int clbk_prueba_slider (void *dp3, int d2)
        {
            if (dp3)
            {
                // Creamos una referencia temporal al manager del objeto actual.
                EditorManager &manager = *(static_cast<EditorManager *>(dp3));
                if (manager.editandoActor())
                {
                    // Guardamos la posición actual, cambiamos la posición según el slider
                    // y redibujamos los objetos.
                    static int actual_y = manager.getActorY ();
                    manager.setActorY( actual_y + (50-d2));
                    manager.redibuja ();

                    // Mostramos de nuevo los sliders.
                    //object_message(&dlg_actor[0], MSG_DRAW, 0);
                    //object_message(&dlg_actor[1], MSG_DRAW, 0);
                    object_message(&dlg_actor[1], MSG_DRAW, 0);
                    object_message(&dlg_actor[2], MSG_DRAW, 0);
                }
            }
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
//                    objeto.mover_kbd (c);
                    objeto.mover_kbd_escenario (c);
                    break;

                case MSG_DRAW:
                    objeto.draw ();
                    break;
                        
                // Mensaje cuando se presiona el botón derecho del ratón.
                case MSG_RPRESS:
                    objeto.prb_x = mouse_x;
                    objeto.prb_y = mouse_y;
                    objeto.menu_contextual (mouse_x, mouse_y);
                    break;

                case MSG_CLICK:
                    //objeto.prueba_click ();
                    objeto.prueba_dblclk ();
                    break;

                case MSG_DCLICK:
                    objeto.prueba_click ();
                    break;

                // Mensaje que se produce repetidamente mientras no exista otro.
                case MSG_IDLE:
                        // Comprobamos si se ha movido el ratón.
                        if ( !((mouse_ant_x == mouse_x) && 
                                (mouse_ant_y == mouse_y)) )
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


