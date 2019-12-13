///
/// @file Mosaico.h
/// @brief Fichero de definición de la clase "Mosaico".
/// @author Juan Manuel Rico
/// @date Noviembre 2015
/// @version
///      - 1.0.0 Noviembre 2015
///

#ifndef _MOSAICO_H_
#define _MOSAICO_H_

#include "ActorGraphic.h"
#include "DatFile.h"
#include "Tesela.h"
#include <string>
#include <list>

namespace fwg {
    
class Tesela;

/// Parte gráfica de un actor formada por un conjunto de Bitmaps estáticos.
/// @todo Cambiar la clase de Allegro BITMAP por la propia Bitmap.
///
class Mosaico : public ActorGraphic
{
private:
    std::list<Tesela*> teselas;         ///< Lista de las teselas gráficas que constituyen el mosaico.
    std::list<Tesela*>::iterator it;    ///< Iterador de uso en la lista de teselas. @note Este iterador no tiene sentido en las propiedades.

public:
    /// Constructor básico y mínimo.
    ///
    Mosaico ();

    /// Constructor de copia de la clase.
    /// @param copia  Mosaico a copiar.
    /// @param propietario  Propietario de la nueva copia de mosaico.
    ///
    Mosaico (const Mosaico& copia, Actor* propietario);

    /// Constructor.
    /// @param actor_asociado  Actor al que se le asignará el nuevo mosaico.
    ///
    Mosaico (Actor* actor_asociado);

    /// Dibuja las teselas del mosaico en pantalla.
    /// @param pantalla  Lugar donde dibujar el mosaico.
    /// @todo Independizar la clase de la biblioteca de Allegro.
    ///
    void draw (BITMAP* pantalla);

    /// Dibuja las teselas del mosaico en pantalla.
    /// @param x  Coordenada x de la posición en pantalla.
    /// @param y  Coordenada y de la posición en pantalla.
    /// @param pantalla  Lugar donde dibujar el mosaico.
    /// @todo Independizar la clase de la biblioteca de Allegro.
    ///
    void draw (int x, int y, BITMAP* pantalla);

    /// Añade una nueva tesela al inicio de la lista.
    ///
    /// Al añadirse al inicio de la lista es la primera tesela en dibujarse, quedando por
    /// detrás del resto.
    /// @param nueva  Puntero a la tesela a añadir.
    ///
    void add_primera_Tesela (Tesela* nueva);

    /// Añade una nueva tesela al final de la lista.
    ///
    /// Al añadirse al final de la lista es la última tesela en dibujarse, quedando por
    /// delante del resto.
    /// @param nueva Puntero a la tesela a añadir.
    /// @todo Integrar "add_ultima_Tesela" y "add_primera_Tesela" en una única
    /// @code
    ///     add_Tesela (Tesela* nueva, Posicion pos = Mosaico::Delante)
    /// @endcode
    ///
    void add_ultima_Tesela (Tesela* nueva);

    /// Borra una tesela al inicio de la lista.
    ///
    void del_primera_Tesela ();

    /// Mueve la tesela elegida según un incremento de 'y' y de 'x'.
    /// @param inc_x  Incremento en x con el que se desplaza la tesela.
    /// @param inc_y  Incremento en y con el que se desplaza la tesela.
    /// @param elegida  Tesela que se desea desplazar.
    ///
    void move_Tesela (int inc_x, int inc_y, Tesela* elegida);

    /// Devuelve la última tesela añadida.
    /// @return Puntero a la última telesa del mosaico.
    ///
    Tesela* last_Tesela () const;

    /// Intercambia la posición de dos Teselas en la lista.
    ///
    /// Intercambiar dos teselas en la lista implica que cambia su
    /// orden al dibujarlas quedando una por encima de la otra.
    /// @param tesela_1  Tesela a intercambiar.
    /// @param tesela_2  Tesela a intercambiar.
    /// @todo El procedimiento no está terminado tendría que
    ///         - Sobrecargar esta función con los índices de las teselas.
    ///         - Desarrollar la función si fuera necesaria. 
    ///
    void swap_Tesela (Tesela* tesela_1, Tesela* tesela_2);

    /// Clona un mosaico completo.
    /// @param propietario  Actor al que se le asignará la tesela clonada.
    virtual Mosaico* clone (Actor* propietario) const;

    /// Obtiene las propiedades del mosaico en una única cadena de caracteres.
    /// @return Cadena de caracteres con todas las propiedades del mosaico.
    ///
    std::string& print () const;

    /// Elimina todas las teselas del mosaico.
    ///
    void clear ();
};
}
#endif
