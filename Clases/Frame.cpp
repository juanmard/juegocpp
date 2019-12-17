///---------------------------------------------------------
/// @file       Frame.h
/// @author     Juan Manuel Rico
/// @date       Noviembre 2015
/// @version    1.1.0
///
/// @brief      Gráfico básico de una animación.
///---------------------------------------------------------
///

#include "Frame.h"
#include <sstream>

namespace fwg {
    
    Frame::Frame ()
    {
    }

    Frame::~Frame ()
    {
    }

    std::string Frame::print () const
    {
      std::ostringstream cadena;

      // El puntero 'bmp' hay que transformarlo en el nombre asociado en almacén.
      cadena << bmp << ", Pos <" << cx << "," << cy << "> " << "Ticks: " << ticks;
      return (cadena.str());
    }

    BITMAP* Frame::getBitmap () const
    {
        return bmp;
    }
}