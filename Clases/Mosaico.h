#ifndef MOSAICO_H
#define MOSAICO_H

#include "ActorGraphic.h"
#include "DatFile.h"
#include "Tesela.h"
#include <list>

using namespace std;

class Tesela;

class Mosaico : public ActorGraphic
{
    public:
                Mosaico     (Actor *actor_asociado);
        void    draw        (BITMAP *pantalla);
        void    add_Tesela  (Tesela *nueva);    

    private:
   		list<Tesela *> skins;
		list<Tesela *>::iterator skins_iter;
};
#endif