///---------------------------------------------------------
/// @file       JoystickAllegro.h
/// @author     Juan Manuel Rico
/// @date       Diciembre 2019
/// @version    1.0.0
///
/// @brief      Joystick usando bibliotecas de Allegro.
///---------------------------------------------------------

#ifndef _JOYSTICKALLEGRO_H_
#define _JOYSTICKALLEGRO_H_

#include "../Joystick.h"
#include <allegro.h>

namespace alg4 {
        
    /// Define el comportamiento del joystick usando bibliotecas de Allegro.
    /// 
    /// @todo Eliminar de la clase la palabra 'Allegro' y dejar el espacio
    ///       de nombres para referenciar la clase. p.j:
    ///       @code
    ///           // Usar este formato.
    ///           Joystick joy1 = new alg4::Joystick();
    ///           
    ///           // En lugar de este.
    ///           Joystick joy1 = new alg4::JoystickAllegro();
    ///       @endcode
    /// 
    class JoystickAllegro : public fwg::Joystick
    {
        public:
            JoystickAllegro ();

        protected:
            /// Instala el joystick en el motor gráfico.
            /// 
            bool install ();
            
            /// Obtiene el número máximo de botones.
            /// 
            /// @return Número máximo de botones para este joystick.
            /// 
            unsigned int getNumButtons ();

            /// Obtiene el número máximo de ejes.
            /// 
            /// @return Número máximo de ejes para este joystick.
            /// 
            unsigned int getNumAxis ();
            
            /// Refresca los datos del joystick.
            /// 
            void update ();
    };
}

#endif