#pragma once

#include <vector>
#include <allegro.h>

namespace fwg { class Ladrillo; };

namespace alg4 {
/**
 * \brief   LadrilloGUI.
 */
class LadrilloGUI
{
  public:
              LadrilloGUI     (fwg::Ladrillo& ladri, std::vector<DIALOG>& gui_padre_param);
              ~LadrilloGUI    ();
    void      rellenarGUI     (fwg::Ladrillo& ladrillo);

  private:
    enum {inicio=0, bitmap=3, fin=5};
    unsigned int        pto_inserccion;
    std::vector<DIALOG>&    gui_padre;
    fwg::Ladrillo&          ladrillo;

public:
  // Prueba GUI interna.
  static  DIALOG  dlg_plantilla[];
  static  char *  dummy_getter (int index, int *list_size)
  {
    if (index < 0)
    {
      *list_size = 6;
      return NULL;
    }
    else
    {
      switch (index)
      {
        case 0:  return const_cast<char*>("primero");
        case 1:  return const_cast<char*>("segundo");
        case 2:  return const_cast<char*>("tercero");
        case 3:  return const_cast<char*>("cuarto");
        case 4:  return const_cast<char*>("quinto");
        case 5:  return const_cast<char*>("cordero");
        default: return const_cast<char*>("sin índice");
      }
    }
  };
};

}