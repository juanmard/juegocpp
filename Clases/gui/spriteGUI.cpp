///
///
///
#include "spriteGUI.hpp"

#include <guichan/exception.hpp>
#include <guichan/font.hpp>
#include <guichan/graphics.hpp>
#include <guichan/widgets/label.hpp>
#include <guichan/allegro/allegroimage.hpp>

namespace gui
{

spriteGUI::spriteGUI ():
sprite(NULL),
etiqueta(new gcn::Label("Prueba 1")),
imagen(new gcn::Icon()),
rojo(new gcn::Color (255,0,0)),
verde(new gcn::Color (0,255,0))
{
    this->add(etiqueta,0,0);
    this->add(imagen,10,10);
    this->setPosition (10,10);

    addMouseListener(this);
//    addKeyListener(this);
//    addFocusListener(this);
};

spriteGUI::spriteGUI (const std::string& caption):
sprite(NULL),
etiqueta(new gcn::Label (caption)),
imagen(new gcn::Icon()),
rojo(new gcn::Color (255,0,0)),
verde(new gcn::Color (0,255,0))
{
    setOpaque(false);
    setWidth(200);
    setHeight(100);
    setBackgroundColor (*rojo);

    addMouseListener(this);
//    addKeyListener(this);
//    addFocusListener(this);
};

spriteGUI::spriteGUI (Sprite* sprite_editar):
sprite(sprite_editar),
etiqueta(new gcn::Label ("Con datos Sprite")),
imagen(new gcn::Icon()),
rojo(new gcn::Color (255,0,0)),
verde(new gcn::Color (0,255,0)),
frame_actual (0)
{
    setOpaque (false);
    setWidth (600);
    setHeight (100);
    setBaseColor (*rojo);
    setFrameSize (1);

    add (etiqueta, 10,10);
    add (imagen,10,50);

    imagen->setFrameSize (2);
    imagen->setWidth (200);
    imagen->setHeight (30);
    imagen->setBaseColor (*verde);

    // Esto es algo transitorio.
    BITMAP* frameBitmap = sprite->getFrame(frame_actual)->getBitmap();
    BITMAP *bmp = create_bitmap(frameBitmap->w, frameBitmap->h);
    blit(frameBitmap, bmp, 0, 0, 0, 0, bmp->w, bmp->h);
    gcn::Image* img = new gcn::AllegroImage (bmp, true);
    imagen->setImage (img);
    img->convertToDisplayFormat();


    addMouseListener(this);
//    addKeyListener(this);
//    addFocusListener(this);
};

const std::string &spriteGUI::getCaption () const
{
    return etiqueta->getCaption ();
};

void spriteGUI::setCaption (const std::string& caption)
{
    etiqueta->setCaption (caption);
};

void spriteGUI::setAlignment (gcn::Graphics::Alignment alignment)
{
    etiqueta->setAlignment (alignment);
};

gcn::Graphics::Alignment spriteGUI::getAlignment() const
{
    return etiqueta->getAlignment ();
};

void spriteGUI::draw (gcn::Graphics* graphics)
{
//    etiqueta->setBackgroundColor (*new gcn::Color(255,0,0));
//    etiqueta->drawFrame(graphics);
    //graphics->setColor (getBackgroundColor ());
    //graphics->drawLine (0, 0, getWidth() - 1, 0);
    //graphics->drawLine (0, 1, 0, getHeight() - 1);
    //graphics->drawLine (getWidth() - 1, 1, getWidth() - 1, getHeight() - 1);
    //graphics->drawLine (1, getHeight() - 1, getWidth() - 1, getHeight() - 1);

    Container::draw (graphics);
//    imagen->drawFrame (graphics);
};

void spriteGUI::logic ()
{
  // // etiqueta->setCaption("logica, logica");
};

void spriteGUI::adjustSize()
{
    etiqueta->adjustSize();
};

void spriteGUI::mousePressed (gcn::MouseEvent& mouseEvent)
{
    etiqueta->setCaption("Ya me diste por fuera.");
    if (mouseEvent.getButton() == gcn::MouseEvent::Left)
    {
        etiqueta->setCaption("Ya me diste.");
        imagen->setBaseColor (*verde);
        if (mouseEvent.getSource() == imagen)
        {
            imagen->setBaseColor (*rojo);

            // Prueba de informaci�n.
            etiqueta->setCaption(sprite->getString());
            //etiqueta->setCaption (sprite->print());

            // Prueba de frames.
            frame_actual ++;
            if (frame_actual >= sprite->getNumFrames ()) {frame_actual = 0;}
            const Frame* frame = sprite->getFrame(frame_actual);
            BITMAP* frameBitmap = frame->getBitmap();
            BITMAP *bmp = create_bitmap(frameBitmap->w, frameBitmap->h);
            blit(frameBitmap, bmp, 0, 0, 0, 0, bmp->w, bmp->h);
            gcn::Image* img = new gcn::AllegroImage (bmp, true);
            imagen->setImage (img);
            img->convertToDisplayFormat();
            imagen->setPosition (10-frame->cx, 50-frame->cy);
        }
        mouseEvent.consume ();
    }
    etiqueta->adjustSize();
};

void spriteGUI::mouseEntered (gcn::MouseEvent& mouseEvent)
{
    setBaseColor (*verde);
};

void spriteGUI::mouseExited (gcn::MouseEvent& mouseEvent)
{
    setBaseColor (*rojo);
};

}