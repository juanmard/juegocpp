#pragma once

#include <allegro.h>
#include "DatFile.h"

/**
 * \class   SoundManager
 * \brief   Controlador de la lista de sonidos del sistema.
 * \todo    Añadir lista de objetos y dejar la parte temporal, eliminar referencias
 *          a las bibliotecas de alegro para generalizar la clase.
 */
class SoundManager
{
public:
    SoundManager    ();
    ~SoundManager   ();
    //SAMPLE *    GetSample (int identificador);

//public:
    //SAMPLE *rebote;
    /**
     * \todo   Incluir futura lista de objetos sonidos para controlar. 
     */
};
