
#ifndef CONTROLLABLEACTOR_H
#define CONTROLLABLEACTOR_H

#include "Actor.h"
#include "ControllableObject.h"

///@todo Limpiar los comentarios documentables de estas clases y utilizar
///      la clase para ordenar y asumir toda la rama de Objetos Controlables (ControllableObject).

class ControllableActor : public Actor, public ControllableObject
{
public:
    // Constructor de copia.
    ControllableActor   (const ControllableActor &copia):Actor(copia),ControllableObject(copia){};
        
    // Constructor por omisión.
    ControllableActor (){};
};

#endif
