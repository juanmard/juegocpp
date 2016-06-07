///
///
///
#ifndef GUI_MENUGUI_HPP
#define GUI_MENUGUI_HPP

#include <string>
//#include "../Sprite.h"
//#include <guichan/graphics.hpp>
//#include <guichan/platform.hpp>
//#include <guichan/widget.hpp>
//#include <guichan/widgets/container.hpp>
#include <guichan/widgets/label.hpp>
//#include <guichan/widgets/button.hpp>
#include <guichan/listmodel.hpp>
#include <guichan/selectionlistener.hpp>
#include <guichan/selectionevent.hpp>
#include <guichan/widgets/listbox.hpp>
#include <guichan/mouselistener.hpp>
#include <guichan/keylistener.hpp>

namespace gui
{
    /// Clase que implementa el comportamiento básico de un menú.
    /// Básicamente se compone de una ListBox modificada con opciones desplegables.
    ///
    class GCN_CORE_DECLSPEC MenuGUI :
                            public gcn::ListBox,
                            public gcn::SelectionListener,
                            private gcn::ListModel
    {
    public:
        /// Constructor.
        ///
        MenuGUI ();

        // Heredado de SelectionListener.
        virtual void valueChanged (const gcn::SelectionEvent& eventp);

        // Heredado de ListModel.
        int getNumberOfElements ();
        std::string getElementAt (int i);

        // Heredado de ListBox
        virtual void draw (gcn::Graphics* graphics);
        //void logic ();

        //// Inherited from MouseListener.
        //virtual void mousePressed (gcn::MouseEvent& mouseEvent);
        //virtual void mouseEntered (gcn::MouseEvent& mouseEvent);
        //virtual void mouseExited (gcn::MouseEvent& mouseEvent);

        //// Heredado de KeyListener.
        //void keyPressed (gcn::KeyEvent& keyEvent);
        //void keyReleased (gcn::KeyEvent& keyEvent);

    protected:
//        gui::Items* items;
        gcn::Label* etiqueta;
    };
}

#endif // end GUI_MENUGUI_HPP
