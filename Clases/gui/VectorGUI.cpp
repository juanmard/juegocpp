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
fontActive (new gcn::ImageFont("rpgfont_red.bmp", " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,!?-+/():;%&'{*#=[]\"ñáéíóú")),
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
    //cambiarComponente (mouseEvent)
    int& componente = x;
    if (mouseEvent.isControlPressed() && tipo==VectorGUI::dosComponentes) componente = y;
    if (mouseEvent.getButton()==gcn::MouseEvent::Left)
    {
        componente++;
    }
    if (mouseEvent.getButton()==gcn::MouseEvent::Right)
    {
        componente--;
    }
};

void VectorGUI::mouseWheelMovedUp (gcn::MouseEvent& mouseEvent)
{
    if (mouseEvent.isControlPressed())
    {
        x++;
    }
    else if (tipo==VectorGUI::dosComponentes)
    {
        y++;
    }
}

void VectorGUI::mouseWheelMovedDown (gcn::MouseEvent& mouseEvent)
{
    if (mouseEvent.isControlPressed())
    {
        x--;
    }
    else if (tipo==VectorGUI::dosComponentes)
    {
        y--;
    }
}

void VectorGUI::keyPressed(gcn::KeyEvent& keyEvent)
{
    unsigned int inc =1;
    if (keyEvent.isShiftPressed()) inc=10;
    switch (keyEvent.getKey().getValue())
    {
        case gcn::Key::Down:
            if (tipo==VectorGUI::dosComponentes) y += inc;
            break;
        case gcn::Key::Up:
            if (tipo==VectorGUI::dosComponentes) y -= inc;
            break;
        case gcn::Key::Left: x -= inc; break;
        case gcn::Key::Right: x += inc; break;
    }
};

//void VectorGUI::keyReleased (gcn::KeyEvent& keyEvent)
//{
//    lista->keyReleased (keyEvent);
//};
//

}
