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
#include <vector>

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
    BITMAP *    getBitmap   (string nombreBitmap);
    BITMAP *    getBitmap   (int indice);
    RGB *       getPalette  (string nombrePaleta);
    string      getName     (BITMAP *puntero);

  private:
    DATAFILE *                fichero;
    string                    nombreFichero;
    map<string, BITMAP *>     bitmaps;
    map<string, RGB *>        paletas;
    map<string, SAMPLE *>     sonidos;

  // Prueba AlmacenGUI. Separar cuando funcione en una clase distinta.
  // AlmacenGUI mostrará una lista de recursos (Bitmaps en principio) que se podrán elegir.
  public:
    vector<DIALOG> &  getDIALOG ();
    vector<DIALOG> dlg;
    static  DIALOG dlg_plantilla[];
    static char *  list_getter (int index, int *list_size)
    {
      // NOTA: Para no referirnos a la plantilla estática (ha eliminar) podemos usar la variable
      //       global de Allegro: 'active_dialog' y probar si funciona.
      if (dlg_plantilla[1].dp3)
      {
        // Creamos una referencia temporal al objeto.
        Almacen &obj = *(static_cast<Almacen *>(dlg_plantilla[1].dp3));
        
        // Si 'index' es negativo debe devolver NULL e indicar el tamaño de la lista.
        // Si 'index' es cero o positivo debe devolver la cadena del nombre del actor.
        if (index < 0)
        {
          *list_size = obj.bitmaps.size ();
          return NULL;
        }
        else
        {
          return const_cast<char *>(obj.getName(obj.getBitmap (index)).c_str());
        }
      }
    }

    /**
     * \brief   Callback de la futura clase 'AlmacenGUI'.
     */
    static int callback (int msg, DIALOG *d, int c)
    {
      // Se sitúa el puntero del manager en 'dp3' pues en 'dp' 
      // debe estar el 'getter' de la lista y en 'dp2' el array de la selección.
      if (d[0].dp3)
      {
        // Creamos una referencia temporal al objeto actual.
        Almacen &obj = *(static_cast<Almacen *>(d[0].dp3));

        // Se guarda el índice actual de la lista para comprobar cuando cambia.
        static int indice_ant = d[0].d1;

        // Se procesan los mensajes.
        switch (msg)
        {
          case MSG_IDLE:
              // Si cambia el índice es que debemos actualizar el bitmap
              // y mandarle un mensaje para que se refresque.
              if (d[0].d1 != indice_ant)
              {
                // Limpiamos el fondo antes de volver a dibujar.
                BITMAP *fondo = create_bitmap (d[2].w,d[2].h);
                clear_to_color(fondo, 243);
                d[2].dp = fondo;
                object_message(&d[2], MSG_DRAW, 0);
                d[2].dp = obj.getBitmap (d[0].d1);
                indice_ant = d[0].d1;
                // int i;
                // return dialog_message(&d[0], MSG_DRAW, 0, &i);
                return object_message(&d[2], MSG_DRAW, 0);
                //return broadcast_dialog_message(MSG_DRAW, 0);
              }
              break;
              //return object_message(&d[2], MSG_DRAW, 0);
;

          case MSG_GOTMOUSE:
          case MSG_LOSTMOUSE:
//                objeto.centrarActor (d[0].d1);
//                indice_ant = d[0].d1;
                break;
        }
      }
      return d_list_proc (msg, d, c);
    };


};

#endif // _ALMACEN_H_
