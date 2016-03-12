#include "Nombres.h"

Nombres::Nombres(void)
{
}

Nombres::~Nombres(void)
{
}

/**
 * \brief   Obtiene cadena representativa del objeto como un insertor en el flujo.
 * \details Es un procedimiento global.
 */
ostream&  operator<< (ostream &os, const Nombres::codigo cod)
{
    os << Nombres::Imprimir(cod);
    return os;
}
