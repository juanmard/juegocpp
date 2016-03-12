#include <sstream>
#include "ActorGraphic.h"
#include "Actor.h"

ActorGraphic::ActorGraphic ():
owner(NULL)
{
};

ActorGraphic::ActorGraphic (Actor *a):
owner(a)
{
}

ActorGraphic::~ActorGraphic()
{
}

void ActorGraphic::update()
{
}

void ActorGraphic::init()
{
}

/** Dibuja la parte gráfica del actor en "bmp".
 *  
 *  Normalmente esta función es sobreescrita por el 
 *  hijo que hereda (Sprite, Bitmap, pixel...).
 *
 *  @param bmp - BITMAP en donde se dibuja la parte gráfica del actor.
 *
 */
void ActorGraphic::draw (BITMAP *bmp)
{
}

/** Dibuja la parte gráfica en la posición x, y en "bmp".
 *  
 */
void ActorGraphic::draw (int x, int y, BITMAP *bmp)
{
}

int ActorGraphic::get_w()
{
    return 0;
}

int ActorGraphic::get_h()
{
    return 0;
}

int ActorGraphic::get_x()
{
    return (int)(owner->get_x());
}

int ActorGraphic::get_y()
{
    return (int)(owner->get_y());
}

Mask * ActorGraphic::get_mask ()
{
    return NULL;
}

/**
 * \brief   Duplica la parte gráfica del actor y le asigna el nuevo propietario.
 */
ActorGraphic *  ActorGraphic::clone (Actor *propietario) const
{
	return NULL;
}

std::string ActorGraphic::getString () const
{
    ostringstream cadena;
    string propietario;

    owner->getNombre (propietario);
    cadena << "Propietario: " << propietario << "\n";
    return (cadena.str());
};

/**
 * \brief   Entrega el actor asociado a esta parte gráfica.
 */
Actor *  ActorGraphic::getActor () const
{
  return owner;
}

std::ifstream& ActorGraphic::leer (std::ifstream& ifs)
{
    return ifs;
};

std::ifstream& operator>> (std::ifstream& ifs, ActorGraphic& grafico)
{
    return grafico.leer(ifs);
};

void ActorGraphic::setOwner (Actor& propietario)
{
    if (!owner) this->owner = &propietario;
};

