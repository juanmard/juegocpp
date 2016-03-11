/**
 *  \file     AlmacenGUI.cpp
 *  \brief    Fichero de implementación de la clase AlmacenGui.
 *
 *  \author  Juan Manuel Rico
 *  \date     diciembre 2010
 *  \version  1.00
 *
 */
#include "AlmacenGUI.h"

/* Plantilla estática */
DIALOG AlmacenGUI::dlg_plantilla[] = 
{
     /* (proc)          (x)  (y)  (w)  (h)  (fg) (bg) (key) (flags) (d1) (d2) (dp)                                 (dp2) (dp3) */
   { d_box_proc   ,        584, 176, 208, 248, 67, 243,   0,    0,      0,   0,   NULL,                             NULL, NULL },
   { AlmacenGUI::callback, 592, 200, 192, 56,  67, 243,   0,    0,      0,   0,   (void *) list_getter,             NULL, NULL },
   { d_text_proc,          592, 184, 128, 8,   67, 243,   0,    0,      0,   0,   (void *)"Nombre del fichero",     NULL, NULL },
   { d_bitmap_proc,        592, 264, 192, 152, 67, 243,   0,    0,      0,   0,   NULL,                             NULL, NULL },
   { NULL,                   0,   0,   0,   0,  0,   0,   0,    0,      0,   0,   NULL,                             NULL, NULL }
};

/* Variable estática que referencia al almacen activo. */
Almacen * AlmacenGUI::almacen_activo = NULL;

/**
 * \brief   Constructor de la GUI para el almacén dado por parámetro.
 * \param   almacen   Referencia al almacén que se le asocia.
 */
AlmacenGUI::AlmacenGUI (Almacen &almacen)
{
  setAlmacen (almacen);
  dlg_plantilla[1].dp3 = (void *) &almacen;
  dlg_plantilla[2].dp = const_cast<char *>((new string("Almacén: \"" + almacen.getNombre() + "\""))->c_str());
  dlg_plantilla[3].dp = screen;

  dlg.clear ();
  dlg.push_back (dlg_plantilla[0]);
  dlg.push_back (dlg_plantilla[1]);
  dlg.push_back (dlg_plantilla[2]);
  dlg.push_back (dlg_plantilla[3]);
};


/**
 * \brief   Constructor por omisión.
 * \details Mostramos simplemente la plantilla y la guardamos en 'dlg'.
 */
AlmacenGUI::AlmacenGUI ()
{
  dlg_plantilla[3].dp = screen;
  dlg.clear ();
  dlg.push_back (dlg_plantilla[0]);
  dlg.push_back (dlg_plantilla[1]);
  dlg.push_back (dlg_plantilla[2]);
  dlg.push_back (dlg_plantilla[3]);
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
vector<DIALOG> &  AlmacenGUI::getGUI ()
{
  return dlg;
}

/**
 * \brief   Cambiamos el objeto 'almacen' a visualizar en la GUI.
 */
void  AlmacenGUI::setAlmacen (Almacen &almacen)
{
  almacen_activo = &almacen;
}
