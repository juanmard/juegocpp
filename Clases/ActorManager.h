///
/// @file ActorManager.h
/// @brief Fichero de definici�n de la clase "ActorManager".
/// @author Juan Manuel Rico
/// @date Noviembre 2015
/// @version 1.0.0
///

#ifndef _ACTORMANAGER_H_
#define _ACTORMANAGER_H_

#include <list>
#include <iostream>
#include <string>
#include "PrintableObject.h"

class Game;
class Actor;
class Bloque;

/// Maneja y controla los actores de la escena.
///
/// Esta clase controla todos los actores y sus estados dentro de la escena.
/// Fundamentalmente se encarga de manejar tres listas: una de control de actores, otra de actores a borrar y otra de actores a crear.
/// En cada ciclo de actualizaci�n comprueba los actores a borrar y los que se deben crear actualizando con ellas la lista de actores
/// a controlar. El control que se realiza sobre esta �ltima lista es enviar un mensaje de actualizaci�n (update) para que ejecuten,
/// cada uno de los actores, sus procedimeintos de actualizaci�n propios.
///
class ActorManager : public PrintableObject
{
protected:
    Game* game;                                 ///< Puntero al juego propietario del controlador.
    std::list<Actor*> actors;                   ///< Lista de actores a controlar.
    std::list<Actor*>::iterator actors_iter;    ///< Iterador de la lista de actores.
    std::list<Actor*> to_del;                   ///< Lista de actores a eliminar.
    std::list<Actor*> to_create;                ///< Lista de actores a a�adir.

public:
    /// Constructor.
    /// @param g  Puntero al juego propietario del controlador.
    ///
    ActorManager (Game* g);

    /// Destructor.
    ///
    ~ActorManager ();

    /// A�ade un nuevo actor a controlar.
    /// @param a  Puntero al actor que se desea a�adir.
    ///
    void add (Actor* a);

    /// Borra un actor que est� siendo controlado y deja de estarlo.
    /// @param a  Puntero al actor que se desea eliminar.
    ///
    /// @warning Queda por resolver si en este procedimiento se elimina el actor de memoria o si
    ///          bien lo �nico que se desea es dejar de controlarlo con este controlador, en ese
    ///          caso habr�a que decidir quien se hace cargo del actor para que no quede el puntero hu�rfano.
    ///
    void del (Actor* a);

    /// Obtiene un actor de la lista dando la posici�n en la que se encuentra.
    ///
    /// Entregar� el primer actor de la lista cuyo bloque se encuentre dentro de
    /// la posici�n de b�squeda dada como par�metro.
    /// @param x  Coordenada x de la posici�n de b�squeda.
    /// @param y  Coordenada y de la posici�n de b�squeda.
    /// @return Puntero al actor que se encuentra en dicha posici�n. Entregar� NULL
    ///         si no encuentra ning�n actor en dicha posici�n de b�squeda.
    ///
    /// @todo Hacer que el procedimiento entregue una lista de actores puesto que varios
    ///       actores y sus bloques asociados pueden solaparse.
    ///
    Actor* get_actor (int x, int y);

    /// Rebobina la lista de actores.
    ///
    void rewind ();

    /// Entrega el siguiente actor de la lista.
    /// @return Puntero al siguiente actor de la lista.
    ///         Devuelve NULL si estamos al final de la lista.
    ///
    Actor* next ();

    /// Entrega el actor actual de la lista.
    /// @return Puntero al actor actual de la lista.
    ///
    Actor* current ();

    /// Actualiza la lista completa de actores.
    /// En este caso actualiza el aspecto y la f�sica implicada.
    ///
    void update ();

    /// Entrega el n�mero de actores que actualmente contiene la lista.
    /// @return N�mero de actores de la lista.
    ///
    unsigned int num_actors () const;

    /// Obtiene el iterador de inicio de la lista.
    /// @return Referencia a un iterador que apunta al inicio de la lista de actores.
    ///
    std::list<Actor*>::const_iterator& get_begin_iterator () const;

    /// Obtiene el iterador de fin de lista.
    /// @return Referencia a un iterador que apunta al final de la lista de actores.
    ///
    std::list<Actor*>::const_iterator& get_end_iterator () const;

    /// Devuelve una lista de punteros de actores que interseccionan con un bloque.
    /// @param bloque  Referencia al bloque con el que queremos intersectar.
    /// @return Referencia a una nueva lista de actores.
    ///
    std::list<Actor*>& get_actores (const Bloque& bloque) const;

