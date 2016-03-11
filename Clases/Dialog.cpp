
#include "Dialog.h"
#include "DlgActor.h"
#include "VentanaALG.h"

//#define PRUEBAS
//#define DEBUG

// \todo    Hacer el enum propio de la clase, no global.
enum {pantalla=0, lista=4, bitmap=5, pos=13, nombre=15, caja=6, ultimo=16};

// Inicialización de las variables estáticas de la clase.
// Diálogo general de la GUI del editor.
DIALOG Dialog::dialog[] =
{
   /* (proc)                 (x)  (y)  (w)  (h)  (fg) (bg) (key) (flags)                               (d1) (d2) (dp)                                   (dp2) (dp3) */
   { Dialog::marco_callback, 16,  24,  612, 300, 254, 50,  0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_menu_proc,            0,   0,   640, 15,  7,   15,  0,    D_SELECTED | D_GOTFOCUS | D_GOTMOUSE, 0,   0,   Dialog::menu_editor,                   NULL, NULL },
   { d_text_proc,            534, 342, 80,  16,  14,  219, 0,    0,                                    0,   0,   const_cast<char*>("  Modo Edicion  "), NULL, NULL },
   { d_text_proc,            8,   360, 32,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Estado:"),         NULL, NULL },
   { d_list_proc,            385, 342, 144, 60,  50,  219, 0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_bitmap_proc,          552, 412, 83,  64,  0,   0,   0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_box_proc,             92,  336, 128, 80,  16,  164, 0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_text_proc,            100, 360, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("andando"),         NULL, NULL },
   { d_text_proc,            8,   372, 40,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Anterior:"),       NULL, NULL },
   { d_text_proc,            100, 372, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("disparando"),      NULL, NULL },
   { d_text_proc,            8,   384, 40,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Siguiente:"),      NULL, NULL },
   { d_text_proc,            100, 384, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("saltando"),        NULL, NULL },
   { d_text_proc,            8,   400, 40,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Posicion:"),       NULL, NULL },
   { d_text_proc,            100, 400, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("00X, 00Y"),        NULL, NULL },
   { d_text_proc,            8,   344, 32,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Nombre:"),         NULL, NULL },
   { d_text_proc,            100, 344, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Sin nombre"),      NULL, NULL },
   { NULL,                   0,   0,   0,   0,   0,   0,   0,    0,                                    0,   0,   NULL,                                  NULL, NULL }
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
actor (NULL)
{
    // Se inicializan los colores de la GUI.
    gui_fg_color = makecol(255,255,255);
    gui_bg_color = makecol(128,128,128);

    // Se inicializa el tamaño inicial de la ventana que recibe las llamadas.
    //~ dialog[0].x = 0;
    //~ dialog[0].y = 14;
    //~ dialog[0].h = SCREEN_H;
    //~ dialog[0].w = SCREEN_W;

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
    dlg_ventana = new VentanaALG ("Prueba",100,100,120,120);

    // Se apunta a ese diálogo en el menú del objeto.
    //mnu_actor[3].dp = editor->get_actor ();

    // Inicializamos las propiedades del actor.
    dlg_actor[0].fg = makecol (255,255,255);
    dlg_actor[0].bg = makecol (0,0,255);     //bitmap_mask_color (screen); 

    // Inicializamos el slider de prueba.
    dlg_actor[1].dp2 = (void*)Dialog::clbk_prueba_slider;
    dlg_actor[1].dp3 = manager;
    dlg_actor[2].dp2 = (void*)Dialog::clbk_prueba_slider;
    dlg_actor[2].dp3 = manager;

    // Inicializamos la lista de trajes de prueba.
    dlg_actor[3].dp = (void*)Dialog::cb_prueba_lista;
    dlg_actor[3].dp3 = manager;
    
    // Inicializamos las llamadas del menú contextual.
    // Parece ser que incluir la referencia directa no funciona, hay que pasar por
    // un procedimiento estático.
    //    mnu_actor[1].proc = reinterpret_cast<int(*)()>(&Dialog::DuplicarActor);
    mnu_actor[1].dp = this;
    mnu_actor[2].dp = this;

  // Inicializamos la lista de pruebas.
//  dialog[lista].dp = (void*)Dialog::dummy_getter;
  dialog[lista].dp = (void*)Dialog::cb_prueba_lista;
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
  clear_to_color (screen, makecol(128,128,128));

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
    control_texto.set_xy (400, 100);
  //  prueba.add(control_texto);
        
    MenuALG &control_menu = *(new MenuALG());
    control_menu.set_xy (300, 50);
    ItemALG &menu_item = *(new ItemALG());
    control_menu.add(menu_item);
    
    menu_item = *(new ItemALG("Prueba2"));
    control_menu.add(menu_item);
    prueba.add(control_menu);

    prueba.show();

    // Después de pulsar 'ESC' modificamos el dialogo de prueba y lo volvemos a mostrar.
    menu_item = *(new ItemALG("Prueba3"));
    control_menu.add (menu_item);
    prueba.add (control_menu);
    prueba.show ();

    // Eliminamos la tecla 'ESC' del buffer de teclado.
    key[KEY_ESC] = false;
#endif
}

/**
 * Oculta el puntero del ratón.
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
            manager->resaltarActor (x, y);

            // Para hacer pruebas con el slider editamos el actor.
            manager->editarActor (x, y);

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
    if (manager->editandoActor())
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
void  Dialog::prueba_click ()
{
        // Prueba del diálogo del Actor.
        DlgActor dialogo (this);
        dialogo.load (manager->getActor (mouse_x + manager->getEscenarioX (),
                                          mouse_y + manager->getEscenarioY ()));
        dialogo.show();            

        // Comprobamos que el Diálogo tiene un "Manager" asociado.
        // - Si existe lo utilizamos para resaltar el objeto.
        // - Si no existe mostramos un mensaje de advertencia en pantalla.
        if (manager)
        {
            // Le decimos al "Manager" que resalte el objeto.
            manager->resaltarActor (mouse_x + manager->getEscenarioX (), mouse_y + manager->getEscenarioY ());
            
#ifdef DEBUG
            // Mostramos en pantalla el mensaje para comprobar la posición del ratón.
            gui_textout_ex (screen, "* Aquí está", mouse_x + manager->getEscenarioX (), mouse_y + manager->getEscenarioY (), 0xFFFF, FALSE);
#endif
        }
        else
        {
            gui_textout_ex (screen, const_cast<char*>("NO SE HA INICIALIZADO LA REFERENCIA AL JUEGO!!!"), SCREEN_W/2, SCREEN_H/2, 0xFFFF, makecol(255, 100, 200), TRUE);
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
void  Dialog::draw ()
{
  // Oculta el ratón para no dejar rastros por pantalla ni parpadeos.
  mouse_out ();

  // Se dibuja el escenario y un contorno.
  // \todo  Se debería agrupar en una única petición al EditorManager.
  //        y el EditorManager hacer la petición al StageManager para que
  //        se dibujaran los cuadrados sobre el buffer original y luego realizar
  //        el volcado ('Blit') sobre la pantalla. De esta forma se evitaría el
  //        parpadeo de los gráficos debidos a más de un volcado por ciclo.
  int x = dialog[0].x; int y = dialog[0].y;
  int w = dialog[0].w; int h = dialog[0].h;
  manager->dibujarEscenario (Bloque (x, y, w, h));
  // manager->dibujarEscenario ();
  rect (manager->getBuffer (), 0, 0, w-1, h-1, makecol (255, 0, 0));
  blit (manager->getBuffer (), screen, 0, 0, x, y, w, h);

  // Redibujar los propios controles de la GUI.
  //int error;
  //dialog_message (&dialog[1], MSG_DRAW, 0, &error);

  // Si hay un actor en edición se dibujan sus ¿nuevos? valores.
  if (actor)
  {
    // \todo  Realizar una única petición al EditorManager.
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
void Dialog::prueba_dblclk ()
{
  if (manager)
  {
    // Si hay actor editando, dejamos de editarlo.
    if (actor)
    {
      actor = NULL;
    }
    // Si actualmente no hay actor editando, lo buscamos bajo el ratón.
    else
    {
      actor = manager->getActor (mouse_x - dialog[0].x + manager->getEscenarioX (),
                                 mouse_y - dialog[0].y + manager->getEscenarioY ());
      // Si encontramos el actor bajo el ratón, guardamos sus propiedades.
      if (actor)
      {
        // Tomamos la referencia del ratón respecto al actor.
        ref_x = actor->get_x() - manager->getEscenarioX () - mouse_x;
        ref_y = actor->get_y() - manager->getEscenarioY () - mouse_y;
      }
    }
    // Se actualizan los valores en la GUI del actor recién encontrado.
    actualizarValoresActor ();

    // Dibujamos de nuevo la GUI.
    draw ();
  }
}

/**
* \brief    Duplica un actor que se encuentra bajo la posición local x,y.
* \todo     Esto no es una acción propia de la GUI, debe estar como acción en el EditorManager.
*/
int  Dialog::DuplicarActor (int x, int y)
{
  if (actor)
  {
    manager->duplicarActor (x, y);
  }
  return D_O_K; 
};

/**
* \brief    Cambia el traje del actor que actualmente se esté editando.
* \todo     Esto no es una acción propia de la GUI, debe estar como acción en el EditorManager.
*/
int  Dialog::CambiarTraje ()
{
    // Se le pregunta al EditorManager si está editando un actor actualmente.
    if (manager->editandoActor())
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
        y -= 1;
        break;
    case 's':
        y += 1;
        break;
    case 'a':
        x -= 1;
        break;
    case 'd':
        x += 1;
        break;
    case 'f':
    case 'F':
        manager->step ();
        actualizarValoresActor ();
        draw ();
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
    dialog[nombre].dp = const_cast<char *>(Nombres::Imprimir (actor->getNombre()).c_str());
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
