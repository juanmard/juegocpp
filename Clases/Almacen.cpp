///
/// @file Almacen.cpp
/// @brief Fichero con el código de implementación de la clase Almacen.
/// @author Juan Manuel Rico
/// @date Diciembre 2010
/// @version
///      - 1.0.0 Diciembre 2010
///      - 1.0.1 Marzo 2015
///

#include "Almacen.h"
#include "AlmacenGUI.h"

Almacen::Almacen (std::string paramNombreFichero)
{
    // Se intenta cargar el fichero de datos en memoria.
    fichero = load_datafile (paramNombreFichero.c_str ());
    if (fichero) {
        // Se pudo cargar el fichero de datos en memoria. Guardamos el nombre del fichero.
        nombreFichero = paramNombreFichero;

        // Recorremos los datos y emparejamos nombres con punteros de los distintos recursos.
        std::string nombre;
        for (int i=0; fichero[i].type != DAT_END; i++) {
            nombre = get_datafile_property(&fichero[i], DAT_ID('N','A','M','E'));
            switch (fichero[i].type) {
            case DAT_BITMAP:
                bitmaps[nombre] = (BITMAP*) fichero[i].dat;
                // cout << "Bitmap >> " << nombre << "," << bitmaps[nombre] << endl;
                break;

            case DAT_PALETTE:
                paletas[nombre] = (RGB*) fichero[i].dat;
                // cout << "Paleta >> " << nombre << "," << paletas[nombre] << endl;
                break;

            case DAT_SAMPLE:
                sonidos[nombre] = (SAMPLE*) fichero[i].dat;
                // cout << "Sonido >> " << nombre << "," << sonidos[nombre] << endl;
                break;

            default:
                // cout << "DAT desconocido >> " << nombre << "," << fichero[i].dat << endl;
                break;
            }
        }
    } else {
        // No se encontró el fichero. Borramos la cadena del nombre. Avisamos en consola.
        nombreFichero.clear ();
        std::cout << "ERROR: No se pudo acceder al fichero de datos: \"" << paramNombreFichero << "\"" << std::endl \
                  << "Compruebe que se encuentra en el mismo directorio que el juego." << std::endl;
    }

    // Se crea una GUI para esta clase.
    gui = new AlmacenGUI (*this);
};

Almacen::Almacen ():
    nombreFichero (NULL),
    gui (NULL)
{
};

Almacen::~Almacen ()
{
    // Liberar los recursos del fichero.
    // Liberar los recursos 'map'.
};

BITMAP* Almacen::get_bitmap (std::string nombreBitmap)
{
    return bitmaps[nombreBitmap];
};

BITMAP* Almacen::get_bitmap (int indice)
{
    if (fichero[indice].type == DAT_BITMAP) {
        return (BITMAP*) fichero[indice].dat;
    } else {
        std::cout << "Warning: Bitmap no encontrado." << std::endl;
        return NULL;
    }
};

std::string Almacen::get_nombre (int indice) const
{
    return get_datafile_property(&fichero[indice], DAT_ID('N','A','M','E'));
};

RGB* Almacen::get_palette (std::string nombrePaleta)
{
    return paletas[nombrePaleta];
};

std::string Almacen::get_name (BITMAP* puntero)
{
    std::string nombre;
    std::map<std::string, BITMAP*>::iterator it;

    it = bitmaps.begin ();
    while ( (it!=bitmaps.end()) && nombre.empty() ) {
        // Para 'debug' mostramos el proceso de búsqueda.
        // cout << it->first << " => " << it->second << endl;
        if (it->second == puntero) {
            nombre = it->first;
        }
        it++;
    }
    /// Para 'debug' mostramos los valores finales.
    /// cout << "Puntero de bitmap a buscar: " << puntero << endl
    ///      << "Nombre asociado en 'map': " << nombre << endl;
    return nombre;
};

std::vector<DIALOG>& Almacen::get_DIALOG ()
{
    return gui->get_GUI ();
};

unsigned int Almacen::get_size () const
{
    return (bitmaps.size () + paletas.size () + sonidos.size ());
};

std::string Almacen::get_nombre () const
{
    return nombreFichero;
};

void Almacen::add_GUI (std::vector<DIALOG>& gui_padre)
{
    // Se crea una GUI para esta clase.
    gui = new AlmacenGUI (*this, gui_padre);
};
