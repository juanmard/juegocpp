///
/// @file SpriteGUI.cpp
/// @brief Fichero de implementaci�n de la clase "SpriteGUI".
/// @author Juan Manuel Rico
/// @date Junio 2016
/// @version 1.0.0
///

#include "SpriteGUI.hpp"
#include <guichan/exception.hpp>
#include <guichan/font.hpp>
#include <guichan/graphics.hpp>
#include <guichan/widgets/label.hpp>
#include <guichan/allegro/allegroimage.hpp>

namespace gui
{

SpriteGUI::SpriteGUI ():
sprite(NULL),
etiqueta(new gcn::Label()),
imagen(new gcn::Icon()),
rojo(new gcn::Color (255,0,0)),
verde(new gcn::Color (0,255,0))
{
    this->add(etiqueta,0,0);
    this->add(imagen,10,10);
    this->setPosition (10,10);

    addMouseListener (this);
    addKeyListener (this);
    addActionListener (this);
//    addFocusListener(this);
};

SpriteGUI::SpriteGUI (Sprite* sprite_editar):
sprite(sprite_editar),
etiqueta(new gcn::Label ("GUI Sprite")),
add_frame (new gcn::Button ("A�adir")),
del_frame (new gcn::Button ("Borrar")),
imagen(new gcn::Icon ()),
rojo(new gcn::Color (255,0,0)),
verde(new gcn::Color (0,255,0)),
frame_actual (0),
prueba_menu (new MenuGUI())
{
    setOpaque (false);
    setWidth (600);
    setHeight (180);
    setBaseColor (*rojo);
    setFrameSize (1);

    // Se toma la imagen del frame actual.
    imagen->setFrameSize (2);
    imagen->setWidth (200);
    imagen->setHeight (30);
    imagen->setBaseColor (*verde);
    imagen->setImage (sprite->getImage(frame_actual));

    // Se a�aden los controles a este contenedor.
    add (etiqueta, 5, 150);
    add (add_frame, 5, 5);
    add (del_frame, add_frame->getWidth()+10, 5);
    add (imagen,(add_frame->getWidth()+del_frame->getWidth())/2-imagen->getWidth()/2+add_frame->getX(),50);
    prueba_menu->setHeight (100);
    prueba_menu->setWidth (100);
    add (prueba_menu, 100, 100);
    prueba_menu->setVisible (false);

    // Nos a�adimos a los oyentes de los mensajes del rat�n y el teclado.
    addMouseListener (this);
    addKeyListener (this);

    // Nos a�adimos a los oyentes de las acciones del men� de prueba.
    prueba_menu->addActionListener (this);
};

const std::string &SpriteGUI::getCaption () const
{
    return etiqueta->getCaption ();
};

void SpriteGUI::setCaption (const std::string& caption)
{
    etiqueta->setCaption (caption);
};

void SpriteGUI::setAlignment (gcn::Graphics::Alignment alignment)
{
    etiqueta->setAlignment (alignment);
};

gcn::Graphics::Alignment SpriteGUI::getAlignment() const
{
    return etiqueta->getAlignment ();
};

void SpriteGUI::draw (gcn::Graphics* graphics)
{
    Container::draw (graphics);
//    prueba_menu->draw (graphics);
};

void SpriteGUI::logic ()
{
  // // etiqueta->setCaption("logica, logica");
  imagen->setImage (sprite->getImage(frame_actual));
};

void SpriteGUI::adjustSize()
{
    etiqueta->adjustSize();
};

void SpriteGUI::mousePressed (gcn::MouseEvent& mouseEvent)
{
    if (mouseEvent.getButton () == gcn::MouseEvent::Right)
    {
        // Se muestra el men� de prueba.
        prueba_menu->setPosition (mouseEvent.getX (), mouseEvent.getY ());
        prueba_menu->setVisible (true);
    };

    //etiqueta->setCaption("Ya me diste por fuera.");
    if (mouseEvent.getButton() == gcn::MouseEvent::Left)
    {
        //etiqueta->setCaption("Ya me diste.");
        imagen->setBaseColor (*verde);
        if (mouseEvent.getSource() == imagen)
        {
            imagen->setBaseColor (*rojo);

            // Prueba de informaci�n.
            etiqueta->setCaption(sprite->getString());
            //etiqueta->setCaption (sprite->print());

            // Prueba de frames.
            frame_actual ++;
            if (frame_actual >= sprite->getNumFrames ()) {frame_actual = 0;}
        }
        mouseEvent.consume ();
    }
    etiqueta->adjustSize();
};

void SpriteGUI::mouseEntered (gcn::MouseEvent& mouseEvent)
{
    setBaseColor (*verde);
//    prueba_menu->setVisible (true);
};

void SpriteGUI::mouseExited (gcn::MouseEvent& mouseEvent)
{
    setBaseColor (*rojo);
//    prueba_menu->setVisible (false);
};

void SpriteGUI::keyPressed(gcn::KeyEvent& keyEvent)
{
    gcn::Key key = keyEvent.getKey();

    if (key.getValue() == gcn::Key::Left)
    {
        etiqueta->setCaption ("Izquierda pulsada");
        etiqueta->adjustSize();
        keyEvent.consume();
    }
    if (key.getValue() == gcn::Key::Right)
    {
        etiqueta->setCaption ("Derecha pulsada");
        etiqueta->adjustSize();
        keyEvent.consume();
    }
};

void SpriteGUI::keyReleased (gcn::KeyEvent& keyEvent)
{
    gcn::Key key = keyEvent.getKey();

    if (key.getValue() == gcn::Key::Left)
    {
        if (frame_actual == 0)
        {
            frame_actual = sprite->getNumFrames ()-1;
        }
        else
        {
            frame_actual--;
        }
        distributeActionEvent();
        etiqueta->setCaption ("Izquierda soltada");
    }
    if (key.getValue() == gcn::Key::Right)
    {
        frame_actual++;
        if (frame_actual >= sprite->getNumFrames ()) frame_actual = 0;
        etiqueta->setCaption ("Derecha soltada");
    }
};

void SpriteGUI::action (const gcn::ActionEvent& actionEvent)
{
    if (actionEvent.getId()=="menu")
    {
        // Si la acci�n la produce el men� de prueba mostramos su item en la etiqueta.
        etiqueta->setCaption (prueba_menu->getElementAt(prueba_menu->getSelected()));
        etiqueta->adjustSize ();
    };
};

}