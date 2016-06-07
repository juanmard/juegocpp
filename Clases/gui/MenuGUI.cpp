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
etiqueta(new gcn::Label ("Etiqueta prueba..."))
{
    this->setFocusable (true);
    this->setListModel (this);
    this->addSelectionListener (this);
    //this->setSelectionColor (gcn::Color(255,0,0));
    this->setActionEventId ("menu");
    etiqueta->setX(100);
};

void MenuGUI::addItem (Item* item)
{
    items.push_back (item);
};


void MenuGUI::draw (gcn::Graphics* graphics)
{
        gcn::ListBox::draw (graphics);
//    etiqueta->draw (graphics);
};

//void MenuGUI::logic ()
//{
// // etiqueta->setCaption("logica, logica");
//};

void MenuGUI::valueChanged (const gcn::SelectionEvent& event)
{
//    this->setSize (getWidth()+5, getHeight());
//    etiqueta->setCaption(this->getElementAt(this->getSelected ()));
//    this->distributeActionEvent ();
};

void MenuGUI::mousePressed (gcn::MouseEvent& mouseEvent)
{
    this->distributeActionEvent ();
};


//void SpriteGUI::mouseEntered (gcn::MouseEvent& mouseEvent)
//{
//};
//

void MenuGUI::mouseExited (gcn::MouseEvent& mouseEvent)
{
    setVisible (false);
};

void MenuGUI::mouseMoved (gcn::MouseEvent& mouseEvent)
{
    setSelected (mouseEvent.getY () / getRowHeight ());
};

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

int MenuGUI::getNumberOfElements ()
{
    return items.size();
};

std::string MenuGUI::getElementAt (int i)
{
    return items[i]->getNombre();
};

}
