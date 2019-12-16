///---------------------------------------------------------
/// @file       Sprite.cpp
/// @author     Juan Manuel Rico
/// @date       Octubre 2015
/// @version    1.1.0
///
/// @brief      Gráfico con animación básica.
///---------------------------------------------------------
///

#include "Sprite.h"
#include "EditableObject.h"
#include "Bitmap.h"
#include <guichan/allegro/allegroimage.hpp>
#include <allegro.h>

namespace fwg {
    
    Sprite::Sprite (Actor* aowner):
    ActorGraphic (aowner),
    actualTick (0),
    actualFrame (0),
    mirror (false)
    {
    }

    Sprite::Sprite (const Sprite& copia, Actor* aowner):
    ActorGraphic (aowner),
    frames (copia.frames),
    actualTick (copia.actualTick),
    actualFrame (copia.actualFrame),
    mirror (copia.mirror)
    {
    }

    void Sprite::init ()
    {
    //    actual_frame=0;
    //    actual_tick=0;
    }

    void Sprite::addFrame (BITMAP* bmp, int cx, int cy, int ticks)
    {
        Frame tmpFrame;

        tmpFrame.bmp = bmp;
        tmpFrame.cx = cx;
        tmpFrame.cy = cy;
        tmpFrame.ticks = ticks;

        // Crea la máscara.
        tmpFrame.mask = new Mask;
        tmpFrame.mask->create(bmp);

        // Guarda el cuadro (frame) en la lista.
        frames.push_back(tmpFrame);
    }

    void Sprite::update ()
    {
        if (frames.size() <= 1) return;
        if (actualTick > frames[actualFrame].ticks)
        {
            // Con el nuevo fotograma retenemos la aniamción.
            if (actualFrame == 0) setFree (false);
            actualTick = 0;
            actualFrame++;
            if (actualFrame >= (int)frames.size())
            {
                // Al terminar el ciclo de la animación libera el gráfico.
                setFree (true);

                // Y prepara el gráfico para un nuevo ciclo.
                actualFrame=0;
            }
        }
        else
        {
            //set_free (false);
            actualTick++;
        }
    }

    void Sprite::draw (BITMAP* bmp)
    {
      if (mirror)
      {
        draw_sprite_h_flip (bmp,  frames[actualFrame].bmp,
                            getX () - frames[actualFrame].cx,
                            getY () - frames[actualFrame].cy);
      }
      else
      {
        draw_sprite (bmp, frames[actualFrame].bmp,
                     getX () - frames[actualFrame].cx,
                     getY () - frames[actualFrame].cy);
      }
    }

    int Sprite::getW ()
    {
        return frames[actualFrame].bmp->w;
    }

    int Sprite::getH ()
    {
        return frames[actualFrame].bmp->h;
    }

    int Sprite::getX ()
    {
      return ActorGraphic::getX()-(frames[actualFrame].cx);
    }

    int Sprite::getY ()
    {
      return ActorGraphic::getY()-(frames[actualFrame].cy);
    }

    Mask* Sprite::getMask ()
    {
      return frames[actualFrame].mask;
    }

    Sprite* Sprite::clone (Actor* propietario) const
    {
      // Al clonar usamos el constructor de copia de la clase.
      return (new Sprite (*this, propietario));
    }

    void Sprite::draw (int x, int y, BITMAP* bmp)
    {
      if (mirror)
      {
        draw_sprite_h_flip (bmp, frames[actualFrame].bmp, 
                            x - frames[actualFrame].cx,
                            y - frames[actualFrame].cy);
      }
      else
      {
        rotate_scaled_sprite (bmp, frames[actualFrame].bmp,
                              x - frames[actualFrame].cx,
                              y - frames[actualFrame].cy,
                              ftofix(0.0), ftofix(2.0));
                              
        //draw_sprite (bmp, frames[actualFrame].bmp, 
        //             x - frames[actualFrame].cx,
        //             y - frames[actualFrame].cy);
      }
    }

    void Sprite::setMirror (bool paramMirror)
    {
      mirror = paramMirror;
    }

    bool Sprite::getMirror ()
    {
        return mirror;
    }

    void Sprite::notMirror ()
    {
        mirror = !mirror;
    }

    std::string Sprite::getString () const
    {
        std::ostringstream cadena;

        // Se incluye la estructura del padre.
        // cadena  << ActorGraphic::getString ();
        cadena << "Padre: " << owner->getNombre() << " ";

        // Se incluyen las propiedades de Sprite.
        cadena  << "Sprite >> NumFrames: " << frames.size () \
                << " >> Frame actual: " << actualFrame \
                << " >> Tick actual: " << actualTick \
                << " >> Ángulo: " << mirror << std::endl;

        // Se incluyen los valores de los Frames.
        for (unsigned int i=0; i<frames.size (); i++)
        {
            cadena << "Frame " << i << " {" << frames[i].print () << "}\n";
        }

        return (cadena.str());
    };

    const Frame* Sprite::getFrame (int ind) const
    {
        return &frames[ind];
    };

    alg4::Menu& Sprite::getMenu () const
    {
        alg4::Menu* ptr_menu = new alg4::Menu ();
        ptr_menu->add (owner->getNombre());             // Se toma el nombre del propietario del Sprite.
        ptr_menu->add ("");                             // Separador.
        ptr_menu->add ("&Editar SPRITE", D_EXIT);       // Algunos items inútiles de prueba.
        ptr_menu->add ("&Repartir SPRITE", D_SELECTED);
        ptr_menu->add ("&Duplicar SPRITE", D_EXIT);
        ptr_menu->add ("&Añadir SPRITE");
        ptr_menu->add ("&Prueba llamada", D_EXIT, NULL, NULL, alg4::Menu::callback);
        return *ptr_menu;
    }

    alg4::Formulario& Sprite::getFormulario () const
    {
        alg4::Formulario* ptr_formulario = new alg4::Formulario ();
        ptr_formulario->add (alg4::Formulario::BOX, 0, 0, 400, 200);
        ptr_formulario->add (10, 10, "Esto es una etiqueta de formulario.");
        ptr_formulario->add (10, 20, "Esta es otra.");
        ptr_formulario->add (10, 30, "Y una más.");
        ptr_formulario->add (alg4::Formulario::SLIDER, 10, 60, 190, 15);
        ptr_formulario->add (alg4::Formulario::BOX, 10, 90, 200, 20);
        ptr_formulario->add (10, 130, new Bitmap (NULL,frames[0].bmp));    
        ptr_formulario->add (60, 130, new Bitmap (NULL,frames[1].bmp));    
        ptr_formulario->add (110,130, new Bitmap (NULL,frames[2].bmp));    
        return *ptr_formulario;
    }

    unsigned int Sprite::getNumFrames () const
    {
        return frames.size ();
    }

    const gcn::Image* Sprite::getImage (unsigned int ind) const
    {
        throw *new std::runtime_error ("La obtención de una imagen desde un \"Sprite\" está sin implementar.\n¿Ha creado un \"SpriteAllegro\"?.");
    }

    void Sprite::setXFrame (int ind, int x)
    {
        frames[ind].cx = x;
    }

    void Sprite::setYFrame (int ind, int y)
    {
        frames[ind].cy = y;
    }

}
