///
/// @file ReadableObject.h
/// @brief Fichero de definición de la clase "ReadableObject".
/// @author Juan Manuel Rico
/// @date Noviembre 2015
/// @version 1.0.0
///

#ifndef _READABLEOBJECT_
#define _READABLEOBJECT_

#include <string>
#include <sstream>
#include <istream>

/// Define el comportamiento de un objeto leible en modo texto.
///
/// Se trata de leer las características de un objeto a partir de una cadena de caracteres que lo representa.
/// Se puede ver como la clase complementaria a PrintableObject.
///
class ReadableObject
{
private:
    /// Lee las características del objeto desde una cadena de texto que lo representa.
    /// @param cadena  La cadena que representa al objeto y de donde se pueden extraer los datos del objeto.
    /// @return Cantidad de caracteres leidos de la cadena.
    ///
    virtual unsigned int read (const std::string& cadena) = 0;

public:
    /// Constructor.
    ///
    ReadableObject ();

    /// Destructor.
    ///
    virtual ~ReadableObject ();

    /// Sobrecarga de operador.
    /// @param cadena  Cadena donde está guardada la representación del objeto.
    /// @param objeto  Referencia al objeto del que se quiere extraer la representación y ser modificado.
    /// @return Cadena que se utiliza para encadenar llamadas al operador.
    ///
    friend const std::string& operator>> (const std::string& cadena, ReadableObject& objeto); 

    /// Sobrecarga de operador.
    /// @param isstream  Canal de cadena (string-stream) desde donde obtener la representación del objeto.
    /// @param objeto  Referencia al objeto que se quiere modificar con los datos del canal.
    /// @return Canal de cadena (string-stream) para continuar el volcado si es necesario.
    ///
    friend std::istringstream& operator>> (std::istringstream& iss, ReadableObject& objeto);

    /// Sobrecarga de operador.
    /// @param istream  Canal de entrada desde donde obtener la representación del objeto.
    /// @param objeto  Referencia al objeto que se quiere modificar con los datos del canal.
    /// @return Canal de entrada para continuar el volcado si es necesario.
    ///
    friend std::istream& operator>> (std::istream& is, ReadableObject& objeto);
};

#endif
