#pragma once

#include <allegro.h>

#define   MSG_MOUSEMOVE   MSG_USER + 2

/**
 * \brief       Muestra un actor en una pequeña GUI para editar sus propiedades.
 * \details     Esta GUI utiliza funciones básicas de Allegro. Contiene funciones globales para los
 *              "callback" de las componentes. Las funciones de modificación y actualización de
 *              objetos deben ser encomendadas a la clase "EditorManager".
 * \todo        Hacer esto mismo pero con una clase genérica llamada "BaseALG" que haga virtuales
 *              todas las llamadas "MSG_xxxx", el resto heredarán de ella y sólo tendrán que redefinir
 *              estas llamadas.
 */
class BaseALG
{
	public:
                BaseALG          ();
                ~BaseALG         ();
        void    show             ();

protected:
        DIALOG              dialog[1];
        BaseALG             *base;
        int                 x_ant, y_ant;
        
        virtual int         msg_draw            (int msg, DIALOG *d, int c);
        virtual int         msg_idle            (int msg, DIALOG *d, int c);
        virtual int         msg_mousemove       (int msg, DIALOG *d, int c);
        virtual int         msg_click           (int msg, DIALOG *d, int c);
        virtual int         msg_dclick          (int msg, DIALOG *d, int c);

        /**
         * \brief   Callback Allegro de la clase.
         */
        static int callback (int msg, DIALOG *d, int c)
        {
            // Si ya está inicializado el objeto...
            if (d[0].dp)
            {
                BaseALG *obj = static_cast<BaseALG *>(d[0].dp);
                // Seleccionamos los mensajes.
                switch (msg)
                {
                case MSG_DRAW:
                    return obj->msg_draw (msg, d, c);

                case MSG_CLICK:
                    return obj->msg_click (msg, d, c);

                case MSG_DCLICK:
                    return obj->msg_dclick (msg, d, c);

                case MSG_MOUSEMOVE:
                    return obj->msg_mousemove (msg, d, c);

                case MSG_IDLE:
                    return obj->msg_idle (msg, d, c);

                default:
                    // Se pasan los mensajes al padre.
                    if (d[0].dp2)
                    {
                        return static_cast<BaseALG *>(d[0].dp2)->callback (msg,d,c);
                    }
                }
            }
            return D_O_K;
        };
};
