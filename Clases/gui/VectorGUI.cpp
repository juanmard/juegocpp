///
/// @file VectorGUI.cpp
/// @brief Fichero de implementación de la clase "VectorGUI".
/// @author Juan Manuel Rico
/// @date Junio 2016
/// @version 1.0.0
///

#include <sstream>
#include "VectorGUI.hpp"
#include "guichan\imagefont.hpp"

namespace gui
{

VectorGUI::VectorGUI (int& _x, int& _y):
gcn::Label(),
gcn::MouseListener(),
fontActive (new gcn::ImageFont("rpgfont_red.bmp", " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,!?-+/():;%&'{*#=[]\"ñáéíóú")),
x (_x),
y (_y)
{
    setFrameSize (1);
    addMouseListener (this);
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

    cadena << x << ", " << y;
    setCaption(cadena.str());
    adjustSize();
};

void VectorGUI::mouseEntered (gcn::MouseEvent& mouseEvent)
{
    if (fontActive) setFont (fontActive);
};

void VectorGUI::mouseExited (gcn::MouseEvent& mouseEvent)
{
    setFont (this->getParent()->getFont());
};

void VectorGUI::mousePressed (gcn::MouseEvent& mouseEvent)
{
    if (mouseEvent.getButton()==gcn::MouseEvent::Left)
    {
        x++;
    }
    if (mouseEvent.getButton()==gcn::MouseEvent::Right)
    {
        x--;
    }
};

void VectorGUI::mouseWheelMovedUp (gcn::MouseEvent& mouseEvent)
{
    if (mouseEvent.isShiftPressed())
    {
        x++;
    }
    else
    {
        y++;
    }
}

void VectorGUI::mouseWheelMovedDown (gcn::MouseEvent& mouseEvent)
{
    if (mouseEvent.isShiftPressed())
    {
        x--;
    }
    else
    {
        y--;
    }
}
//void VectorGUI::keyPressed(gcn::KeyEvent& keyEvent)
//{
//    lista->keyPressed (keyEvent);
//};
//
//void VectorGUI::keyReleased (gcn::KeyEvent& keyEvent)
//{
//    lista->keyReleased (keyEvent);
//};
//

}
