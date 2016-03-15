#include "Mosaico.h"


Mosaico::Mosaico(Actor *aowner) : ActorGraphic (aowner)
{
}

void    Mosaico::add_Tesela  (Tesela *nueva)
{
    skins.push_back (nueva);
};    


void Mosaico::draw (BITMAP *pantalla)
{
    list<Tesela *>::iterator tmp_iter;

    // Dibuja todas las teselas del mosaico.
    for (tmp_iter=skins.begin(); tmp_iter!=skins.end(); tmp_iter++)
    {
        (*tmp_iter)->draw (pantalla);
    }
}
