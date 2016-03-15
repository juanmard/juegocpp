#pragma once
#include "Actor.h"
#include "DatFile.h"
#include "Bitmap.h"
#include "Nombres.h"

/**
 * \brief   Ladrillo para ser golpeado por la pelota del juego.
 * \todo    Añadir posibilidad de lanzar objetos al jugador, de desviar la pelota, etc...
 */
class Ladrillo :  public Actor
{
public:
            Ladrillo    (void);
            Ladrillo    (int x, int y);
            ~Ladrillo   (void);
    void    hit         (Actor *who, int damage);

private:
    void        crear_ladrillo (void);

    Bitmap     *chaqueta;
    SAMPLE     *peloteo;
};
