///
/// @file ctlSprite.h
/// @brief Fichero de definición de la clase "ctlSprite".
/// @author Juan Manuel Rico
/// @date Mayo 2016
/// @version 1.0.0
///

#ifndef _CTLSPRITE_H_
#define _CTLSPRITE_H_

#include <vector>
#include "ctlObject.h"

class Sprite;

/// Objeto de control para la clase Sprite.
///
class ctlSprite : public ctlObject
{
public:
         ctlSprite (Sprite* sprite);
         ~ctlSprite ();
    void update ();

private:
    std::vector<ctlObject *> controles;
};

#endif