///
/// @file ControlManager.h
/// @brief Fichero de definición de la clase "ControlManager".
/// @author Juan Manuel Rico
/// @date Octubre 2015
/// @version 1.0.0
///

#ifndef CONTROLMANAGER_H
#define CONTROLMANAGER_H

#include <vector>
#include "Peripheral.h"
#include "Control.h"

#define MAXPERIPHERALS 5

/// Control de controles para objetos controlables.
///
class ControlManager
{
public:
    /// Definición para guardar los distintos cambios en los
    /// componentes de los periféricos.
    ///
    typedef struct
    {
        Peripheral* p;                  ///< Puntero al periférico donde se ha detectado el cambio.
        Peripheral::component_t comp;   ///< Componente que ha provocado el cambio.
    } change_t;
    
    /// Constructor por defecto.
    ///
    ControlManager ();

    /// Destructor por defecto.
    ///
    ~ControlManager ();

    /// Obtiene un cambio producido en algún periférico.
    /// @return Estructura de cambio con la referencia al periférico y el componente.
    ///
    change_t get_change ();
    
    /// Añade un control a la lista de controles supervisados.
    /// @param ctrl  Puntero al control que se desea supervisar.
    /// @return Posición de la lista donde se ha añadido el control.
    ///
    int add_control (Control* ctrl);

    /// Añade un periférico a la lista de periféricos a supervisar.
    /// @param periph  Periférico a añadir.
    /// @return Posición del periférico en lista.
    ///
    /// @note No le veo sentido a añadir por separado un periférico, cuando en el control
    ///       lo tenemos implícito y tenemos que añadir los controles.
    ///
    int add_peripheral (Peripheral* periph);

    /// Obtiene el control dado por su posición en la lista.
    /// @param number  Posición del control en la lista.
    /// @return Puntero al control dentro de la lista.
    ///
    Control* get_control (int number);

    /// Obtiene el periférico dado por su posición en la lista.
    /// @param number  Posición del periférico en la lista.
    /// @return Puntero al periférico dentro de la lista.
    ///
    Peripheral* get_peripheral (int number);

    /// Actualiza todos los controles.
    ///
    void update ();

protected:
    std::vector<Control*> controls;                         ///< Lista de controles a supervisar.
    std::vector<Control*>::iterator controls_iter;          ///< Iterador de la lista de controles.
    std::vector<Peripheral*> peripherals;                   ///< Lista de periféricos a supervisar.
    std::vector<Peripheral*>::iterator peripherals_iter;    ///< Iterador de la lista de periféricos.
    int old_state[MAXPERIPHERALS];                          ///< Lista de antiguos estados de los periféricos.
};

#endif