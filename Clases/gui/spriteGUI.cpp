///
///
///
#include "spriteGUI.hpp"

#include <guichan/exception.hpp>
#include <guichan/font.hpp>
#include <guichan/graphics.hpp>

namespace gui
{

spriteGUI::spriteGUI ()
{
    mAlignment = gcn::Graphics::Left;
};

spriteGUI::spriteGUI (const std::string& caption)
{
    mCaption = caption;
    mAlignment = gcn::Graphics::Left;

    setWidth(getFont()->getWidth(caption));
    setHeight(getFont()->getHeight());
};

const std::string &spriteGUI::getCaption () const
{
    return mCaption;
};

void spriteGUI::setCaption (const std::string& caption)
{
    mCaption = caption;
};

void spriteGUI::setAlignment (gcn::Graphics::Alignment alignment)
{
    mAlignment = alignment;
};

gcn::Graphics::Alignment spriteGUI::getAlignment() const
{
    return mAlignment;
};

void spriteGUI::draw (gcn::Graphics* graphics)
{
    int textX;
    int textY = getHeight() / 2 - getFont()->getHeight() / 2;

    switch (getAlignment())
    {
    case gcn::Graphics::Left:
            textX = 0;
            break;
    case gcn::Graphics::Center:
            textX = getWidth() / 2;
            break;
    case gcn::Graphics::Right:
            textX = getWidth();
            break;
        default:
            throw GCN_EXCEPTION("Unknown alignment.");
    }

    graphics->setFont(getFont());
    graphics->setColor(getForegroundColor());
    graphics->drawText(getCaption(), textX, textY, getAlignment());
};

void spriteGUI::adjustSize()
{
    setWidth(getFont()->getWidth(getCaption()));
    setHeight(getFont()->getHeight());
};

}
