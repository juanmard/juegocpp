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
    BITMAP *    GetBitmap   (string paramNombreRecurso);
    BITMAP *    GetBitmap   (int indice);
    RGB *       GetPalette  (string nombrePaleta);

  protected:
    /**
     * \brief   Función que se llama automáticamente al cargar un fichero de datos.
     * \details La función se encarga de emparejar los nombres de los bitmaps con
     *          el puntero a los datos.
     */
    static void callback (DATAFILE *datFile)
    {
      static map<string, DATAFILE *>   bitmaps;
      string nombre = get_datafile_property(datFile, DAT_ID('N','A','M','E'));

      bitmaps[nombre] = (DATAFILE *) datFile->dat;
      // Otras posibilidades de añaidr el elemento...
      //bitmaps.insert (pair<string,DATAFILE *>(nombre,(DATAFILE *) datFile->dat));
      //bitmaps.insert (make_pair(nombre,(DATAFILE *) datFile->dat));
      //bitmaps.insert (map<string,DATAFILE *>::value_type(nombre,(DATAFILE *) datFile->dat));
      cout << "DataFile >> " << nombre << "," << bitmaps[nombre] << endl;
    }

  private:
    DATAFILE *                fichero;
    string                    nombreFichero;
    map<string, DATAFILE *>   bitmaps;
};

#endif // _ALMACEN_H_
