///
/// @file Peripheral.h
/// @brief Fichero de definición de la clase "Peripheral".
/// @author Juan Manuel Rico
/// @date Octubre 2015
/// @version 1.0.0
///

#ifndef _PERIPHERAL_H_
#define _PERIPHERAL_H_

#include <string>

#define INVALID_STATE       -2
#define INVALID_COMPONENT   -2

/// @class Define el periférico de un equipo.
/// Se define un periférico (p.j. teclado) para poder abstraer los controles del juego y de esta forma
/// los actores del juego pueden ser controlados por más de un periférico.
///
class Peripheral
{
public:
    /// @enum Eventos que generan los componentes del periférico. 
    typedef enum
    {
      NO_EVENT,         ///< Sin evento.
      ON_PRESS,         ///< Se pulsa el componente.
      ON_RELEASE,       ///< Se suelta el componente.
      ON_PRESSING,      ///< Componente siendo pulsado.
      ON_RELEASSING     ///< Componente siendo soltado.
    } event_t;
    
    /// @typedef Se define el tipo para los diferentes estados del componente.
    typedef int state_t;

    /// @typedef Se define el tipo para identificar a los diferentes componentes del periférico.
    typedef int component_t;

    /// Constructor por defecto.
    ///
    Peripheral ();

    /// Destructor por defecto.
    ///
    virtual ~Peripheral ();

    /// Obtiene el estado del componente.
    /// @param comp  Componente del que se desea conocer su estado.
    /// @return Estado del componente.
    ///
    virtual state_t get_state (component_t comp);

    /// Obtiene el componente que ha cambiado en el periférico.
    /// @return Componente que ha cambiado.
    ///
    virtual component_t get_change ();
    
    /// Obtiene el nombre del componente.
    /// @param comp  Componente del que se desea obtener su nombre.
    /// @return Cadena con el nombre del componente.
    ///
    virtual std::string get_component_name (component_t comp);
    
    /// Reinicia el periférico.
    ///
    virtual void reset ();
};

#endif
