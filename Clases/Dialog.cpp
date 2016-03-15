#include "Dialog.h"
#include "DlgActor.h"
#include "VentanaALG.h"
//#include "resize.h"
#include <iostream>
#include <fstream>
#include "GUIEscenario.h"
#include "ActorGUI.h"

// Inicialización de las variables estáticas de la clase.
// Diálogo general de la GUI del editor.
DIALOG Dialog::dialog[] =
{
   /* (proc)                       (x)  (y)  (w)  (h)  (fg) (bg) (key) (flags) (d1) (d2) (dp)                                     (dp2) (dp3) */
   { Dialog::callback_scr,         16,  24,  612, 300, 254, 50,  0,    0,      0,   0,   NULL,                                    NULL, NULL },
   { d_menu_proc,                  0,   0,   640, 15,  7,   15,  0,    0,      0,   0,   Dialog::menu_editor,                     NULL, NULL },
   { d_text_proc,                  344, 328, 100, 8,   14,  219, 0,    0,      0,   0,   const_cast<char*>("Lista de actores: "), NULL, NULL },
   { d_text_proc,                  8,   380, 32,  8,   50,  219, 0,    0,      0,   0,   const_cast<char *>("Estado:"),           NULL, NULL },
   { Dialog::callback_lista,       344, 340, 144, 92,  50,  219, 0,    0,      0,   0,   NULL,                                    NULL, NULL },
   { d_bitmap_proc,                500, 336, 104, 96,  0,   0,   0,    0,      0,   0,   NULL,                                    NULL, NULL },
   { d_box_proc,                   100, 336, 156, 112, 16,  164, 0,    0,      0,   0,   NULL,                                    NULL, NULL },
   { d_text_proc,                  108, 380, 82,  8,   50,  219, 0,    0,      0,   0,   const_cast<char *>("andando"),           NULL, NULL },
   { d_text_proc,                  12,  420, 40,  8,   50,  219, 0,    0,      0,   0,   const_cast<char *>("Anterior:"),         NULL, NULL },
   { d_text_proc,                  108, 420, 82,  8,   50,  219, 0,    0,      0,   0,   const_cast<char *>("disparando"),        NULL, NULL },
   { d_text_proc,                  12,  432, 40,  8,   50,  219, 0,    0,      0,   0,   const_cast<char *>("Siguiente:"),        NULL, NULL },
   { d_text_proc,                  108, 432, 82,  8,   50,  219, 0,    0,      0,   0,   const_cast<char *>("saltando"),          NULL, NULL },
   { d_text_proc,                  8,   368, 40,  8,   50,  219, 0,    0,      0,   0,   const_cast<char *>("Posicion:"),         NULL, NULL },
   { Dialog::callback_coordenadas, 108, 368, 82,  8,   50,  219, 0,    0,      0,   0,   const_cast<char *>("00X, 00Y"),          NULL, NULL },
   { d_text_proc,                  8,   344, 32,  8,   50,  219, 0,    0,      0,   0,   const_cast<char *>("Nombre:"),           NULL, NULL },
   { d_text_proc,                  108, 344, 82,  8,   50,  219, 0,    0,      0,   0,   const_cast<char *>("Sin nombre"),        NULL, NULL },
   { d_check_proc,                 348, 436, 112, 12,  50,  219, 0,    0,      1,   0,   const_cast<char *>("Centrar en pantalla"), NULL, NULL },
   { d_text_proc,                  8,   356, 40,  8,   50,  219, 0,    0,      0,   0,   const_cast<char *>("Dimensiones:"),      NULL, NULL },
   { Dialog::callback_coordenadas, 108, 356, 82,  8,   50,  219, 0,    0,      0,   0,   const_cast<char *>("00X, 00Y"),          NULL, NULL },
   { d_text_proc,                  12,  458, 322, 8,   50,  219, 0,    0,      0,   0,   (void*)"Para pruebas con la GUI pulsa la telca T", NULL, NULL },
   { NULL,                         0,   0,   0,   0,   0,   0,   0,    0,      0,   0,   NULL,                                    NULL, NULL }
};

