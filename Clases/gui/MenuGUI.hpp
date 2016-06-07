///
///
///
#ifndef GUI_MENUGUI_HPP
#define GUI_MENUGUI_HPP

#include <string>
#include <vector>
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
    class Item
    {
    public:
        Item (const std::string& nuevo):nombre(nuevo){};
        const std::string& getNombre () const {return nombre;};
    private:
        std::string nombre;
    };

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
        MenuGUI ();

        /// Añade un Item al menú.
        void addItem (Item* item);

        // Heredado de SelectionListener.
        virtual void valueChanged (const gcn::SelectionEvent& eventp);

        // Heredado de ListModel.
        int getNumberOfElements ();
        std::string getElementAt (int i);

        // Heredado de ListBox
        virtual void draw (gcn::Graphics* graphics);
        //void logic ();

        //// Inherited from MouseListener.
        virtual void mousePressed (gcn::MouseEvent& mouseEvent);
        //virtual void mouseEntered (gcn::MouseEvent& mouseEvent);
        virtual void mouseExited (gcn::MouseEvent& mouseEvent);
        virtual void mouseMoved (gcn::MouseEvent& mouseEvent);

        //// Heredado de KeyListener.
        //void keyPressed (gcn::KeyEvent& keyEvent);
        //void keyReleased (gcn::KeyEvent& keyEvent);

    protected:
        std::vector<Item*> items;
        gcn::Label* etiqueta;
    };
}

#endif // end GUI_MENUGUI_HPP
