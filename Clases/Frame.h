///
/// @file Frame.h
/// @brief Fichero de definición de la clase "Frame".
/// @author Juan Manuel Rico
/// @date Noviembre 2015
/// @version 1.0.0
///

#ifndef _FRAME_H_
#define _FRAME_H_

#include <allegro.h>
#include "Mask.h"
#include <string>

/// Cuadro básico (Frame) de la animación.
///
/// @todo Cambiar el BITMAP que es un tipo de Allegro, por un tipo Bitmap propio.
/// @todo Generar los procedimientos necesarios para dejar las propiedades privadas y no públicas.
/// @todo Agrupar cx y cy en un único vector.
///
class Frame
{
public:
  BITMAP* bmp;  ///< Imagen que debe mostrar el cuadro.
  fgm::Mask* mask;   ///< Máscara de colisión del cuadro.
  int cx;       ///< Coordenada x de la posición relativa del cuadro.
  int cy;       ///< Coordenada y de la posición relativa del cuadro.
  int ticks;    ///< Tiempo (en ciclos de juego) que debe permanecer el cuadro en pantalla.

public:
    /// Constructor básico.
    ///
    Frame ();

    /// Destructor básico.
    ///
    ~Frame ();

    /// Entrega una cadena con la estructura de datos del cuadro.
    /// @return Cadena de caracteres con la estructura del cuadro.
    std::string print () const;

    /// Entrega un puntero a la imagen del "frame".
    /// @return Puntero al BITMAP de Allegro con la imagen del "frame".
    BITMAP* getBitmap () const;
};

#endif
