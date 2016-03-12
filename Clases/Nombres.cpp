///
/// @file Nombres.cpp
/// @brief Fichero de implementación de la clase "Nombres".
/// @author Juan Manuel Rico
/// @date Noviembre 2015
/// @version
///      - 1.0.0 Noviembre 2015
///

#include "Nombres.h"

Nombres::Nombres ()
{
};

Nombres::~Nombres ()
{
};

std::ostream&  operator<< (std::ostream &os, const Nombres::codigo cod)
{
    os << Nombres::Imprimir(cod);
    return os;
};

