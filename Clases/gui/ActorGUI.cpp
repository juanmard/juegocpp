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
    //this->setNombre("Mi actor");
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
    bloque = new gcn::Container ();

    // Inicializa propiedades de widgets.
    // Contenedor (this).
    this->setFocusable (true);
    this->setFrameSize (2);
    this->setSize (160,200);

    // Posición.
    posicion->addActionListener (this);

    // Tamaño
    tamano->addActionListener (this);

    // Bloque
    bloque->setFrameSize (2);
    bloque->setSize (50,50);

    // Añade los controles al contenedor que somos.
    this->add (nombre,5,5);
    this->add (posicion,5,20);
    this->add (tamano,5,35);
    this->add (bloque,30,70);

    // Nos añadimos como oyentes de nuestros mensajes.
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
    this->nombre->adjustSize ();
};

void ActorGUI::setPosicion (int x, int y)
{
//    bloque->setPosition (x, y);
};

void ActorGUI::setTamano (int w, int h)
{
    bloque->setSize (w, h);
};

void ActorGUI::mouseEntered (gcn::MouseEvent& mouseEvent)
{
 //   this->distributeMovedEvent();
//    this->setBaseColor(gcn::Color(255,0,0,128));
};

void ActorGUI::action (const gcn::ActionEvent& actionEvent)
{
    int tmpX=0;
    int tmpY=0;

    // ¿Qué cambiamos?
    // @note Para poder utilizar los incrementos de más o menos una unidad definir un campo
    //       de incremento en el vector, de tal forma que se pueda hacer algo como:
    //       @code
    //            (VectorGUI*)(actionEvent.getSource())->getIncX();
    //       @endcode
    if (actionEvent.getId () == "incX") tmpX += 1;
    if (actionEvent.getId () == "decX") tmpX -= 1;
    if (actionEvent.getId () == "incY") tmpY += 1;
    if (actionEvent.getId () == "decY") tmpY -= 1;

    // ¿De qué vector viene el cambio?
    if (actionEvent.getSource() == posicion)
    {
        actor->set_x (actor->get_x()+tmpX);
        actor->set_y (actor->get_y()+tmpY);
    }
    if (actionEvent.getSource() == tamano)
    {
        actor->set_wh (actor->get_w()+tmpX, actor->get_h()+tmpY);
    }
    update ();
};

};