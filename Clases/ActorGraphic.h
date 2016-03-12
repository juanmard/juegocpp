///
/// @file ActorGraphic.h
/// @brief Fichero de definición de la clase "ActorGraphic".
/// @author Juan Manuel Rico
/// @date Octubre 2015
/// @version 1.0.0
///

#ifndef _ACTORGRAPHIC_H_
#define _ACTORGRAPHIC_H_

#include <allegro.h>
#include "PrintableObject.h"
#include <string>
#include <sstream>
#include "Actor.h"

/// Controla la parte gráfica del actor.
///
/// Esta clase define la parte gráfica del actor.
///
class ActorGraphic : public PrintableObject
{
protected:
    Actor* owner;       ///< Puntero al actor propietario del gráfico.
    bool graph_free;    ///< Indica si el gráfico está libre para ser cambiado por otro.

public:
    /// Constructor por defecto.
    ///
    ActorGraphic ();

    /// Constructor con asignación.
    /// @param a  Actor que será propietario de la parte gráfica creada.
    ///
    ActorGraphic (Actor* a);

    /// Destructor.
    ///
    virtual ~ActorGraphic ();

    /// Inicializa el gráfico.
    ///
    virtual void init ();

    /// Actualiza el gráfico.
    ///
    virtual void update ();

    /// Dibuja la parte gráfica del actor.
    /// @param bmp  BITMAP en donde se dibuja la parte gráfica del actor.
    ///
    /// @note Normalmente esta función es sobreescrita por el hijo que hereda (Sprite, Bitmap, pixel...).
    ///
    virtual void draw (BITMAP* bmp);

    /// Dibuja la parte gráfica del actor.
    /// @param x  Coordenada x de la posición donde dibujar.
    /// @param y  Coordenada y de la posición donde dibujar.
    /// @param bmp  BITMAP en donde se dibujará la parte gráfica.
    ///
    virtual void draw (int x, int y, BITMAP* bmp);

    /// Obtener el ancho del gráfico.
    /// @return Ancho obtenido.
    ///
    virtual unsigned int get_w () const;

    /// Obtener el alto del gráfico.
    /// @return Alto obtenido.
    ///
    virtual unsigned int get_h () const;

    /// Obtener la posición x del propietario del gráfico.
    /// @return Posición x del propietario.
    ///
    virtual int get_x () const;

    /// Obtener la posición y del propietario del gráfico.
    /// @return Posición y del propietario.
    ///
    virtual int get_y () const;

    /// Obtiene la máscara del gráfico.
    /// @return Puntero a la máscara del gráfico.
    ///
    virtual Mask* get_mask () const;

    /// Duplica la parte gráfica del actor y le asigna el nuevo propietario.
    /// @param propietario  Puntero del nuevo propietario al que asignar el duplicado.
    /// @return Puntero al gráfico creado.
    ///
    virtual ActorGraphic* clone (Actor* propietario) const;

    /// Entrega la estructura del gráfico en forma de cadena de caracteres.
    ///
    /// Este procedimiento es virtual para que lo definan los gráficos derivados.
    /// @return Cadena con las propiedades del gráfico.
    /// @todo Esta estructura es muy similar a la que se encuentra en la rama de
    ///       los actores, luego sería conveniente en agruparla en una clase común
    ///       a modo de interfaz que comparten (p.j. PrintableObject).
    ///
    ///       Y para desligar el gráfico de su actor propietario sería conveniente
    ///       que los gráficos tuvieran entidad propia derivando de "DrawableObject".
    ///
    virtual std::string& print () const;

    /// Lee el gráfico de un fichero.
    /// @param ifs Fichero desde el que leer las propiedades gráficas.
    /// @return Referencia al fichero para poder encadenar lecturas.
    ///
    virtual std::ifstream& leer (std::ifstream& ifs);

    /// Sobrecarga del operador >> para poder leer del fujo de datos del fichero.
    /// @param ifs Fichero desde el que leer las propiedades gráficas.
    /// @param grafico Parte gráfica del actor que se actualizará desde la lectura del fichero.
    /// @return Referencia al fichero para poder encadenar lecturas.
    ///
    friend std::ifstream& operator>> (std::ifstream& ifs, ActorGraphic& grafico);

    /// Obtiene el actor propietario del gráfico.
    /// @return Puntero al actor propietario.
    virtual Actor* getActor () const;

    /// Se modifica el actor propietario del gráfico.
    /// @param propietario Actor nuevo propietario del gráfico.
    /// @note Esta modificación puede generar una incongruencia, ya que el
    ///       antiguo actor propietario puede quedar con un gráfico asignado
    ///       que ya no es el suyo, mientras que el gráfico considera que
    ///       ahora su propietario es otro.
    ///
    ///       Para evitar esta incongruencia únicamente se modificará el
    ///       actor propietario si previamente el gráfico no tenía ninguno
    ///       asignado.
    ///
    void setOwner (Actor& propietario);

    /// Indica si el gráfico es libre para ser cambiado por otro en el actor propietario.
    /// @return Un booleano indicando si el gráfico está libre.
    ///
    /// @note Se ve la necesidad de crear este procedimiento para evitar que, animaciones sobre todo, queden sin desarrollar
    ///       completamente sus animación. Esto sucede puesto que el procedimiento "Actor::set_actor_graphic" simplemente
    ///       intercambia sus punteros.
    ///
    bool is_free ();

public:
    /// Cambia el estado del gráfico, indicando si está o no libre para ser cambiado por otro.
    /// @param estate  Un booleano indicando si el gráfico deja o no de estar libre.
    ///
    void set_free (bool estate);
};

#endif
