/**
 *  \file     AlmacenGUI.cpp
 *  \brief    Fichero de implementación de la clase AlmacenGui.
 *
 *  \author   Juan Manuel Rico
 *  \date     Diciembre 2010
 *  \version  1.00
 *
 */
#include "AlmacenGUI.h"
#include <sstream>

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
Almacen * AlmacenGUI::almacen_activo = NULL;

/**
 * \brief   Constructor de la GUI para el almacén dado por parámetro.
 * \param   almacenParam   Referencia al almacén que se le asocia.
 */
AlmacenGUI::AlmacenGUI (Almacen &almacenParam):
almacen (almacenParam),
activado (false)
{
  // Si no hay otro hacemos activo el almacén recién creado.
  if (!almacen_activo)
  {
    activarAlmacen (almacenParam);
  }

  // Modificamos la plantilla para este almacén.
  dlg_plantilla[0].dp3 = (void *) this;
  dlg_plantilla[1].dp3 = (void *) this;
  dlg_plantilla[2].dp = const_cast<char *>((new string("Almacén: \"" + almacenParam.getNombre() + "\""))->c_str());
  dlg_plantilla[3].dp = screen;

  // Guardamos la plantilla modificada.
  // NOTA:  En lugar de crear un nuevo vector dlg habría que guardar el punto de insercción del padre y añadirlos a él
  //        la plantilla modificada. Algo así:
  //
  //          pto_insercción = dlg_padre.size ();
  //          dlg_padre.push_back [i];
  //
  //        Más tarde se podrían modificar haciendo referencia al punto de insercción:
  //
  //          dlg_padre[pto_inserccion+4];
  //
  //        O incluso sobrecargar el operador [] para que hiciera:
  //
  //          objeto[4]
  //
  //        Y en el operador sobrecargado se obtendría la referencia automáticamente:
  //
  //          return dlg_padre[pto_insercción+indiceParam]
  //
  dlg.clear ();
  for (int i=0; i<=5; i++)
  {
    dlg.push_back (dlg_plantilla[i]);
  }
};


/**
 * \brief   Constructor por omisión.
 * \details Mostramos simplemente la plantilla y la guardamos en 'dlg'.
 *
AlmacenGUI::AlmacenGUI ()
{
  dlg_plantilla[3].dp = screen;
  dlg.clear ();
  dlg.push_back (dlg_plantilla[0]);
  dlg.push_back (dlg_plantilla[1]);
  dlg.push_back (dlg_plantilla[2]);
  dlg.push_back (dlg_plantilla[3]);
};
*/

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
void  AlmacenGUI::activarAlmacen (Almacen &almacenParam)
{
  almacen_activo = &almacenParam;
}

/**
 * \brief   Se mueve el ratón por encima del contenedor.
 */
void  AlmacenGUI::moverMouse ()
{
  if (activado)
  {
    ostringstream cadena;

    cadena << "x,y: " << mouse_x << "," << mouse_y;
    dlg[4].dp = const_cast<char *>(cadena.str().c_str());
    //position_dialog(&dlg[0], mouse_x, mouse_y);
    //int j;
    //dialog_message (&dlg[0],MSG_DRAW,0, &j);
    object_message (&dlg[4],MSG_DRAW,0);
  }
}
