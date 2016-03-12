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

/// @todo En este caso las cadenas de salida son no-constantes para poder encadenar salidas de cadena.
///       ¿Y si algún objeto no quiere modificar por ejemplo la cadena con su nombre?
///       ¿Sería mejor hacer constantes las cadenas? ¿Funcionaría?... Probar:
///       @code const std::string& operator<< (const std::string& cadena, const PrintableObject& objeto) @endcode
///
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
