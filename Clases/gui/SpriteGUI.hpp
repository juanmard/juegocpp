///
///
///
#ifndef GUI_SPRITEGUI_HPP
#define GUI_SPRITEGUI_HPP

#include <string>
#include "../Sprite.h"
#include <guichan/graphics.hpp>
#include <guichan/platform.hpp>
#include <guichan/widget.hpp>
#include <guichan/widgets/container.hpp>
#include <guichan/mouselistener.hpp>
#include <guichan/focuslistener.hpp>
#include <guichan/widgets/label.hpp>
#include <guichan/widgets/button.hpp>
#include <guichan/widgets/icon.hpp>

namespace gui
{
    /**
     * Implementation of a label capable of displaying a caption.
     */
    class GCN_CORE_DECLSPEC SpriteGUI :
                            public gcn::Container,
                            public gcn::MouseListener
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
        SpriteGUI (Sprite* sprite_editar);

        /**
         * Gets the caption of the label.
         *
         * @return The caption of the label.
         * @see setCaption
         */
        const std::string &getCaption() const;

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

    protected:
        Sprite* sprite;          ///< Sprite que se quiere editar.
        gcn::Label* etiqueta;    ///< Etiqueta del widget.
        gcn::Button* add_frame;
        gcn::Button* del_frame;
        gcn::Icon* imagen;       ///< Imagen del frame actual que se muestra.

        gcn::Color *rojo, *verde;
        unsigned int frame_actual;
    };
}

#endif // end GUI_SPRITEGUI_HPP
