#pragma once

#include <string>
#include <list>
#include <allegro.h>

//using namespace std;
using std::string;
using std::list;

/**
 * \brief       Muestra un actor en una pequeña GUI para editar sus propiedades.
 * \details     Esta GUI utiliza funciones básicas de Allegro. Contiene funciones globales para los
 *              "callback" de las componentes. Las funciones de modificación y actualización de
 *              objetos deben ser encomendadas a la clase "EditorManager".
 * \todo        Hacer esto mismo pero con una clase genérica llamada "VentanaALG" que haga virtuales
 *              todas las llamadas "MSG_xxxx", el resto heredarán de ella y sólo tendrán que redefinir
 *              estas llamadas.
 */
class VentanaALG
{
	public:
                VentanaALG          ();
                VentanaALG          (string nombre);
                VentanaALG          (string nombre, int x, int y, int w, int h);
                ~VentanaALG         ();
        void    show                ();
        void    mover_ventana       (int x, int y);
        void    mouse_move          ();

protected:
        // Usada como parte común a todos los constructores.
        void    init_componentes    ();
        void    init_nombre         (string nombre);

        // Los componentes de la ventana es todo lo que forma parte de una
        // ventana básica (Barra de título, fondo, botón de cerrar...etc).
        // En principio vamos a poner dos componentes que formarán la ventana,
        //  * El fondo (0) y la barra de menú(1), el (2) se reserva para NULL.
        // Luego esta barra de menú puede separarse en una clase aparte cuando se
        // complique su formato.
        enum {fondo=0, barra, fin};

        DIALOG  componentes[3];

        // La lista de controles es lo que va a contener la ventana y lo que le dará
        // la GUI al usuario.
        list<DIALOG *>      controles;

        // El nombre es lo que identificará a la ventana
        string              nombre;

        // Se reservan dos variables para las posiciones relativas del cursor.
        int  x_ant, y_ant;
        int  x_rel, y_rel;

        // Nos dicen si la ventana se encuentra en estado "enganchado".
        // \todo Quitar esto y utilizar un "enum" con distintos estados de la ventana
        //       P,j: Movimiento, inactiva, replegada, minimizada, maximizada... etc. 
        bool                enganchado;
        
        // Derivaciones de los mensajes más comunes de Allegro.
        // \todo Generalizar estos estados para transformar para distintas bibliotecas.
        int         msg_draw            (int msg, DIALOG *d, int c);
        int         msg_idle            (int msg, DIALOG *d, int c);
        int         msg_click           (int msg, DIALOG *d, int c);
        int         msg_dclick          (int msg, DIALOG *d, int c);
        void        msg_dclick_fondo    (int msg, DIALOG *d, int c);


        /**
         * \brief   Callback para la barra.
         */
        static int barra_cback (int msg, DIALOG *d, int c)
        {
            // Si ya está inicializado el objeto...
            if (d[0].dp3)
            {
                // Seleccionamos los mensajes.
                switch (msg)
                {
                case MSG_DCLICK:
                    return static_cast<VentanaALG *>(d[0].dp3)->msg_dclick (msg,d,c);

                case MSG_IDLE:
                    return static_cast<VentanaALG *>(d[0].dp3)->msg_idle (msg,d,c);
                }
            }
            // No funciona. Error de acceso.
            return d_text_proc (msg,d,c);
        }

        /**
         * \brief   Callback para el fondo.
         */
        static int fondo_cback (int msg, DIALOG *d, int c)
        {
            // Si ya está inicializado el objeto...
            if (d[0].dp3)
            {
                // Seleccionamos los mensajes.
                switch (msg)
                {
                case MSG_DCLICK:
                    static_cast<VentanaALG *>(d[0].dp3)->msg_dclick_fondo (msg,d,c);
                    break;
                }
            }
            // En lugar de esto debería devolver antes el del hijo.
            return d_shadow_box_proc (msg,d,c);
        }
};

