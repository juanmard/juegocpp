
#include "Dialog.h"
#include "DlgActor.h"
#include "VentanaALG.h"

//#define PRUEBAS
//#define DEBUG

// Inicialización de las variables estáticas de la clase.
// Diálogo general de la GUI del editor.
DIALOG Dialog::dialog[] =
{
   /* (proc)                 (x)  (y)  (w)  (h)  (fg) (bg) (key) (flags)                               (d1) (d2) (dp)                                     (dp2) (dp3) */
   { Dialog::marco_callback, 16,  24,  612, 300, 254, 50,  0,    0,                                    0,   0,   NULL,                                    NULL, NULL },
   { d_menu_proc,            0,   0,   640, 15,  7,   15,  0,    D_SELECTED | D_GOTFOCUS | D_GOTMOUSE, 0,   0,   Dialog::menu_editor,                     NULL, NULL },
   { d_text_proc,            344, 328, 100, 8,   14,  219, 0,    0,                                    0,   0,   const_cast<char*>("Lista de actores: "), NULL, NULL },
   { d_text_proc,            8,   360, 32,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Estado:"),           NULL, NULL },
   { Dialog::lista_callback, 344, 340, 144, 92,  50,  219, 0,    0,                                    0,   0,   NULL,                                    NULL, NULL },
   { d_bitmap_proc,          500, 336, 104, 96,  0,   0,   0,    0,                                    0,   0,   NULL,                                    NULL, NULL },
   { d_box_proc,             92,  336, 128, 80,  16,  164, 0,    0,                                    0,   0,   NULL,                                    NULL, NULL },
   { d_text_proc,            100, 360, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("andando"),           NULL, NULL },
   { d_text_proc,            8,   372, 40,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Anterior:"),         NULL, NULL },
   { d_text_proc,            100, 372, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("disparando"),        NULL, NULL },
   { d_text_proc,            8,   384, 40,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Siguiente:"),        NULL, NULL },
   { d_text_proc,            100, 384, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("saltando"),          NULL, NULL },
   { d_text_proc,            8,   400, 40,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Posicion:"),         NULL, NULL },
   { d_text_proc,            100, 400, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("00X, 00Y"),          NULL, NULL },
   { d_text_proc,            8,   344, 32,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Nombre:"),           NULL, NULL },
   { d_text_proc,            100, 344, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Sin nombre"),        NULL, NULL },
   { NULL,                   0,   0,   0,   0,   0,   0,   0,    0,                                    0,   0,   NULL,                                    NULL, NULL }
};

// Diálogo de objeto.
DIALOG Dialog::dlg_actor [] =
{
   /* (proc)             (x),  (y),  (w),  (h), (fg),  (bg), (key),  (flags),   (d1),  (d2),  (dp),                                (dp2), (dp3)     */
   { d_text_proc,          0,  100,  300,  200,    7,    15,     0,        0,      0,     0, const_cast<char*>("x, y"),             NULL, NULL },
   { d_slider_proc,       20,  200,   20,  160,    2,    33,     0,        0,    100,    50,                                  NULL, NULL, NULL },
   { d_slider_proc,       60,  200,   20,  160,    2,    33,     0,        0,    100,    50,                                  NULL, NULL, NULL },
    // Prueba para la lista de trajes. dp se actualiza en el constructor y apunta al procedimiento para obtener información de la lista.
   { Dialog::mi_list_proc, 0,   40,   120, 200,    2,    33,     0,        0,    100,    50,                                  NULL, NULL, NULL },
   { d_text_proc,        470,   20,  160,   20,    2,    33,     0,        0,      0,     0, const_cast<char*>("  Modo Edición  "), NULL, NULL },
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
    { const_cast<char*>("&Editar"),  NULL, Dialog::mnu_actor,   0, NULL },
    { const_cast<char*>("&Ayuda"),   NULL, Dialog::mnu_ayuda,   0, NULL },
    { NULL, NULL, NULL, 0, NULL }
};

// Menú del objeto.
MENU Dialog::mnu_actor [] =
{
   { const_cast<char*>("&Mover"),       Dialog::menu_callback,      NULL,          0, NULL },
   { const_cast<char*>("&Duplicar"),    Dialog::cb_menu_opciones,   NULL,          0, NULL },
   { const_cast<char*>("&Traje"),       Dialog::cb_menu_opciones,   NULL,          0, NULL },
   { const_cast<char*>("&Tamaño"),      Dialog::menu_callback,      NULL, D_DISABLED, NULL },
   { const_cast<char*>("&Propiedades"), Dialog::menu_callback,      NULL,          0, NULL },
   { NULL, NULL, NULL, 0, NULL }
};

/**
 * \brief   Construye la clase que servirá de GUI para editar un juego.
 */
Dialog::Dialog (EditorManager *editor):
manager (editor),
actor (NULL),
ref_x (0), ref_y(0)
{
    // Se inicializan los colores de la GUI.
    gui_fg_color = makecol(255,255,255);
    gui_bg_color = makecol(128,128,128);

    // Se  inicializa el ancho del menú.
    dialog[menu].w = SCREEN_W;

    // Se inicializan parámetros de los "callback".
    // \todo    Enum para referencias a "dialog". 
    dialog[scr].dp = this;
    dialog[scr].dp2 = manager;

    // Se crea un diálogo para el actor vacío.
    dlg_actor2 = new DlgActor(this);
    dialog[scr].dp3 = dlg_actor;

    dlg_ventana2 = new VentanaALG ("Otra prueba de fondo...",0,0,SCREEN_W,SCREEN_H);
    dlg_ventana = new VentanaALG ("Prueba",100,100,120,120);

    // Se apunta a ese diálogo en el menú del objeto.
    //mnu_actor[3].dp = editor->get_actor ();

    // Inicializamos las propiedades del actor.
    dlg_actor[0].fg = makecol (255,255,255);
    dlg_actor[0].bg = makecol (0,0,255);

    // Inicializamos el slider de prueba.
    dlg_actor[1].dp2 = (void*)Dialog::clbk_prueba_slider;
    dlg_actor[1].dp3 = manager;
    dlg_actor[2].dp2 = (void*)Dialog::clbk_prueba_slider;
    dlg_actor[2].dp3 = manager;

    // Inicializamos las llamadas del menú contextual.
    // Parece ser que incluir la referencia directa no funciona, hay que pasar por
    // un procedimiento estático.
    //    mnu_actor[1].proc = reinterpret_cast<int(*)()>(&Dialog::DuplicarActor);
    mnu_actor[1].dp = this;
    mnu_actor[2].dp = this;

  // Inicializamos la lista de actores.
  dialog[lista].dp = (void *) Dialog::getterListaActores;
  dialog[lista].dp3 = manager;

  // Bitmap
  dialog[bitmap].dp = manager->getBuffer ();

  // Color del fondo de los controles.
  for (int i = pantalla; i < ultimo; i++)
  {
    dialog[i].bg = makecol (128,128,128);
  }
  
  // Color de la caja que borra los valores.
  dialog[caja].fg = makecol (128,128,128);
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
  // Se borra la pantalla.
  manager->borrarPantalla ();

  // Se modifica el tamaño del escenario mostrado (ribete) y se ajusta a la GUI.
  manager->setRibete (Bloque (dialog[scr].x, dialog[scr].y,
                              dialog[scr].w, dialog[scr].h));

  // Se hace visible el menú de edición.
  // Si se pulsa ESC debemos mostrar el mensaje de cierre 'quit'.
  // Repetimos el bucle hasta que en el mensaje de cierre se elija "Sí".
  int salida = D_O_K;
  while (salida != D_CLOSE)
  {
    salida = do_dialog (dialog,-1);
    if (salida == -1)
    {
      salida = quit ();
    }
  }
}

/**
 * \brief   Oculta el puntero del ratón.
 */
void Dialog::mouse_out (void)
{
  show_mouse (NULL);
}

/**
 * \brief   Muestra el ratón en pantalla.
 */
void Dialog::mouse_in (void)
{
  show_mouse (screen);
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
//            manager->resaltarActor (x, y);

            // Para hacer pruebas con el slider editamos el actor.
//            manager->editarActor (x, y);

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
//    if (manager->editandoActor())
    {
        int actor_x = manager->getActorX ();
        int actor_y = manager->getActorY ();
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
        manager->setActorX(actor_x);
        manager->setActorY(actor_y);
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
void  Dialog::prueba_dclick ()
{
}

/**
 * \brief   Dibuja de nuevo la GUI.
 */
void  Dialog::draw ()
{
  // Oculta el ratón para no dejar rastros por pantalla ni parpadeos.
  mouse_out ();

  // Se dibuja el escenario.
  manager->dibujarEscenario ();

  // Redibujar los propios controles de la GUI.
  //int error;
  //dialog_message (&dialog[1], MSG_DRAW, 0, &error);

  // Si hay un actor en edición se dibujan sus ¿nuevos? valores.
  if (actor)
  {
    // \todo  Realizar una única petición al EditorManager esto realiza un doble
    //        volcado en pantalla.
    int x = dialog[0].x; int y = dialog[0].y;
    int w = dialog[0].w; int h = dialog[0].h;
    int xAct = actor->get_x () - manager->getEscenarioX ();// + dialog[pantalla].x;
    int yAct = actor->get_y () - manager->getEscenarioY ();// + dialog[pantalla].y;
    int wAct = actor->get_w ();
    int hAct = actor->get_h ();
    rect (manager->getBuffer (), xAct, yAct, xAct+wAct, yAct+hAct, makecol(0,255,0));
    blit (manager->getBuffer (), screen, 0, 0, x, y, w, h);
  }

  // Usamos la caja para borrar.
  object_message(&dialog[caja], MSG_DRAW, 0);
  // Actualizamos las propiedades del actor.
  object_message(&dialog[nombre], MSG_DRAW, 0);
  object_message(&dialog[estado], MSG_DRAW, 0);
  object_message(&dialog[pos], MSG_DRAW, 0);

  // Vuelve a mostrar el ratón.
  mouse_in ();
}

/**
 * \brief   Mueve el actor activo a la posición actual del ratón.
 */
void  Dialog::mover_actor  (void)
{
  // Eliminamos la referencia tomada respecto al actor a la posición actual del ratón y movemos el actor.
  // Se hace esto para evitar el movimiento del actor respecto a la posición del ratón.
//  manager->moverActor (mouse_x + ref_x + manager->getEscenarioX (), mouse_y + ref_y + manager->getEscenarioY ());
  if (actor)
  {
    actor->set_x (mouse_x + ref_x + manager->getEscenarioX ());
    actor->set_y (mouse_y + ref_y + manager->getEscenarioY ());
    actualizarValoresActor ();
  }
}

/**
 * \brief   Prueba de click con el ratón.
 */
void Dialog::prueba_click ()
{
  if (manager)
  {
    actor = manager->getActor (mouse_x - dialog[0].x + manager->getEscenarioX (),
                               mouse_y - dialog[0].y + manager->getEscenarioY ());

    // Si encontramos el actor bajo el ratón, guardamos sus propiedades.
    if (actor)
    {
      // Tomamos la referencia del ratón respecto al actor.
      tomarReferencia ();
    }
    // Se actualizan los valores en la GUI del actor recién encontrado.
    actualizarValoresActor ();

    // Dibujamos de nuevo la GUI.
    draw ();
  }
};

/**
* \brief    Duplica un actor que se encuentra bajo la posición local x,y.
* \todo     Esto no es una acción propia de la GUI, debe estar como acción en el EditorManager.
*/
void  Dialog::duplicarActor ()
{
  // Si hay un actor seleccionado para editar...
  if (actor)
  {
    manager->duplicarActor (actor);
  }
}

/**
* \brief    Cambia el traje del actor que actualmente se esté editando.
* \todo     Esto no es una acción propia de la GUI, debe estar como acción en el EditorManager.
*/
int  Dialog::CambiarTraje ()
{
    // Se le pregunta al EditorManager si está editando un actor actualmente.
//    if (manager->editandoActor())
    {
        // Si se está ediando un actor...
        // 1 - Preguntar por la lista de trajes que hay en la clase "Vestuario"
        //     mediante el EditorManager.
        // Esto lo hace directamente desde la función callback de la lista (cb_prueba_lista)

        // 2 - La GUI debe crear un control de lista.
        do_dialog (&dlg_actor[3],-1); // Usamos como prueba una parte del dlg_actor.

        // 3 - Llenar el control de lista con los posibles trajes.
        // Esto también se hace directamente desde la función callback de la lista.
        
        // 4 - Según nos movemos por la lista indicar al EditorManager que debe cambiar
        //     el traje del actor y mostrar el cambio.
    }
    return D_O_K; 
};

/**
 *  \brief  Mueve con el teclado el escenario.
 */
void    Dialog::mover_kbd_escenario   (int code)
{
    int x = manager->getEscenarioX ();
    int y = manager->getEscenarioY ();
    switch ((code & 0xff))
    {
    case 'w':
        y -= 4;
        break;
    case 's':
        y += 4;
        break;
    case 'a':
        x -= 4;
        break;
    case 'd':
        x += 4;
        break;
    case 'f':
    case 'F':
        // \warning   Se actualiza dos veces la pantalla, en 'step' y en 'draw'.
        manager->step ();
        actualizarValoresActor ();
        break;
    }
    manager->moverEscenario (x, y);
    draw ();
};

/**
 * \brief   Actualizamos los valores del actor en pantalla.
 */
void  Dialog::actualizarValoresActor ()
{
  // Si hay un actor que se está editando...
  if (actor)
  {
    // Construimos la cadena de posición.
    std::stringstream posicion;
    posicion << actor->get_x ()
             <<  ", "
             << actor->get_y ();
    std::string str = posicion.str();

    // Actualizamos el valor de los controles.
    dialog[pos].dp = const_cast <char*> (str.c_str());
    dialog[estado].dp = const_cast <char*> ((actor->getEstado ()).c_str());
    dialog[nombre].dp = const_cast<char *>((actor->getNombre ()).c_str());
  }
  else
  {
    // Construimos la cadena de posición.
    std::stringstream posicion;
    posicion << manager->getEscenarioX ()
             <<  ", "
             << manager->getEscenarioY ();
    std::string str = posicion.str();

    // Actualizamos el valor de los controles.
    dialog[pos].dp = const_cast <char*> (str.c_str());
    dialog[nombre].dp = const_cast<char *>("Escenario");
  }
}

/**
 * \brief   Centramos el actor pasado como índice en una lista en el escenario.
 * \param   indice    Índice del actor en la lista.
 */
void  Dialog::centrarActor (int indice)
{
  manager->centrarActor (indice);
}

/**
 * \brief   Se toma el actor del que mostrar sus propiedades.
 */
void  Dialog::setActor (Actor *actorMostrar)
{
  actor = actorMostrar;
  actualizarValoresActor ();
}

/**
 * \brief   Se cambia el color del ribete.
 */
void  Dialog::setColorRibete (int color)
{
  manager->setColorRibete (color);
}

/**
 * \brief   Se toma la referencia del ratón respecto al actor.
 */
void  Dialog::tomarReferencia ()
{
  ref_x = actor->get_x() - manager->getEscenarioX () - mouse_x;
  ref_y = actor->get_y() - manager->getEscenarioY () - mouse_y;
}

/**
 * \brief   Se mueve el escenario según la posición del ratón.
 */
void  Dialog::moverEscenario ()
{
  // Si el actor no está activo y se está pulsando la tecla de mover
  // con el ratón, movemos el escenario.
  if ((actor == NULL) && key[KEY_LCONTROL])
  {
    int x =  mouse_x; //manager->getEscenarioX () - dialog[scr].x - rel_scr_y; 
    int y =  mouse_y; //manager->getEscenarioY () - mouse_y - dialog[scr].y - rel_scr_y; 

    manager->moverEscenario (x, y);
    draw ();
  }
};
