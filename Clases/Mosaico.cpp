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

/**
 * \brief Mueve la tesela elegida según un incremento de 'y' y de 'x'.
 */
void    Mosaico::move_Tesela     (int inc_x, int inc_y, Tesela *elegida)
{
    elegida->Set_x (elegida->Get_x() + inc_x);
    elegida->Set_y (elegida->Get_y() + inc_y);
}

/**
 * \brief Devuelve la última tesela añadida.
 */
Tesela *    Mosaico::last_Tesela     (void)
{
    return skins.back();
}