/*
 * linux
 * Copyright (C) Juanma Rico 2010 <juanmard@gmail.com>
 * 
 */

#ifndef _BEN_H_
#define _BEN_H_

#include <map>
#include "ControllableActor.h"
#include "Almacen.h"
#include "Sprite.h"

/**
 * \brief   Clase que modela el actor controlable de Ben.
 */
class Ben : public ControllableActor 
{
  public:
    // Definición de acciones de Ben.
    typedef enum {DOWN, UP, LEFT, RIGHT, JUMP, SPELL} action_t;
    typedef enum {esperando, andando, girando, cayendo, disparando, saltando, bajando} Estados_t;

  private:
        typedef enum {
                  esperando_izq, andando_izq, girando_izq, cayendo_izq, disparando_izq, saltando_izq, bajando_izq,
                  esperando_der, andando_der, girando_der, cayendo_der, disparando_der, saltando_der, bajando_der
                  } Sprites_t;

public:
    /// Constructor básico de la clase.
    ///
    Ben ();

              Ben         (Almacen &almacen);
    void      do_action   (ControllableActor::action_t act, int magnitude);
    void      update      ();
    void      hit         (Actor *who, int damage);
    void      getEstado   (string &strEstado) const;
    void      getNombre   (string &strNombre) const;
    string    getNombre   () const;
    ostream&  operator<<  (ostream *sb);

  private:
    Sprites_t     estado2Sprite     (Estados_t estado) const;

  private:
    map<Sprites_t,Sprite *>     sprites;
    Estados_t                   estado, estado_ant, estado_sig;
    unsigned int                timer;
    int                         gravedad;
    int                         sentido;

  // Insertor de flujo para la clase.
  friend ostream&  operator<< (ostream &os, Ben &ben);
};

#endif // _BEN_H_
