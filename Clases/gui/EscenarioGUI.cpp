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

EscenarioGUI::EscenarioGUI (StageManager* param)
{
    // Se reserva el puntero de representación del escenario.
    stage_manager = param;
    
    // Inicializa propiedades de widgets.
    setFocusable (true);
    setFrameSize (2);
    setX(100);
    setY(200);
    setHeight(200);
    setWidth(300);

    // Inicializa la imagen a mostrar del escenario.
    // TODO: Eliminar la dependencia y generalizar AllegroImage con Image.
    stage_image = new gcn::AllegroImage(stage_manager->getBuffer(),false);
    stage_image->convertToDisplayFormat();

    // Nos añadimos como oyentes de nuestros mensajes.
    addMouseListener (this);
};

EscenarioGUI::~EscenarioGUI ()
{
};

void EscenarioGUI::draw (gcn::Graphics* graphics)
{
    // Prueba de gráfico.
    graphics->drawImage (stage_image, 100, 100, 0, 0, 200, 300);
    graphics->drawText ("Prueba de Escenario", 0, 0);
};

void EscenarioGUI::action (const gcn::ActionEvent& actionEvent)
{
};

void EscenarioGUI::mouseEntered (gcn::MouseEvent& mouseEvent)
{
    distributeMovedEvent();
    setBaseColor(gcn::Color(255,0,0));
};

void EscenarioGUI::mouseExited (gcn::MouseEvent& mouseEvent)
{
    distributeMovedEvent();
    setBaseColor(gcn::Color(255,255,0));
};

};
