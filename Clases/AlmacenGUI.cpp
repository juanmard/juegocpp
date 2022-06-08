///
/// @file AlmacenGUI.cpp
/// @brief Fichero de implementación de la clase "AlmacenGUI".
/// @author Juan Manuel Rico
/// @date Marzo 2010
/// @version
///      - 1.0.0 Marzo 2010
///      - 1.0.1 Diciembre 2010
///      - 1.0.2 Noviembre 2015
///

#include <sstream>
#include "AlmacenGUI.h"

/* Plantilla estática */
DIALOG AlmacenGUI::dlg_plantilla[] =
{
   /* (proc)                   (x)  (y)  (w)  (h)  (fg) (bg) (key) (flags) (d1) (d2) (dp)                          (dp2) (dp3) */
   { AlmacenGUI::callback_mov, 584, 176, 208, 264, 67,  243, 0,    0,      0,   0,   NULL,                         NULL, NULL },
   { AlmacenGUI::callback,     592, 200, 192, 56,  67,  243, 0,    0,      0,   0,   (void *) list_getter,         NULL, NULL },
   { d_text_proc,              592, 184, 128, 8,   67,  243, 0,    0,      0,   0,   (void *)"Nombre del fichero", NULL, NULL },
   { d_bitmap_proc,            592, 264, 192, 152, 67,  243, 0,    0,      0,   0,   NULL,                         NULL, NULL },
   { d_text_proc,              592, 424, 128, 8,   67,  243, 0,    0,      0,   0,   (void *)"Mensaje",            NULL, NULL },
   { NULL,                     0,   0,   0,   0,   0,   0,   0,    0,      0,   0,   NULL,                         NULL, NULL }
};

/* Variable estática que referencia al almacen activo. */
Almacen* AlmacenGUI::almacen_activo = NULL;

AlmacenGUI::AlmacenGUI (Almacen& _almacen):
almacen (_almacen),
pto_inserccion (0),
activado (false)
{
  // Si no hay otro hacemos activo el almacén recién creado.
  if (!almacen_activo)
  {
    activar_almacen (_almacen);
  }

  // Modificamos la plantilla para este almacén.
  dlg_plantilla[0].dp3 = (void *) this;
  dlg_plantilla[1].dp3 = (void *) this;
  dlg_plantilla[2].dp = const_cast<char*>((*new std::string("Almacén: \"" + _almacen.get_nombre() + "\"")).c_str());
  dlg_plantilla[3].dp = screen;

  // Guardamos la plantilla modificada.
  dlg.clear ();
  dlg.insert (dlg.end(), &dlg_plantilla[0], &dlg_plantilla[5]);
};

AlmacenGUI::AlmacenGUI (Almacen& _almacen, std::vector<DIALOG>& gui_padre):
almacen (_almacen),
activado (false)
{
  // Si no hay otro hacemos activo el almacen recién creado.
  if (!almacen_activo)
  {
    activar_almacen (_almacen);
  }

  // Modificamos la plantilla para este almacén.
  dlg_plantilla[0].dp3 = (void *) this;
  dlg_plantilla[1].dp3 = (void *) this;
  dlg_plantilla[2].dp = const_cast<char *>((new std::string("Almacén: \"" + _almacen.get_nombre() + "\""))->c_str());
  dlg_plantilla[3].dp = screen;

  // Guardamos la plantilla modificada.
  pto_inserccion = gui_padre.size ()-1;
  gui_padre.insert (gui_padre.end()-1, &dlg_plantilla[0], &dlg_plantilla[5]);
};

/**
 * \brief   Destructor por omisión.
 * \todo    Liberar los recursos correctamente.
 */
AlmacenGUI::~AlmacenGUI ()
{
  // Liberar los recursos.
};

/**
 * \brief   Devuelve el conjunto de DIALOG.
 */
std::vector<DIALOG>& AlmacenGUI::get_GUI ()
{
  return dlg;
}

/**
 * \brief   Cambiamos el objeto 'almacen' a visualizar en la GUI.
 */
void AlmacenGUI::activar_almacen (Almacen& almacenParam)
{
  almacen_activo = &almacenParam;
};

/**
 * \brief   Se mueve el ratón por encima del contenedor.
 */
void AlmacenGUI::mover_mouse (DIALOG* d)
{
  if (atrapado)
  {
    position_dialog(&d[0], mouse_x, mouse_y);
    int j;
    dialog_message (&d[0],MSG_DRAW,0, &j);
  }
  
  if (!atrapado && activado)
  {
    std::ostringstream cadena;
    cadena << "x,y: " << mouse_x << "," << mouse_y;
    d[4].dp = const_cast<char *>((new std::string(cadena.str()))->c_str());
    object_message (&d[4],MSG_DRAW,0);
  }
}

