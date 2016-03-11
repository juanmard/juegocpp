#pragma once
#include "Actor.h"
#include "DatFile.h"
#include "Bitmap.h"
#include "Nombres.h"

/**
 * \brief   Actor para ser golpeado por la pelota del juego.
 * \todo    Añadir posibilidad de lanzar objetos al jugador, de desviar la pelota, etc...
 */
class Ladrillo :  public Actor
{
public:
                        Ladrillo    (const Ladrillo &copia);
                        Ladrillo    (void);
                        Ladrillo    (int x, int y);
                        ~Ladrillo   ();
    void                hit         (Actor *who, int damage);
    void                update      ();
    virtual Ladrillo *  clone       () const;
    
private:
    /**
     * \brief Definición de los distintos estados del ladrillo.
     *        Reservamos los diez primeros estados para estados generales de la clase "Actor"
     */
    //typedef 
    enum {ESPERA=10, EN_CAIDA}; 
    // estado_t;

    void        crear_ladrillo (void);

    Bitmap     *chaqueta;
    SAMPLE     *peloteo;
};
