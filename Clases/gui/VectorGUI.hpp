///
///
///
#ifndef GUI_VECTORGUI_HPP
#define GUI_VECTORGUI_HPP

#include <guichan/widgets/label.hpp>
#include <guichan/mouselistener.hpp>
#include <guichan/keylistener.hpp>
#include <guichan/mouseevent.hpp>
#include <guichan/font.hpp>

namespace gui
{
    /// Clase que implementa el comportamiento básico de la GUI de un vector.
    /// Se intenta que tenga el mismo comportamiento que el original del juego.
    /// Esto es, que se ponga en rojo cuando pase por encima el ratón, que se cambien
    /// con las teclas el valor y con la rueda de ratón.
    ///
    class GCN_CORE_DECLSPEC VectorGUI :
                            public gcn::Label,
                            public gcn::MouseListener,
                            public gcn::KeyListener
    {
    public:
        /// Constructor.
        VectorGUI (int& x, int& y);

        // Establece la fuente de activaci�n.
        void setFontActive (gcn::Font* font);

        // Heredado de ListModel.
        //int getNumberOfElements ();
        //std::string getElementAt (int i);

        // Heredado de Label
        //virtual void draw (gcn::Graphics* graphics);
        void logic ();

        ////// Inherited from MouseListener.
        virtual void mousePressed (gcn::MouseEvent& mouseEvent);
        virtual void mouseEntered (gcn::MouseEvent& mouseEvent);
        virtual void mouseExited (gcn::MouseEvent& mouseEvent);
        //virtual void mouseMoved (gcn::MouseEvent& mouseEvent);
        void mouseWheelMovedUp (gcn::MouseEvent& mouseEvent);
        void mouseWheelMovedDown (gcn::MouseEvent& mouseEvent);

        ////// Heredado de KeyListener.
        ////void keyPressed (gcn::KeyEvent& keyEvent);
        ////void keyReleased (gcn::KeyEvent& keyEvent);

    protected:
        gcn::Font* fontActive;
        int& x;             ///< Referencia a la componente x que modifica.
        int& y;             ///< Referencia a la componente y que modifica.
        bool Refrescar;     ///< Necesita refrescar la variable.
    };
}

#endif // end GUI_VECTORGUI_HPP
