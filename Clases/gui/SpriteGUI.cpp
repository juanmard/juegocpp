﻿///
/// @file SpriteGUI.cpp
/// @brief Fichero de implementaciÃƒÂ³n de la clase "SpriteGUI".
/// @author Juan Manuel Rico
/// @date Junio 2016
/// @version 1.0.0
///

#include "SpriteGUI.hpp"
#include <sstream>
#include <guichan/exception.hpp>
#include <guichan/font.hpp>
#include <guichan/imagefont.hpp>
#include <guichan/graphics.hpp>
#include <guichan/widgets/label.hpp>
#include <guichan/allegro/allegroimage.hpp>

namespace gui
{

SpriteGUI::SpriteGUI (Sprite* sprite_editar):
sprite(sprite_editar),
etiqueta(new gcn::Label ("GUI Sprite")),
add_frame (new gcn::Button ("Añadir")),
del_frame (new gcn::Button ("Borrar")),
fotogramas (new gcn::Container()),
imagenAnterior(new gcn::Icon ()),
imagenActual(new gcn::Icon ()),
imagenPosterior(new gcn::Icon ()),
rojo(new gcn::Color (255,0,0)),
verde(new gcn::Color (0,255,0)),
frame_actual (0),
numFrame (new gcn::Label("Frame:")),
pos (new gcn::Label("Posición:")),
ticks (new gcn::Label("Ticks:")),
prb_x(0), prb_y(0),
vector_pos (new gui::VectorGUI(prb_x, prb_y)),
prueba_menu (new gui::MenuGUI())
{
    setOpaque (true);
    setWidth (600);
    setHeight (180);
    setFrameSize (1);

    // Se añaden las imágenes de los frames.
    add (fotogramas,20,20);
    fotogramas->setFrameSize(1);
    fotogramas->setSize(200,150);
    imagenActual->setWidth (200);
    imagenActual->setHeight (30);
    //imagenAnterior->setImage (sprite->getImage(frame_actual-1));
    imagenActual->setImage (sprite->getImage(frame_actual));
    //imagenPosterior->setImage (sprite->getImage(frame_actual+1));
    fotogramas->add (imagenActual,50,50);


    // Se aÃ±aden los controles a este contenedor.
    add (etiqueta, 5, 150);
    add (add_frame, 5, 5);
    add (del_frame, add_frame->getWidth()+10, 5);

    // Se aÃ±ade un menÃº de prueba.
    prueba_menu->setFont(new gcn::ImageFont ("fixedfont.bmp", " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789ñ"));
    prueba_menu->setVisible (false);
    prueba_menu->addItem (new gui::Item ("Añadir"));
    prueba_menu->addItem (new gui::Item ("Recortar"));
    prueba_menu->addItem (new gui::Item ("Pegar"));
    prueba_menu->addItem (new gui::Item ("Borrar"));
    prueba_menu->adjustSize ();
    add (prueba_menu, 0, 0);

    // Se aÃ±aden etiquetas de las propiedades del frame actual.
    unsigned int widthHeight = this->getFont()->getHeight();
    add (this->numFrame, 200, 10);
    add (this->pos,      200, 10 + 1*(widthHeight));
    add (this->ticks,    200, 10 + 2*(widthHeight));
    numFrame->setWidth (200);
    pos->setWidth (200);
    ticks->setWidth (200);
    numFrame->setAlignment (gcn::Graphics::Right);
    pos->setAlignment (gcn::Graphics::Right);
    ticks->setAlignment (gcn::Graphics::Right);

    add (vector_pos, pos->getX()+pos->getWidth()+10, pos->getY());
    add (new gui::VectorGUI(prb_x), ticks->getX()+ticks->getWidth()+10, ticks->getY());

    // Nos aÃ±adimos a los oyentes de los mensajes del ratÃ³n y el teclado.
    addMouseListener (this);
    addKeyListener (this);

    // Nos aÃ±adimos a los oyentes de las acciones del menÃº de prueba.
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
    // Se dibuja el sprite.
    //this->etiqueta->_draw (graphics);
    //this->fotogramas->_draw (graphics);
    //this->imagenActual->_draw (graphics);
    Container::draw (graphics);
};

void SpriteGUI::logic ()
{
  // // etiqueta->setCaption("logica, logica");
  imagenActual->setImage (sprite->getImage(frame_actual));
  imagenActual->setPosition (prb_x, prb_y);

  // Se actualiza los valores... esto debe estar actualizado por evento desde el vector que lo modifica.
  //sprite->setXFrame(frame_actual, prb_x);
  //sprite->setYFrame(frame_actual, prb_y);

  // Si hay cambios en el nÃºmero de frame que se muestra,
  // actualizar la etiqueta.
  // if (actualizarFrame)
  //{
  std::ostringstream cadena;

  cadena << "Frame " << frame_actual;
  this->numFrame->setCaption(cadena.str());
  // actualizarFrame = false;
  //}
};

void SpriteGUI::adjustSize()
{
    etiqueta->adjustSize();
};

void SpriteGUI::mousePressed (gcn::MouseEvent& mouseEvent)
{
    if (mouseEvent.getButton () == gcn::MouseEvent::Right)
    {
        // Se muestra el menÃƒÂº de prueba.
        // @todo... hacer mejor...
        if (this->getWidgetAt (mouseEvent.getX(),mouseEvent.getY())==this->imagenActual)
        {
            prueba_menu->show (mouseEvent.getX(), mouseEvent.getY());
        }
    };

    //etiqueta->setCaption("Ya me diste por fuera.");
    if (mouseEvent.getButton() == gcn::MouseEvent::Left)
    {
        //etiqueta->setCaption("Ya me diste.");
        imagenActual->setBaseColor (*verde);
        if (mouseEvent.getSource() == imagenActual)
        {
            imagenActual->setBaseColor (*rojo);

            // Prueba de informaciÃƒÂ³n.
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
    ///setBaseColor (*verde);
};

void SpriteGUI::mouseExited (gcn::MouseEvent& mouseEvent)
{
    ///setBaseColor (*rojo);
};

void SpriteGUI::keyPressed(gcn::KeyEvent& keyEvent)
{
    if (!keyEvent.isConsumed())
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
    }
};

void SpriteGUI::keyReleased (gcn::KeyEvent& keyEvent)
{
    if (!keyEvent.isConsumed())
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
    }
};

void SpriteGUI::action (const gcn::ActionEvent& actionEvent)
{
    if (actionEvent.getId()=="menu")
    {
        // Si la acciÃƒÂ³n la produce el menÃƒÂº de prueba mostramos su item en la etiqueta.
        etiqueta->setCaption (prueba_menu->getElementAt(prueba_menu->getSelected()));
        if (etiqueta->getCaption() == "Item 2")
        {
            etiqueta->setCaption ("Elegimos el menú 2.");
        }
        etiqueta->adjustSize ();
    };
};

}