///
/// @file Loro.cpp
/// @brief Fichero de la clase "Loro".
/// @author Juan Manuel Rico
/// @date Marzo 2010
/// @version 1.0.0
///

#include "Loro.h"
#include "Keyboard.h"
#include "Control.h"

namespace fwg {

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
    izquierda->addFrame(almacen.get_bitmap("sprite_042"), 0, 13, 10);
    izquierda->addFrame(almacen.get_bitmap("sprite_043"), 0,  0, 10);
    izquierda->addFrame(almacen.get_bitmap("sprite_044"), 0,  3, 10);
    izquierda->setMirror(true);

    // Animación de la izquierda.
    derecha = new Sprite(this);
    derecha->addFrame(almacen.get_bitmap("sprite_042"), 0, 13, 10);
    derecha->addFrame(almacen.get_bitmap("sprite_043"), 0,  0, 10);
    derecha->addFrame(almacen.get_bitmap("sprite_044"), 0,  3, 10);
    derecha->setMirror(false);

    // Animación de giro.
    giro_der = new Sprite(this);
    giro_der->addFrame(almacen.get_bitmap("pre2_338"), 10, 0, 5);
    giro_der->setMirror (true);

    giro_izq = new Sprite(this);
    giro_izq->addFrame(almacen.get_bitmap("pre2_338"), 10, 0, 5);
    giro_izq->setMirror (false);

    setCodigo (Nombres::herny);
    setX (SCREEN_W/2);
    setY (SCREEN_H/2);
    setIsDetected (true);
    setCollisionMethod (CollisionManager::PP_COLLISION);
    setWH (36,26);

    // Animación de inicio.
    estado = FLOTANDO_DER;
    setActorGraphic (derecha);

    // Se crea el control necesario para las acciones del loro.
    control = new Control ();
    control->addActionName (LEFT,  "Izquierda");
    control->addActionName (RIGHT, "Derecha");
    control->addActionName (UP,    "Arriba");
    control->addActionName (DOWN,  "Abajo");
    control->addActionName (JUMP,  "Saltar");
    control->setOwner(this);

    // Se va a usar el teclado como único periférico para el loro.
    control->setActionPeripheral (UP,    kboard,  KEY_UP,    Peripheral::ON_PRESSING);
    control->setActionPeripheral (DOWN,  kboard,  KEY_DOWN,  Peripheral::ON_PRESSING);
    control->setActionPeripheral (LEFT,  kboard,  KEY_LEFT,  Peripheral::ON_PRESSING);
    control->setActionPeripheral (RIGHT, kboard,  KEY_RIGHT, Peripheral::ON_PRESSING);
    control->setActionPeripheral (JUMP,  kboard,  KEY_A,     Peripheral::ON_PRESS);
};

void Loro::doAction (ControllableActor::Action act, int magnitude)
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
            tiempoEstado = 10;
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
            tiempoEstado = 10;
            estado = GIRANDO_DER;
            setActorGraphic (giro_der);
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

void Loro::getNombre (std::string& strNombre) const
{
    strNombre = Nombres::Imprimir (nombre);
};

std::string Loro::get_nombre () const
{
    return "Loro";
};

Peripheral* Loro::getPeripheral () const
{
    return kboard;
};

void Loro::actualizar_estado ()
{
    switch (estado)
    {
        case GIRANDO_IZQ:
            estado = FLOTANDO_IZQ;
            setActorGraphic (izquierda);
            break;

        case GIRANDO_DER:
            estado = FLOTANDO_DER;
            setActorGraphic (derecha);
            break;

        case TROPEZANDO:
            estado = FLOTANDO_DER;
            setActorGraphic (derecha);
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
            x = who->getX () - getW () - 3;
            setActorGraphic (giro_der);
            break;

        case VOLANDO_IZQ:
        case FLOTANDO_IZQ:
            x = who->getX () + who->getW () + 3;
            setActorGraphic (giro_izq);
            break;
        }
        tiempoEstado = 50;
        estado = TROPEZANDO;
        break;
     default:
        break;
    };
};

}