///
/// @file PrintableObject.h
/// @brief Fichero de definición de la clase "PrintableObject".
/// @author Juan Manuel Rico
/// @date Noviembre 2015
/// @version 1.0.0
///

#ifndef _PRINTABLEOBJECT_
#define _PRINTABLEOBJECT_

#include <string>
#include <sstream>
#include <ostream>

/// Define el comportamiento de un objeto imprimible en modo texto.
///
class PrintableObject
{
private:
    /// Imprime la representación del objeto en forma de cadena de texto.
    /// @return Obtiene la cadena que representa al objeto.
    ///
    virtual std::string& print () const = 0;

public:
    /// Constructor.
    ///
    PrintableObject ();

    /// Destructor.
    ///
    virtual ~PrintableObject ();

    /// Sobrecarga de operador.
    /// @param cadena  Cadena donde guardar la representación del objeto.
    /// @return Cadena que se utiliza para encadenar llamadas al operador.
    ///
    friend std::string& operator<< (std::string& cadena, const PrintableObject& objeto); 

    /// Sobrecarga de operador.
    /// @param osstream  Canal de cadena (string-stream) donde volcar la representación del objeto.
    /// @return Canal de cadena (string-stream) para continuar el volcado si es necesario.
    ///
    friend std::ostringstream& operator<< (std::ostringstream& osstream, const PrintableObject& objeto);

    /// Sobrecarga de operador.
    /// @param ostream  Canal de salida donde volcar la representación del objeto.
    /// @return Canal de salida para continuar el volcado si es necesario.
    ///
    friend std::ostream& operator<< (std::ostream& ostream, const PrintableObject& objeto);

};

#endif
