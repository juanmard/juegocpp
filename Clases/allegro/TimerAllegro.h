///---------------------------------------------------------
/// @file       TimerAllegro.h
/// @author     Juan Manuel Rico
/// @date       Diciembre 2019
/// @version    1.0.0
///
/// @brief      Timer usando bibliotecas Allegro 4.
///---------------------------------------------------------
#ifndef _TIMERALLEGRO_H_
#define _TIMERALLEGRO_H_

#include <allegro.h>
#include "../Timer.h"

namespace alg4
{
    /// Clase que implementa un "timer" mediante bibliotecas de Allegro4.
    class TimerAllegro : public fwg::Timer
    {
        public:
            /// Constructor y destructor.
            /// @todo Implementar la destrucción del "timer".
            TimerAllegro (unsigned int mseg=14, unsigned int max_fs=10);
            ~TimerAllegro ();
            
            /// Heredados de "fwg::Timer". 
            void install ();
            unsigned int getTick () const;
    };
}

#endif // _TIMERALLEGRO_H_
