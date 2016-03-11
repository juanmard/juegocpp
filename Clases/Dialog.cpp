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
   /* (proc)                      (x)  (y) (w)  (h)  (fg) (bg) (key) (flags)                           (d1) (d2) (dp)                                    (dp2) (dp3) */
   { Dialog::marco_callback,      10,  10,  800, 600,  2,   34,  0,    0,                                    0,   0,   NULL,                                   NULL, NULL },
   { d_menu_proc,                  0,   0,  348,  12,  7,   15,  0,    D_SELECTED | D_GOTFOCUS | D_GOTMOUSE, 0,   0,   menu_editor,                            NULL, NULL },
   { d_text_proc,                470,  20,  160,  20,  2,   33,  0,    0,                                    0,   0,   const_cast<char*>("  Modo Edición  "),  NULL, NULL },
   { NULL,                         0,   0,    0,   0,  0,    0,  0,    0,                                    0,   0,   NULL,                                   NULL, NULL }
};                                  

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
    dialog[0].dp = this;
    dialog[0].dp2 = owner;

    // Se crea un diálogo para el actor vacío.
    dlg_actor = new DlgActor(this);
    dialog[0].dp3 = dlg_actor;

    dlg_ventana2 = new VentanaALG ("Otra prueba de fondo...",0,0,SCREEN_W,SCREEN_H);
    dlg_ventana = new VentanaALG("Prueba",100,100,120,120);

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
    //do_dialog (dialog,-1);

    // Hacemos unas pruebas cuando salgamos.
    DialogALG prueba;

    BoxALG *control1 = new BoxALG();
    prueba.add(*control1);
    
    BoxALG *control2 = new BoxALG();
    control2->set_xy (200,200);
    prueba.add(*control2);
    
    BoxALG *control3 = new BoxALG();
    control3->set_xy (300,100);
    prueba.add(*control3);
        
    TextALG *control4 = new TextALG();
    control4->set_xy (300,100);
    prueba.add(*control4);
        
    prueba.show();
    //do_menu(menu_editor, 0, 0);
}

void Dialog::mouse_out (void)
{
    // Se oculta el ratón.
    show_mouse (NULL);
}

void Dialog::mostrar_marco ()
{
    rect (screen, dialog[0].x, dialog[0].y, 
                  dialog[0].x + dialog[0].w,
                  dialog[0].y + dialog[0].h,
                  dialog[0].bg);
}

/**
 *  \brief  Se encarga de seleccionar el menu contextual adecuado según la posición actual del ratón.
 */
void Dialog::menu_contextual ()
{
    // Resaltamos el objeto.
    owner->resaltar (mouse_x, mouse_y);

    // Elegimos el menú adecuado: actor, lista de actores, fondo...

    // Mostramos el menu del objeto en la posición del ratón.
    do_menu (menu_objeto, mouse_x, mouse_y);
}

/**
 *  \brief  Mueve con el teclado el actor actual en edición.
 */
void    Dialog::mover_kbd   (int code)
{
    Actor *actor;

    actor = owner->get_actor();
    if (actor)
    {
        int actor_x = actor->get_x ();
        int actor_y = actor->get_y ();
        switch ((code & 0xff))
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
        owner->redibuja ();
    }
};

void    Dialog::prueba_click    ()
{
        // Dibujamos los objetos.
        if (owner)
        {
            owner->redibuja ();
        }
        else
        {
            gui_textout(screen, "NO SE HA INICIALIZADO LA REFERENCIA AL JUEGO!!!",
                        SCREEN_W/2, SCREEN_H/2, 0xFFFF, TRUE);
        }

        // Resaltamos el objeto que apunta.
        owner->resaltar (mouse_x, mouse_y);

        // Mostramos en pantalla el mensaje.
        gui_textout(screen, "* Aquí está", mouse_x, mouse_y, 0xFFFF, FALSE);
}

void    Dialog::mostrar_actor   ()
{
    // Cargamos las propiedades del actor marcado.
    // \todo    ¿No deberíamos dar la posición x e y para obtener el actor?
    //          Esto nos muestra el actor marcado como editado... peligroso
    //          que no sea justo el que está bajo la x y la y.
    
    dlg_actor->load (owner->get_actor());
    dlg_actor->show();
    
    dlg_ventana2->show();
    dlg_ventana->show ();
    owner->redibuja();
}

void    Dialog::draw   ()
{
    // Queda redibujar los propios controles.
    owner->redibuja();
}
