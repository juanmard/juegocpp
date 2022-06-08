///
/// @file Vector2Df.cpp
/// @brief Fichero de implementación de la clase "Vector2Df".
/// @author Juan Manuel Rico
/// @date Noviembre 2015
/// @version 1.0.1
///

#include <sstream>
#include "Vector2Df.h"

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

unsigned int Vector2Df::read (const std::string& cadena)
{
    std::istringstream iss (cadena);
    iss.ignore (10,'<');
    iss >> x;
    iss.ignore (10,',');
    iss >> y;
    return iss.gcount();
};

//void Vector2Df::read (const std::istringstream& iss)
//{
//    iss.ignore (10,'<');
//    iss >> x;
//    iss.ignore (10,',');
//    iss >> y;
//};
