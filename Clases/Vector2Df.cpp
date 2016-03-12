///
/// @file Vector2Df.cpp
/// @brief Fichero de implementación de la clase "Vector2Df".
/// @author Juan Manuel Rico
/// @date Noviembre 2015
/// @version 1.0.1
///

#include "Vector2Df.h"
#include <sstream>

Vector2Df::Vector2Df ()
{
};

Vector2Df::Vector2Df (float _x, float _y)
{
    x = _x;
    y = _y;
};

std::string& Vector2Df::print () const
{
    std::ostringstream osstream;
    osstream << "<" << x << ", " << y << ">";
    return *new std::string (osstream.str ());
};