// Menú fichero.
MENU Dialog::mnu_fichero[] =
{
  { const_cast<char*>("&Leer mapa"),    Dialog::menu_fichero, NULL, ~(D_DISABLED | D_SELECTED), NULL },
  { const_cast<char*>("&Grabar mapa"),  Dialog::menu_fichero, NULL, ~(D_DISABLED | D_SELECTED), NULL },
  { const_cast<char*>(""),              Dialog::quit,         NULL,                 D_DISABLED, NULL },
  { const_cast<char*>("&Salir\tF2"),    Dialog::quit,         NULL,                          0, NULL },
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
  { const_cast<char*>("&Fichero"), NULL, Dialog::mnu_fichero,    0, NULL },
  { const_cast<char*>("&Editar"),  NULL, &Dialog::mnu_actor[3],  0, NULL },
  { const_cast<char*>("&Ayuda"),   NULL, Dialog::mnu_ayuda,      0, NULL },
  { NULL, NULL, NULL, 0, NULL }
};

// Menú del objeto.
MENU Dialog::mnu_actor [] =
{
  { const_cast<char*>("sin nombre"),   Dialog::cb_menu_opciones,  NULL,          0, NULL },
  { const_cast<char*>("Prueba"),       Dialog::cb_menu_opciones,  NULL, D_DISABLED, NULL },
  { const_cast<char*>(""),             Dialog::cb_menu_opciones,  NULL, D_DISABLED, NULL },
  { const_cast<char*>("&Mover"),       Dialog::cb_menu_opciones,  NULL, D_DISABLED, NULL },
  { const_cast<char*>("&Duplicar"),    Dialog::cb_menu_opciones,  NULL,          0, NULL },
  { const_cast<char*>("&Traje"),       Dialog::cb_menu_opciones,  NULL, D_DISABLED, NULL },
  { const_cast<char*>("&Tamaño"),      Dialog::cb_menu_opciones,  NULL, D_DISABLED, NULL },
  { const_cast<char*>("&Propiedades"), Dialog::cb_menu_opciones,  NULL, D_DISABLED, NULL },
  { NULL, NULL, NULL, 0, NULL }
};

/**
 * \brief   Construye la clase que servirá de GUI para editar un juego.
 */
Dialog::Dialog (EditorManager *editor):
manager (editor),
actor (NULL),
ref_x (0), ref_y(0),
moviendoActor (false)
{
  // Se inicializan los colores de la GUI.
  gui_fg_color = makecol(44,44,211);
  gui_bg_color = makecol(207,207,255);
  gui_mg_color = makecol(105,56,36);

  // Se inicializan parámetros de los "callback".
  dialog[scr].dp = this;
  dialog[scr].dp2 = manager;
  dialog[posicion].dp3 = this;
  dialog[dimensiones].dp3 = this;

  // Se  inicializa el ancho del menú.
  dialog[menu].w = SCREEN_W;

  // Inicializamos la lista de actores.
  dialog[lista].dp = (void *) Dialog::getterListaActores;
  dialog[lista].dp3 = this;

  // Bitmap
  dialog[bitmap].dp = manager->getBuffer ();

  // Color del fondo de los controles.
  for (int i = scr; i < ultimo; i++) dialog[i].bg = makecol (128,128,128);

  // Color de la caja que borra los valores.
  dialog[caja].fg = makecol (128,128,128);

  // Menú para duplicar.
  mnu_actor[4].dp = this;

  // Inicializamos el menú de fichero.
  mnu_fichero[0].dp = this;
  mnu_fichero[1].dp = this;

  // Hacemos una prueba de menú dinámico.
  menu_dinamico.add (const_cast<char*>("Etiqueta 1 - Opciones"));
  menu_dinamico.add (const_cast<char*>("Etiqueta 2 - Padre"), 0, &mnu_actor[3], NULL);
  menu_dinamico.add (const_cast<char*>("Etiqueta 3 - Duplicar"), 0, this, NULL, Dialog::cb_menu_opciones);
  menu_dinamico.add (const_cast<char*>("Etiqueta 4"), 0, NULL, NULL, Dialog::about);
  mnu_actor[0].child = menu_dinamico;
}

