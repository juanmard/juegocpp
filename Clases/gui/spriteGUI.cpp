///
///
///
#include "spriteGUI.hpp"

#include <guichan/exception.hpp>
#include <guichan/font.hpp>
#include <guichan/graphics.hpp>
#include <guichan/widgets/label.hpp>

namespace gui
{

spriteGUI::spriteGUI ():
sprite(NULL),
etiqueta(new gcn::Label("Prueba 1")),
imagen(new gcn::Icon())
{
    this->add(etiqueta,0,0);
    this->add(imagen,10,10);
    this->setPosition (10,10);
};

spriteGUI::spriteGUI (const std::string& caption):
sprite(NULL),
etiqueta(new gcn::Label (caption)),
imagen(new gcn::Icon())
{
    setOpaque(false);
    setWidth(200);
    setHeight(100);
};

const std::string &spriteGUI::getCaption () const
{
    return etiqueta->getCaption ();
};

void spriteGUI::setCaption (const std::string& caption)
{
    etiqueta->setCaption (caption);
};

void spriteGUI::setAlignment (gcn::Graphics::Alignment alignment)
{
    etiqueta->setAlignment (alignment);
};

gcn::Graphics::Alignment spriteGUI::getAlignment() const
{
    return etiqueta->getAlignment ();
};

void spriteGUI::draw (gcn::Graphics* graphics)
{
//    etiqueta->setBackgroundColor (*new gcn::Color(255,0,0));
//    etiqueta->drawFrame(graphics);
      graphics->setColor (*new gcn::Color (255,0,0));
      graphics->drawLine (0, 0, getWidth() - 1, 0);
      graphics->drawLine (0, 1, 0, getHeight() - 1);
      graphics->drawLine (getWidth() - 1, 1, getWidth() - 1, getHeight() - 1);
      graphics->drawLine (1, getHeight() - 1, getWidth() - 1, getHeight() - 1);



    Container::draw (graphics);
    etiqueta->draw (graphics);
    imagen->draw (graphics);
};

void spriteGUI::adjustSize()
{
    etiqueta->adjustSize();
};



}
