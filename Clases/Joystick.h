///---------------------------------------------------------
/// @file       Joystick.h
/// @author     Juan Manuel Rico
/// @date       Diciembre 2019
/// @version    1.0.0
///
/// @brief      Definición del joystick como periférico.
///---------------------------------------------------------

#ifndef _JOYSTICK_H_
#define _JOYSTICK_H_

#include <vector>
#include "Peripheral.h"

namespace fwg {
    
    /// Clase para los ejes de un joystick.
    /// 
    class JoyAxi{public: int d1,d2;};
    
    /// Clase para los botones de un joystick.
    /// 
    class JoyButton{public: bool b; int value;};
    
    /// Define el comportamiento del joystick como un periférico.
    /// 
    /// @todo Cosas por terminar en esta clase:
    ///        - Completar todos los nombres de los componentes del
    ///          joystick en el método 'getComponentName'.
    ///        - Establecer la numeración de los componentes y los estados
    ///          de todos los joysticks y ejes posibles, así como los 'oldState'
    ///          de todos. Actualmente el componente está definido como un entero,
    ///          así como sus estados.
    ///        - Definir por separado el enumeral de botones y ejes.
    ///
    class Joystick : public Peripheral
    {
    public:
            /// @note Estos pueden definirse por separado para
            ///       las clases "JoyAxis" y "JoyButtons"
            enum {
                   NONE = 20,    ///< Joystick without state.
                   UP,            ///< Joystick up.
                   DOWN,         ///< Joystick down.
                   LEFT,         ///< Joystick left.
                   RIGHT,        ///< Joystick right.
                   BUTTON_1 = 0, ///< Button 1.
                   BUTTON_2,     ///< Button 2.
                   BUTTON_3,     ///< Button 3.
                   BUTTON_4,     ///< Button 4.
                   BUTTON_5,     ///< Button 5.
                   BUTTON_6,     ///< Button 6.
                   BUTTON_7,     ///< Button 7.
                   BUTTON_8,     ///< Button 8.
                   BUTTON_9,     ///< Button 9.
                   BUTTON_10,    ///< Button 10.                
                   BUTTON_11,    ///< Button 11.                
                   BUTTON_12     ///< Button 12.                
                 } joyState;
                 
        public:
            static int activos;                 ///< Número de joysticks activos.

        protected:
            unsigned int joyId;                 ///< Identificador del joystick.
            std::vector<JoyAxi> axis;           ///< Set of axis.
            std::vector<JoyButton> buttons;     ///< Set of buttons.
            std::vector<int> oldStateAxis;      ///< Old state of axis.
            std::vector<bool> oldStateButtons;  ///< Old state of buttons.
            unsigned int numAxis;               ///< Número de ejes detectados del joystick.
            unsigned int numButtons;            ///< Número de botones detectados del joystick.
            
        public:
            /// Constructor por defecto.
            ///
            Joystick ();
            
            /// Obtiene el estado de una tecla.
            /// 
            /// @param comp  Tecla de la que se desea conocer el estado.
            /// @return Estado de la tecla.
            ///
            State getState (Component comp);

            /// Obtiene la tecla que ha cambiado en el teclado.
            /// 
            /// @return Tecla que ha cambiado de estado.
            /// 
            Component getChange ();

            /// Obtiene el nombre de una tecla.
            /// 
            /// @param comp Tecla de la que se desea conocer su nombre.
            /// @return Cadena de caracteres con el nombre de la tecla.
            ///
            std::string getComponentName (Component comp);

            /// Inicializa el joystick.
            ///
            void reset ();
            
        protected:
            /// Inicializa el joystick.
            /// 
            /// Inicializa el joystick con la estructura de datos obtenidos
            /// de la definición de los métodos virtuales puros de la clase
            /// que hereda.
            /// 
            void init ();

            /// Instala el joystick en el motor gráfico.
            /// 
            /// @return Devuelve 'true' si se ha realizado la instalación
            ///         correctamente.
            /// 
            virtual bool install () = 0;
            
            /// Obtiene el número máximo de botones.
            /// 
            /// @return Número máximo de botones para este joystick.
            /// 
            virtual unsigned int getNumButtons () = 0;

            /// Obtiene el número máximo de ejes.
            /// 
            /// @return Número máximo de ejes para este joystick.
            /// 
            virtual unsigned int getNumAxis () = 0;
            
            /// Refresca los datos del joystick.
            /// 
            virtual void update () = 0;
    };
}

#endif