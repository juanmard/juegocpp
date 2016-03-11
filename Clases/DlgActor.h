#pragma once

#include <allegro.h>
#include "Actor.h"
#include "Dialog.h"
#include "Nombres.h"

#define   MSG_MOUSEMOVE   MSG_USER + 2

/**
 * \brief       Muestra un actor en una pequeña GUI para editar sus propiedades.
 * \details     Esta GUI utiliza funciones básicas de Allegro. Contiene funciones globales para los
 *              "callback" de las componentes. Las funciones de modificación y actualización de
 *              objetos deben ser encomendadas a la clase "EditorManager".
 * \todo        Hacer esto mismo pero con una clase genérica llamada "VentanaALG" que haga virtuales
 *              todas las llamadas "MSG_xxxx", el resto heredarán de ella y sólo tendrán que redefinir
 *              estas llamadas.
 */
class DlgActor
{
	public:
                DlgActor          (Actor *actor);
                DlgActor          (Dialog *dlg);
                ~DlgActor         (void);
        void    show              (void);
        void    load              (Actor *actor);
        void    save              (void);

protected:
        int             x_rel, y_rel;
        int             x_ant, y_ant;
        bool            enganchado;
		Actor           *actor;
        Dialog          *owner;
        static DIALOG   dlg_propiedades[];

        void            msg_idle            ();
        void            msg_mousemove       ();
        void            msg_click           ();
        void            msg_dclick          ();

        /**
         * \brief   Callback Allegro de la clase.
         * \todo    
         *          - Añadir a las funciones los parámetros de entrada y de retorno.
         *            Ej: return obj->msg_dclick(msg,d,c);
         *          - Una vez detectado el mensaje, si no se ha procesado pasar al
         *            padre. Ej: [int] owner->msg_owner (msg,d,c);
         */
        static int box_callback (int msg, DIALOG *d, int c)
        {
            // Si ya está inicializado el objeto...
            if (d[0].dp)
            {
                DlgActor *obj = static_cast<DlgActor *>(d[0].dp);

                // Seleccionamos los mensajes.
                switch (msg)
                {
                case MSG_DCLICK:
// Mandar antes el mensaje al padre para poder mover toda la ventana por la pantalla
// y no únicamente por la propia ventana.
//                    object_message(&((obj->owner)->dialog[0]), MSG_DCLICK, c);
                    obj->msg_dclick ();
                    break;

                case MSG_CLICK:
                    obj->msg_click ();
                    break;

                case MSG_MOUSEMOVE:
                    obj->msg_mousemove ();
                    break;

                case MSG_IDLE:
                    obj->msg_idle ();
                    break;

                default:
                    return d_box_proc (msg,d,c);
                }
            }
            return D_O_K;
        };

};
