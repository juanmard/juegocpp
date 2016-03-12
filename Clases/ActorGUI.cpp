/**
 *  \file     Actor.cpp
 *  \brief    Prueba del "framework" de un juego.
 *
 *  \details  La clase instancia un tipo de juego de prueba con todos los controladores posibles.
 *            La primera versión de la instancia se utiliza para actualizar el juego de plataformas
 *            programado antiguamente en C "puro y duro".
 *
 *  \author   Juan Manuel Rico
 *  \date     diciembre 2010
 *  \version  1.00
 *
 *  \todo     Comentar todas estas clases y funciones más detalladamente.
 */
#include "ActorGUI.h"
#include <string>
#include "Actor.h"

Actor *  ActorGUI::actor_activo = NULL;
DIALOG   ActorGUI::dlg_plantilla[] =
{
   /* (proc)             (x)  (y)  (w)  (h)  (fg) (bg) (key) (flags) (d1) (d2) (dp)                          (dp2) (dp3) */
   { ActorGUI::callback, 8,   314, 616, 20,  67,  243, 0,    0,      0,   0,   (void*)"Actor >>",            NULL, NULL },
   { d_box_proc,         8,   336, 616, 240, 67,  243, 0,    0,      0,   0,   NULL,                         NULL, NULL },
   { d_box_proc,         14,  342, 258, 192, 67,  243, 0,    0,      0,   0,   NULL,                         NULL, NULL },
   { d_text_proc,        22,  346, 58,  8,   67,  243, 0,    0,      0,   0,   (void*)"Nombre:",             NULL, NULL },
   { d_text_proc,        22,  358, 80,  8,   67,  243, 0,    0,      0,   0,   (void*)"Posicion:",           NULL, NULL },
   { d_text_proc,        22,  368, 96,  8,   67,  243, 0,    0,      0,   0,   (void*)"Ancho, Alto: ",       NULL, NULL },
   { d_text_proc,        22,  380, 72,  8,   67,  243, 0,    0,      0,   0,   (void*)"Grafico: ",           NULL, NULL },
   { d_text_proc,        22,  390, 112, 8,   67,  243, 0,    0,      0,   0,   (void*)"Tiempo estado: ",     NULL, NULL },
   { d_text_proc,        22,  402, 114, 8,   67,  243, 0,    0,      0,   0,   (void*)"Estado actual: ",     NULL, NULL },
   { d_check_proc,       18,  492, 144, 12,  67,  243, 0,    0,      1,   0,   (void*)"Mostrar limites",     NULL, NULL },
   { d_text_proc,        142, 346, 122, 8,   67,  243, 0,    0,      0,   0,   (void*)"Nombre actor",        NULL, NULL },
   { d_text_proc,        142, 358, 122, 8,   67,  243, 0,    0,      0,   0,   (void*)"100, 100",            NULL, NULL },
   { d_text_proc,        142, 368, 122, 8,   67,  243, 0,    0,      0,   0,   (void*)"100, 100",            NULL, NULL },
   { ActorGUI::callback_graf,  142, 380, 122, 8,   67,  243, 0,    0,      0,   0,   (void*)"Sprite",              NULL, NULL },
   { d_text_proc,              142, 390, 122, 8,   67,  243, 0,    0,      0,   0,   (void*)"100",                 NULL, NULL },
   { d_list_proc,              142, 400, 122, 12,  67,  243, 0,    0,      0,   0,   (void*)ActorGUI::list_getter, NULL, NULL },
   { d_slider_proc,            98,  512, 168, 16,  67,  243, 0,    0,      16,  4,   NULL,                         NULL, NULL },
   { NULL,                     0,   0,   0,   0,   0,   0,   0,    0,      0,   0,   NULL,                         NULL, NULL }
};

/**
 * \brief   Prueba para añadir la GUI de las propiedades del actor a una GUI padre.
 */
ActorGUI::ActorGUI (Actor &a, vector<DIALOG> &gui_padre):
actor (a)
{
  // Si no hay otro hacemos activo el actor.
  if (!actor_activo)
  {
    actor_activo = &a;
  }

  // Rellenamos con los datos del objeto. Esto debería ir en 'setActor ()' que muestra otro actor.
  string *cadena = new string(a.getNombre());
  dlg_plantilla[nombre].dp = const_cast<char*>(cadena->c_str());

  // Prueba de DIALOG. Llenamos el vector de DIALOG's.
  // Usamos la plantilla global.
  pto_inserccion = gui_padre.size ()-1;
  gui_padre.insert (gui_padre.end()-1, &dlg_plantilla[navegador], &dlg_plantilla[fin]);

  delete (cadena);
};

/**
 * Destruye la GUI del actor.
 */
ActorGUI::~ActorGUI()
{
  // Liberar recursos.
}

