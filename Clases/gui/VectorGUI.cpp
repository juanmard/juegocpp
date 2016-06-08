///
/// @file VectorGUI.cpp
/// @brief Fichero de implementación de la clase "VectorGUI".
/// @author Juan Manuel Rico
/// @date Junio 2016
/// @version 1.0.0
///

#include <sstream>
#include "VectorGUI.hpp"

namespace gui
{

VectorGUI::VectorGUI (int& _x, int& _y):
gcn::Label(),
gcn::MouseListener(),
x (_x),
y (_y)
{
    setFrameSize (1);
    addMouseListener (this);
};

//void VectorGUI::draw (gcn::Graphics* graphics)
//{
//    gcn::Label::draw (graphics);
//};
//

void VectorGUI::logic ()
{
    std::ostringstream cadena;

    cadena << x << ", " << y;
    setCaption(cadena.str());
    adjustSize();
};

void VectorGUI::mouseEntered (gcn::MouseEvent& mouseEvent)
{
    this->setBaseColor (gcn::Color (255,0,0));
    this->setFrameSize (1);
};

void VectorGUI::mouseExited (gcn::MouseEvent& mouseEvent)
{
    this->setBaseColor (getParent()->getBaseColor());
    this->setFrameSize (0);
};

void VectorGUI::mousePressed (gcn::MouseEvent& mouseEvent)
{
    if (mouseEvent.isShiftPressed())
    {
        x++;
    }
    else
    {
        y++;
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
        x++;
    }
    else
    {
        y++;
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
