#include "DlgActor.h"

/**
 * \brief   Inicialización de las variables estáticas.
 */
DIALOG DlgActor::dlg_propiedades[] =
{
  /* (proc)                 (x)  (y)  (w)  (h)  (fg) (bg) (key) (flags) (d1) (d2) (dp)                               (dp2) (dp3) */
  { DlgActor::box_callback, 88,  64,  356, 332, 0,  255,  0,    0,      0,   0,   NULL,                              NULL, NULL },
  { d_text_proc,            95,  64,  115, 11,  0,  255,  0,    0,      0,   0,   const_cast<char*>("Propiedades"),  NULL, NULL },
  { d_textbox_proc,         120, 80,  247, 82,  0,  255,  0,    0,      0,   0,   const_cast<char*>("Escribe aqui"), NULL, NULL },
  { d_slider_proc,          112, 172, 320, 13,  0,  255,  0,    0,      16,  4,   NULL,                              NULL, NULL },
  { d_radio_proc,           117, 193, 14,  13,  0,  255,  0,    0,      0,   0,   const_cast<char*>("Activo"),       NULL, NULL },
  { d_button_proc,          100, 364, 70,  25,  0,  255,  0,    0,      0,   0,   (void*)"button",                   NULL, NULL },
  { d_button_proc,          384, 363, 55,  26,  0,  255,  0,    0,      0,   0,   const_cast<char*>("Cerrar"),       NULL, NULL },
  { NULL,                   0,   0,   0,   0,   0,    0,  0,    0,      0,   0,   NULL,                              NULL, NULL }
};

/**
 * \brief   Construye la clase que servirá de GUI para editar un actor.
 */
DlgActor::DlgActor (Actor *actor_tmp)
{
  // Guardamos referencia al propietario.
  actor = actor_tmp;

  // Se inicializan los colores de la GUI.
  gui_fg_color = makecol(255,255,255);
  gui_bg_color = makecol(128,128,128);

  // Posición anterior del ratón.
  x_ant = mouse_x;
  y_ant = mouse_y;

  // Se inicializan parámetros de los "callback".
  // \todo    Enum para referencias a "dialog". 
  dlg_propiedades[0].dp = this;
}

/**
 * \brief   Construye la clase como hija de otro diálogo.
 * \param   dlg_tmp   Diálogo padre o propietario de este.
 */
DlgActor::DlgActor (Dialog *dlg_tmp):
owner (dlg_tmp),
x_ant (mouse_x),
y_ant (mouse_y),
enganchado (false)
{
  dlg_propiedades[0].dp = this;
}

/**
 * \brief   Destructor por omisión.
 */
DlgActor::~DlgActor ()
{
}

/**
 * \brief   Muestra el diálogo.
 */
void  DlgActor::show ()
{
  do_dialog (dlg_propiedades,-1);
}

/**
 * \brief   Carga el actor a editar.
 */
void  DlgActor::load (Actor *remoto)
{
  // Propiedades de prueba.
  static char buffer[200];

  if (remoto)
  {
    uszprintf (buffer, sizeof(buffer), 
              "Nombre: %s\nPosición: %d, %d\nColor: %d",
              Nombres::Imprimir(remoto->getCodigo ()).c_str(),
              remoto->get_x(),
              remoto->get_y(),
              remoto->get_color()
              );
    //dlg_propiedades[2].dp = const_cast<char *>("Prueba, prueba...");
    dlg_propiedades[2].dp = buffer;
  }
}

/**
 * \brief   Fijar las propiedades modificadas al actor.
 */
void  DlgActor::save ()
{
}

/**
 * \brief   Controla el movimiento del ratón de la clase.
 * \details Allegro no tiene mensaje de movimiento de ratón.
 *          Tenemos que simularlo nosotros haciendo una comprobación constante.
 */
void  DlgActor::msg_idle ()
{
  // Si alguna de las componentes del cursor es distinto...
  if (   (x_ant != mouse_x) 
      || (y_ant != mouse_y) )
  {
    // Enviamos el mensaje de movimiento de cursor.
    object_message (&dlg_propiedades[0], MSG_MOUSEMOVE, 0);

    // Actualizamos la nueva posición del cursor.
    x_ant = mouse_x;
    y_ant = mouse_y;
  }
};

/**
 * \brief   Controla el movimiento del ratón de la clase.
 */
void  DlgActor::msg_mousemove ()
{
  // Si el ratón ha atrapado el marco...
  if (enganchado)
  {
    // Mover y dibujar contorno.
    owner->draw ();
    rect (screen, 
          mouse_x + x_rel,
          mouse_y + y_rel,
          mouse_x + x_rel + dlg_propiedades[0].w, 
          mouse_y + y_rel + dlg_propiedades[0].h,
          makecol(128,128,128)
          );
  }
};

/**
 * \brief   Controla el click del ratón de la clase.
 */
void  DlgActor::msg_click ()
{
  if (enganchado)
  {
    // Cambiamos la posición de todos los objetos del diálogo.
    // Enviamos mensaje de MSG_DRAW.
    // Desenganchamos el diálogo.
    // enganchado = false;
  }
};

/**
 * \brief   Controla el doble click del ratón de la clase.
 */
void  DlgActor::msg_dclick ()
{
  // Si está seleccionado el diálogo...
  if (enganchado)
  {
    // Lo queremos soltar en la nueva posición, para ello...
    // Cambiamos la posición del marco (y sus controles...)
    // Las coordenadas actuales serán las del cursor más la 
    // relativa al marco padre cuando se hizo el 'enganche'.
    int act_x = mouse_x + x_rel;
    int act_y = mouse_y + y_rel;
    position_dialog(&dlg_propiedades[0], act_x, act_y);

    // Dibujamos antes el diálogo padre.
    owner->draw ();

    // Dibujamos el marco y sus controles.
    broadcast_dialog_message (MSG_DRAW, 0);
    //object_message (&dlg_propiedades[0], MSG_DRAW, 0);
  }
  else
  {
    // Guardamos la posición relativa del cursor respecto al marco.
    // Se utilizará para mantener la distancia entre ratón y marco al moverse.
    x_rel = dlg_propiedades[0].x - mouse_x;
    y_rel = dlg_propiedades[0].y - mouse_y;
  }
  // Pase lo que pase... cambiamos el estado del enganche.
  enganchado = !enganchado;
};
