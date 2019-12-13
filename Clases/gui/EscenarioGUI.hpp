///
///
///
#ifndef GUI_ESCENARIOGUI_HPP
#define GUI_ESCENARIOGUI_HPP

#include <guichan.hpp>
#include <guichan/allegro/allegroimage.hpp>
#include "../StageManager.h"

namespace gui
{
/// Clase para editar gráficamente (GUI) el escenario del juego.
/// Su misión es mostrar el escenario actual del juego y poder modificarlo mediante
///    pulsaciones de ratón y teclado. Para ello se utilizan las clases que nos
///    proporciona GUICHAN.
///
class GCN_CORE_DECLSPEC EscenarioGUI :
                      public gcn::Widget,
                      public gcn::MouseListener,
                      public gcn::KeyListener,
                      public gcn::ActionListener
{
    public:
        /// Constructor por defecto de la GUI del escenario.
        /// @note No asigna el escenario que se desea editar.
        EscenarioGUI (fwg::StageManager* param);

        /// Constructor básico de la GUI.
                ///EscenarioGUI (fwg::Actor* actor);

        /// Destructor del editor del escenario.
        virtual ~EscenarioGUI ();

        // Heredado de Widget.
        void draw (gcn::Graphics* graphics);
        void action (const gcn::ActionEvent& actionEvent);

        // Heredado de MouseListener.
        virtual void mouseEntered (gcn::MouseEvent& mouseEvent);
        virtual void mouseExited (gcn::MouseEvent& mouseEvent);

    private:
    protected:
        fwg::StageManager* stage_manager;
        gcn::Image* stage_image;
};

};

#endif // end GUI_ESCENARIOGUI_HPP
