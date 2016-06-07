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
    this->setListModel (this);
    this->addSelectionListener (this);
    //this->setSelectionColor (gcn::Color(255,0,0));
    this->setActionEventId ("menu");
    etiqueta->setX(100);
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
    this->setSize (getWidth()+5, getHeight());
    etiqueta->setCaption(this->getElementAt(this->getSelected ()));
    this->distributeActionEvent ();
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

int MenuGUI::getNumberOfElements ()
{
    return 3;
};

std::string MenuGUI::getElementAt (int i)
{
    switch(i)
    {
        case 0:
            return std::string("Menu 1");
        case 1:
            return std::string("Menu 2");
        case 2:
            return std::string("Menu 3");
        default:
            return std::string("");
    }
};


}
