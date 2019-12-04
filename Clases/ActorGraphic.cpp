///
/// @file ActorGraphic.cpp
/// @brief Fichero de implementación de la clase "ActorGraphic".
/// @author Juan Manuel Rico
/// @date Octubre 2015
/// @version 1.0.0
///

#include "ActorGraphic.h"
#include "Actor.h"

namespace fwg {
    
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

unsigned int ActorGraphic::get_w () const
{
    return 0;
};

unsigned int ActorGraphic::get_h () const
{
    return 0;
};

int ActorGraphic::get_x () const
{
    return (int)(owner->get_x());
};

int ActorGraphic::get_y () const
{
    return (int)(owner->get_y());
};

Mask* ActorGraphic::get_mask () const
{
    return NULL;
};

ActorGraphic* ActorGraphic::clone (Actor* propietario) const
{
    return new ActorGraphic();
};

/// @todo Agrupar los valores de posición y dimensiones en un bloque,
///       para así poder imprimir directamente en el formato del bloque.
std::string& ActorGraphic::print () const
{
    std::ostringstream cadena;

    cadena << "Propietario: " << owner->get_nombre() << std::endl;
    cadena << "Posición: [" << get_x() << ", " << get_y() << "]" << std::endl;
    cadena << "Dimensiones: [" << get_h() << ", " << get_w() << "]" << std::endl;
    return *new std::string(cadena.str());
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

}