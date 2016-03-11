#ifndef _MAPA_H_
#define _MAPA_H_

#include <string>
#include "Actor.h"
#include "ActorManager.h"
#include "DatFile.h"

using namespace std;

/**
 * \class   Mapa
 * \brief   Clase que define la disposición de actores dentro del escenario.
 * \todo
 *          - Grabar los distintos actores de la escena.
 *          - Recuperar los actores y sus propiedades y ponerlos en escena.
 */
class Mapa
{
  public:
                Mapa      (DatFile &ficheroDatos);
                Mapa      ();
                ~Mapa     ();
    void        Read      (ActorManager &manager);
    void        Save      (const ActorManager &manager) const;
    string      getString () const;

  private:
    string      nombre;
    DatFile *   fichero;
    string      buffer;
};

#endif
