///
/// @file VectorGUI.cpp
/// @brief Fichero de implementación de la clase "VectorGUI".
/// @author Juan Manuel Rico
/// @date Junio 2016
/// @version 1.0.0
///

#include <sstream>
#include "VectorGUI.hpp"
#include "guichan/imagefont.hpp"

namespace gui
{

VectorGUI::VectorGUI ():
gcn::Label(),
gcn::MouseListener(),
fontActive (new gcn::ImageFont("rpgfont_red.bmp", " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,!?-+/():;%&'{*#=[]\"")),
tipo (VectorGUI::dosComponentes),
x(*new int()),
y(*new int())
{
    setFrameSize (0);
    addMouseListener (this);
    setFocusable(true);
    addKeyListener (this);
};

VectorGUI::VectorGUI (int& _x, int& _y):
gcn::Label(),
gcn::MouseListener(),
fontActive (new gcn::ImageFont("rpgfont_red.bmp", " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,!?-+/():;%&'{*#=[]\"")),
tipo (VectorGUI::dosComponentes),
x (_x),
y (_y)
{
    setFrameSize (0);
    addMouseListener (this);
    setFocusable(true);
    addKeyListener (this);
};

VectorGUI::VectorGUI (int& _x):
gcn::Label(),
gcn::MouseListener(),
fontActive (new gcn::ImageFont("rpgfont_red.bmp", " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,!?-+/():;%&'{*#=[]\"")),
tipo (VectorGUI::unaComponente),
x (_x),
y(_x)
{
    setFrameSize (0);
    addMouseListener (this);
    setFocusable(true);
    addKeyListener (this);
};

void VectorGUI::setFontActive (gcn::Font* font)
{
    fontActive = font;
};

//void VectorGUI::draw (gcn::Graphics* graphics)
//{
//    gcn::Label::draw (graphics);
//};
//

void VectorGUI::logic ()
{
    // if (modificado)...
    // @todo: No hacerlo siempre, solo cuando se tenga que actualizar.
    std::ostringstream cadena;

    cadena << x;
    if (tipo == VectorGUI::dosComponentes)
    {
      cadena << ", " << y;
    }
    setCaption(cadena.str());
    adjustSize();
};

void VectorGUI::mouseEntered (gcn::MouseEvent& mouseEvent)
{
    if (fontActive) setFont (fontActive);
    requestFocus();
};

void VectorGUI::mouseExited (gcn::MouseEvent& mouseEvent)
{
    setFont (this->getParent()->getFont());
};

void VectorGUI::mousePressed (gcn::MouseEvent& mouseEvent)
{
    int* componente = &x;
    unsigned int inc = 1;
    
    if (mouseEvent.isShiftPressed()) inc = 10;
    if (mouseEvent.isControlPressed() && (tipo == VectorGUI::dosComponentes))
    {
        componente = &y; 
    }
    
    if (mouseEvent.getButton()==gcn::MouseEvent::Left)
    {
        (*componente)+=inc;
    }

    if (mouseEvent.getButton()==gcn::MouseEvent::Right)
    {
        (*componente)-=inc;
    }
    
    mouseEvent.consume ();
};

void VectorGUI::mouseWheelMovedUp (gcn::MouseEvent& mouseEvent)
{
    unsigned int inc = 1;
    if (mouseEvent.isShiftPressed()) inc = 10;
    if (mouseEvent.isControlPressed() && (tipo==VectorGUI::dosComponentes))
    {
        y+=inc;
    }
    else
    {
        x+=inc;
    }
}

void VectorGUI::mouseWheelMovedDown (gcn::MouseEvent& mouseEvent)
{
    unsigned int inc = 1;
    if (mouseEvent.isShiftPressed()) inc = 10;
    if (mouseEvent.isControlPressed() && (tipo==VectorGUI::dosComponentes))
    {
        y-=inc;
        this->setActionEventId ("decY");
        this->distributeActionEvent ();
    }
    else
    {
        x-=inc;
        this->setActionEventId ("decX");
        this->distributeActionEvent ();
    }
}

void VectorGUI::keyPressed(gcn::KeyEvent& keyEvent)
{
    unsigned int inc =1;
    if (keyEvent.isShiftPressed()) inc=10;
    switch (keyEvent.getKey().getValue())
    {
        case gcn::Key::Down:
            if (tipo==VectorGUI::dosComponentes)
            {
                y += inc;
                this->setActionEventId ("incY");
                this->distributeActionEvent ();
            }
            break;

        case gcn::Key::Up:
            if (tipo==VectorGUI::dosComponentes)
            {
                y -= inc;
                this->setActionEventId ("decY");
                this->distributeActionEvent ();
            }
            break;

        case gcn::Key::Left:
            x -= inc;
            this->setActionEventId ("decX");
            this->distributeActionEvent ();
            break;

        case gcn::Key::Right:
            x += inc;
            this->setActionEventId ("incX");
            this->distributeActionEvent ();
            break;

        case gcn::Key::LeftShift:
            //this->setPosition(100,100);
            break;

        default:
            break;
    }
    keyEvent.consume ();
};

//void VectorGUI::keyReleased (gcn::KeyEvent& keyEvent)
//{
//    lista->keyReleased (keyEvent);
//};
//

}
