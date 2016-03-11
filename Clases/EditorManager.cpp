#include "EditorManager.h"

// Función CallBack para control de mensajes.
int d_menu_prueba_proc (int msg, DIALOG *d, int c)
{
    // Se filtran mensajes.
    switch (msg)
    {
    case MSG_CHAR:
        return D_USED_CHAR;
    case MSG_CLICK:
        int x = gui_mouse_x();
        int y = gui_mouse_y(); 
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
   { d_menu_prueba_proc,   0, 0, 800, 600, 2,   34,  0,    0,                                0,   0,   NULL,                                   NULL, NULL },
   { d_menu_proc,        0,   0,  348, 12,  7,   15,  0,    D_SELECTED|D_GOTFOCUS|D_GOTMOUSE, 0,   0,   menu_editor,                            NULL, NULL },
   { d_text_proc,        470, 20, 160, 20,  2,   33,  0,    0,                                0,   0,   const_cast<char*>("  Modo Edición  "), NULL, NULL },
   { NULL,               0,   0,  0,   0,   0,   0,   0,    0,                                0,   0,   NULL,                                   NULL, NULL }
};

/**
 * \brief   Construye la clase para editar un juego.
 * \details Debe generar otra ventana, obtener la lista de objetos y realizar su propio bucle de estética
 *          para representar los objetos del juego a editar.
 * \todo    Se debe generar la ventana de forma independiente de las bibliotecas (Allegro), para ello crear una
 *          "interfase" con estas funcionalidades, es decir, desligar de esta clase.
 */
EditorManager::EditorManager(Game *g)
{
	// Referencia al juego.
    game = g;
}

EditorManager::~EditorManager()
{
}

/**
 * \brief   Activa el modo edición del juego.
 * \details Al activar el modo edición del juego se debe:
 *          - Parar el bucle normal del juego.
 *          - Generar un menu con las propiedades de edición.
 *          - Activar un bucle propio únicamente de la parte gráfica.
 */
void EditorManager::activate ()
{
    // Se para el bucle del juego.
    game->pause ();

    // Se hace visible el menú de edición.
    gui_fg_color = makecol(255,255,255);
    gui_bg_color = makecol(128,128,128);
    do_dialog (dialog,-1);
    //do_menu(menu_editor, 0, 0);

    // Se entra en el bucle gráfico.

    // Se sale del editor.
    show_mouse (NULL);
    game->stage_manager->draw ();
    game->play ();
}

/**
 * \brief   Edita el objeto actual.
 * \details Centra la pantalla de visualización en el objeto y abre un cuadro de diálogo con las
 *          propiedades del objeto.
 */
void EditorManager::edit ()
{

}

/**
 * \brief   Elige el objeto actual.
 * \details Elige el objeto actual según su índice en la lista.
 */
void EditorManager::set (int indice)
{
}

