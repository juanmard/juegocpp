#include "DlgActor.h"

/**
 * \brief   Inicialización de las variables estáticas.
 */
DIALOG DlgActor::dlg_propiedades[] =
{
   /* (proc)         (x)  (y)  (w)  (h)  (fg) (bg) (key) (flags) (d1) (d2) (dp)                              (dp2) (dp3) */
   { d_box_proc,     380, 226, 249, 242, 18,  4,   0,    0,      0,   0,   NULL,                              NULL, NULL },
   { d_button_proc,  568, 437, 55,  26,  18,  4,   0,    0,      0,   0,   const_cast<char*>("Cerrar"),       NULL, NULL },
   { d_text_proc,    383, 230, 115, 11,  18,  4,   0,    0,      0,   0,   const_cast<char*>("Propiedades"),  NULL, NULL },
   { d_textbox_proc, 401, 246, 211, 82,  18,  4,   0,    0,      0,   0,   const_cast<char*>("Escribe aquí"), NULL, NULL },
   { d_slider_proc,  403, 335, 208, 13,  18,  4,   0,    0,      16,  4,   NULL,                              NULL, NULL },
   { d_radio_proc,   405, 359, 14,  13,  18,  4,   0,    0,      0,   0,   const_cast<char*>("Activo"),       NULL, NULL },
   { NULL,           0,   0,   0,   0,    0,  0,   0,    0,      0,   0,   NULL,                              NULL, NULL }
};

/**
 * \brief   Construye la clase que servirá de GUI para editar un actor.
 */
DlgActor::DlgActor (Actor *remoto)
{
    // Guardamos referencia al propietario.
    actor = remoto;

    // Se inicializan los colores de la GUI.
    gui_fg_color = makecol(255,255,255);
    gui_bg_color = makecol(128,128,128);

    // Se inicializan parámetros de los "callback".
    // \todo    Enum para referencias a "dialog". 
    dlg_propiedades[0].dp = actor;
}

DlgActor::DlgActor (void)
{
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

