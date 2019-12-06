///---------------------------------------------------------
/// @file       Peripheral.h
/// @author     Juan Manuel Rico
/// @date       Octubre 2015
/// @version    1.0.0
///
/// @brief      Define un periférico para el control.
///---------------------------------------------------------

#ifndef _PERIPHERAL_H_
#define _PERIPHERAL_H_

#include <string>

#define INVALID_STATE       -2
#define INVALID_COMPONENT   -2

namespace fwg {

    /// Define el periférico de un equipo.
    ///
    /// Se define un periférico (p.j. teclado) para poder abstraer los controles del
    /// juego y de esta forma, los actores pueden ser controlados por más de un
    /// periférico.
    ///
    class Peripheral
    {
        public:
            /// Eventos que generan los componentes del periférico. 
            typedef enum
            {
              NO_EVENT,         ///< Sin evento.
              ON_PRESS,         ///< Se pulsa el componente. Un único evento al pulsar.
              ON_RELEASE,       ///< Se suelta el componente. Un único evento al soltar.
              ON_PRESSING,      ///< Componente siendo pulsado.
              ON_RELEASSING     ///< Componente siendo soltado.
            } Event;
            
            /// Se define el tipo para los diferentes estados del componente.
            typedef int State;

            /// Se define el tipo para identificar a los diferentes componentes del periférico.
            typedef int Component;

            /// Constructor por defecto.
            ///
            Peripheral ();

            /// Destructor por defecto.
            ///
            virtual ~Peripheral ();

            /// Obtiene el estado del componente.
            /// 
            /// @param comp  Componente del que se desea conocer su estado.
            /// @return Estado del componente.
            ///
            virtual State getState (Component comp);

            /// Obtiene el componente que ha cambiado en el periférico.
            /// 
            /// @return Componente que ha cambiado.
            ///
            virtual Component getChange ();
            
            /// Obtiene el nombre del componente.
            /// 
            /// @param comp Componente del que se desea obtener su nombre.
            /// @return Cadena con el nombre del componente.
            ///
            virtual std::string getComponentName (Component comp);
            
            /// Reinicia el periférico.
            ///
            virtual void reset ();
    };
}

#endif
