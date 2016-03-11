#ifndef SUELO_H
#define SUELO_H

#include <allegro.h>
#include "Mosaico.h"

class Suelo : public Mosaico
{
public:
        Suelo (Actor *aowner, int size);

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