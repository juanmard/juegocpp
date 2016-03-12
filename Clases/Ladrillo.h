#pragma once
#include "Actor.h"
#include "DatFile.h"
#include "Bitmap.h"
#include "Nombres.h"
#include "LadrilloGUI.h"
#include <vector>

using std::vector;

/**
 * \brief   Actor para ser golpeado por la pelota del juego.
 * \todo    Añadir posibilidad de lanzar objetos al jugador, de desviar la pelota, etc...
 */
class Ladrillo :  public Actor
{
public:
                        Ladrillo    (const Ladrillo &copia);
                        Ladrillo    (void);
                        Ladrillo    (int x, int y);
                        Ladrillo    (int x, int y, Almacen &almacen);
                        ~Ladrillo   ();
    void                hit         (Actor *who, int damage);
    void                update      ();
    virtual Ladrillo *  clone       () const;
    void                getNombre   (string &strNombre) const;
    string              getNombre   () const;
    virtual Menu &      getMenu     () const;
    void                addGUI      (vector<DIALOG> &gui_padre);

private:
  /**
   * \brief Definición de los distintos estados del ladrillo.
   *        Reservamos los diez primeros estados para estados generales de la clase "Actor"
   */
  enum {ESPERA=10, EN_CAIDA}; 

  void        crear_ladrillo (void);
  Bitmap     *chaqueta;
  SAMPLE     *peloteo;
};
