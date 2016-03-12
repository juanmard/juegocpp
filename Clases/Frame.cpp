///
/// @file Frame.cpp
/// @brief Fichero de implementación de la clase "Frame".
/// @author Juan Manuel Rico
/// @date Noviembre 2015
/// @version 1.0.0
///

#include "Frame.h"
#include <sstream>

Frame::Frame ()
{
};

Frame::~Frame ()
{
};

std::string Frame::print () const
{
  std::ostringstream cadena;

  // El puntero 'bmp' hay que transformarlo en el nombre asociado en almacén.
  cadena << bmp << ", Pos <" << cx << "," << cy << "> " << "Ticks: " << ticks;
  return (cadena.str());
};

