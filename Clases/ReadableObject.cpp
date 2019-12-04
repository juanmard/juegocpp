///
/// @file ReadableObject.cpp
/// @brief Fichero de implementación de la clase "ReadableObject".
/// @author Juan Manuel Rico
/// @date Noviembre 2015
/// @version 1.0.0
///

#include "ReadableObject.h"

namespace fwg {

ReadableObject::ReadableObject ()
{
};

ReadableObject::~ReadableObject ()
{
};

const std::string& operator>> (const std::string& cadena, ReadableObject& objeto)
{
    /// @todo ¿Devolver el número de caracteres leídos de la cadena para devolver el resto de la cadena que queda por leer?
    objeto.read (cadena);
    return cadena;
};

std::istringstream& operator>> (std::istringstream& iss, ReadableObject& objeto)
{
    std::string cadena;
    std::getline (iss, cadena);
    objeto.read (cadena);
    return iss;
};

std::istream& operator>> (std::istream& is, ReadableObject& objeto)
{
    // Para C++ básico.
    //char cadena[256];
    //is.getline (cadena, 255);
    //objeto.read (*new std::string(cadena));

    // Solo C++98 y C++11
    std::string cadena;
    std::getline (is, cadena);
    objeto.read (cadena);
    return is;
};

}
