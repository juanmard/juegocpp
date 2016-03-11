
#include "Dialog.h"

//#define PRUEBAS
//#define DEBUG

// Inicialización de las variables estáticas de la clase.
// Diálogo general de la GUI del editor.
DIALOG Dialog::dialog[] =
{
   /* (proc)                  (x)  (y)  (w) (h) (fg) (bg) (key) (flags)                              (d1) (d2) (dp)                                    (dp2) (dp3) */
   { Dialog::marco_callback,   0,   0, 300, 200,  2,  34,  0,    0,                                    0,   0,  NULL,                                   NULL, NULL },
   { d_menu_proc,              0,   0, 300,  12,  7,  15,  0,    D_SELECTED | D_GOTFOCUS | D_GOTMOUSE, 0,   0,  Dialog::menu_editor,                    NULL, NULL },
   { d_text_proc,            470,  20, 160,  20,  2,  33,  0,    0,                                    0,   0,  const_cast<char*>("  Modo Edición  "),  NULL, NULL },
   { NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL }
};                                  

// Diálogo de objeto.
DIALOG Dialog::dlg_actor [] =
{
   /* (proc)             (x),  (y),  (w),  (h), (fg),  (bg), (key),  (flags),   (d1),  (d2),  (dp),                                (dp2), (dp3)     */
   { d_text_proc,          0,  100,  300,  200,    7,    15,     0,        0,      0,     0, const_cast<char*>("x, y"),             NULL, NULL },
   { d_text_proc,        470,   20,  160,   20,    2,    33,     0,        0,      0,     0, const_cast<char*>("  Modo Edición  "), NULL, NULL },
   { d_slider_proc,       20,  200,   20,  160,    2,    33,     0,        0,    100,    50,                                  NULL, NULL, NULL },
   { d_slider_proc,       60,  200,   20,  160,    2,    33,     0,        0,    100,    50,                                  NULL, NULL, NULL },
   { NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL }
};                                  

// Menú fichero.
MENU Dialog::mnu_fichero[] =
{
   { const_cast<char*>("&Abrir mapa"),   Dialog::quit, NULL, D_DISABLED, NULL },
   { const_cast<char*>("&Guardar mapa"), Dialog::quit, NULL, D_DISABLED, NULL },
   { const_cast<char*>(""),              Dialog::quit, NULL, D_DISABLED, NULL },
   { const_cast<char*>("&Salir\tF2"),    Dialog::quit, NULL,          0, NULL },
   { NULL, NULL, NULL, 0, NULL }
};

// Menú ayuda.
MENU Dialog::mnu_ayuda[] =
{
    { const_cast<char*>("&Manual\tF1"), Dialog::about, NULL, D_DISABLED, NULL },
    { const_cast<char*>("&Sobre..."),   Dialog::about, NULL,          0, NULL },
    { NULL, NULL, NULL, 0, NULL }
};

// Menú de edición.
MENU Dialog::menu_editor [] =
{
    { const_cast<char*>("&Fichero"), NULL, Dialog::mnu_fichero, 0, NULL },
    { const_cast<char*>("&Editar"),  NULL,  Dialog::mnu_actor, 0, NULL },
    { const_cast<char*>("&Ayuda"),   NULL,   Dialog::mnu_ayuda, 0, NULL },
    { NULL, NULL, NULL, 0, NULL }
};

// Menú del objeto.
MENU Dialog::mnu_actor [] =
{
   { const_cast<char*>("&Mover"),       Dialog::menu_callback,      NULL,          0, NULL },
   { const_cast<char*>("&Duplicar"),    Dialog::cb_menu_opciones,   NULL,          0, NULL },
   { const_cast<char*>("&Tamaño"),      Dialog::menu_callback,      NULL, D_DISABLED, NULL },
   { const_cast<char*>("&Propiedades"), Dialog::menu_callback,      NULL,          0, NULL },
   { NULL, NULL, NULL, 0, NULL }
};

/**
 * \brief   Construye la clase que servirá de GUI para editar un juego.
 */
Dialog::Dialog (EditorManager *editor)
{
    // Guardamos referencia al propietario.
    manager = editor;

    // Se inicializan los colores de la GUI.
    gui_fg_color = makecol(255,255,255);
    gui_bg_color = makecol(128,128,128);

    // Se inicializa el tamaño inicial de la ventana que recibe las llamadas.
    dialog[0].x = 0;
    dialog[0].y = 14;
    dialog[0].h = SCREEN_H;
    dialog[0].w = SCREEN_W;

    // Se  inicializa el ancho del menú.
    dialog[1].w = SCREEN_W;
    
    // Se inicializan parámetros de los "callback".
    // \todo    Enum para referencias a "dialog". 
    dialog[0].dp = this;
    dialog[0].dp2 = manager;

    // Se crea un diálogo para el actor vacío.
    dlg_actor2 = new DlgActor(this);
    dialog[0].dp3 = dlg_actor;

    dlg_ventana2 = new VentanaALG ("Otra prueba de fondo...",0,0,SCREEN_W,SCREEN_H);
    dlg_ventana = new VentanaALG("Prueba",100,100,120,120);

    // Se apunta a ese diálogo en el menú del objeto.
    //mnu_actor[3].dp = editor->get_actor ();

    // Inicializamos las propiedades del actor.
    dlg_actor[0].fg = makecol(255,255,255);
    dlg_actor[0].bg = makecol (0,0,255);     //bitmap_mask_color (screen); 

    // Inicializamos el slider de prueba.
    dlg_actor[2].dp2 = (void*)Dialog::clbk_prueba_slider;
    dlg_actor[2].dp3 = manager;
    dlg_actor[3].dp2 = (void*)Dialog::clbk_prueba_slider;
    dlg_actor[3].dp3 = manager;

    // Inicializamos las llamadas del menú contextual.
    // Parece ser que incluir la referencia directa no funciona, hay que pasar por
    // un procedimiento estático.
    //    mnu_actor[1].proc = reinterpret_cast<int(*)()>(&Dialog::DuplicarActor);
    mnu_actor[1].dp = this;
}

