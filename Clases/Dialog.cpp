#include "Dialog.h"

/**
 * \brief   Función CallBack para control de los objetos de pantalla.
 * \param   d[0].dp     Debe contener una referencia al propietario.
 * \todo    
 *          - Eliminar el cero del acceso al array y encapsular con enum.
 *          - Crear una clase aparte que no dependa de las variables de Allegro.
 */
int d_pantalla_proc (int msg, DIALOG *d, int c)
{
    // Se filtran mensajes.
    switch (msg)
    {
    case MSG_CHAR:
        return D_USED_CHAR;

    case MSG_CLICK:
        // Recuperamos la posición del ratón.
        int x = gui_mouse_x();
        int y = gui_mouse_y();
        
        // Dibujamos los objetos.
        EditorManager *editor = (EditorManager *)(d[0].dp);
        if (editor)
        {
            editor->redibuja ();
        }
        else
        {
            gui_textout(screen, "NO SE HA INICIALIZADO LA REFERENCIA AL JUEGO!!!", 30, SCREEN_H/2, 0xFFFF, FALSE);
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

/**
 * \brief   Salida de prueba.
 */
 int quit(void)
{
   if (alert("Salir del editor?", NULL, NULL, "&Sí", "&No", 's', 'n') == 1)
      return D_CLOSE;
   else
      return D_O_K;
}

/*
 * Acerca de ...
 */
int about(void)
{
   alert("* Editor - Juego ++ *",
         "",
         "Editor basado en Allegro - Juanma Rico 2009",
         "Ok", 0, 0, 0); 
   return D_O_K;
}

/**
 * \brief Submenu de ayuda del editor.
 */
MENU mnu_ayuda[] =
{
   { "&About \tF1",     about,  NULL,      0,  NULL  },
   { NULL,               NULL,  NULL,      0,  NULL  }
};

/**
 * \brief Submenu de ayuda del editor.
 */
MENU mnu_fichero[] =
{
   { "&Salir \tF2",      quit,  NULL,      0,  NULL  },
   { NULL,               NULL,  NULL,      0,  NULL  }
};

/**
 * \brief Menú principal de edición.
 */
MENU menu_editor [] =
{
   { "&Fichero",  NULL,   mnu_fichero,  0,   NULL  },
   { "&Editar",   NULL,     mnu_ayuda,  0,   NULL  },
   { "&Ayuda",    NULL,     mnu_ayuda,  0,   NULL  },
   { NULL,        NULL,          NULL,  0,   NULL  }
};

DIALOG dialog[] =
{
   /* (proc)             (x)  (y) (w)  (h)  (fg) (bg) (key) (flags)                           (d1) (d2) (dp)                                    (dp2) (dp3) */
   { d_pantalla_proc,      0,   0, 800, 600, 2,   34,  0,    0,                                0,   0,   NULL,                                   NULL, NULL },
   { d_menu_proc,          0,   0,  348, 12,  7,   15,  0,    D_SELECTED|D_GOTFOCUS|D_GOTMOUSE, 0,   0,   menu_editor,                            NULL, NULL },
   { d_text_proc,        470,  20, 160, 20,  2,   33,  0,    0,                                0,   0,   const_cast<char*>("  Modo Edición  "), NULL, NULL },
   { NULL,                 0,   0,  0,   0,   0,   0,   0,    0,                                0,   0,   NULL,                                   NULL, NULL }
};

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
}

Dialog::~Dialog (void)
{
    // Se oculta el ratón.
    show_mouse (NULL);

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
