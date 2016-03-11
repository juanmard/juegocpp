#include "VentanaALG.h"

/**
 * \brief   Construye la clase que servirá de GUI para editar un actor.
 */
VentanaALG::VentanaALG (string nombre_rec)
{
    init_componentes ();
    init_nombre (nombre_rec);
}

/**
 * \brief   Construye la clase que servirá de GUI para editar un actor.
 */
VentanaALG::VentanaALG (string nombre_rec, int x_rec, int y_rec, int w_rec, int h_rec)
{
    // Iniciamos los componentes básicos.
    init_componentes ();

    // Iniciamos el nombre.
    init_nombre (nombre_rec);

    // Los cambios de tamaños.
    componentes[fondo].x = x_rec;
    componentes[fondo].y = y_rec;
    componentes[fondo].w = w_rec;
    componentes[fondo].h = h_rec;
    componentes[barra].x = componentes[fondo].x;
    componentes[barra].y = componentes[fondo].y;
    componentes[barra].w = componentes[fondo].w;
}

/**
 * \brief   Construye la clase que servirá de GUI para editar un actor.
 */
VentanaALG::VentanaALG ()
{
    init_componentes ();
}

/**
 * \brief   Construye la clase que servirá de GUI para editar un actor.
 */
void    VentanaALG::init_nombre (string nombre_rec)
{
    // Hacemos una copia del nombre en nuestra clase.
    nombre = nombre_rec;
    
    // Generamos un puntero compatible con C.
    componentes[barra].dp = const_cast<char *>(nombre.c_str ());
}

/**
 * \brief   Construye la clase que servirá de GUI para editar un actor.
 */
void    VentanaALG::init_componentes ()
{
    // Estado inicial de la ventana.
    enganchado = false;

    // Tamaño y color de la ventana.
    // Se inicializan los colores de la GUI.
    // Estos tamaños y colores deben darse como predeterminados
    // en variables estáticas de la clase. 
    componentes[fondo].proc = fondo_cback; //d_shadow_box_proc;
    componentes[fondo].x = 0;
    componentes[fondo].y = 0;
    componentes[fondo].w = 100;
    componentes[fondo].h = 100;
    componentes[fondo].fg = makecol(255,255,255);
    componentes[fondo].bg = makecol(128,128,128);
    componentes[fondo].key = 0;
    componentes[fondo].flags = 0;
    componentes[fondo].d1 = 0;
    componentes[fondo].d2 = 0;
    componentes[fondo].dp = NULL;
    componentes[fondo].dp2 = NULL;
    componentes[fondo].dp3 = this;

    // Inicializamos la barra (Si llega a entidad de clase aquí la crearemos.
    // Ej: this->Add_BTitulo (new BarraTitulo (this, "Nombre"));
    componentes[barra].proc = barra_cback; //d_text_proc;
    componentes[barra].x = componentes[fondo].x;
    componentes[barra].y = componentes[fondo].y;
    componentes[barra].w = componentes[fondo].w;
    // En este punto deberíamos tener presente la altura del tipo
    // de letra que vamos a usar en el título.
    componentes[barra].h = 14;
    componentes[barra].fg = componentes[fondo].fg;
    componentes[barra].bg = componentes[fondo].bg;
    componentes[barra].key = 0;
    componentes[barra].flags = 0;
    componentes[barra].d1 = 0;
    componentes[barra].d2 = 0;
    componentes[barra].dp = NULL;
    componentes[barra].dp2 = NULL;
    componentes[barra].dp3 = this;
   
    // Fin de los componentes.
    componentes[fin].proc = NULL;
}

VentanaALG::~VentanaALG (void)
{
}

/**
 * \brief   Controla el movimiento del ratón de la clase.
 */

int VentanaALG::msg_draw (int msg, DIALOG *d, int c)
{
    // Sólo devuelve el retorno del fondo
    // \todo Utilizar "dialog_message" en su lugar. 
    object_message(&componentes[barra], MSG_DRAW, c);
    return object_message(&componentes[fondo], MSG_DRAW, c);
};

int VentanaALG::msg_dclick (int msg, DIALOG *d, int c)
{
    // Si está seleccionado el diálogo...
    if (enganchado)
    {
        // este doble-click se recibe en la ventana padre..., no funciona aquí...
        // aquí sólo funciona cuando se guarda las posiciones relativas al cursor...
        // 1 - Se suelta en la nueva posición, para ello...
        mover_ventana (mouse_x + x_rel, mouse_y + y_rel);

        // 2 - Actualizamos el fondo.
        // 3 - Dibujamos el marco y sus controles.
        // broadcast_dialog_message(MSG_DRAW, 0);
        // object_message (&dlg_propiedades[0], MSG_DRAW, 0);
    }
    else
    {
        // Guardamos la posición relativa del cursor respecto al marco.
        // Se utilizará para mantener la distancia entre ratón y marco al moverse.
        x_rel = componentes[fondo].x - mouse_x;
        y_rel = componentes[fondo].y - mouse_y;
    }
    // Pase lo que pase... cambiamos el estado del enganche.
    enganchado = !enganchado;
    return D_O_K;
};

/**
 * \brief   Controla el movimiento del ratón de la clase.
 * \details Allegro no tiene mensaje de movimiento de ratón.
 *          Tenemos que simularlo nosotros haciendo una comprobación constante.
 */
int VentanaALG::msg_idle (int msg, DIALOG *d, int c)
{
    // Si alguna de las componentes del cursor es distinto al guardado
    // es que el cursor se ha movido.
    if (   (x_ant != mouse_x) 
        || (y_ant != mouse_y) )
    {
        // Llamamos al movimiento del ratón.
        mouse_move ();

        // Actualizamos la nueva posición del cursor.
        x_ant = mouse_x;
        y_ant = mouse_y;
    }
    return D_O_K;
};

void    VentanaALG::show ()
{
    do_dialog (componentes, barra);    
};

void    VentanaALG::mover_ventana (int x, int y)
{
};

void    VentanaALG::mouse_move ()
{
    // Si el estado de la ventana es "enganchada"...
    if (enganchado)
    {
        int x = mouse_x + x_rel;
        int y = mouse_y + y_rel;

        //padre->msg_draw (msg,d,c);
        rect (screen, x, y, x + componentes[fondo].w, y + componentes[fondo].h, makecol(255,0,0));
    }
};

void  VentanaALG::msg_dclick_fondo (int msg, DIALOG *d, int c)
{
    // Si está seleccionado el diálogo...
    if (enganchado)
    {
        // 1 - Se suelta en la nueva posición, para ello...
        mover_ventana (mouse_x + x_rel, mouse_y + y_rel);

        // 2 - Actualizamos el fondo.
        // 3 - Dibujamos el marco y sus controles.
        // broadcast_dialog_message(MSG_DRAW, 0);
        // object_message (&dlg_propiedades[0], MSG_DRAW, 0);
        enganchado = false;
    }
};

