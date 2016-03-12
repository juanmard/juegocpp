///
/// @file Loro.cpp
/// @brief Fichero de la clase "Loro".
/// @author Juan Manuel Rico
/// @date Marzo 2010
/// @version 1.0.0
///

#include "Loro.h"

Loro::Loro ():
ControllableActor ()
{
};

Loro::Loro (Almacen &almacen)
{
    // ¡Cuidado! Esto falla si en el almacén no existe el bitmap que se pide.
    // Animación de la derecha.
    izquierda = new Sprite(this);
    izquierda->add_frame(almacen.getBitmap("sprite_042"), 0, 13, 10);
    izquierda->add_frame(almacen.getBitmap("sprite_043"), 0,  0, 10);
    izquierda->add_frame(almacen.getBitmap("sprite_044"), 0,  3, 10);
    izquierda->setMirror(true);

    // Animación de la izquierda.
    derecha = new Sprite(this);
    derecha->add_frame(almacen.getBitmap("sprite_042"), 0, 13, 10);
    derecha->add_frame(almacen.getBitmap("sprite_043"), 0,  0, 10);
    derecha->add_frame(almacen.getBitmap("sprite_044"), 0,  3, 10);

    // Animación de giro.
    giro = new Sprite(this);
    giro->add_frame(almacen.getBitmap("pre2_338"), 0, 0, 50);
    giro->add_frame(almacen.getBitmap("pre2_338"), 0, 0, 50);
    giro->add_frame(almacen.getBitmap("pre2_338"), 0, 0, 50);

    // Animación de inicio.
    set_actor_graphic (derecha);

    setCodigo (Nombres::herny);
    set_x(SCREEN_W/2);
    set_y(SCREEN_H/2);
    set_is_detected (true);
    set_collision_method(CollisionManager::PP_COLLISION);
    set_wh (36,26);
    estado = Loro::FLOTANDO;
};

void Loro::do_action (ControllableActor::action_t act, int magnitude)
{
    switch (estado)
    {
    case FLOTANDO:
        switch (act)
        {
        case LEFT:
            estado = VOLANDO_IZQ;
            set_actor_graphic(izquierda);
            x-=1;
            break;

        case RIGHT:
            estado = VOLANDO_DER;
            set_actor_graphic(derecha);
            x+=1;
            break;
        }
        break;

    case VOLANDO_IZQ:
        switch (act)
        {
        case LEFT:
            estado = VOLANDO_IZQ;
            set_actor_graphic(izquierda);
            x-=1;
            break;

        default:
            estado = FLOTANDO;
            break;
        }
        break;

    case VOLANDO_DER:
        switch (act)
        {
        case RIGHT:
            estado = VOLANDO_DER;
            set_actor_graphic(derecha);
            x+=1;
            break;

        case LEFT:
            estado = GIRANDO_IZQ;
            set_actor_graphic(giro);
            break;

        default:
            estado=FLOTANDO;
            break;
        }
        break;

        case GIRANDO_IZQ:
        case GIRANDO_DER:
            if (giro->is_free())
            {
                estado = FLOTANDO;
            }
            break;

    // Estado no contemplado por el autómata.
    default:
        break;
    };
};

void Loro::getNombre (std::string &strNombre) const
{
    strNombre = Nombres::Imprimir (nombre);
};

std::string Loro::getNombre () const
{
    return "Loro";
};

