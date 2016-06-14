///
/// @file SpriteGUI.cpp
/// @brief Fichero de implementaciÃƒÂ³n de la clase "SpriteGUI".
/// @author Juan Manuel Rico
/// @date Junio 2016
/// @version 1.0.0
///

#include "ActorGUI.hpp"

namespace gui
{

ActorGUI::ActorGUI ()
{
    // Llama al inicializador básico de la clase.
    this->init ();
};

ActorGUI::ActorGUI (Actor* actorEditar)
{
    // Inicializa en vacío.
    this->init ();

    // Asigna el actor dado por parámetro.
    this->setActor (actorEditar);

    // Actualiza las propiedades que obtiene del actor.
    this->update ();
};

ActorGUI::~ActorGUI ()
{
};

void ActorGUI::setActor (Actor* nuevoActor)
{
    actor = nuevoActor;
};

void ActorGUI::init ()
{
    // Inicializa las propiedades de la clase.
    this->setActor (NULL);
    nombre = new gcn::Label ("Sin actor");

    // Genera el esquema de controles.
    this->setFrameSize (4);
    this->setSize (100,100);

    // Añade los controles al contenedor que somos.
    this->add (nombre,10,10);
};

void ActorGUI::update ()
{
    this->setNombre (this->actor->getNombre());
};

void ActorGUI::setNombre (std::string& nuevoNombre)
{
    this->nombre->setCaption (nuevoNombre);
};

};