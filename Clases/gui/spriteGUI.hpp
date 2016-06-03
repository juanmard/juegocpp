///
///
///
#ifndef GUI_SPRITEGUI_HPP
#define GUI_SPRITEGUI_HPP

#include <string>

#include <guichan/graphics.hpp>
#include <guichan/platform.hpp>
#include <guichan/widget.hpp>

namespace gui
{
    /**
     * Implementation of a label capable of displaying a caption.
     */
    class GCN_CORE_DECLSPEC spriteGUI : public gcn::Widget
    {
    public:
        /**
         * Constructor.
         */
        spriteGUI ();

        /**
         * Constructor. The label will be automatically resized
         * to fit the caption.
         *
         * @param caption The caption of the label.
         */
        spriteGUI (const std::string& caption);

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

        virtual void draw(gcn::Graphics* graphics);

    protected:
        /**
         * Holds the caption of the label.
         */
        std::string mCaption;

        /**
         * Holds the alignment of the caption.
         */
        gcn::Graphics::Alignment mAlignment;
    };
}

#endif // end GUI_SPRITEGUI_HPP
