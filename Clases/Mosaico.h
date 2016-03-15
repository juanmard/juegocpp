#ifndef _MOSAICO_H_
#define _MOSAICO_H_

#include "ActorGraphic.h"
#include "DatFile.h"
#include "Tesela.h"
#include <string>
#include <list>

//using namespace std;
using std::string;
using std::list;

class Tesela;

class Mosaico : public ActorGraphic
{
private:
    list<Tesela *> teselas;         ///< Lista de las teselas gráficas que constituyen el mosaico.
    list<Tesela *>::iterator it;    ///< Iterador de uso en la lista de teselas. @note Este iterador no tiene sentido en las propiedades.

public:
    /// Constructor básico y mínimo.
    ///
    Mosaico ();

                            Mosaico             (const Mosaico &copia, Actor *propietario);
                            Mosaico             (Actor *actor_asociado);
        void                draw                (BITMAP *pantalla);
        void                draw                (int x, int y, BITMAP *pantalla);
        void                add_primera_Tesela  (Tesela *nueva);
        void                add_ultima_Tesela   (Tesela *nueva);
        void                del_primera_Tesela  ();
        void                move_Tesela         (int inc_x, int inc_y, Tesela *elegida);
        Tesela *            last_Tesela         () const;
        void                swap_Tesela         (Tesela *tesela_1, Tesela *tesela_2);
        virtual Mosaico *   clone               (Actor *propietario) const;

    /// Obtiene las propiedades del mosaico en una única cadena de caracteres.
    /// @return Cadena de caracteres con todas las propiedades del mosaico.
    /// @warning No podemos hacer el método constante debido a la inicialización de los
    ///          iteradores constantes (Investigar).
    ///
    std::string print ();

    /// Elimina todas las teselas del mosaico.
    ///
    void clear ();
};

#endif
