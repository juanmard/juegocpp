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
#include <guichan/widgets/listbox.hpp>
#include <guichan/mouselistener.hpp>
#include <guichan/keylistener.hpp>

namespace gui
{
    // La clase para los controles con lista.
    class Items : public gcn::ListModel
    {
    public:
        int getNumberOfElements() {return 3;};
        std::string getElementAt(int i)
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
        }
    };

    /// Clase que implementa el comportamiento básico de un menú.
    /// Básicamente se compone de una ListBox modificada con opciones desplegables.
    ///
    class GCN_CORE_DECLSPEC MenuGUI :
                            public gcn::ListBox
    {
    public:
        /// Constructor.
        ///
        MenuGUI ();

        /// Constructor.
        /// @param  etiqueta  Cadena con el nombre que mostrará la opción.
        ///
        //MenuGUI (const std::string& etiqueta);

        //// Inherited from Widget
        virtual void draw (gcn::Graphics* graphics);
        //void logic ();

        //// Inherited from MouseListener.
        virtual void mousePressed (gcn::MouseEvent& mouseEvent);
        //virtual void mouseEntered (gcn::MouseEvent& mouseEvent);
        //virtual void mouseExited (gcn::MouseEvent& mouseEvent);

        //// Heredado de KeyListener.
        void keyPressed (gcn::KeyEvent& keyEvent);
        void keyReleased (gcn::KeyEvent& keyEvent);

    protected:
        gui::Items* items;
        gcn::ListBox* lista;
        gcn::Label* etiqueta;
    };
}

#endif // end GUI_MENUGUI_HPP
