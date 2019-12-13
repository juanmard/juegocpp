#include "LadrilloGUI.h"
#include "Ladrillo.h"
#include "Actor.h"

namespace alg4 {

DIALOG LadrilloGUI::dlg_plantilla[] =
{
   /* (proc)        (x)  (y)  (w)  (h)  (fg) (bg) (key) (flags) (d1) (d2) (dp)                              (dp2) (dp3) */
   { d_box_proc,    288, 360, 256, 192, 67,  243, 0,    0,      0,   0,   NULL,                             NULL, NULL },
   { d_list_proc,   296, 390, 240, 34,  67,  243, 0,    0,      0,   0,   (void*)LadrilloGUI::dummy_getter, NULL, NULL },
   { d_text_proc,   296, 374, 128, 8,   67,  243, 0,    0,      0,   0,   (void*)"Prueba Ladrillo",         NULL, NULL },
   { d_bitmap_proc, 296, 454, 240, 88,  67,  243, 0,    0,      0,   0,   NULL,                             NULL, NULL },
   { d_button_proc, 296, 428, 120, 20,  67,  243, 0,    0,      0,   0,   (void*)"&Imagen",               NULL, NULL },
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
LadrilloGUI::LadrilloGUI (fwg::Ladrillo& ladri, std::vector<DIALOG>& gui_padre_param):
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
void  LadrilloGUI::rellenarGUI (fwg::Ladrillo& ladrillo)
{
  // Rellenamos el gráfico.
  fwg::Bitmap* grafico = (fwg::Bitmap*) ladrillo.getActorGraphic ();
  gui_padre[pto_inserccion+bitmap].dp = grafico->get_imagen();
}

}