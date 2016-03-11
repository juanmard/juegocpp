#ifndef TESELA_H
#define TESELA_H

#include <allegro.h>
#include "Mosaico.h"

class Mosaico;

class Tesela
{
public:
                        Tesela      (const Tesela &copia, Mosaico *padre);
                        Tesela      (Mosaico *padre);
                        Tesela      (Mosaico *padre, BITMAP *imagen, int x_tmp=0, int y_tmp=0, bool mirror_tmp=false);
    virtual Tesela *    clone       (Mosaico *padre) const;    
    void                draw        (BITMAP *bmp);
    void                SetDibujo   (BITMAP *imagen);
    void                Set_x       (int x_tmp);
    void                Set_y       (int y_tmp);
    int                 Get_x       (void);
    int                 Get_y       (void);
    void                Guardar     (void);

private:
    Mosaico *mosaico_padre;
    int     x, y;
    BITMAP *dibujo;

    // \todo Igual sería bueno incluir los 360 grados de giro.
    //       En lugar de únicamente la simetría en x.
    bool mirror;

    /* \todo Igual sería conveniente generar una clase con estos bloques.
     *       Y ser estos los que se interseccionan. De esta forma un actor puede estar
     *       compuesto de varios bloques y afinar la intersección.
     *       Se pueden dibujar estos contornos para referencia. Para las teselas
     *       sólo se necesitan las referencias enlazadas.
     *
    typedef struct Bloque
    {
        int x, y;
        int ancho, alto;
    };
     */
};

#endif
