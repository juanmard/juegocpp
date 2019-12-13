///
///
///
#ifndef GUI_SPRITEGUI_HPP
#define GUI_SPRITEGUI_HPP

#include <string>
#include "MenuGUI.hpp"
#include "VectorGUI.hpp"
#include "../Sprite.h"
#include <guichan/graphics.hpp>
#include <guichan/platform.hpp>
#include <guichan/widget.hpp>
#include <guichan/widgets/container.hpp>
#include <guichan/widgets/label.hpp>
#include <guichan/widgets/button.hpp>
#include <guichan/widgets/icon.hpp>
#include <guichan/mouselistener.hpp>
#include <guichan/keylistener.hpp>
#include <guichan/actionlistener.hpp>
#include "VectorGUI.hpp"

namespace gui
{
    /**
     * Implementation of a label capable of displaying a caption.
     */
    class GCN_CORE_DECLSPEC SpriteGUI :
                            public gcn::Container,
                            public gcn::MouseListener,
                            public gcn::KeyListener,
                            public gcn::ActionListener
    {
    public:
        /**
         * Constructor.
         */
        SpriteGUI ();

        /**
         * Constructor. The label will be automatically resized
         * to fit the caption.
         *
         * @param caption The caption of the label.
         */
        SpriteGUI (const std::string& caption);
        SpriteGUI (fwg::Sprite* sprite_editar);

        /**
         * Gets the caption of the label.
         *
         * @return The caption of the label.
         * @see setCaption
         */
        const std::string& getCaption() const;

        /**
         * Sets the caption of the label. It's advisable to call
         * adjustSize after setting of the caption to adjust the
         * label's size to fit the caption.
         *
         * @param caption The caption of the label.
         * @see getCaption, adjustSize
         */
        void setCaption(const std::string& caption);

        /**
         * Sets the alignment of the caption. The alignment is relative
         * to the center of the label.
         *
         * @param alignemnt The alignment of the caption of the label.
         * @see getAlignment, Graphics
         */
        void setAlignment(gcn::Graphics::Alignment alignment);

        /**
         * Gets the alignment of the caption. The alignment is relative to
         * the center of the label.
         *
         * @return The alignment of caption of the label.
         * @see setAlignmentm Graphics
         */
        gcn::Graphics::Alignment getAlignment() const;

        /**
         * Adjusts the label's size to fit the caption.
         */
        void adjustSize();

        // Inherited from Widget
        virtual void draw (gcn::Graphics* graphics);
        void logic ();

        // Inherited from MouseListener.
        virtual void mousePressed (gcn::MouseEvent& mouseEvent);
        virtual void mouseEntered (gcn::MouseEvent& mouseEvent);
        virtual void mouseExited (gcn::MouseEvent& mouseEvent);

        // Heredado de KeyListener.
        void keyPressed (gcn::KeyEvent& keyEvent);
        void keyReleased (gcn::KeyEvent& keyEvent);

        // Heredado de ActionListener.
        virtual void action (const gcn::ActionEvent& actionEvent);

    protected:
        fwg::Sprite* sprite;             ///< Sprite que se quiere editar.
        gcn::Label* etiqueta;       ///< Etiqueta del widget.
        gcn::Button* add_frame;
        gcn::Button* del_frame;

        gcn::Container* fotogramas;     ///< Contiene los Frames a editar.
        gcn::Icon* imagenAnterior;      ///< Imagen del frame actual que se muestra.
        gcn::Icon* imagenActual;        ///< Imagen del frame actual que se muestra.
        gcn::Icon* imagenPosterior;     ///< Imagen del frame actual que se muestra.

        gcn::Color *rojo, *verde;
        unsigned int frame_actual;  ///< Frame actual del Sprite.
        gcn::Label* numFrame;       ///< Etiqueta para número de Frame.
        gcn::Label* pos;            ///< Etiqueta para la posición.
        gcn::Label* ticks;          ///< Etiqueta para los ticks.

        int prb_x, prb_y;           ///< Prueba para VectorGUI.

        gui::VectorGUI* vector_pos;
        gui::MenuGUI* prueba_menu;  ///< Menú de prueba.
    };
}

#endif // end GUI_SPRITEGUI_HPP
