#pragma once

#include "ActorGraphic.h"
#include "Almacen.h"
#include <string>

/** 
 * \brief   Parte gráfica de un actor como un gráfico fijo.
 * \details Esta clase modela una imagen fija como gráfico para un actor.
 */
class Bitmap : public ActorGraphic
{
  public:
                        Bitmap      (Actor *aowner, BITMAP *bmp);
                        Bitmap      (Actor *aowner, string nombreParam);
                        Bitmap      (Actor *aowner, BITMAP *bmp, string nombreParam);
                        Bitmap      (Actor *aowner, Almacen *almacen, const string nombre);
    void                draw        (BITMAP *destino);
    void                draw        (int x, int y, BITMAP *destino);
    int                 get_w       ();
    int                 get_h       ();
    virtual Bitmap *    clone       (Actor *propietario) const;
    virtual string      getString   () const;
    BITMAP *            getImagen   () const;
    static  void        setAlmacen  (Almacen *almacen) {almacenGlobal = almacen;};

  protected:
    // Almacén para todos los objetos de la clase Bitmap.
    static  Almacen *   almacenGlobal;

  protected:
    string      nombre;
    Almacen *   almacen;
    BITMAP *    fuente;
};
