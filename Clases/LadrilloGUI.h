#pragma once

#include <vector>
#include <allegro.h>

using std::vector;
class Ladrillo;

/**
 * \brief   LadrilloGUI.
 */
class LadrilloGUI
{
  public:
              LadrilloGUI     (Ladrillo &ladri, vector<DIALOG> &gui_padre_param);
              ~LadrilloGUI    ();
    void      rellenarGUI     (Ladrillo &ladrillo);

  private:
    enum {inicio=0, bitmap=3, fin=5};
    unsigned int        pto_inserccion;
    vector<DIALOG> &    gui_padre;
    Ladrillo &          ladrillo;

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
