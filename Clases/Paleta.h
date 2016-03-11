#pragma once
#include "Suelo.h"
#include "ControllableActor.h"
#include "Nombres.h"

/**
 * \brief       Actor que cambia la dirección de la pelota.
 * \details     Es controlable mediante el teclado.
 *
 */
class Paleta : public ControllableActor
{
public:
        typedef enum
        {
            LEFT,
            RIGHT
        } action_t;

public:
    Paleta (void);
    ~Paleta (void);

    void do_action  (ControllableObject::action_t act, int magnitude);
    void hit        (Actor *who, int damage);

protected:
        Suelo *piel;
};
