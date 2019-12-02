///
/// @file Bitmap.h
/// @brief Fichero de definición de la clase "Bitmap".
/// @author Juan Manuel Rico
/// @date Noviembre 2015
/// @version 1.0.0
///

#ifndef _BITMAP_H_
#define _BITMAP_H_

#include "ActorGraphic.h"
#include "Actor.h"
#include "Almacen.h"
#include <string>

namespace fgm {
/// Parte gráfica de un actor como gráfico fijo.
///
/// Esta clase modela una imagen fija como gráfico para un actor.
/// @warning Quizás no sea buena idea heredarla de ActorGraphic, ya que un Bitmap
///          debe ser utilizado en otros contextos, como por ejemplo como parte
///          de una animación más compleja en los Sprites.
///
class Bitmap : public fgm::ActorGraphic
{
protected:
    static fgm::Almacen* almacenGlobal;      ///< Puntero estático del almacén para todos los objetos de la clase Bitmap.
    fgm::Almacen* almacen;                   ///< Puntero al almacén de la clase. @warning ¿Es esta variable necesario?
    BITMAP* fuente;                     ///< Fuente de la imagen del Bitmap.
    std::string nombre;                 ///< Nombre del Bitmap.

public:
    /// Constructor.
    /// @param aowner  Puntero al actor que se le será asignado como dueño.
    /// @param bmp  Puntero al BITMAP de Allegro.
    ///
    Bitmap (fgm::Actor* aowner, BITMAP* bmp);

    /// Constructor.
    ///
    /// Utiliza únicamente el nombre del bitmap para buscar y crear el Bitmap.
    /// @param aowner  Puntero al actor que se le será asignado como dueño.
    /// @param nombreParam  Cadena de texto con el nombre que se le asignará al Bitmap.
    ///
    Bitmap (fgm::Actor* aowner, std::string nombreParam);

    /// Constructor.
    /// @param aowner  Puntero al actor que se le será asignado como dueño.
    /// @param bmp  Puntero al BITMAP de Allegro.
    /// @param nombreParam  Cadena de texto con el nombre que se le asignará al Bitmap.
    ///
    Bitmap (fgm::Actor* aowner, BITMAP* bmp, std::string nombreParam);

    /// Constructor.
    ///
    /// Este constructor utiliza el almacén de recursos.
    /// @param aowner  Puntero al actor que se le será asignado como dueño.
    /// @param almacen  Puntero al almacén donde se encuentran todos los gráficos del juego.
    /// @param nombre  Cadena de texto con el nombre que se le asignará al Bitmap.
    ///
    Bitmap (fgm::Actor* aowner, fgm::Almacen* almacen, const std::string nombre);


    /// Dibuja en BITMAP de Allegro.
    ///
    /// Dibuja el Bitmap fuente (el Bitmap dado al crear el objeto), en el BITMAP
    /// destino (pasado por parámetro), normalmente la pantalla o un buffer intermedio.
    /// @param destino  Puntero a un BITMAP de Allegro donde dibujar el Bitmap.
    ///
    void draw (BITMAP* destino);

    /// Dibuja el bitmap en la zona de memoria dada como destino.
    /// @warning Se mantienen las dos formas de dibujar: Usando al almacén global y el BITMAP fuente.
    ///          En un futuro la línea es mantener todos los punteros BITMAP en el almacén y referenciarlos
    ///          únicamente con su nombre. En ese momento se eliminará la propiedad 'fuente' de la clase.
    /// @note Mantenemos este procedimiento por compatibilidad (No entiendo porqué no funciona el parámetro por omisión)
    /// @note Ahora lo entiendo... no funciona porque el procedimiento que se hereda de ActorGraphic es sin el parámetro.
    ///
    void draw (int x, int y, BITMAP* destino, bool mirror=false);
    void draw (int x, int y, BITMAP* destino);

    /// Obtiene el valor de la anchura del Bitmap.
    /// @return Valor del ancho del Bitmap.
    ///
    unsigned int get_w () const;

    /// Obtiene el valor de la altura del Bitmap.
    /// @return Valor del alto del Bitmap.
    ///
    unsigned int get_h () const;

    /// Realiza una copia exacta del Bitmap y se la asigna a un nuevo actor.
    /// @param propietario  Puntero al nuevo propietario del Bitmap.
    /// @return Puntero a la nueva copia creada.
    ///
    virtual Bitmap* clone (fgm::Actor* propietario) const;

    /// Devuelve la estructura básica del objeto en forma de cadena.
    /// @todo Hacer este procedimiento virtual y que los distintos gráficos hereden
    ///       de una clase más genérica llamada "Gráfico" que es "Imprimible" y "Dibujable".
    ///
    virtual std::string& print () const;

    /// Devuelve la zona de memoria donde está la imagen.
    ///
    /// También se podría utilizar el nombre y el almacén para obtener este mismo dato:
    /// @code
    ///   return almacen->getBitmap (nombre);
    /// @endcode
    /// Este es el que debe quedar cuando eliminemos el resto de parámetros.
    /// @return Puntero de Allegro hacia la imagen.
    ///
    BITMAP* get_imagen () const;

    /// Fija el puntero global que hace referencia al almacén.
    /// @param almacen  Puntero al almacén estático.
    static void set_almacen (fgm::Almacen* almacen)
    {
        almacenGlobal = almacen;
    };
};

}
#endif
