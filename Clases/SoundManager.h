///
/// @file SoundManager.h
/// @brief Fichero de la clase "SoundManager".
/// @author Juan Manuel Rico
/// @date Noviembre 2015
/// @version 1.0.0
///

#ifndef _SOUNDMANAGER_H_
#define _SOUNDMANAGER_H_

#include <allegro.h>
#include "DatFile.h"

/// Controlador de la lista de sonidos del sistema.
/// @todo Añadir lista de objetos y dejar la parte temporal, eliminar referencias
///       a las bibliotecas de alegro para generalizar la clase.
///       Incluir futura lista de objetos sonidos para controlar.
/// @warning Esta clase no está desarrollada, necesita de mucho código para que sea funcional.
///
class SoundManager
{
public:
    /// Constructor.
    ///
    SoundManager ();

    /// Destructor.
    ///
    ~SoundManager ();

    /// Obtener un sonido determinado de la lista.
    /// @param identificador  Identificador del sonido en la lista.
    /// @return Puntero al 'sample' requerido.
    //SAMPLE* GetSample (int identificador);

//public:
    //SAMPLE* rebote;   ///< Sonido de prueba para el rebote.
};

#endif
