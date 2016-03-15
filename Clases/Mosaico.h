///
/// @file Mosaico.h
/// @brief Fichero de definici�n de la clase "Mosaico".
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

class Tesela;

/// Parte gr�fica de un actor formada por un conjunto de Bitmaps est�ticos.
/// @todo Cambiar la clase de Allegro BITMAP por la propia Bitmap.
///
class Mosaico : public ActorGraphic
{
private:
    std::list<Tesela*> teselas;         ///< Lista de las teselas gr�ficas que constituyen el mosaico.
    std::list<Tesela*>::iterator it;    ///< Iterador de uso en la lista de teselas. @note Este iterador no tiene sentido en las propiedades.

public:
    /// Constructor b�sico y m�nimo.
    ///
    Mosaico ();

    /// Constructor de copia de la clase.
    /// @param copia  Mosaico a copiar.
    /// @param propietario  Propietario de la nueva copia de mosaico.
    ///
    Mosaico (const Mosaico& copia, Actor* propietario);

    /// Constructor.
    /// @param actor_asociado  Actor al que se le asignar� el nuevo mosaico.
    ///
    Mosaico (Actor* actor_asociado);

    /// Dibuja las teselas del mosaico en pantalla.
    /// @param pantalla  Lugar donde dibujar el mosaico.
    /// @todo Independizar la clase de la biblioteca de Allegro.
    ///
    void draw (BITMAP* pantalla);

    /// Dibuja las teselas del mosaico en pantalla.
    /// @param x  Coordenada x de la posici�n en pantalla.
    /// @param y  Coordenada y de la posici�n en pantalla.
    /// @param pantalla  Lugar donde dibujar el mosaico.
    /// @todo Independizar la clase de la biblioteca de Allegro.
    ///
    void draw (int x, int y, BITMAP* pantalla);

    /// A�ade una nueva tesela al inicio de la lista.
    ///
    /// Al a�adirse al inicio de la lista es la primera tesela en dibujarse, quedando por
    /// detr�s del resto.
    /// @param nueva  Puntero a la tesela a a�adir.
    ///
    void add_primera_Tesela (Tesela* nueva);

    /// A�ade una nueva tesela al final de la lista.
    ///
    /// Al a�adirse al final de la lista es la �ltima tesela en dibujarse, quedando por
    /// delante del resto.
    /// @param nueva Puntero a la tesela a a�adir.
    /// @todo Integrar "add_ultima_Tesela" y "add_primera_Tesela" en una �nica
    /// @code
    ///     add_Tesela (Tesela* nueva, Posicion pos = Mosaico::Delante)
    /// @endcode
    ///
    void add_ultima_Tesela (Tesela* nueva);

    /// Borra una tesela al inicio de la lista.
    ///
    void del_primera_Tesela ();

    /// Mueve la tesela elegida seg�n un incremento de 'y' y de 'x'.
    /// @param inc_x  Incremento en x con el que se desplaza la tesela.
    /// @param inc_y  Incremento en y con el que se desplaza la tesela.
    /// @param elegida  Tesela que se desea desplazar.
    ///
    void move_Tesela (int inc_x, int inc_y, Tesela* elegida);

    /// Devuelve la �ltima tesela a�adida.
    /// @return Puntero a la �ltima telesa del mosaico.
    ///
    Tesela* last_Tesela () const;

    /// Intercambia la posici�n de dos Teselas en la lista.
    ///
    /// Intercambiar dos teselas en la lista implica que cambia su
    /// orden al dibujarlas quedando una por encima de la otra.
    /// @param tesela_1  Tesela a intercambiar.
    /// @param tesela_2  Tesela a intercambiar.
    /// @todo El procedimiento no est� terminado tendr�a que
    ///         - Sobrecargar esta funci�n con los �ndices de las teselas.
    ///         - Desarrollar la funci�n si fuera necesaria. 
    ///
    void swap_Tesela (Tesela* tesela_1, Tesela* tesela_2);

    /// Clona un mosaico completo.
    /// @param propietario  Actor al que se le asignar� la tesela clonada.
    virtual Mosaico* clone (Actor* propietario) const;

    /// Obtiene las propiedades del mosaico en una �nica cadena de caracteres.
    /// @return Cadena de caracteres con todas las propiedades del mosaico.
    ///
    std::string& print () const;

    /// Elimina todas las teselas del mosaico.
    ///
    void clear ();
};

#endif
