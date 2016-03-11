/*
 * linux
 * Copyright (C) Juanma Rico 2010 <juanmard@gmail.com>
 * 
 */

#ifndef _BLOQUE_H_
#define _BLOQUE_H_

/**
 * \brief   Clase que se encarga de modelar un bloque genérico, representado por una posición,
 *          una anchra y una altura.
 */
class Bloque
{
  public:
            Bloque      ();
            Bloque      (int x, int y, int w, int h);
            ~Bloque     ();
    void    setXY       (int x, int y);
    void    setWH       (int w, int h);
    int     getX        () const;
    int     getY        () const;
    int     getW        () const;
    int     getH        () const;
    void    setY        (int y);
    void    centrar     (const Bloque &bloque);

  private:
    int   x, y;
    int   w, h;
};

#endif
