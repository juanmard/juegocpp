///
/// @file Almacen.h
/// @brief Fichero con el código de declaración de la clase Almacen.
/// @author Juan Manuel Rico
/// @date Diciembre 2010
/// @version
///         - 1.0.0 Diciembre 2010
///         - 1.0.1 Marzo 2015
///

#ifndef _ALMACEN_H_
#define _ALMACEN_H_

#include <allegro.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>

/// @note Esta clase se usa para editar o visualizar los recursos del almacén.
///       Lo ideal es que heredara de "EditableObject" y entregara un "Formulario".
class AlmacenGUI;

/// @class Almacen
/// Maneja los recursos (gráficos y sonidos) del juego.
///
/// Esta clase nos debe dar acceso a los distintos recursos que necesita el juego.
/// Los recursos se obtienen de un fichero de tipo DAT generado por Grabber.
/// @todo Crear métodos "GetSample" y "SetSample" para manejo de sonidos.
///
class Almacen
{
public:
    /// Construye el almacén dando el nombre del fichero DAT a cargar.
    ///
    /// Intenta leer el fichero. Si consigue abrirlo genera tablas de los distintos tipos de
    ///         recursos y sus nombres dados en el fichero.
    ///         Si no consigue abrirlo, envía un mensaje de error por consola.
    ///         Se crea también una GUI para poder mostrar todos los recursos.
    /// @param paramNombreFichero Cadena con el nombre del fichero de tipo DAT.
    /// @todo Por hacer:
    ///        - Cuando se produzca el error en la lectura del fichero lazar una excepción para ser capturada.
    ///        - Eliminar la creación de la GUI en el constructor. Ponerla en un método aparte.
    ///
    Almacen (std::string paramNombreFichero);

    /// Constructor por omisión. Crea un almacén vacío y sin GUI.
    ///
    Almacen ();

    /// Destructor por omisión.
    /// @todo Liberar los recursos correctamente.
    ///
    ~Almacen ();

    /// Devuelve un 'BITMAP allegro' como recurso dando el nombre del bitmap.
    ///
    /// Este método se simplifica gracias a la carga previa en la clase 'map'. Se usa como índice
    /// de la tabla 'map' el nombre obtenido del fichero DAT.
    /// @param nombreBitmap Nombre identificativo del bitmap dentro del fichero.
    /// @return  Puntero a la zona de memoria donde se encuentra guardado el BITMAP. 
    ///
    BITMAP* getBitmap (std::string nombreBitmap);

    /// Devuelve un 'BITMAP allegro' como recurso dando el índice.
    /// Este índice es el número identificativo indicado en el fichero
    /// ".H" generado por Grabber.
    /// @param indice Índice del recurso que se busca.
    /// @return Puntero a la zona de memoria donde se encuentra guardado el BITMAP.
    ///         Si el tipo de recurso apuntado por el índice no es un BITMAP devuelve NULL.
    /// @todo Comprobar que el índice se encuentra dentro del máximo de recursos.
    ///
    BITMAP* getBitmap (int indice);

    /// Devuelve un puntero a un array de 256 estructuras RGB (Paleta de colores).
    ///
    /// Este procedimiento se simplifica gracias a la carga previa en la clase 'map'. Se usa como
    /// índice el nombre de la paleta en el fichero DAT.
    /// @param nombrePaleta Cadena con el nombre de la paleta que queremos obtener.
    /// @return Puntero a la zona de memoria de las 256 estructuras RGB que conforman la paleta de colores.
    ///
    RGB* getPalette (std::string nombrePaleta);

    /// Devuelve el nombre asociado al puntero en 'bitmaps'.
    ///
    /// Recorre todo el 'map' y compara los punteros hasta encontrar el dado por parámetro.
    /// Procedimiento lento. Se utiliza para guardar el BITMAP como cadena, que sólo se usará
    /// en casos puntuales del juego.
    /// @param puntero Puntero del bitmap del que queremos obtener su nombre.
    /// @return Cadena nueva de caracteres con el nombre asociado al puntero. Si no encuentra la
    ///         asociación con el puntero devolverá una cadena vacía.
    /// @todo Por hacer:
    ///     - En lugar de pasar como parámetro el puntero pasar una referencia constante al puntero
    ///       y así evitar modificaciones accidentales del mismo.
    ///     - Confirmar que se devuelve una cadena vacía si no se encuentra asociación con el puntero.
    ///     - Usar una constante DEBUG para el precompilador en lugar de comentarlas.
    ///
    std::string getName (BITMAP* puntero);

    /// Devuelve el nombre de un recurso según el índice en el fichero.
    ///
    /// El nombre que se devuelve es el que se encuentra asociado al índice en el fichero DAT.
    /// @param indice Índice del recurso del que obtener el nombre.
    /// @return Cadena con el nombre del recurso, según el obtenido del fichero DAT.
    ///
    std::string getNombre (int indice) const;

    /// Obtiene el nombre del fichero desde donde se han cargado los recursos del almacén.
    /// @return  Nombre del fichero DAT desde donde se obtuvieron los recursos.
    ///
    std::string getNombre () const;

    /// Obtiene el número total de recursos en el almacén.
    ///
    /// Se obtienen los recursos guardados desde el fichero DAT al crear el almacén.
    /// Pueden existir recursos de distinto tipo a los guardados en el fichero y estos no se
    /// contarán.
    /// @return El número de recursos que se encuentran en el almacén.
    /// @todo Añadir una variable en la clase que nos diga el número de recursos en el fichero que
    ///       existen, pero que no se pudieron clasificar.
    ///
    unsigned int getSize () const;

    /// Pasa de un dialog estático a otro dinámico.
    /// @return Referencia a un conjunto de diálogos.
    /// @todo Confirmar que este método es usado y es necesario.
    ///
    std::vector<DIALOG>& getDIALOG ();

    /// Añade la GUI de la clase a la GUI padre.
    ///
    /// Crea una GUI para esta clase y la añade a la GUI padre pasada como parámetro.
    /// @param dlg_padre Referencia a un conjunto de estructuras 'DIALOG allegro' donde
    ///                  incluir la nueva GUI asociada a la clase.
    ///
    void addGUI (std::vector<DIALOG>& dlg_padre);

private:
    DATAFILE* fichero;                      ///< Puntero de referencia al fichero abierto DAT.
    std::string nombreFichero;              ///< Nombre del fichero.
    std::map<std::string, BITMAP*> bitmaps; ///< Lista mapeada de referencias a BITMAP cargados.
    std::map<std::string, RGB*> paletas;    ///< Lista mapeada de referencias a paletas cargadas.
    std::map<std::string, SAMPLE*> sonidos; ///< Lista mapeada de referencias a sonidos cargadas.
    AlmacenGUI* gui;                        ///< Puntero de referencia a la GUI de almacén.
};

#endif //_ALMACEN_H_
