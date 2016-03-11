#include "BaseALG.h"

/**
 * \brief   Construye la clase que servirá de GUI para editar un actor.
 */
BaseALG::BaseALG ()
{
    // Posición anterior del ratón.
    x_ant = mouse_x;
    y_ant = mouse_y;

    dialog[0].proc = BaseALG::callback;
    dialog[1].proc = NULL;
    dialog[0].x = 0;
    dialog[0].y = 0;
    dialog[0].w = SCREEN_W;
    dialog[0].h = SCREEN_H;
    dialog[0].fg = makecol(255,255,255);
    dialog[0].bg = makecol(128,128,128);
  
    // Se inicializan parámetros de los "callback".
    // La clase "BaseALG" no tiene padre.
    dialog[0].dp = this;
    dialog[0].dp2 = NULL;
}

/**
 * \brief   Propiedades.
 */
BaseALG::~BaseALG (void)
{
}

/**
 * \brief   Propiedades.
 */
void    BaseALG::show (void)
{
    do_dialog (dialog,-1);
}

/**
 * \brief   Controla el movimiento del ratón de la clase.
 * \details Allegro no tiene mensaje de movimiento de ratón.
 *          Tenemos que simularlo nosotros haciendo una comprobación constante.
 */
int BaseALG::msg_idle (int msg, DIALOG *d, int c)
{
    // Si alguna de las componentes del cursor es distinto...
    if (   (x_ant != mouse_x) 
        || (y_ant != mouse_y) )
    {
        // Enviamos el mensaje de movimiento de cursor.
        object_message (dialog, MSG_MOUSEMOVE, 0);

        // Actualizamos la nueva posición del cursor.
        x_ant = mouse_x;
        y_ant = mouse_y;
    }
    return D_O_K;
};

/**
 * \brief   Controla el movimiento del ratón de la clase.
 */
int BaseALG::msg_mousemove (int msg, DIALOG *d, int c)
{
    return D_O_K;
};

/**
 * \brief   Controla el movimiento del ratón de la clase.
 */
int BaseALG::msg_click (int msg, DIALOG *d, int c)
{
    return D_O_K;
};

/**
 * \brief   Controla el movimiento del ratón de la clase.
 */
int BaseALG::msg_draw (int msg, DIALOG *d, int c)
{
    
    return d_shadow_box_proc (msg, d, c);
};

/**
 * \brief   Controla el movimiento del ratón de la clase.
 */
int BaseALG::msg_dclick (int msg, DIALOG *d, int c)
{
    return D_O_K;
};