/*
 * linux
 * Copyright (C) Juanma Rico 2010 <juanmard@gmail.com>
 */

#include "Almacen.h"

Almacen::Almacen (string paramNombreFichero)
{
  fichero = load_datafile(paramNombreFichero.c_str ());
  if (!fichero)
  {
    //No se encontró el fichero.
    nombreFichero = "";
  }
  else
  {
    nombreFichero = paramNombreFichero.c_str();
  }
};

Almacen::Almacen ()
{
};

Almacen::~Almacen ()
{
  // Liberar los recursos del fichero.
};

/**
 * \brief   Devuelve un BITMAP como recurso dando el nonbre del recurso. 
 * \todo    Controlar que el recurso solicitado es realmente un BITMAP.
 */
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
    }
    else
    {
      printf ("No se encuentra el recurso %s en el fichero %s", paramNombreRecurso.c_str(), nombreFichero.c_str());
    }
  }
  return (BITMAP *)tmp_bmp;
};

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
    //if (tmpDat->type != DAT_RGB)
    if (tmpDat)
    {
      tmpRGB = (RGB *) tmpDat->dat;
    }
    else
    {
      printf ("No se encuentra el recurso %s en el fichero %s", nombrePaleta.c_str(), nombreFichero.c_str());
    }
  }
  return (RGB *)tmpRGB;
};
