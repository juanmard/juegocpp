/**
 *  \file     Almacen.cpp
 *  \brief    Fichero con el código de implementación de la clase Almacen.
 *
 *  \author   Juan Manuel Rico
 *  \date     Diciembre 2010
 *  \version  1.00
 *
 */
#include "Almacen.h"
#include "AlmacenGUI.h"

/**
 * \brief   Construye el almacén dando el nombre del fichero DAT a cargar.
 * \details Intenta leer el fichero, si consigue abrirlo genera tablas de los distintos tipos de
 *          recursos y sus nombres dados en el fichero.
 *          Si no consigue abrirlo, envía un mensaje de error por consola.
 *          Se crea también una GUI para poder mostrar todos los recursos.
 *
 * \param   paramNombreFichero  Cadena con el nombre del fichero de tipo DAT.
 *
 * \todo    Por hacer:
 *          - Cuando se produzca el error en la lectura del fichero lazar una excepción para ser capturada.
 *          - Eliminar la creación de la GUI en el constructor. Ponerla en un método aparte.
 */
Almacen::Almacen (string paramNombreFichero)
{
  // Se intenta cargar el fichero de datos en memoria.
  fichero = load_datafile (paramNombreFichero.c_str ());
  if (fichero)
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
  else
  {
    // No se encontró el fichero. Borramos la cadena del nombre. Avisamos en consola.
    nombreFichero.clear ();
    cout << "ERROR: No se pudo acceder al fichero de datos: \"" << paramNombreFichero << "\"" << endl \
         << "Compruebe que se encuentra en el mismo directorio que el juego." << endl;
  }

  // Se crea una GUI para esta clase.
  gui = new AlmacenGUI (*this);
};

/**
 * \brief   Constructor por omisión.
 * \details Crea un almacén vacío y sin GUI.
 */
Almacen::Almacen ():
nombreFichero (NULL),
gui (NULL)
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
 * \brief   Devuelve un 'BITMAP allegro' como recurso dando el nombre del bitmap.
 * \details Este método se simplifica gracias a la carga previa en la clase 'map'. Se usa como índice
 *          de la tabla 'map' el nombre obtenido del fichero DAT.
 * \param   nombreBitmap  Nombre identificativo del bitmap.
 * \return  Puntero a la zona de memoria donde se encuentra guardado el BITMAP. 
 */
BITMAP *  Almacen::getBitmap (string nombreBitmap)
{
  return bitmaps[nombreBitmap];
};

/**
 * \brief   Devuelve un 'BITMAP allegro' como recurso dando el índice.
 * \details Este índice es el número identificativo indicado en el fichero
 *          '.H' generado por Grabber.
 * \param   indice  Índice del recurso que se busca.
 * \return  Puntero a la zona de memoria donde se encuentra guardado el BITMAP.
 *          Si el tipo de recurso apuntado por el índice no es un BITMAP devuelve NULL.
 *
 * \todo    Comprobar que el índice se encuentra dentro del máximo de recursos.
 */
BITMAP *  Almacen::getBitmap (int indice)
{
  if (fichero[indice].type == DAT_BITMAP)
  {
    return (BITMAP *) fichero[indice].dat;
  }
  else
  {
    return NULL;
  }
};

/**
 * \brief   Devuelve el nombre de un recurso según el índice en el fichero.
 * \details El nombre que se devuelve es el que se encuentra asociado al índice en el fichero DAT.
 * \param   indice  Índice del recurso del que obtener el nombre.
 * \return  Cadena con el nombre del recurso, según el obtenido del fichero DAT.
 */
string  Almacen::getNombre (int indice) const
{
  return get_datafile_property(&fichero[indice], DAT_ID('N','A','M','E'));
};

 /**
 * \brief   Devuelve un puntero a un array de 256 estructuras RGB (Paleta de colores).
 * \details Este procedimiento se simplifica gracias a la carga previa en la clase 'map'. Se usa como
 *          índice el nombre de la paleta en el fichero DAT.
 * \param   nombrePaleta  Cadena con el nombre de la paleta que queremos obtener.
 * \return  Puntero a la zona de memoria de las 256 estructuras RGB que conforman la paleta de colores.
 */
RGB *  Almacen::getPalette (string nombrePaleta)
{
  return paletas[nombrePaleta];
};

/**
 * \brief   Devuelve el nombre asociado al puntero en 'bitmaps'.
 * \details Recorre todo el 'map' y compara los punteros hasta encontrar el dado por parámetro.
 *          Procedimiento lento. Se utiliza para guardar el BITMAP como cadena, que sólo se usará
 *          en casos puntuales del juego.
 * \param   puntero   Puntero del bitmap del que queremos obtener su nombre.
 * \return  Cadena nueva de caracteres con el nombre asociado al puntero. Si no encuentra la
 *          asociación con el puntero devolverá una cadena vacía.
 * \todo    Por hacer:
 *          - En lugar de pasar como parámetro el puntero pasar una referencia constante al puntero
 *            y así evitar modificaciones accidentales del mismo.
 *          - Confirmar que se devuelve una cadena vacía si no se encuentra asociación con el puntero.
 *          - Usar una constante DEBUG para el precompilador en lugar de comentarlas.
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
};

/**
 * \brief   Pasa de un dialog estático a otro dinámico.
 * \todo    Confirmar que este método es usado y es necesario.
 */
vector<DIALOG> &  Almacen::getDIALOG ()
{
  return gui->getGUI ();
};

/**
 * \brief   Obtiene el número total de recursos en el almacén.
 * \details Se obtienen los recursos guardados desde el fichero DAT al crear el almacén.
 *          Pueden existir recursos de distinto tipo a los guardados en el fichero y estos no se
 *          contarán.
 * \return  El número de recursos que se encuentran en el almacén.
 *
 * \todo    Añadir una variable en la clase que nos diga el número de recursos en el fichero que
 *          existen, pero que no se pudieron clasificar.
 */
unsigned int  Almacen::getSize () const
{
  return (bitmaps.size () + paletas.size () + sonidos.size ());
};

/**
 * \brief   Obtiene el nombre del fichero desde donde se han cargado los recursos del almacén.
 * \return  Nombre del fichero DAT desde donde se obtuvieron los recursos.
 */
string  Almacen::getNombre () const
{
  return nombreFichero;
};

/**
 * \brief   Añade la GUI de la clase a la GUI padre.
 * \details Crea una GUI para esta clase y la añade a la GUI padre pasada como parámetro.
 * \param   gui_padre   Referencia a un conjunto de estructuras 'DIALOG allegro' donde
 *                      incluir la nueva GUI asociada a la clase.
 */
void  Almacen::addGUI (vector<DIALOG> &gui_padre)
{
  // Se crea una GUI para esta clase.
  gui = new AlmacenGUI (*this, gui_padre);
};
