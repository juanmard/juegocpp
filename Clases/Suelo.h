#ifndef _SUELO_H_
#define _SUELO_H_

#include "Mosaico.h"
#include <allegro.h>
#include "Almacen.h"
#include <string>

using namespace std;

class Actor;

/** 
 * \brief   Gráfico de suelo modificable en tamaño para actores.
 * \details Esta clase modela un suelo gráfico modificable en tamaño y basado en mosaicos.
 */
class Suelo : public Mosaico
{
  public:
                      Suelo     (const Suelo &copia, Actor *propietario);
                      Suelo     (Actor *aowner, int size);
                      Suelo     (Actor *aowner, Almacen &almacen, int size);
    virtual Suelo *   clone     (Actor *propietario) const;
    void              setSize   (int size);
    int               getSize   (void);
    virtual string    getString () const;

  private:
    int       size;
    BITMAP *  suelo_1;
    BITMAP *  suelo_2;
};

#endif
