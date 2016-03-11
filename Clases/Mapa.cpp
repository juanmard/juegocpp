#include "Mapa.h"

/**
 * \brief   Constructor del mapa que carga del fichero de datos.
 */
Mapa::Mapa (DatFile &ficheroDatos):
nombre ("sin nombre"),
fichero (&ficheroDatos),
buffer ("")
{
}

/**
 * \brief   Constructor por omisión.
 */
Mapa::Mapa ():
nombre ("sin nombre"),
fichero (NULL),
buffer ("")
{
}

/**
 * \brief   Destructor que debe descargar de memoria el recurso.
 */
Mapa::~Mapa ()
{
//    delete &nombre;
//    delete &buffer;
}

/**
 * \brief   Se les pide a los actores su estructura en forma de cadena y se guarda en el buffer.
 */
void  Mapa::Read (ActorManager &manager)
{
  buffer.clear ();
  manager.rewind ();
  Actor *actual = manager.next ();
  while (actual != NULL)
  {
    buffer = buffer + " " + actual->getString ();
    actual = manager.next ();
  }
}

/**
 * \brief   
 */
void  Mapa::Save (const ActorManager &manager) const
{
}

/**
 * \brief   Obtiene el mapa completo en forma de cadena.
 */
string  Mapa::getString () const
{
  return buffer;
}
