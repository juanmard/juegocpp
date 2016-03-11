#include "DlgActor.h"

/**
 * \brief   Inicialización de las variables estáticas.
 */
DIALOG DlgActor::dlg_propiedades[] =
{
   /* (proc)                    (x)  (y)  (w)  (h)  (fg) (bg) (key) (flags) (d1) (d2) (dp)                              (dp2) (dp3) */
   { DlgActor::box_callback,   380, 226, 249, 242,  18,  4,   0,    0,      0,   0,   NULL,                              NULL, NULL },
   { d_button_proc,            568, 437,  55,  26,  18,  4,   0,    0,      0,   0,   const_cast<char*>("Cerrar"),       NULL, NULL },
   { d_text_proc,              383, 230, 115,  11,  18,  4,   0,    0,      0,   0,   const_cast<char*>("Propiedades"),  NULL, NULL },
   { d_textbox_proc,           401, 246, 211,  82,  18,  4,   0,    0,      0,   0,   const_cast<char*>("Escribe aquí"), NULL, NULL },
   { d_slider_proc,            403, 335, 208,  13,  18,  4,   0,    0,      16,  4,   NULL,                              NULL, NULL },
   { d_radio_proc,             405, 359,  14,  13,  18,  4,   0,    0,      0,   0,   const_cast<char*>("Activo"),       NULL, NULL },
   { NULL,                       0,   0,   0,   0,   0,  0,   0,    0,      0,   0,   NULL,                              NULL, NULL }
};

/**
 * \brief   Construye la clase que servirá de GUI para editar un actor.
 */
DlgActor::DlgActor (Actor *actor_tmp)
{
    // Guardamos referencia al propietario.
    actor = actor_tmp;

    // Se inicializan los colores de la GUI.
    gui_fg_color = makecol(255,255,255);
    gui_bg_color = makecol(128,128,128);

    // Posición anterior del ratón.
    x_ant = mouse_x;
    y_ant = mouse_y;

    // Se inicializan parámetros de los "callback".
    // \todo    Enum para referencias a "dialog". 
    dlg_propiedades[0].dp = this;
}

DlgActor::DlgActor (Dialog *dlg_tmp)
{
    owner = dlg_tmp;

    // Se inicializan los colores de la GUI.
    gui_fg_color = makecol(255,255,255);
    gui_bg_color = makecol(128,128,128);

    // Posición anterior del ratón.
    x_ant = mouse_x;
    y_ant = mouse_y;

    enganchado = false;
    dlg_propiedades[0].dp = this;
}

DlgActor::~DlgActor (void)
{
}

/**
 * \brief   Propiedades.
 */
void    DlgActor::show (void)
{
    do_dialog (dlg_propiedades,-1);
}

/**
 * \brief   Propiedades.
 */
void    DlgActor::load (Actor *remoto)
{
    // Propiedades de prueba.
    static char buffer[40];
    if (remoto)
    {
        uszprintf(buffer, sizeof(buffer), "x, y: %d, %d\nColor: %d",
                                          remoto->get_x(),
                                          remoto->get_y(),
                                          remoto->get_color());
        //dlg_propiedades[3].dp = "Prueba, prueba...";
        dlg_propiedades[3].dp = buffer;
    }
}

/**
 * \brief   Propiedades.
 */
void DlgActor::save (void)
{
}

/**
 * \brief   Controla el movimiento del ratón de la clase.
 * \details Allegro no tiene mensaje de movimiento de ratón.
 *          Tenemos que simularlo nosotros haciendo una comprobación constante.
 */
void DlgActor::msg_idle ()
{
    // Si alguna de las componentes del cursor es distinto...
    if (   (x_ant != mouse_x) 
        || (y_ant != mouse_y) )
    {
        // Enviamos el mensaje de movimiento de cursor.
        object_message (&dlg_propiedades[0], MSG_MOUSEMOVE, 0);

        // Actualizamos la nueva posición del cursor.
        x_ant = mouse_x;
        y_ant = mouse_y;
    }
};

/**
 * \brief   Controla el movimiento del ratón de la clase.
 */
void DlgActor::msg_mousemove ()
{
    // Si el ratón ha atrapado el marco...
    if (enganchado)
    {
        // Mover y dibujar contorno.
        //int inc_x = mouse_x - x_ant;
        //int inc_y = mouse_y - y_ant;
        //dlg_propiedades[0].x += inc_x;
        //dlg_propiedades[0].y += inc_y;
        //rect (screen, dlg_propiedades[0].x, dlg_propiedades[0].y,
        //              dlg_propiedades[0].x + dlg_propiedades[0].w,
        //              dlg_propiedades[0].y + dlg_propiedades[0].h, 18);
        owner->draw ();
        rect (screen, mouse_x + x_rel,
                      mouse_y + y_rel,
                      mouse_x + x_rel + dlg_propiedades[0].w, 
                      mouse_y + y_rel + dlg_propiedades[0].h,
                      makecol(128,128,128));
    }
};

void DlgActor::msg_click ()
{
    if (enganchado)
    {
        // Cambiamos la posición de todos los objetos del diálogo.
        // Enviamos mensaje de MSG_DRAW.
        // Desenganchamos el diálogo.
        // enganchado = false;
    }
};

void DlgActor::msg_dclick ()
{
    // Si está seleccionado el diálogo...
    if (enganchado)
    {
        // Lo queremos solatar en la nueva posición, para ello...
        // Cambiamos la posición del marco (y sus controles...)
        // Para pruebas se mueve sólo el marco.
        dlg_propiedades[0].x = mouse_x + x_rel;
        dlg_propiedades[0].y = mouse_y + y_rel;

        // Dibujamos padre.
        owner->draw ();

        // Dibujamos el marco y sus controles.
        broadcast_dialog_message(MSG_DRAW, 0);
        //object_message (&dlg_propiedades[0], MSG_DRAW, 0);
    }
    else
    {
        // Guardamos la posición relativa del cursor respecto al marco.
        // Se utilizará para mantener la distancia entre ratón y marco al moverse.
        x_rel = dlg_propiedades[0].x - mouse_x;
        y_rel = dlg_propiedades[0].y - mouse_y;
    }
    // Pase lo que pase... cambiamos el estado del enganche.
    enganchado = !enganchado;
};