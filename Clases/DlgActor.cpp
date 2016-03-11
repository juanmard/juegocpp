#include "DlgActor.h"

/**
 * \brief   Diálogo con el objeto actor.
 * \todo    Incluir esta variable en el entorno de "DlgActor".
 */
DIALOG dlg_propiedades[] =
{
   /* (proc)        (x)  (y)  (w)  (h)  (fg) (bg) (key) (flags) (d1) (d2) (dp)             (dp2) (dp3) */
   { d_box_proc,    153, 88,  238, 142, 18,   4,   0,    0,      0,   0,   NULL,            NULL, NULL },
   { d_button_proc, 325, 194, 55,  26,  18,   4,   0,    0,      0,   0,   const_cast<char*>("Cerrar"), NULL, NULL },
   { d_text_proc,   161, 98,  115, 11,  18,   4,   0,    0,      0,   0,   const_cast<char*>("Propiedades"),     NULL, NULL },
   { NULL,          0,   0,   0,   0,    0,   0,   0,    0,      0,   0,   NULL,            NULL, NULL }
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
void    DlgActor::get_callback (void)
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
}

/**
 * \brief   Propiedades.
 */
void DlgActor::save (void)
{
}
