///
///
///
#ifndef GUI_ESCENARIOGUI_HPP
#define GUI_ESCENARIOGUI_HPP

#include <guichan.hpp>

namespace gui
{
/// Clase para editar gráficamente (GUI) el escenario del juego.
/// Su misión es mostrar el escenario actual del juego y poder modificarlo mediante
///    pulsaciones de ratón y teclado. Para ello se utilizan las clases que nos
///    proporciona GUICHAN.
///
class GCN_CORE_DECLSPEC EscenarioGUI :
                      public gcn::Widget,
//                      public gcn::MouseListener,
//                      public gcn::KeyListener,
                      public gcn::ActionListener
{
    public:
        /// Constructor por defecto de la GUI del escenario.
        /// @note No asigna el escenario que se desea editar.
                EscenarioGUI ();

        /// Constructor básico de la GUI.
                ///EscenarioGUI (Actor* actor);

        /// Destructor del editor del escenario.
        ///virtual ~EscenarioGUI ();

        // Heredado de Widget.
        virtual void draw (gcn::Graphics* graphics);
        void action (const gcn::ActionEvent& actionEvent);

        // Heredado de MouseListener.
        virtual void mouseEntered (gcn::MouseEvent& mouseEvent);

    private:
    protected:
        //Escenario* escenario;
};
};

#endif // end GUI_ESCENARIOGUI_HPP
