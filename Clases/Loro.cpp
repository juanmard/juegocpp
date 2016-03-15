///
/// @file Loro.cpp
/// @brief Fichero de la clase "Loro".
/// @author Juan Manuel Rico
/// @date Marzo 2010
/// @version 1.0.0
///

#include "Loro.h"
#include "Keyboard.h"

Loro::Loro ():
ControllableActor (),
kboard (NULL)
{
};

Loro::Loro (Almacen &almacen):
ControllableActor (),
kboard (new Keyboard())
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
    derecha->setMirror(false);

    // Animación de giro.
    giro_der = new Sprite(this);
    giro_der->add_frame(almacen.getBitmap("pre2_338"), 10, 0, 5);
    giro_der->setMirror (true);

    giro_izq = new Sprite(this);
    giro_izq->add_frame(almacen.getBitmap("pre2_338"), 10, 0, 5);
    giro_izq->setMirror (false);

    setCodigo (Nombres::herny);
    set_x(SCREEN_W/2);
    set_y(SCREEN_H/2);
    set_is_detected (true);
    set_collision_method(CollisionManager::PP_COLLISION);
    set_wh (36,26);

    // Animación de inicio.
    estado = FLOTANDO_DER;
    set_actor_graphic (derecha);

    // Se crea el control necesario para las acciones del loro.
    control = new Control ();
    control->add_action_name (LEFT,  "Izquierda");
    control->add_action_name (RIGHT, "Derecha");
    control->add_action_name (UP,    "Arriba");
    control->add_action_name (DOWN,  "Abajo");
    control->add_action_name (JUMP,  "Saltar");
    control->set_owner(this);

    // Se va a usar el teclado como único periférico para el loro.
    control->set_actionperipheral (UP,    kboard,  KEY_UP,    Peripheral::ON_PRESSING);
    control->set_actionperipheral (DOWN,  kboard,  KEY_DOWN,  Peripheral::ON_PRESSING);
    control->set_actionperipheral (LEFT,  kboard,  KEY_LEFT,  Peripheral::ON_PRESSING);
    control->set_actionperipheral (RIGHT, kboard,  KEY_RIGHT, Peripheral::ON_PRESSING);
    control->set_actionperipheral (JUMP,  kboard,  KEY_A,     Peripheral::ON_PRESS);
};

void Loro::do_action (ControllableActor::action_t act, int magnitude)
{
    switch(act)
    {
    case UP:
        y-=1;
        break;

    case DOWN:
        y+=1;
        break;

    case LEFT:
        switch (estado)
        {
        case FLOTANDO_DER:
            tiempo_estado = 10;
            estado = GIRANDO_IZQ;
            break;

        case FLOTANDO_IZQ:
            x-=1;
            break;
        }
        break;

    case RIGHT:
        switch (estado)
        {
        case FLOTANDO_IZQ:
            tiempo_estado = 10;
            estado = GIRANDO_DER;
            set_actor_graphic (giro_der);
            break;

        case FLOTANDO_DER:
            estado = FLOTANDO_DER;
            x+=1;
            break;
        }
        break;

    case JUMP:
        y-=10;
        x+=10;
        break;

    default:
        break;
    }
};

void Loro::getNombre (std::string &strNombre) const
{
    strNombre = Nombres::Imprimir (nombre);
};

std::string Loro::getNombre () const
{
    return "Loro";
};

Peripheral* Loro::get_peripheral () const
{
    return kboard;
};

void Loro::actualizar_estado ()
{
    switch (estado)
    {
        case GIRANDO_IZQ:
            estado=FLOTANDO_IZQ;
            set_actor_graphic (izquierda);
            break;

        case GIRANDO_DER:
            estado=FLOTANDO_DER;
            set_actor_graphic (derecha);
            break;

        case TROPEZANDO:
            estado=FLOTANDO_DER;
            set_actor_graphic (derecha);
            break;
    };
};

void Loro::hit (Actor* who, int damage)
{
    switch (who->getCodigo())
    {
    case Nombres::ladrillo:
        switch (estado)
        {
        case VOLANDO_DER:
        case FLOTANDO_DER:
            x = who->get_x() - get_w() - 3;
            set_actor_graphic (giro_der);
            break;

        case VOLANDO_IZQ:
        case FLOTANDO_IZQ:
            x = who->get_x() + who->get_w() + 3;
            set_actor_graphic (giro_izq);
            break;
        }
        tiempo_estado = 50;
        estado = TROPEZANDO;
        break;
    };
};

