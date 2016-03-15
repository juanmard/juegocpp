/**
 *  \file     ActorGUI.cpp
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
#include <sstream>
#include "Actor.h"
#include "ActorGraphic.h"
#include "LadrilloGUI.h"
#include "VectorGUI.h"
#include "GUIContador.h"
#include "GUIVector.h"
#include "EscenarioGUI.h"

using std::ostringstream;

Actor *  ActorGUI::actor_activo = NULL;
DIALOG   ActorGUI::dlg_plantilla[] =
{
   /* (proc)                  (x)  (y)  (w)  (h)  (fg) (bg) (key) (flags) (d1) (d2) (dp)                              (dp2) (dp3) */
   { ActorGUI::callback,      8,   314, 616, 20,  67,  243, 0,    0,      0,   0,   (void*)"Actor >>",                NULL, NULL },
   { d_box_proc,              8,   336, 616, 240, 67,  243, 0,    0,      0,   0,   NULL,                             NULL, NULL },
   { d_box_proc,              14,  342, 258, 192, 67,  243, 0,    0,      0,   0,   NULL,                             NULL, NULL },
   { d_text_proc,             22,  346, 58,  8,   67,  243, 0,    0,      0,   0,   (void*)"Nombre:",                 NULL, NULL },
   { d_text_proc,             22,  358, 80,  8,   67,  243, 0,    0,      0,   0,   (void*)"Posicion:",               NULL, NULL },
   { d_text_proc,             22,  368, 96,  8,   67,  243, 0,    0,      0,   0,   (void*)"Dimensiones: ",           NULL, NULL },
   { d_text_proc,             22,  380, 72,  8,   67,  243, 0,    0,      0,   0,   (void*)"Grafico: ",               NULL, NULL },
   { d_text_proc,             22,  390, 112, 8,   67,  243, 0,    0,      0,   0,   (void*)"Tiempo estado: ",         NULL, NULL },
   { d_text_proc,             22,  402, 114, 8,   67,  243, 0,    0,      0,   0,   (void*)"Estado actual: ",         NULL, NULL },
   { d_check_proc,            18,  492, 144, 12,  67,  243, 0,    0,      1,   0,   (void*)"Mostrar limites",         NULL, NULL },
   { d_text_proc,             142, 346, 122, 8,   67,  243, 0,    0,      0,   0,   (void*)"Nombre actor",            NULL, NULL },
   { VectorGUI::callback,     142, 358, 122, 8,   67,  243, 0,    0,      0,   0,   (void*)"100, 100",                NULL, NULL },
   { VectorGUI::callback,     142, 368, 122, 8,   67,  243, 0,    0,      0,   0,   (void*)"100, 100",                NULL, NULL },
   { ActorGUI::callback_graf, 142, 380, 122, 8,   67,  243, 0,    0,      0,   0,   (void*)"Sprite",                  NULL, NULL },
//   { ContadorGUI::callback,   142, 390, 122, 8,   67,  243, 0,    0,      0,   0,   (void*)"100",                     NULL, NULL },
   { GUIContador::callback,   142, 390, 122, 8,   67,  243, 0,    0,      0,   0,   (void*)"100",                     NULL, NULL },
   { GUIVector::callback,     142, 450, 122, 8,   67,  243, 0,    0,      0,   0,   (void*)"100, 100",                NULL, NULL },
   { d_list_proc,             142, 400, 122, 12,  67,  243, 0,    0,      0,   0,   (void*)LadrilloGUI::dummy_getter, NULL, NULL },
   { d_slider_proc,           98,  512, 168, 16,  67,  243, 0,    0,      16,  4,   NULL,                             NULL, NULL },
   { NULL,                    0,   0,   0,   0,   0,   0,   0,    0,      0,   0,   NULL,                             NULL, NULL }
};

/**
 * \brief   Prueba para añadir la GUI de las propiedades del actor a una GUI padre.
 */
