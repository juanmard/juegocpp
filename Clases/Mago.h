/*
 * linux
 * Copyright (C) Juanma Rico 2010 <juanmard@gmail.com>
 * 
 */

#ifndef _MAGO_H_
#define _MAGO_H_

#include <map>
#include "ControllableActor.h"
#include "Almacen.h"
#include "Sprite.h"

class Mago : public ControllableActor 
{
  public:
    // Definición de acciones del Mago.
    typedef enum {DOWN, UP, LEFT, RIGHT, JUMP, SPELL} action_t;
    typedef enum  {esperando, andando, cayendo, disparando, saltando} Estados_t;

  private:
        typedef enum {
                  esperando_izq, andando_izq, cayendo_izq, disparando_izq, saltando_izq,
                  esperando_der, andando_der, cayendo_der, disparando_der, saltando_der
                  } Sprites_t;

  public:
            Mago        (Almacen &almacen);
    void    do_action   (ControllableActor::action_t act, int magnitude);
    void    update      ();
    void    hit         (Actor *who, int damage);

  private:
    Sprites_t     estado2Sprite     (Estados_t estado) const;

  private:
    map<Sprites_t,Sprite *>     sprites;
    Estados_t                   estado, estado_sig;
    unsigned int                timer;
    int                         gravedad;
    int                         sentido;
};

#endif // _MAGO_H_
