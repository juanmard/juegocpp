#include "LadrilloGUI.h"
#include "Ladrillo.h"
#include "Actor.h"

DIALOG LadrilloGUI::dlg_plantilla[] =
{
   /* (proc)        (x)  (y)  (w)  (h)  (fg) (bg) (key) (flags) (d1) (d2) (dp)                              (dp2) (dp3) */
   { d_box_proc,    284, 342, 256, 192, 67,  243, 0,    0,      0,   0,   NULL,                             NULL, NULL },
   { d_list_proc,   292, 368, 240, 56,  67,  243, 0,    0,      0,   0,   (void*)LadrilloGUI::dummy_getter, NULL, NULL },
   { d_text_proc,   292, 352, 128, 8,   67,  243, 0,    0,      0,   0,   (void*)"Prueba Ladrillo",         NULL, NULL },
   { d_bitmap_proc, 292, 432, 240, 88,  67,  243, 0,    0,      0,   0,   NULL,                             NULL, NULL },
   { NULL,          0,   0,   0,   0,   0,   0,   0,    0,      0,   0,   NULL,                             NULL, NULL }
};

/**
 * \brief   Destructor.
 */
LadrilloGUI::~LadrilloGUI ()
{
}

/**
 * \brief   Constructor.
 */
LadrilloGUI::LadrilloGUI (Ladrillo &ladri, vector<DIALOG> &gui_padre_param):
gui_padre (gui_padre_param),
ladrillo (ladri)
{
  // Guardamos el punto de insercción y añadimos la GUI al padre.
  pto_inserccion = gui_padre.size ()-1;
  gui_padre.insert (gui_padre.end()-1, &dlg_plantilla[inicio], &dlg_plantilla[fin]);

  // Se cambia los valores con el ladrillo actual.
  rellenarGUI (ladrillo);
}

/**
 * \brief   Cambiamos los valores mostrados en la GUI según el Ladrillo pasado como parámetro.
 */
void  LadrilloGUI::rellenarGUI (Ladrillo &ladrillo)
{
  // Rellenamos el gráfico.
  Bitmap *grafico = (Bitmap *) ladrillo.get_actor_graphic ();
  gui_padre[pto_inserccion+bitmap].dp = grafico->getImagen();
}
