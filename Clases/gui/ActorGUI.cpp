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
    
    // Se hace una pequeña prueba.
    this->setNombre("Mi actor");
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
    posicion = new gui::VectorGUI ();
    tamano = new gui::VectorGUI ();

    // Genera el esquema de controles.
    this->setFocusable (true);
    this->setFrameSize (4);
    this->setSize (160,200);

    // Añade los controles al contenedor que somos.
    this->add (nombre, 5, 5);
    this->add (posicion, 5, 20);
    this->add (tamano, 5, 35);

    // Añadimos los oyentes de entrada.
    addMouseListener(this);
};

void ActorGUI::update ()
{
    this->setNombre (actor->getNombre());
    this->setPosicion (actor->get_x(), actor->get_y());
    this->setTamano (actor->get_w(), actor->get_h());
};

void ActorGUI::setNombre (const std::string& nuevoNombre)
{
    this->nombre->setCaption (nuevoNombre);
};

void ActorGUI::setPosicion (int x, int y)
{
    //this->posicion->setXY(x,y);
};

void ActorGUI::setTamano (int w, int h)
{
    //this->posicion->setXY(x,y);
};

void ActorGUI::mouseEntered (gcn::MouseEvent& mouseEvent)
{
 //   this->distributeMovedEvent();
    this->setBaseColor(gcn::Color(255,0,0,128));
};

};