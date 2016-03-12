#include "Nombres.h"

Nombres::Nombres(void)
{
}

Nombres::~Nombres(void)
{
}

/**
 * \brief   Obtiene cadena representativa del objeto.
 * \details Es un procedimiento global.
 */
ostream&  operator<< (ostream &o, const Nombres::codigo cod)
{
    o << Nombres::Imprimir(cod);
    return o;
}
