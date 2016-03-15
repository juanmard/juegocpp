///
/// @file ActorGraphic.cpp
/// @brief Fichero de implementación de la clase "ActorGraphic".
/// @author Juan Manuel Rico
/// @date Octubre 2015
/// @version 1.0.0
///

#include "ActorGraphic.h"

ActorGraphic::ActorGraphic ():
owner(NULL),
graph_free (true)
{
};

ActorGraphic::ActorGraphic (Actor* a):
owner(a),
graph_free (true)
{
};

ActorGraphic::~ActorGraphic ()
{
};

void ActorGraphic::update ()
{
};

void ActorGraphic::init ()
{
};

void ActorGraphic::draw (BITMAP* bmp)
{
};

void ActorGraphic::draw (int x, int y, BITMAP* bmp)
{
};

int ActorGraphic::get_w ()
{
    return 0;
};

int ActorGraphic::get_h ()
{
    return 0;
};

int ActorGraphic::get_x ()
{
    return (int)(owner->get_x());
};

int ActorGraphic::get_y ()
{
    return (int)(owner->get_y());
};

Mask* ActorGraphic::get_mask ()
{
    return NULL;
};

ActorGraphic* ActorGraphic::clone (Actor* propietario) const
{
    return new ActorGraphic();
};

std::string ActorGraphic::print () const
{
    std::ostringstream cadena;
    std::string propietario;

    owner->getNombre (propietario);
    cadena << "Propietario: " << propietario << "\n";
    return (cadena.str());
};

Actor* ActorGraphic::getActor () const
{
  return owner;
};

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

bool ActorGraphic::is_free ()
{
    return graph_free;
};

void ActorGraphic::set_free (bool estate)
{
    graph_free = estate;
};