/**
 * \brief   Destructor de la clase.
 */
Dialog::~Dialog (void)
{
    // Ocultamos el puntero del ratón.
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

// Hacemos unas pruebas independientes de la definición de la clase.
#ifdef  PRUEBAS
    DialogALG prueba;

    BoxALG &control_caja = *(new BoxALG());
//    prueba.add(control_caja);
    
    control_caja = *(new BoxALG());
    control_caja.set_xy (200,200);
 //   prueba.add(control_caja);
    
    control_caja = *(new BoxALG());
    control_caja.set_xy (300,100);
 //   prueba.add(control_caja);
        
    TextALG &control_texto = *(new TextALG());
    control_texto.set_xy (400,100);
  //  prueba.add(control_texto);
        
    MenuALG &control_menu = *(new MenuALG());
    control_menu.set_xy (300,50);
    ItemALG &menu_item = *(new ItemALG());
    control_menu.add(menu_item);
    
    menu_item = *(new ItemALG("Prueba2"));
    control_menu.add(menu_item);
    prueba.add(control_menu);

    prueba.show();

    // Después de pulsar 'ESC' modificamos el dialogo de prueba y lo volvemos a mostrar.
    menu_item = *(new ItemALG("Prueba3"));
    control_menu.add(menu_item);
    prueba.add(control_menu);

    prueba.show();

    // Eliminamos la tecla 'ESC' del buffer de teclado.
    key[KEY_ESC]=false;
#endif
 }

void Dialog::mouse_out (void)
{
    // Se oculta el ratón.
    show_mouse (NULL);
}

/**
 * \brief   Muestra el ratón en pantalla.
 */
void Dialog::mouse_in (void)
{
    // Se muestra el ratón - Allegro.
    show_mouse (screen);
}

/**
 * \brief   Muestra el marco del diálogo para propósitos de depuración.
 */
void Dialog::mostrar_marco ()
{
    rect (screen, dialog[0].x, dialog[0].y, 
                  dialog[0].x + dialog[0].w,
                  dialog[0].y + dialog[0].h,
                  dialog[0].bg);
    int des = 10;
    rect (screen, dialog[0].x+des, dialog[0].y+des, 
                  dialog[0].x + dialog[0].w - des,
                  dialog[0].y + dialog[0].h - des-14,
                  dialog[0].bg);
}

/**
 *  \brief  Se encarga de seleccionar el menu contextual adecuado según la posición actual del ratón.
 */
void Dialog::menu_contextual (int x, int y)
{
    // Elegimos el menú adecuado: actor, lista de actores, fondo... según el tipo de objeto.

    // Para pruebas suponemos que el objeto elegido es un actor.
    //switch (objeto->tipo)
    //{
    //    case actor:
    //    {
            // Resaltamos el actor.
            manager->ResaltarActor (x, y);

            // Para hacer pruebas con el slider editamos el actor.
            manager->EditarActor (x, y);

            // Mostramos el menu del actor en la posición del ratón.
            do_menu (mnu_actor, x, y);

            // Obtenemos la opción elegida. Podemos usar la opción de Allegro "active_menu->Text".
            // Según la opción elegida ejecutar una u otra función.
            // O bien, en la definición del menú poner la función estática de la clase a ejecutar
            // Al elegir la opción.
            // Si la opción es obtener las propiedades del actor, lo suyo sería abrir un control
            // nuevo con todas las propiedades para modificarlas, las propiedades se deben pedir al "manager".
            // Algo así:
            // dlg_actor[pos_x]=manager->getActorX ();
            // dlg_actor[heigth]=manager->getActorH ();
            
    //      }
    //  }
}

/**
 *  \brief  Mueve con el teclado el actor actual en edición.
 */
void    Dialog::mover_kbd   (int code)
{
    if (manager->EditandoActor())
    {
        int actor_x = manager->GetActorX ();
        int actor_y = manager->GetActorY ();
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
        manager->SetActorX(actor_x);
        manager->SetActorY(actor_y);
        draw ();

        // Forzamos muestre las coordenadas también con las teclas.
        // Esto habrá que eliminarlo, sólo se debe dibujar en un lugar.
        /*
        dialog_objeto[0].x = actor_x;
        dialog_objeto[0].y = actor_y;        
        object_message(&dialog_objeto[0], MSG_DRAW, 0);
        */
    }
};

