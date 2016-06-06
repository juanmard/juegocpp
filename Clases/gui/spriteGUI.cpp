///
/// @file SpriteGUI.cpp
/// @brief Fichero de implementación de la clase "SpriteGUI".
/// @author Juan Manuel Rico
/// @date Junio 2016
/// @version 1.0.0
///
#pragma once

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

    addMouseListener(this);
    addKeyListener(this);
//    addFocusListener(this);
};

SpriteGUI::SpriteGUI (Sprite* sprite_editar):
sprite(sprite_editar),
etiqueta(new gcn::Label ("GUI Sprite")),
add_frame (new gcn::Button ("Añadir")),
del_frame (new gcn::Button ("Borrar")),
imagen(new gcn::Icon ()),
rojo(new gcn::Color (255,0,0)),
verde(new gcn::Color (0,255,0)),
frame_actual (0)
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

    // Se añaden los controles a este contenedor.
    add (etiqueta, 5, 150);
    add (add_frame, 5, 5);
    add (del_frame, add_frame->getWidth()+10, 5);
    add (imagen,(add_frame->getWidth()+del_frame->getWidth())/2-imagen->getWidth()/2+add_frame->getX(),50);

    addMouseListener (this);
    addKeyListener (this);
//    addFocusListener(this);
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
};

void SpriteGUI::logic ()
{
  // // etiqueta->setCaption("logica, logica");
};

void SpriteGUI::adjustSize()
{
    etiqueta->adjustSize();
};

void SpriteGUI::mousePressed (gcn::MouseEvent& mouseEvent)
{
    etiqueta->setCaption("Ya me diste por fuera.");
    if (mouseEvent.getButton() == gcn::MouseEvent::Left)
    {
        etiqueta->setCaption("Ya me diste.");
        imagen->setBaseColor (*verde);
        if (mouseEvent.getSource() == imagen)
        {
            imagen->setBaseColor (*rojo);

            // Prueba de información.
            etiqueta->setCaption(sprite->getString());
            //etiqueta->setCaption (sprite->print());

            // Prueba de frames.
            frame_actual ++;
            if (frame_actual >= sprite->getNumFrames ()) {frame_actual = 0;}
            imagen->setImage (sprite->getImage(frame_actual));
        }
        mouseEvent.consume ();
    }
    etiqueta->adjustSize();
};

void SpriteGUI::mouseEntered (gcn::MouseEvent& mouseEvent)
{
    setBaseColor (*verde);
};

void SpriteGUI::mouseExited (gcn::MouseEvent& mouseEvent)
{
    setBaseColor (*rojo);
};

void SpriteGUI::keyPressed(gcn::KeyEvent& keyEvent)
{
    gcn::Key key = keyEvent.getKey();

    etiqueta->setCaption ("Tecla va");
    if (key.getValue() == gcn::Key::PageUp)
    {
        frame_actual--;
        if (frame_actual < 0) frame_actual = 0;
        distributeActionEvent();
        keyEvent.consume();
    }
    if (key.getValue() == gcn::Key::PageDown)
    {
        frame_actual++;
        if (frame_actual >= sprite->getNumFrames ()) frame_actual = 0;
        distributeActionEvent();
        keyEvent.consume();
    }
};

void SpriteGUI::keyReleased (gcn::KeyEvent& keyEvent)
{
    //Key key = keyEvent.getKey();

    //if (key.getValue() == gcn::Key::Left
    //        || key.getValue() == gcn::Key::Right)
    //{
    //    distributeActionEvent();
    //    keyEvent.consume();
    //}
};

}
