///---------------------------------------------------------
/// @file       TimerAllegro.cpp
/// @author     Juan Manuel Rico
/// @date       Diciembre 2019
/// @version    1.0.0
///
/// @brief      Timer usando bibliotecas Allegro 4.
///---------------------------------------------------------
#include "TimerAllegro.h"

/// Variable que cuenta los "ticks" cada "quantum" de tiempo.
/// @note Las variables que modifiquen las funciones 'timer' de Allegro
///       tienen que ser de tipo 'volatile'.
volatile int tick;

/// Función definida como 'timer' de Allegro llamada por la interrupción.
void tick_count()
{
  tick++;
}
END_OF_FUNCTION(tick_count);


namespace alg4 {

    TimerAllegro::TimerAllegro (unsigned int mseg, unsigned int max_fs):
    Timer (mseg, max_fs)
    {
    }

    TimerAllegro::~TimerAllegro ()
    {
    }
    
    void TimerAllegro::install ()
    {
        // Se instala el temporizador.
        install_timer ();

        // Se protegen variables y se instala interrupción del "timer".
        LOCK_VARIABLE (tick);
        LOCK_FUNCTION (tick_count);
        install_int (&tick_count, quantum);
    }
    
    unsigned int TimerAllegro::getTick () const
    {
        return tick;
    }
}
