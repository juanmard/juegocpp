#include "Dialog.h"
 
/* Inicialización de las variables estáticas de la clase. */
// Menú fichero.
MENU Dialog::mnu_fichero[] =
{
   { "&Salir \tF2",       Dialog::quit,  NULL,      0,  NULL  },
   { NULL,                        NULL,  NULL,      0,  NULL  }
};

// Menú ayuda.
MENU Dialog::mnu_ayuda[] =
{
    { "&About \tF1",     Dialog::about,  NULL,      0,  NULL  },
    { NULL,                       NULL,  NULL,      0,  NULL  }
};



// Declaración de procedimientos.
int d_pantalla_proc (int msg, DIALOG *d, int c);
int propiedades (void);
int menu_callback (void);
//_declspec(dllimport) int __cdecl d_menu_proc (int msg,DIALOG *d, int c);

/**
 * \brief Submenu de ayuda del editor.
 */
/**
 * \brief Menú principal de edición.
 */
MENU menu_editor [] =
{
    { "&Fichero",  NULL, Dialog::mnu_fichero,  0,   NULL  },
    { "&Editar",   NULL,   Dialog::mnu_ayuda,  0,   NULL  },
    { "&Ayuda",    NULL,   Dialog::mnu_ayuda,  0,   NULL  },
    { NULL,        NULL,                NULL,  0,   NULL  }
};

/**
 * \brief Menú propiedades.
 */
MENU menu_objeto [] =
{
   { "&Mover",          menu_callback,   NULL,  0,   NULL  },
   { "&Tamaño",         menu_callback,   NULL,  0,   NULL  },
   { "&Propiedades",    menu_callback,   NULL,  0,   NULL  },
   { NULL,              NULL,   NULL,  0,   NULL  }
};

DIALOG dialog[] =
{
   /* (proc)             (x)  (y) (w)  (h)  (fg) (bg) (key) (flags)                           (d1) (d2) (dp)                                    (dp2) (dp3) */
   { d_pantalla_proc,      0,   0,  800, 600,  2,   34,  0,    0,                                    0,   0,   NULL,                                   NULL, NULL },
   { d_menu_proc,          0,   0,  348,  12,  7,   15,  0,    D_SELECTED | D_GOTFOCUS | D_GOTMOUSE, 0,   0,   menu_editor,                            NULL, NULL },
   { d_text_proc,        470,  20,  160,  20,  2,   33,  0,    0,                                    0,   0,   const_cast<char*>("  Modo Edición  "),  NULL, NULL },
   { NULL,                 0,   0,    0,   0,  0,    0,  0,    0,                                    0,   0,   NULL,                                   NULL, NULL }
};                                  

/**
 * \brief   Propiedades.
 */

/**
 * \brief   Función CallBack para control de los objetos de pantalla.
 * \param   d[0].dp     Debe contener una referencia al propietario.
 * \todo    
 *          - Eliminar el cero del acceso al array y encapsular con enum.
 *          - Crear una clase aparte que no dependa de las variables de Allegro.
 */
int d_pantalla_proc (int msg, DIALOG *d, int c)
{
    static int x;
    static int y;
    static EditorManager *editor = (EditorManager *)(d[0].dp);
 
    Actor *actor = editor->get_actor ();
    x = gui_mouse_x();
    y = gui_mouse_y();

    // Se filtran mensajes.
    switch (msg)
    {
    case MSG_CHAR:
    case MSG_UCHAR:
    case MSG_XCHAR:
        if (actor)
        {
            int actor_x = actor->get_x ();
            int actor_y = actor->get_y ();
            switch ((c & 0xff))
            {
            case 'w':
                actor_y -= 1;
                break;
            case 's':
                actor_y += 1;
                break;
            case 'a':
                actor_x -= 1;
                break;
            case 'd':
                actor_x += 1;
                break;
            }
            actor->set_x(actor_x);
            actor->set_y(actor_y);
            editor->redibuja ();
        }
        return D_O_K;
    
    case MSG_DCLICK:
            break;

    case MSG_RPRESS:
        // Resaltamos el objeto.
        editor->resaltar (x,y);

        // Según el objeto en ese momento apuntado.
        // Desplegamos uno u otro menú.
        // Si es un único objeto el del objeto.
        do_menu (menu_objeto,x,y);

        // Si es una lista de objetos.
        //do_menu (menu_lista,x,y);

        // Si se hace sobre el fondo.
        //do_menu (menu_fondo,x,y);
        break;

    case MSG_CLICK:
        // Dibujamos los objetos.
        if (editor)
        {
            editor->redibuja ();
        }
        else
        {
            gui_textout(screen, "NO SE HA INICIALIZADO LA REFERENCIA AL JUEGO!!!", SCREEN_W/2, SCREEN_H/2, 0xFFFF, TRUE);
        }

        // Resaltamos el objeto que apunta.
        editor->resaltar (x,y);

        // Mostramos en pantalla el mensaje.
        gui_textout(screen, "* Aquí está", x, y, 0xFFFF, FALSE);
        return D_O_K;
    }

    // Acciones predefinidas del menu.
    // Da error de acceso.
    //return d_menu_proc (msg,d,c);
    return D_O_K;
}

/*
 * Menu de prueba.
 */
int menu_callback(void)
{
   char str[256];

   ustrzcpy(str, sizeof str, active_menu->text);
   alert("Selected menu item:", "", ustrtok(str, "\t"), "Ok", NULL, 0, 0);
   return D_O_K;
}

/**
 * \brief   Construye la clase que servirá de GUI para editar un juego.
 */
Dialog::Dialog (EditorManager *editor)
{
    // Guardamos referencia al propietario.
    owner = editor;

    // Se inicializan los colores de la GUI.
    gui_fg_color = makecol(255,255,255);
    gui_bg_color = makecol(128,128,128);

    // Se inicializan parámetros de los "callback".
    // \todo    Enum para referencias a "dialog". 
    dialog[0].dp = owner;

    // Pruebas para incluir en la clase.
    //mnu_ayuda[0].proc = &Dialog::about;

    // Se crea un diálogo para el actor vacío.
//    dlg_actor = new DlgActor();

    // Se apunta a ese diálogo en el menú del objeto.
    // \todo Sustituir el 3 por enum. pj. "menu_objeto[propiedades].dp = ..."
//    menu_objeto[3].dp = dlg_actor->get_callback ();
}

Dialog::~Dialog (void)
{
    mouse_out ();

    // \todo Liberar memoria de todos los objetos utilizados.
}

/**
 * \brief   Activa el modo edición del juego.
 * \details Al activar el modo edición del juego se debe:
 *          - Parar el bucle normal del juego.
 *          - Generar un menu con las propiedades de edición.
 *          - Activar un bucle propio únicamente de la parte gráfica.
 */
void Dialog::show (void)
{
    // Se hace visible el menú de edición.
    do_dialog (dialog,-1);
    //do_menu(menu_editor, 0, 0);
}

void Dialog::mouse_out (void)
{
    // Se oculta el ratón.
    show_mouse (NULL);
}
