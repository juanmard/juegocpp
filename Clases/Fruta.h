///
/// @file Fruta.h
/// @brief Fichero cabecera de la clase "Fruta".
/// @details El comportamiento de la fruta es estar en espera hasta que el jugador se la coma.
/// @author Juan Manuel Rico
/// @date Noviembre 2025
/// @version 1.0.0
///

#ifndef _FRUTA_H_
#define _FRUTA_H_

#include "StorageManager.h"
#include "Sprite.h"
#include "Menu.h"
#include "Formulario.h"

/// Fruta estática como comida para el jugador.
///
/// @note Realmente no se debería definir como un actor controlable,
///       ya que queda estática a la espera de una interacción con el jugador.
///
class Fruta : public Actor
{
private:
    Sprite *idle, *uvas;                        ///< Animaciones para la fruta.

public:
    /// Constructor básico.
    ///
    Fruta ();

    /// Constructor mediante almacén de gráficos.
    /// @param almacen  Almacen con los gráficos para crear la animación de la fruta.
    /// @todo Este parámetro de almacen no tiene mucho sentido en esta clase, debería ser
    ///       más sencillo crear un actor del tipo Fruta.
    ///
    Fruta (StorageManager &almacen);

    /// Obtiene el nombre en forma de cadena de texto.
    /// @param strNombre Referencia a la cadena donde se guardará el nombre de la fruta.
    ///
    void getNombre (std::string &strNombre) const;

    /// Obtiene el nombre de la fruta.
    /// @return Nombre de la fruta en forma de cadena.
    ///
    /// @todo Poder asignar un nombre distinto a cada actor y poder actualizarlo.
    ///
    std::string getNombre () const;

    /// Reacciona antre una colisión con otro actor.
    /// Esta es la parte de la reacción del entorno que debe tener presente el autómata.
    /// @param  who     Puntero del actor que provoca la colisión.
    /// @param  damage  Intensidad con la que se produce la colisión.
    ///
    void hit (Actor* who, int damage);

    /// 
    ///
    std::string& get_nombre () const;

    /// Redefine los métodos 'virtuales puros' de 'EditableObject'.
    Menu&        getMenu () const;
    Formulario&  getFormulario () const;
};
#endif