/**
 * \brief Prueba el click de ratón resaltando el contorno del objeto en el que se produce.
 */
void    Dialog::prueba_click    ()
{
        // Comprobamos que el Diálogo tiene un "Manager" asociado.
        // - Si existe lo utilizamos para resaltar el objeto.
        // - Si no existe mostramos un mensaje de advertencia en pantalla.
        if (manager)
        {
            // Le decimos al "Manager" que resalte el objeto.
            manager->ResaltarActor (mouse_x, mouse_y);
            
#ifdef DEBUG
            // Mostramos en pantalla el mensaje para comprobar la posición del ratón.
            gui_textout(screen, "* Aquí está", mouse_x, mouse_y, 0xFFFF, FALSE);
#endif
        }
        else
        {
            gui_textout(screen,  const_cast<char*>("NO SE HA INICIALIZADO LA REFERENCIA AL JUEGO!!!"), SCREEN_W/2, SCREEN_H/2, 0xFFFF, TRUE);
        }
 }

/**
 * \brief  Carga el actor marcado en un actor temporal para modificar sus propiedades.
 *         ¿Es necesario esto para algo?
 */
void    Dialog::mostrar_actor   ()
{
    // Cargamos las propiedades del actor marcado.
    // \todo    ¿No deberíamos dar la posición x e y para obtener el actor?
    //          Esto nos muestra el actor marcado como editado... peligroso
    //          que no sea justo el que está bajo la x y la y.
    
    //dlg_actor->load (manager->get_actor());
    //dlg_actor->show();
    
    //dlg_ventana2->show();
    //dlg_ventana->show ();
    //manager->redibuja();
}

/**
 * \brief   Dibuja de nuevo la GUI.
 */
void    Dialog::draw   ()
{
    // Oculta el ratón para no dejar rastros por pantalla.
    mouse_out ();
    
    // Pide redibujar los objetos del juego.
    manager->redibuja();

    // Redibujar los propios controles de la GUI.
    // Nota: Esto no es necesario de momento, sólo mostramos el marco.
    mostrar_marco ();

    // Mostramos la posición actual del actor en un cuadro de texto.
    // \todo    Deberíamos comprobar que estamos editando y moviendo un actor.
    if (manager->EditandoActor())
    {
        //~ Prueba fallida para hacer trasparente las letras.
        //~ BITMAP *copia;
        //~ int w=dialog_objeto[0].w;
        //~ int h=dialog_objeto[0].h;
        //~ copia=create_bitmap (h,w);
        //~ blit (screen, copia, mouse_x, mouse_y, 0, 0, w, h);
        //~ blit (copia, screen, 0,0,mouse_x+100, mouse_y+100, w, h);
        
        // Le decimos a la posición sobre el cursor que se muestre.
        object_message(&dlg_actor[0], MSG_DRAW, 0);
    }

    // Vuelve a mostrar el ratón.
    mouse_in ();
}

/**
 * \brief   Mueve el actor activo a la posición especificada
 *
 */
void    Dialog::mover_actor  (void)
{
        // Eliminamos la referencia tomada respecto al actor a la posición actual del ratón y movemos el actor.
        // Se hace esto para evitar el movimiento del actor respecto a la posición del ratón.
        manager->MoverActor(mouse_x + ref_x, mouse_y + ref_y);

        // Convertimos la posición a una cadena y la ponemos en el objeto
        //  para mostrarlo más tarde como texto junto al cursor.
        std::stringstream posicion;
        posicion << mouse_x + ref_x <<  ", " << mouse_y + ref_y;
        std::string str = posicion.str();
        dlg_actor[0].dp = const_cast <char*> (str.c_str());

        // Movemos la posición de la cadena cerca del cursor.
        dlg_actor[0].x=mouse_x+15;
        dlg_actor[0].y=mouse_y-10;
}

void Dialog::prueba_dblclk ()
{
    if (manager)
    {
            // Le decimos al "Manager" que resalte el objeto.
            manager->ResaltarActor (mouse_x, mouse_y);
        
            // Editar puede también desactivar la edición... hay que cambiarlo.
            manager->EditarActor (mouse_x, mouse_y);

            // Si la última petición de edición hizo que se editara...
            if (manager->EditandoActor())
            {
                // Tomamos la referencia del ratón respecto al actor.
                // ¿Esto no lo debería hacer el EditorManager (manager)?
                ref_x = manager->GetActorX() - mouse_x;
                ref_y = manager->GetActorY() - mouse_y;
            }
    }
}

/**
* \brief    Duplica un actor que se encuentra bajo la posición local x,y.
*/
int  Dialog::DuplicarActor (int x, int y)
{
    if (manager->EditandoActor())
    {
        manager->DuplicarActor (x, y);
    }
    return D_O_K; 
};

