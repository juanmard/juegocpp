///
/// @file MenuGUI.cpp
/// @brief Fichero de implementación de la clase "MenuGUI".
/// @author Juan Manuel Rico
/// @date Junio 2016
/// @version 1.0.0
///

#include "MenuGUI.hpp"

namespace gui
{

MenuGUI::MenuGUI ():
items (new gui::Items ()),
etiqueta(new gcn::Label ("Etiqueta prueba..."))
{
    this->setListModel (items);
    this->addSelectionListener(this);
    //this->setSelectionColor (gcn::Color(255,0,0));
};


void MenuGUI::draw (gcn::Graphics* graphics)
{
    gcn::ListBox::draw (graphics);
    etiqueta->draw (graphics);
};

//void MenuGUI::logic ()
//{
// // etiqueta->setCaption("logica, logica");
//};

void MenuGUI::valueChanged (const gcn::SelectionEvent& event)
{
    this->setSize (getWidth()+5, getHeight());
    etiqueta->setCaption(this->items->getElementAt(this->getSelected ()));
};


//void MenuGUI::mousePressed (gcn::MouseEvent& mouseEvent)
//{
//    lista->mousePressed (mouseEvent);
//};

//
//void SpriteGUI::mouseEntered (gcn::MouseEvent& mouseEvent)
//{
//};
//
//void SpriteGUI::mouseExited (gcn::MouseEvent& mouseEvent)
//{
//};
//
//void MenuGUI::keyPressed(gcn::KeyEvent& keyEvent)
//{
//    lista->keyPressed (keyEvent);
//};
//
//void MenuGUI::keyReleased (gcn::KeyEvent& keyEvent)
//{
//    lista->keyReleased (keyEvent);
//};
//
}
