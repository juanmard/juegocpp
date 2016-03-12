/*
 * linux
 * Copyright (C) Juanma Rico 2010 <juanmard@gmail.com>
 * 
 */

#ifndef _LORO_H_
#define _LORO_H_

#include "ControllableActor.h"
#include "Almacen.h"

class Loro : public ControllableActor 
{
public:
    // Definición de acciones del loro.
    typedef enum {DOWN, UP, LEFT, RIGHT, JUMP} action_t;

public:
    /// Constructor básico.
    ///
    Loro ();

    Loro          (Almacen &almacen);
    void      do_action     (ControllableActor::action_t act, int magnitude);
    void      getNombre     (string &strNombre) const;

  protected:

  private:

};

#endif // _LORO_H_
