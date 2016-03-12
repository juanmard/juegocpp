/**
 *  \file     Almacen.h
 *  \brief    Fichero con el código de definición de la clase Almacen.
 *
 *  \author   Juan Manuel Rico
 *  \date     Diciembre 2010
 *  \version  1.00
 *
 */
#ifndef _ALMACEN_H_
#define _ALMACEN_H_

#include <allegro.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>

class AlmacenGUI;

using std::map;
using std::vector;
using std::string;

/**
 * \class   Almacen
 * \brief   Maneja los recursos (gráficos y sonidos) del juego.
 * \details Esta clase nos debe dar acceso a los distintos recursos que necesita el juego.
 *          Los recursos se obtienen de un fichero de tipo DAT generado por Grabber.
 * \todo    Crear métodos "GetSample" y "SetSample" para manejo de sonidos.
 */
class Almacen
{
  public:
                      Almacen       (string paramNombreFichero);
                      Almacen       ();
                      ~Almacen      ();
    BITMAP *          getBitmap     (string nombreBitmap);
    BITMAP *          getBitmap     (int indice);
    RGB *             getPalette    (string nombrePaleta);
    string            getName       (BITMAP *puntero);
    string            getNombre     (int indice) const;
    string            getNombre     () const;
    unsigned int      getSize       () const;
    vector<DIALOG> &  getDIALOG     ();
    void              addGUI        (vector<DIALOG> &dlg_padre);

  private:
    DATAFILE *                fichero;
    string                    nombreFichero;
    map<string, BITMAP *>     bitmaps;
    map<string, RGB *>        paletas;
    map<string, SAMPLE *>     sonidos;
    AlmacenGUI *              gui;
};

#endif // _ALMACEN_H_
