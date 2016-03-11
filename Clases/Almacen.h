/*
 * linux
 * Copyright (C) Juanma Rico 2010 <juanmard@gmail.com>
 */

#ifndef _ALMACEN_H_
#define _ALMACEN_H_

#include <allegro.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <map>

using namespace std;

/**
 * \class   Almacen
 * \brief   Clase que maneja los recursos gráficos y de sonido.
 * \todo   
 *          - Crear métodos "GetSample" y "SetSample" para manejo de sonidos.
 */
class Almacen
{
  public:
                Almacen     (string paramNombreFichero);
                Almacen     ();
                ~Almacen    ();
    BITMAP *    GetBitmap   (string nombreBitmap);
    BITMAP *    GetBitmap   (int indice);
    RGB *       GetPalette  (string nombrePaleta);

  private:
    DATAFILE *                fichero;
    string                    nombreFichero;
    map<string, BITMAP *>     bitmaps;
    map<string, RGB *>        paletas;
    map<string, SAMPLE *>     sonidos;
};

#endif // _ALMACEN_H_