ActorGUI::ActorGUI (Actor &a, vector<DIALOG> &gui_padre):
actor (a),
gui (gui_padre)
{
  // Si no hay otro hacemos activo el actor que estamos creando.
  if (!actor_activo)
  {
    actor_activo = &a;
  }

  // Rellenamos con los datos del objeto. Esto debería ir en 'setActor ()' que muestra otro actor.
  // Lo mejor sería obtener todos los datos en la cadena dada por 'getString' y directamente mostrarlos.
  // Nombre:
  string *cadena = new string(a.getNombre());
  dlg_plantilla[nombre].dp = const_cast<char*>(cadena->c_str());

  // Posición y Dimensiones (Tipo Vector).
  // La clase debe ser 'friend' de 'Actor' para poder acceder a la referencia de sus propiedades.
  dlg_plantilla[posicion].dp3 = new VectorGUI (a.x, a.y);
  dlg_plantilla[dimensiones].dp3 = new VectorGUI (a.w, a.h);

  // Gráfico:
  ActorGraphic *graf = a.get_actor_graphic ();
  cadena = new string(graf->print ());
  *cadena = cadena->substr (0, cadena->find(" >>"));
  dlg_plantilla[grafico].dp = const_cast<char*>(cadena->c_str());

  // Tiempo de estado (Como un tipo Contador).
//  dlg_plantilla[tiempo].dp3 = new ContadorGUI (a.tiempo_estado);
  dlg_plantilla[tiempo].proc = GUIContador::callback;
  dlg_plantilla[tiempo].dp3 = new GUIContador (a.tiempo_estado);

  // prueba de GUIVector
  dlg_plantilla[prueba].proc = GUIVector::callback;
  dlg_plantilla[prueba].dp3 = new GUIVector (a.x, a.y);

  // Enlazamos de prueba el GUIVector con otro...y en ambos sentidos...
  static_cast<GUIControl *>(dlg_plantilla[prueba].dp3)->addEnlace (&dlg_plantilla[posicion]);
  // y se prueba el padre para actualizar el control del gráfico.
  // NOTA: No funciona... no se sabe porqué.
  // static_cast<GUIControl *>(dlg_plantilla[prueba].dp3)->addEnlace (&gui_padre[0]);

  // Guardamos el punto de insercción y añadimos la GUI al padre.
  pto_inserccion = gui_padre.size ()-1;
  gui_padre.insert (gui_padre.end()-1, &dlg_plantilla[inicio], &dlg_plantilla[fin]);
};

/**
 * Destruye la GUI del actor.
 */
ActorGUI::~ActorGUI()
{
  // Liberar recursos.
}

/**
 * \brief   Cambia el actor mostrado en esta GUI.
 */
void  ActorGUI::setActor (Actor &a)
{
  // Marcamos el actor activo para la clase.
  actor_activo = NULL;

  // Hacer más corto el nombre de la variable.
  unsigned int pto = pto_inserccion;

  // Actualizamos el nombre.
  string *cadena = new string(a.getNombre());
  gui[pto + nombre].dp = const_cast<char*>(cadena->c_str());

  // NOTA: Esto debería ir todo en respuesta al mensaje MSG_DRAW e ir en una
  //       clase distinta: TextoGUI.
  rectfill (screen, gui[pto + nombre].x, gui[pto + nombre].y,
            gui[pto + nombre].x + gui[pto + nombre].w,
            gui[pto + nombre].y + gui[pto + nombre].h,
                gui_bg_color);
  object_message (&gui[pto + nombre], MSG_DRAW, 0);

  // Gráfico:
  ActorGraphic *graf = a.get_actor_graphic ();
  cadena = new string(graf->print ());
  *cadena = cadena->substr (0, cadena->find(" >>"));
  gui[pto + grafico].dp = const_cast<char*>(cadena->c_str());
  object_message (&gui[pto + grafico], MSG_DRAW, 0);

  // Posición y Dimensiones.
  // Se cambia la referencia del vector.
  static_cast<VectorGUI *>(gui[pto + posicion].dp3)->setVector (a.x, a.y);
  static_cast<VectorGUI *>(gui[pto + dimensiones].dp3)->setVector (a.w, a.h);
  object_message (&gui[pto + posicion], MSG_DRAW, 0);
  object_message (&gui[pto + dimensiones], MSG_DRAW, 0);
};
