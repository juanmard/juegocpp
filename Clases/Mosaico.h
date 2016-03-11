#ifndef MOSAICO_H
#define MOSAICO_H

#include "ActorGraphic.h"
#include "DatFile.h"
#include "Tesela.h"
#include <string>
#include <list>

using namespace std;

class Tesela;

class Mosaico : public ActorGraphic
{
    public:
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
        string              getString           ();

    private:
      list<Tesela *>            teselas;
      list<Tesela *>::iterator  it;
};
#endif