/**
 * \brief   Destructor de la clase.
 */
Dialog::~Dialog (void)
{
  // Ocultamos el puntero del ratón.
  //mouse_out ();
  // \todo Liberar memoria de todos los objetos utilizados.
}

/**
 * \brief   Activa el modo edición del juego.
 * \details Al activar el modo edición del juego se debe:
 *          - Parar el bucle normal del juego.
 *          - Generar un menu con las propiedades de edición.
 *          - Activar un bucle propio.
 */
void Dialog::show (void)
{
  // Se borra la pantalla.
  manager->borrarPantalla ();

  // Se modifica el tamaño del escenario mostrado (ribete) y se ajusta a la GUI.
  manager->setRibete (Bloque (dialog[scr].x, dialog[scr].y,
                              dialog[scr].w, dialog[scr].h));

  // Se hace visible el menú de edición.
  // El valor de la salida depende del control que la provocó.
  int salida = D_O_K;
  salida = do_dialog (dialog, scr);
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
  // Elegimos el menú adecuado: actor, lista de actores, fondo...
  // según el tipo de objeto.

  // Como prueba mostranos el nombre del objeto en el menú.
  string nombre;
  if (actor)
  {
    actor->getNombre (nombre);
    mnu_actor[0].text=const_cast<char*>(nombre.c_str());
    mnu_actor[1].flags = 0;
    mnu_actor[1].child = actor->getMenu();
  }
  else
  {
    mnu_actor[0].text=const_cast<char*>("Fondo??");
  }

  // Mostramos el menu del actor en la posición del ratón.
  do_menu (mnu_actor, x, y);
}

/**
 * \brief   Dibuja de nuevo la GUI.
 */
void  Dialog::draw ()
{
  // Oculta el ratón para no dejar rastros por pantalla ni parpadeos.
  //mouse_out ();

  // Se dibuja el escenario.
  manager->dibujarEscenario ();

  // Redibujar los propios controles de la GUI.
  //int error;
  //dialog_message (&dialog[1], MSG_DRAW, 0, &error);

  // Usamos la caja para borrar los valores anteriores.
  object_message(&dialog[caja], MSG_DRAW, 0);
  // Actualizamos las propiedades del actor.
  object_message(&dialog[nombre], MSG_DRAW, 0);
  object_message(&dialog[posicion], MSG_DRAW, 0);
  object_message(&dialog[dimensiones], MSG_DRAW, 0);
  object_message(&dialog[estado], MSG_DRAW, 0);

  // Vuelve a mostrar el ratón.
  //mouse_in ();
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
    // Si hay un actor editándose desactivamos el actor actualmente activo.
    if (actor) actor->set_mostrar_bloque (false);

    // Se busca el otro actor.
    actor = manager->getActor (mouse_x - dialog[scr].x + manager->getEscenarioX (),
                               mouse_y - dialog[scr].y + manager->getEscenarioY ());

    // Si encontramos el actor bajo el ratón, activamos el nuevo actor.
    if (actor)
    {
      // Tomamos la referencia del ratón respecto al actor.
      tomarReferencia ();

      // Activamos el nuevo actor.
      setActor (actor);
    }

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
    draw ();
  }
}

/**
 * \brief   Actualizamos los valores del actor en pantalla.
 */
