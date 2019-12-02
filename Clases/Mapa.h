///
/// @file Mapa.h
/// @brief Fichero de definición de la clase "Mapa".
/// @author Juan Manuel Rico
/// @date Noviembre 2015
/// @version
///      - 1.0.0 Noviembre 2015.
///

#ifndef _MAPA_H_
#define _MAPA_H_

#include <string>
#include "PrintableObject.h"
#include "DatFile.h"

namespace fgm {
    
class Actor;
class ActorManager;

/// Clase que define la disposición de actores dentro del escenario.
///
/// Su responsabilidad es obtener y entregar una foto o captura de la disposición
/// y propiedades de todos los actores y propiedades del juego para, de esta forma,
/// poder retomar el juego en cualquier instante. También se encarga de establecer
/// el momento inicial del juego.
/// Para ello se necesita:
///         - Grabar los distintos actores de la escena en cualquier momento
///           del juego o de su edición.
///         - Recuperar los actores y sus propiedades y ponerlos en escena.
///
class Mapa : public PrintableObject
{
private:
    std::string nombre;     ///< Nombre identificativo del mapa.
    DatFile* fichero;       ///< Fichero de datos para el mapa.

public:
    /// Constructor.
    ///
    Mapa ();

    /// Constructor.
    /// @param ficheroDatos  Referencia al fichero de datos.
    ///
    Mapa (DatFile& ficheroDatos);

    /// Destructor.
    ///
    ~Mapa ();

    /// Carga únicamente la lista de actores controlables (modo de prueba).
    ///
    /// Carga de un fichero de texto la lista de actores y los agrega a la lista de actores
    /// controlables de un controlador de actores específico.
    /// @param file  Fichero de texto con los actores.
    /// @param manager  Control de actores donde incluir lo leído.
    /// @todo Hacer una clase que sea ReadeableObject a modo de PrintableObject que pueda incluir
    ///       todo este proceso.
    /// @warning Este procedimiento es a modo de prueba, para eliminarlo del controlador de actores,
    ///          de esta forma el control de actores delega en esta clase.
    ///
    void load (std::string& file, ActorManager& manager);

    /// Lee los actores del mapa.
    ///
    /// Lee los actores del mapa y los incluye en una lista de actores a controlar.
    /// @param manager  Referencia al controlador de actores donde incluir los actores leídos.
    /// @warning Para poder hacer constante el método es necesario hacer constantes ciertos métodos
    ///          de la clase ActorManager, como 'next', 'rewind', etc.
    ///
    void read (const ActorManager& manager); //const;

    /// Graba los actores del mapa.
    ///
    /// Lee la lista de actores y los graba en el mapa.
    /// @param manager  Referencia al controlador de actores donde incluir los actores leídos.
    /// @note No solo debe leer la lista de actores a controlar, debe leer y guardar las tres listas
    ///       del controlador: la de actores a controlar, la de actores a crear y la de actores a borrar.
    ///
    void save (const ActorManager& manager);

    /// Obtiene todo el mapa en una única cadena de caracteres.
    /// @return Cadena de caracteres generada.
    ///
    std::string& print() const;

private:
    /// Busca una palabra en un canal abierto de fichero.
    /// @param palabra  Palabra a buscar dentro del canal.
    /// @param canal  Canal de fichero donde buscar la palabra.
    /// @return Número de caracteres leídos en el canal antes de encontrar la palabra.
    ///         Si no encuentra devuelve 'std::string::npos'.
    /// @todo Crear una clase de fichero heredada de 'ifstream' donde incluir este procedimiento
    ///       de esta forma se evitaría enviar el 'ifstream' por parámetro.
    ///
    std::size_t buscar (const std::string& palabra, std::ifstream& canal) const;

    /// Busca una propiedad en un canal abierto de fichero.
    /// @note Se define la propiedad como una palabra que se encuentra entre paréntesis cuadrados ([ y ]).
    /// @param propiedad  Propiedad a buscar dentro del canal.
    /// @param canal  Canal de fichero donde buscar la propiedad.
    /// @return Número de caracteres leídos en el canal antes de encontrar la propiedad.
    ///         Si no encuentra devuelve 'std::string::npos'.
    /// @todo Crear una clase de fichero heredada de 'ifstream' donde incluir este procedimiento
    ///       de esta forma se evitaría enviar el 'ifstream' por parámetro.
    ///
    std::size_t buscar_propiedad (const std::string& propiedad, std::ifstream& canal) const;

    /// Crea un actor de una clase dada.
    ///
    /// Para crear actores mediante, por ejemplo, la lectura de un fichero se necesita identificar
    /// la clase final (la "hoja" en el árbol de herencia) de dicho actor, de esta forma se obtendrán
    /// propiedades y procedimientos propios únicamente de dicha clase.
    /// @param clase Referencia constante al nombre de la clase actor que se desea crear.
    /// @return Referencia al nuevo actor creado.
    /// @note No es que me guste esta forma... pero no se me ocurre otra de resolver el problema.
    ///
    Actor& crear_actor (const std::string& clase) const;
};

}
#endif
