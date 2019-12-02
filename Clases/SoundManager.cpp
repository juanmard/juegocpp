///
/// @file SoundManager.cpp
/// @brief Fichero de implementación de la clase "SoundManager".
/// @author Juan Manuel Rico
/// @date Noviembre 2015
/// @version 1.0.0
///

#include "SoundManager.h"

namespace fgm {

SoundManager::SoundManager ()
{
   /**
    * \brief    Iniciamos el sonido según el tipo de compilación.
    * \todo     Organizar un poco mejor esto, capturar el error si se produce.
    */
    #ifdef _WIN32
       /* Install a digital sound driver */
      if (install_sound(DIGI_AUTODETECT, MIDI_NONE, NULL) != 0)
      {
        allegro_message("Error inicializando el sistema de sonido.\n%s\n", allegro_error);
      }
    #else
      //if (detect_digi_driver(DIGI_ARTS)) allegro_message ("Encontrado \"aRts (Analog Real-Time Synthesizer)\"");
      //if (detect_digi_driver(DIGI_ALSA)) allegro_message ("Encontrado \"ALSA sound driver\"");
      //if (detect_digi_driver(DIGI_JACK)) allegro_message ("Encontrado \"JACK sound driver\"");
      //if (detect_digi_driver(DIGI_OSS)) allegro_message ("Encontrado \"Open Sound System\"");
      //if (detect_digi_driver(DIGI_ESD)) allegro_message ("Encontrado \"Enlightened Sound Daemon\"");
      if (install_sound(DIGI_ARTS, MIDI_NONE, NULL) != 0)
      {
        allegro_message("Error initialising sound system\n%s\n", allegro_error);
      }
    #endif

      /** 
       * \brief Cargamos samples de prueba.
       * \todo      Esta clase es el "SoundManager" esta no es su misión.
       *            Debemos crear objetos "Sonido" y heredar "Sample" de él para que esta
       *            clase pueda manipularlos y controlarlos, algo similar a lo que se hace
       *            con la parte gráfica de los actores.
       *            Esto es una simple prueba. Cuando funcione debe ser completamente modificado.
       */
//     recursos = DatFile("sprites3.dat");
};

SoundManager::~SoundManager(void)
{
};

}