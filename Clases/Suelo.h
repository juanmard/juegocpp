#ifndef SUELO_H
#define SUELO_H

#include "Mosaico.h"
#include <allegro.h>

class Actor;

/** 
 * \brief   Gráfico de suelo modificable en tamaño para actores.
 * \details Esta clase modela un suelo gráfico modificable en tamaño y basado en mosaicos.
 */
class Suelo : public Mosaico
{
public:
                        Suelo   (const Suelo &copia, Actor *propietario);
                        Suelo   (Actor *aowner, int size);
        virtual Suelo * clone   (Actor *propietario) const;
        /**
         * Procedimientos para controlar el tamaño.
         */
        void    Set_size   (int size);
        int     Get_size   (void);

private:
        int    size;
        BITMAP *suelo_1;
        BITMAP *suelo_2;
};

#endif
