/*
 * linux
 * Copyright (C) Juanma Rico 2010 <juanmard@gmail.com>
 */
#include "Almacen.h"

/**
 * \brief   Constructor del almacén dando el nombre del fichero de datos a cargar.
 */
Almacen::Almacen (string paramNombreFichero)
{
  // Se intenta cargar el fichero de datos en memoria.
  fichero = load_datafile (paramNombreFichero.c_str ());
  if (!fichero)
  {
    // No se encontró el fichero. Borramos la cadena del nombre. Avisamos en consola.
    nombreFichero.clear ();
    cout << "No se pudo acceder al fichero de datos: " << paramNombreFichero << endl;
  }
  else
  {
    // Se pudo cargar el fichero de datos en memoria. Guardamos el nombre del fichero.
    nombreFichero = paramNombreFichero;

    // Recorremos los datos y emparejamos nombres con punteros de los distintos recursos.
    string nombre;
    for (int i=0; fichero[i].type != DAT_END; i++)
    {
      nombre = get_datafile_property(&fichero[i], DAT_ID('N','A','M','E'));
      switch (fichero[i].type)
      {
        case DAT_BITMAP: 
              bitmaps[nombre] = (BITMAP *) fichero[i].dat;
              cout << "Bitmap >> " << nombre << "," << bitmaps[nombre] << endl;
              break;
        case DAT_PALETTE: 
              paletas[nombre] = (RGB *) fichero[i].dat;
              cout << "Paleta >> " << nombre << "," << paletas[nombre] << endl;
              break;
        case DAT_SAMPLE: 
              sonidos[nombre] = (SAMPLE *) fichero[i].dat;
              cout << "Sonido >> " << nombre << "," << sonidos[nombre] << endl;
              break;
        default:
              cout << "DAT desconocido >> " << nombre << "," << fichero[i].dat << endl;
              break;
      }
    }
  }
};

/**
 * \brief   Constructor por omisión.
 */
Almacen::Almacen ()
{
};

/**
 * \brief   Destructor por omisión.
 */
Almacen::~Almacen ()
{
  // Liberar los recursos del fichero.
};

/**
 * \brief   Devuelve un BITMAP como recurso dando el nonbre del recurso. 
 * \todo    Controlar que el recurso solicitado es realmente un BITMAP.
 */
/* Forma alternativa para localizar un bitmap por el nombre.
   Se puede recorrer una sola vez y guardar nombres y punteros en un std::map
   para acceder más rápidamente.

   for (i=0; dat[i].type != DAT_END; i++) {
      if (stricmp(get_datafile_property(dat+i, DAT_ID('N','A','M','E')),
                  "mi_objeto") == 0) {
         // se encontró el objeto en el índice i
      }
   }
   // no encontrado...
*/

/**
 * \brief   Devuelve un BITMAP como recurso dando el nonbre del recurso.
 * \details Este procedimiento se simplifica gracias a la carga previa en la clase 'map'.
 */
BITMAP *  Almacen::GetBitmap (string nombreBitmap)
{
  return bitmaps[nombreBitmap];
}

/*
BITMAP * Almacen::GetBitmap (string paramNombreRecurso)
{
  DATAFILE *  tmp_dat;
  BITMAP *    tmp_bmp = NULL;

  // Se comprueba si el fichero existe.
  if (fichero)
  {
    // Se obtiene el objeto del fichero.
    tmp_dat = load_datafile_object (nombreFichero.c_str(), paramNombreRecurso.c_str() );

    // Se comprueba que realmente es de tipo BITMAP.
    // \todo Comprobar por qué no funciona esta comparación.
    //if (tmp_dat->type != DAT_BITMAP)
    if (tmp_dat)
    {
      tmp_bmp = (BITMAP *) tmp_dat->dat;
      // Prueba para obtener el nombre.
      std::cout << "Bitmap: " << get_datafile_property(tmp_dat, DAT_ID('N','A','M','E')) << std::endl;
    }
    else
    {
      printf ("No se encuentra el recurso %s en el fichero %s", paramNombreRecurso.c_str(), nombreFichero.c_str());
    }
  }
  return (BITMAP *)tmp_bmp;
};

*/

/**
 * \brief   Devuelve un BITMAP como recurso dando el número identificativo indicado 
 *          en el fichero de cabecera generado por Grabber.
 * \todo    Controlar que el recurso solicitado es realmente un BITMAP.
 */
BITMAP * Almacen::GetBitmap(int indice)
{
  return (BITMAP *) fichero[indice].dat;
}

/**
 * \brief   Devuelve una paleta de colores dando el nonbre de la paleta. 
 * \todo    Controlar que el recurso solicitado es realmente una PALETA.
 */
/**
 * \brief   Devuelve un puntero a un array de 256 estructuras RGB (Paleta).
 * \details Este procedimiento se simplifica gracias a la carga previa en la clase 'map'.
 */
RGB *  Almacen::GetPalette (string nombrePaleta)
{
  return paletas[nombrePaleta];
}
/*
RGB * Almacen::GetPalette (string nombrePaleta)
{
  DATAFILE *  tmpDat;
  RGB *       tmpRGB = NULL;

  // Se comprueba si el fichero existe y ha sido abierto.
  if (fichero)
  {
    // Se obtiene el objeto del fichero.
    tmpDat = load_datafile_object (nombreFichero.c_str(), nombrePaleta.c_str());

    // Se comprueba que realmente es de tipo RGB.
    // TODO: Comprobar por qué no funciona esta comparación.
    //if (tmpDat->type != DAT_PALETTE)
    if (tmpDat)
    {
      tmpRGB = (RGB *) tmpDat->dat;
      // Prueba para obtener el nombre de la paleta.
      std::cout << "Paleta: " << get_datafile_property(tmpDat, DAT_ID('N','A','M','E')) << std::endl;
    }
    else
    {
      printf ("No se encuentra el recurso %s en el fichero %s", nombrePaleta.c_str(), nombreFichero.c_str());
    }
  }
  return (RGB *)tmpRGB;
};
*/
