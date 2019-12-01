///
/// @file EscenarioGUI.cpp
/// @brief Fichero de implementación de la clase "EscenarioGUI".
/// @author Juan Manuel Rico
/// @date Enero 2017
/// @version 1.0.0
///

#include "EscenarioGUI.hpp"

namespace gui
{

EscenarioGUI::EscenarioGUI ()
{
    // Inicializa propiedades de widgets.
    //this->setFocusable (true);
    //this->setFrameSize (2);
    //this->setSize (x,y);

    // Nos añadimos como oyentes de nuestros mensajes.
    // addMouseListener (this);
};

//EscenarioGUI::~EscenarioGUI ()
//{
//};

void EscenarioGUI::draw (gcn::Graphics* graphics)
{
    // Prueba de gráfico.
    graphics->fillRectangle (10, 10, 200, 200);
};

void EscenarioGUI::action (const gcn::ActionEvent& actionEvent)
{
};

void EscenarioGUI::mouseEntered (gcn::MouseEvent& mouseEvent)
{
//   this->distributeMovedEvent();
//   this->setBaseColor(gcn::Color(255,0,0,128));
};

};
