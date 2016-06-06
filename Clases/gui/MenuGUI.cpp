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
//lista (new gcn::ListBox (items)),
etiqueta(new gcn::Label ("Etiqueta prueba..."))
{
//items = new gui::Items();
lista = new gcn::ListBox (items);
etiqueta->setCaption(items->getElementAt (0));
};

void MenuGUI::draw (gcn::Graphics* graphics)
{
    lista->draw (graphics);
};

//void SpriteGUI::logic ()
//{
//  // // etiqueta->setCaption("logica, logica");
//  imagen->setImage (sprite->getImage(frame_actual));
//};
//
//void SpriteGUI::mousePressed (gcn::MouseEvent& mouseEvent)
//{
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
//void SpriteGUI::keyPressed(gcn::KeyEvent& keyEvent)
//{
//};
//
//void SpriteGUI::keyReleased (gcn::KeyEvent& keyEvent)
//{
//};
//
}