    /// Obtiene el actor dado como �ndice de la lista.
    /// @param indice  �ndice del actor en la lista.
    /// @return Puntero al actor requerido. Si no existe el �ndice
    ///         devuelve NULL.
    ///
    Actor* get_actor (unsigned int indice) const;

    /// Obtiene los distintos trajes de los actores.
    /// Obtiene los distintos objetos gr�ficos (trajes) de los actores.
    /// @return Referencia a una nueva cadena con el nombre de prueba.
    ///
    /// @note Un traje para un mismo actor puede ser el mismo, luego lo ideal
    ///       ser�a definir una clase "Armario" donde se encuentren todos los
    ///       trajes a utilizar. En este caso se separar�a en una clase distinta
    ///       y en esta clase ir�a este procedimiento.
    /// @todo Crear una clase "Armario" donde se incluyeran todos los trajes que
    ///       utilizar�n actores y decorado a lo largo del juego (atrezzo del juego).
    /// @warning No s� qu� sentido tiene este procedimiento aqu�.
    ///
    std::string& get_armario () const;

    /// Borra todas las listas de los actores.
    ///
    void delete_actors ();

    /// Cargar la lista de actores desde un fichero de texto plano.
    ///
    /// El formato del fichero debe ser el siguiente:
    /// @code
    ///     [Actores]
    ///     Cantidad 3
    ///     Ladrillo {
    ///               Nombre "Ladrillo-001"
    ///               Posici�n <120,40>
    ///               Bloque <32,15>
    ///               Bitmap "sprite_041"
    ///              }
    ///     Paleta {...}
    ///     Henry {...}
    /// @endcode
    /// @param file  Referencia al nombre del fichero a cargar.
    ///
    void load (const std::string& file);

    /// A�ade todos los actores de la lista de actores a crear a la lista principal de control.
    ///
    void add_all_to_create ();

    /// Borra todos los actores que est�n siendo controlados de la lista de actores.
    ///
    void del_all_to_del ();

protected:
    /// Avisa de que se ha agregado un actor sin componente gr�fica.
    /// El aviso se realiza en la consola de salida.
    ///
    void aviso_actor_sin_grafico (const Actor& a) const;

private:
    /// Busca dentro del fichero la propiedad pasada por par�metro.
    /// @param propiedad  Referencia al nombre de la propiedad a buscar.
    /// @param inFile  Referencia al 'filestream' donde buscar.
    /// @return Posici�n de la propiedadd encontrada dentro del fichero.
    ///         Devuelve el valor "string::npos" si no encuentra la propiedad.
    /// @todo Crear una clase de fichero heredada de 'ifstream' donde incluir este procedimiento
    ///       de esta forma se evitar�a enviar el 'ifstream' por par�metro.
    ///
    std::size_t buscar_propiedad (const std::string& propiedad, std::ifstream& inFile) const;

    /// Busca dentro del fichero una palabra pasada por par�metro.
    /// @param palabra  Referencia al nombre de la propiedad a buscar.
    /// @param inFile  Referencia al 'filestream' donde buscar.
    /// @return Posici�n de la palabra encontrada dentro del fichero.
    ///         Devuelve el valor "string::npos" si no encuentra la palabra.
    /// @todo Crear una clase de fichero heredada de 'ifstream' donde incluir este procedimiento
    ///       de esta forma se evitar�a enviar el 'ifstream' por par�metro.
    ///
    std::size_t buscar (const std::string& palabra, std::ifstream& inFile) const;

    /// Crea un actor del tipo indicado.
    ///
    /// Para crear actores mediante, por ejemplo, la lectura de un fichero se necesita identificar
    /// la clase final (la "hoja" en el �rbol de herencia) de dicho actor, de esta forma se obtendr�n
    /// propiedades y procedimientos propios �nicamente de dicha clase.
    /// @param clase Referencia constante al nombre de la clase actor que se desea crear.
    /// @return Referencia al nuevo actor creado.
    ///
    Actor& crear_actor (const std::string& clase) const;

public:
    /// Obtiene una cadena representativa de la lista de actores que actualmente controla.
    /// @return Cadena con la representaci�n de la lista de actores.
    ///
    std::string& print () const;

    /// Obtiene los objetos de un flujo de datos.
    ///
    /// Seg�n el nombre leido del flujo crea un objeto actor de ese tipo y
    /// lo a�ade a la lista activa de actores.
    /// @todo Crear una clase ReadeableObject, al estilo de PrintableObject, para que la clase herede
    ///       de ella y eliminar este procedimiento friend.
    friend std::istream& operator>> (std::istream& is, ActorManager& am);
};

#endif
