///
/// @file Loro.cpp
/// @brief Fichero de la clase "Loro".
/// @author Juan Manuel Rico
/// @date Marzo 2010
/// @version 1.0.0
///

#include "Loro.h"
#include "ControllableActor.h"
#include "Almacen.h"
#include "Sprite.h"

Loro::Loro ():
ControllableActor ()
{
};

Loro::Loro (Almacen &almacen)
{
    // ¡Cuidado! Esto falla si en el almacén no existe el bitmap que se pide.
    Sprite *skin = new Sprite(this);    
    skin->add_frame(almacen.getBitmap("sprite_042"), 0, 13, 10);
    skin->add_frame(almacen.getBitmap("sprite_043"), 0,  0, 10);
    skin->add_frame(almacen.getBitmap("sprite_044"), 0,  3, 10);
    set_actor_graphic (skin);

    setCodigo (Nombres::herny);
    set_x(SCREEN_W/2);
    set_y(SCREEN_H/2);
    set_is_detected (true);
    set_collision_method(CollisionManager::PP_COLLISION);
    set_wh (36,26);
};

void Loro::do_action (ControllableActor::action_t act, int magnitude)
{
    switch (act)
    {
        case DOWN:  y+=1; break;
        case UP:    y-=1; break;
        case LEFT:
          x-=1;
          static_cast<Sprite *>(agraph)->setMirror (true);
          break;
        case RIGHT:
          x+=1;
          static_cast<Sprite *>(agraph)->setMirror (false);
          break;
        case JUMP:  y-=4; break;
    }
};

void Loro::getNombre (string &strNombre) const
{
    strNombre = Nombres::Imprimir (nombre);
};