void  Dialog::actualizarValoresActor ()
{
  // Si hay un actor que se está editando...
  if (actor)
  {
    // Actualizamos el valor de los controles.
    actor->getNombre (strNombre);
    actor->getXY (strPosicion);
    actor->getWH (strDimensiones);
    actor->getEstado (strEstado);

    // \warning   Según http://www.cppreference.com/wiki/string/start' las
    //            cadenas generadas por el método 'c_str()' no es necesario
    //            eliminarlas como objetos. Nos queda saber cual es el ámbito
    //            de estas cadenas una vez generadas.
    // \warning   ¡¡¡Esto último no sucede así en Win32!!!!
    dialog[posicion].dp = const_cast <char *> (strPosicion.c_str ());
    dialog[dimensiones].dp = const_cast <char *> (strDimensiones.c_str ());
    dialog[estado].dp = const_cast <char *> (strEstado.c_str ());
    dialog[nombre].dp = const_cast <char *> (strNombre.c_str ());
  }
  else
  {
    // Construimos la cadena de posición.
    manager->getEscenarioXY (strPosicion);
    strNombre = "Escenario";

    // Actualizamos el valor de los controles.
    dialog[posicion].dp = const_cast <char *> (strPosicion.c_str());
    dialog[nombre].dp = const_cast <char *> (strNombre.c_str());
  }
}

/**
 * \brief   Centramos el actor pasado como índice en una lista en el escenario.
 * \param   indice    Índice del actor en la lista.
 */
void  Dialog::centrarActor (int indice)
{
  // Si había actor anterior se desactiva.
  if (actor) actor->set_mostrar_bloque (false);

  // Se le pide al controlador de edición que centre (y active) el actor
  // con el índice dado.
  manager->centrarActor (indice);
}

/**
 * \brief   Se toma el actor del que mostrar sus propiedades.
 */
void  Dialog::setActor (Actor *actorMostrar)
{
  // Se copia el puntero.
  actor = actorMostrar;

  // Se activa en verde el bloque del actor.
  actor->set_color (makecol(0, 255, 0));
  actor->set_mostrar_bloque (true);

  // Se actualizan las propiedades del actor.
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
  if (actor)
  {
    ref_x = actor->get_x() - manager->getEscenarioX () - mouse_x;
    ref_y = actor->get_y() - manager->getEscenarioY () - mouse_y;
  }
  else
  {
    ref_x = manager->getEscenarioX () + mouse_x;
    ref_y = manager->getEscenarioY () + mouse_y;
  }
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
    int x = ref_x - mouse_x;
    int y = ref_y - mouse_y;
    manager->moverEscenario (x, y);
    draw ();
  }
};

/**
 * \brief   Comprueba la tecla pulsada.
 * \param   code    Código de la tecla pulsada.
 * \return  - 'D_O_K' para seguir siendo procesada.
 *          - 'D_USED_CHAR' si ya no necesita seguir siendo procesada.
 *          - 'D_CLOSED' si se desea cerrar la GUI.
 */
