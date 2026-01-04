#include "AllegroTimer.h"

/// @brief  Variable para guardar 'ticks' del timer.
/// @note  Las variables que modifiquen las funciones 'timer' de Allegro tienen que ser de tipo 'volatile'.
volatile int AllegroTimer::tick = 0;

/// @brief  Función definida como 'timer' de Allegro.
void AllegroTimer::tick_count()
{
  tick++;
}
END_OF_FUNCTION(AllegroTimer::tick_count);

/// @brief  Cronstructor por defecto.
AllegroTimer::AllegroTimer () {}

/// @brief  Destructor por defecto.
AllegroTimer::~AllegroTimer () {}

void AllegroTimer::install () {
  install_timer ();
}

void AllegroTimer::init () {
  actual_tick = tick;
  old_tick = tick;
  max_frame_skip = 15;

  // Protegemos variables e instalamos interrupción del "timer".
  // (14 para ejecutar 70 veces por segundo).
  LOCK_VARIABLE (AllegroTimer::tick);
  LOCK_FUNCTION (AllegroTimer::tick_count);
  install_int (&AllegroTimer::tick_count, 14);
}


