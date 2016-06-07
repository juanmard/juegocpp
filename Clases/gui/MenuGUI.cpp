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
items (new gui::Items()),
etiqueta(new gcn::Label ("Etiqueta prueba..."))
{
    this->setListModel (items);
    etiqueta->setCaption(items->getElementAt (0));
};

//void MenuGUI::draw (gcn::Graphics* graphics)
//{
//    lista->draw (graphics);
//};

//void SpriteGUI::logic ()
//{
//  // // etiqueta->setCaption("logica, logica");
//  imagen->setImage (sprite->getImage(frame_actual));
//};
//

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