int  Dialog::comprobarTecla (int code)
{
  int salida = D_O_K;
  int x = manager->getEscenarioX ();
  int y = manager->getEscenarioY ();

  // Se comprueba el 'scancode'
  switch (code >> 8)
  {
    case KEY_UP:    y -= 6; salida = D_USED_CHAR; break;
    case KEY_DOWN:  y += 6; salida = D_USED_CHAR; break;
    case KEY_LEFT:  x -= 6; salida = D_USED_CHAR; break;
    case KEY_RIGHT: x += 6; salida = D_USED_CHAR; break;
    case KEY_ESC:   salida = quit(); break;
    default:        salida = D_O_K;
  }

  // Se comprueba el código ASCII.
  switch (code & 0xff)
  {
    case 'w': y -= 4; break;
    case 's': y += 4; break;
    case 'a': x -= 4; break;
    case 'd': x += 4; break;
    case 'f':
    case 'F':
        // \warning   Se actualiza dos veces la pantalla, en 'step' y en 'draw'.
        manager->step ();
        actualizarValoresActor ();
        break;

    case 't':
    case 'T':
    // Zona de pruebas.
    {
      cout << "Funciona la zona de pruebas." << endl;
      static vector<DIALOG> pesta;
      DIALOG dlg_tmp1 = {d_box_proc,     0, 400, 800, 280,  0,   0,   0,    0,      0,   0,   NULL,              NULL, NULL };
      DIALOG dlg_tmp2 = {d_button_proc, 16, 400,  80,  16,  1,   0,   0,    0,      0,   0,   (void*)"Pesta 01", NULL, NULL };
      DIALOG fin =      { NULL,          0,   0,   0,   0,  0,   0,   0,    0,      0,   0,   NULL,              NULL, NULL };

      DIALOG dlg_tmp3;
      dlg_tmp3 = dialog[0];

      // Prueba de la nueva GUI.
      dlg_tmp3.proc = GUIEscenario::callback;
      dlg_tmp3.dp3 = new GUIEscenario (*manager);

      pesta.clear ();
      pesta.push_back (dlg_tmp1);
      pesta.push_back (dlg_tmp2);
      pesta.push_back (dlg_tmp3);
      pesta.push_back (fin);

      // Obtenemos el vector de diálogos del actor.
      if (actor)
      {
        actor->addGUI (pesta);
      }

      // Probamos añadiendo el diálogo del Almacén.
      int idx = pesta.size ();
      manager->getAlmacen().addGUI (pesta);
      position_dialog (&pesta[idx-1],590,320);

      // Probamos con dos almacenes.
/*
       Almacen *prueba = new Almacen ("sprites3.dat");
      idx = pesta.size();
      prueba->addGUI (pesta);
      position_dialog (&pesta[idx-1],100,320);
*/

      // Hacemos una prueba dinámica del dialogo principal.
      // Se copia... ¡¡Funciona!!
      //pesta.insert (pesta.end(), &dialog[0], &dialog[18]);

      popup_dialog (&pesta[0],-1);
    }
    return D_USED_CHAR;
    break;
  }

  manager->moverEscenario (x, y);
  draw ();
  return salida;
};

/**
 * \brief   Comprueba el movimiento del ratón.
 */
void  Dialog::moverMouse ()
{
  moverEscenario ();
  if (moviendoActor)
  {
    mover_actor ();
    draw ();
  }
};

/**
 * \brief   Comprueba las teclas en el control de coordenadas.
 * \return  El procesado de la tecla.
 */
int  Dialog::kdb_coordenadas (DIALOG *d, int code)
{
  // Si no hay actor editándose mejor dejarlo.
  int salida = D_O_K;
  if (actor == NULL) return salida;

    // Se comprueba el 'scancode'
  int x = 0;
  int y = 0;
  switch (code >> 8)
  {
    case KEY_UP:    y = -1; salida = D_USED_CHAR; break;
    case KEY_DOWN:  y = +1; salida = D_USED_CHAR; break;
    case KEY_LEFT:  x = -1; salida = D_USED_CHAR; break;
    case KEY_RIGHT: x = +1; salida = D_USED_CHAR; break;
    case KEY_ESC:   salida = quit(); break;
  }

  // \warning   Hay que comprobar quién está llamando a esta función pues en este
  //            caso puede ser tanto la posicion como las dimensiones.
  //            Para probar comparamos los punteros de los controles.
  // \warning   Esta comparación evita que funcione completamente la prueba dinámica de 'pesta'.
  //            Lo ideal será crear una clase GUI para este tipo de vectores y asociar a ellos
  //            los valores que quiere modificar.
  if (d == &dialog[dimensiones])
  {
    x += actor->get_w ();
    y += actor->get_h ();
    actor->set_wh (x, y);
  }
  if (d == &dialog[posicion])
  {
    x += actor->get_x ();
    y += actor->get_y ();
    actor->set_x (x);
    actor->set_y (y);
  }

  // Actualizamos los valores en la gui.
  actualizarValoresActor ();
  return salida;
};

void Dialog::leerActores ()
{
    this->manager->game->actor_manager->deleteActors ();
    this->manager->game->actor_manager->load ("test.txt");
    this->manager->game->actor_manager->add_all_to_create ();
    std::cout << "Lista de actores leídos." << std::endl;
};

void Dialog::grabarActores ()
{
    std::ofstream outfile ("test.txt");
    outfile << *(this->manager->game->actor_manager);
    outfile.close();
    std::cout << "Grabados objetos en fichero \"test.txt\"" << std::endl;
};
