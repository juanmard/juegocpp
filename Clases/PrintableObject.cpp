///
/// @file PrintableObject.cpp
/// @brief Fichero de implementación de la clase "PrintableObject".
/// @author Juan Manuel Rico
/// @date Noviembre 2015
/// @version 1.0.0
///

#include "PrintableObject.h"

PrintableObject::PrintableObject ()
{
};

PrintableObject::~PrintableObject ()
{
};

//std::string& PrintableObject::print (std::string& cadena) const
//{
//    return cadena;
//};

std::string& operator<< (std::string& cadena, const PrintableObject& objeto)
{
    cadena.append (objeto.print ());
    return cadena;
};

std::ostringstream& operator<< (std::ostringstream& osstream, const PrintableObject& objeto)
{
    osstream << objeto.print ();
    return osstream;
};

std::ostream& operator<< (std::ostream& ostream, const PrintableObject& objeto)
{
    ostream << objeto.print ();
    return ostream;
};
