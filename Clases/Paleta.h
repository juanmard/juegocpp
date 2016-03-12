///
/// @file Paleta.h
/// @brief Fichero cabecera de la clase "Paleta".
/// @author Juan Manuel Rico
/// @date Marzo 2015
/// @version 1.0.0
///

#ifndef _PALETA_H_
#define _PALETA_H_

#include "ControllableActor.h"
#include "Almacen.h"
#include "Suelo.h"

/// @class Paleta
/// Actor que cambia la dirección de la pelota.
///
/// Es controlable mediante el teclado. Y se creó el actor para un primer juego de
/// tipo "Arkanoid".
///
class Paleta : public ControllableActor
{
public:
    typedef enum {LEFT, RIGHT} action_t;    ///< Acciones que puede realizar la Paleta.

public:
    /// Constructor por defecto.
    ///
    Paleta ();

    /// Constructor de copia.
    /// @param copia  Actor Paleta a copiar.
    ///
    Paleta (const Paleta &copia);

    /// Constructor.
    ///
    /// Construye la Paleta a partir de un almacén de recursos para gráficos y sonido.
    /// @param almacen  Referencia al objeto que hace de almacén de recursos.
    ///
    /// @note No gusta el tener que pasar el almacén para generar el objeto, a
    ///       eliminar este parámetro si es posible.
    ///
    Paleta (Almacen &almacen);
                        
    /// Destructor.
    ///
    ~Paleta ();
    
    /// Acciones como actor controlable que se realizan.
    /// @param act  Acción que se debe realizar.
    /// @param magnitude  Magnitud en la acción que se realiza.
    ///
    void do_action (ControllableObject::action_t act, int magnitude);
    
    /// Acciones ante colisiones.
    /// @param who  Puntero al actor que provoca la comisión.
    /// @param damage  Daño que produce la colisión.
    ///
    void hit (Actor *who, int damage);

    /// Clona el objeto.
    /// @return Puntero a la Paleta clonada.
    ///
    /// @note Este procedimiento debe ser heredado de 'ObjetoClonable'.
    ///
    virtual Paleta *clone () const;

    /// Obtiene el nombre de la Paleta en forma de cadena de texto.
    /// @param strNombre  Referencia a la cadena donde situar el nombre.
    ///
    void getNombre (std::string &strNombre) const;

    /// Devuelve una cadena con el nombre de la Paleta.
    /// @return Cadena con el nombre.
    ///
    std::string getNombre () const;

protected:
    Suelo *piel;    ///< Puntero al suelo que hace de gráfico.
};

#endif
