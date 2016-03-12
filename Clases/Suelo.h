///
/// @file Suelo.h
/// @brief Fichero cabecera de la clase "Suelo".
/// @author Juan Manuel Rico
/// @date Enero 2009
/// @version 1.0.0
///

#ifndef _SUELO_H_
#define _SUELO_H_

#include "Mosaico.h"
#include <allegro.h>
#include "Almacen.h"
#include <string>

class Actor;

/// Gráfico de suelo modificable en tamaño para actores.
///
/// Esta clase modela un suelo gráfico modificable en tamaño y basado en mosaicos.
/// @todo Independizar los gráficos de su propietario (Actor) puesto que esto hace que
///       no se puedan usar con otros tipos de objetos.
///
class Suelo : public Mosaico
{
public:
    /// Constructor básico y mínimo.
    ///
    Suelo ();

    /// Constructor de copia.
    /// @param copia Objeto suelo a copiar.
    /// @param propietario Actor propietario del suelo a crear.
    ///
    Suelo (const Suelo& copia, Actor* propietario);

    /// Constructor básico para la clase.
    /// @param aowner Actor propietario del suelo que se va a construir.
    /// @param size Tamaño del suelo creado.
    /// @todo Dejar de cargar continuamente el fichero de "sprites".
    ///       Incluir quizás en los parámetros de creación del actor.
    ///       O crear una clase que sea "Vestuario" común a todos los
    ///       actores de la escena desde el Juego principal (o quizás
    ///       desde el "ActorManager").
    Suelo (Actor* aowner, int size);

    /// Constructor de prueba con almacén.
    /// @param aowner Actor propietario del gráfico cuando sea creado.
    /// @param almacen Referencia al almacén de gráficos.
    /// @param size Tamaño del suelo a crear.
    ///
    Suelo (Actor* aowner, Almacen& almacen, int size);

    /// Clona el suelo.
    /// @param propietario Actor al que se le asignará la copia.
    /// @return Puntero de referencia a la copia realizada.
    ///
    Suelo* clone (Actor* propietario) const;

    /// Modifica el tamaño actual del suelo.
    ///
    /// El tamaño del suelo se mide por la cantidad de bloques que tiene,
    /// no se incluyen los terminales del suelo.
    /// @todo Insertar y borrar las teselas del suelo por detrás de los dos 
    ///       suelos terminales y así mantener la coherencia del mosaico guardado
    ///       y el mostrado en pantalla.
    ///
    void setSize (int size);

    /// Obtiene el tamaño actual del suelo.
    /// @return Tamaño del suelo
    /// @todo Hacer este parámetro "unsigned int" puesto que el
    ///       tamaño no puede ser negativo.
    ///
    int getSize (void) const;

    /// Devuelve la estructura básica del objeto en una cadena.
    /// @return Cadena con los valores del suelo.
    ///
    std::string getString () const;

    /// Ajusta el tamaño del actor propietario en función del tamaño del suelo.
    /// @note Si en el momento de la llamada aún no tiene asignado un propietario
    ///       no se hace nada.
    void ajustar ();

private:
    /// Lee las propiedades del suelo desde un fichero de lectura.
    /// @param Referencia al fichero de lectura.
    /// @return Referencia fichero para poder encadenar lecturas.
    ///
    std::ifstream& leer (std::ifstream& ifs);

    /// Inicializa el suelo con las propiedades mínimas
    /// @note Se presupone que el mosaico está vacío y que el tamaño del suelo es cero.
    ///       Si no fuera así habría que ponerlo.
    ///       Se utiliza una carga del fichero de datos... lo apropiado sería utilizar
    ///       Los gráficos dados por un almacén de gráficos.
    ///
    void inicializar ();

private:
    int size;           ///< Tamaño del suelo.
    /// @todo Cambiar estos por un tipo "Bitmap" fijo, independizando de Allegro.
    BITMAP* terminal;    ///< Gráfico del suelo 1 (terminales).
    BITMAP* bloque;      ///< Gráfico del suelo 2 (bloques de repetición).
};

#endif
