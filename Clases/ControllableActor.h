
#ifndef CONTROLLABLEACTOR_H
#define CONTROLLABLEACTOR_H

#include "Actor.h"
#include "ControllableObject.h"

class ControllableActor : public Actor, public ControllableObject
{
public:
    // Constructor de copia.
    ControllableActor   (const ControllableActor &copia):Actor(copia),ControllableObject(copia){};
        
    // Constructor por omisión.
    ControllableActor (){};
};

#endif
