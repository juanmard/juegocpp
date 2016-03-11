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
    cout << "ERROR: No se pudo acceder al fichero de datos: \"" << paramNombreFichero << "\"" << endl \
         << "Compruebe que se encuentra en el mismo directorio que el juego." << endl;
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
              // cout << "Bitmap >> " << nombre << "," << bitmaps[nombre] << endl;
              break;
        case DAT_PALETTE: 
              paletas[nombre] = (RGB *) fichero[i].dat;
              // cout << "Paleta >> " << nombre << "," << paletas[nombre] << endl;
              break;
        case DAT_SAMPLE: 
              sonidos[nombre] = (SAMPLE *) fichero[i].dat;
              // cout << "Sonido >> " << nombre << "," << sonidos[nombre] << endl;
              break;
        default:
              // cout << "DAT desconocido >> " << nombre << "," << fichero[i].dat << endl;
              break;
      }
    }
  }


  // Esto iría en la inicialización de la clase 'AlmacenGUI'.
  dlg_plantilla[1].dp3 = (void *) this;
  dlg_plantilla[2].dp = const_cast<char *>((new string("Almacén: \"" + nombreFichero + "\""))->c_str());
  dlg_plantilla[3].dp = screen;

  dlg.clear ();
  dlg.push_back (dlg_plantilla[0]);
  dlg.push_back (dlg_plantilla[1]);
  dlg.push_back (dlg_plantilla[2]);
  dlg.push_back (dlg_plantilla[3]);
};

/* Prueba GUI Almacen */
DIALOG Almacen::dlg_plantilla[] = 
{
   { d_box_proc,        352, 360, 256, 192, 67, 243,   0,    0,      0,   0,   NULL,                           NULL, NULL },
   { Almacen::callback, 360, 392, 240, 56,  67, 243,   0,    0,      0,   0,   (void*)Almacen::list_getter,    NULL, NULL },
   { d_text_proc,       360, 376, 128, 8,   67, 243,   0,    0,      0,   0,   (void*)"Almacén: ",             NULL, NULL },
   { d_bitmap_proc,     360, 456, 240, 88,  67, 243,   0,    0,      0,   0,   NULL,                           NULL, NULL }
};


/**
 * \brief   Constructor por omisión.
 */
Almacen::Almacen ()
{
};

/**
 * \brief   Destructor por omisión.
 * \todo    Liberar los recursos correctamente.
 */
Almacen::~Almacen ()
{
  // Liberar los recursos del fichero.
  // Liberar los recursos 'map'.
};

/**
 * \brief   Devuelve un BITMAP como recurso dando el nonbre del bitmap.
 * \details Este procedimiento se simplifica gracias a la carga previa en la clase 'map'.
 */
BITMAP *  Almacen::getBitmap (string nombreBitmap)
{
  return bitmaps[nombreBitmap];
}

/**
 * \brief   Devuelve un BITMAP como recurso dando el número identificativo indicado 
 *          en el fichero de cabecera generado por Grabber.
 * \todo    Controlar que el recurso solicitado es realmente un BITMAP.
 * \warning Procedimiento obsoleto. Se mantiene por compatibilidad. No utilizar en el futuro.
 */
BITMAP * Almacen::getBitmap(int indice)
{
  return (BITMAP *) fichero[indice].dat;
}

/**
 * \brief   Devuelve un puntero a un array de 256 estructuras RGB (Paleta).
 * \details Este procedimiento se simplifica gracias a la carga previa en la clase 'map'.
 */
RGB *  Almacen::getPalette (string nombrePaleta)
{
  return paletas[nombrePaleta];
}

/**
 * \brief   Devuelve el nombre asociado al puntero en 'bitmaps'.
 * \details Recorre todo el 'map' y compara los punteros hasta encontrar el dado por parámetro.
 *          Procedimiento lento. Se utiliza para guardar el bitmap como cadena, que sólo se usa
 *          en casos puntuales del juego.
 */
string  Almacen::getName (BITMAP *puntero)
{
  string nombre;
  map<string,BITMAP *>::iterator  it;

  it = bitmaps.begin ();
  while ( (it!=bitmaps.end()) && nombre.empty() )
  {
    // Para 'debug' mostramos el proceso de búsqueda.
    // cout << it->first << " => " << it->second << endl;
    if (it->second == puntero)
    {
      nombre = it->first;
    }
    it++;
  }
  // Para 'debug' mostramos los valores finales.
  // cout << "Puntero de bitmap a buscar: " << puntero << endl \
  //      << "Nombre asociado en 'map': " << nombre << endl;
  return nombre;
}

/**
 * \brief   Pasa de un dialog estático a otro dinámico.
 */
vector<DIALOG> &  Almacen::getDIALOG ()
{
  return dlg;
}