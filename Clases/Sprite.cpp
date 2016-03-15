///
/// @file Sprite.cpp
/// @brief Fichero de implementación de la clase "Sprite".
/// @author Juan Manuel Rico
/// @date Octubre 2015
/// @version 1.0.0
///

#include "Sprite.h"

Sprite::Sprite (Actor* aowner):
ActorGraphic(aowner),
actual_tick (0),
actual_frame (0),
mirror (false)
{
};

Sprite::Sprite (const Sprite& copia, Actor* aowner):
ActorGraphic (aowner),
frames (copia.frames),
actual_tick (copia.actual_tick),
actual_frame (copia.actual_frame),
mirror (copia.mirror)
{
};

void Sprite::init ()
{
//    actual_frame=0;
//    actual_tick=0;
};

void Sprite::add_frame (BITMAP* bmp, int cx, int cy, int ticks)
{
    Frame tmp_frame;

    tmp_frame.bmp = bmp;
    tmp_frame.cx = cx;
    tmp_frame.cy = cy;
    tmp_frame.ticks = ticks;

    // Crea la máscara.
    tmp_frame.mask = new Mask;
    tmp_frame.mask->create(bmp);

    // Guarda el cuadro (frame) en la lista.
    frames.push_back(tmp_frame);
};

void Sprite::update ()
{
    if (frames.size() <= 1) return;
    if (actual_tick > frames[actual_frame].ticks)
    {
        // Con el nuevo fotograma retenemos la aniamción.
        if (actual_frame == 0) set_free (false);
        actual_tick = 0;
        actual_frame++;
        if (actual_frame >= (int)frames.size())
        {
            // Al terminar el ciclo de la animación libera el gráfico.
            set_free (true);

            // Y prepara el gráfico para un nuevo ciclo.
            actual_frame=0;
        }
    }
    else
    {
        //set_free (false);
        actual_tick++;
    }
};

void Sprite::draw (BITMAP* bmp)
{
  if (mirror)
  {
    draw_sprite_h_flip (bmp,  frames[actual_frame].bmp,
                        get_x() - frames[actual_frame].cx,
                        get_y() - frames[actual_frame].cy);
  }
  else
  {
    draw_sprite (bmp, frames[actual_frame].bmp,
                 get_x() - frames[actual_frame].cx,
                 get_y() - frames[actual_frame].cy);
  }
};

int Sprite::get_w ()
{
    return frames[actual_frame].bmp->w;
};

int Sprite::get_h ()
{
    return frames[actual_frame].bmp->h;
};

int Sprite::get_x ()
{
  return ActorGraphic::get_x()-(frames[actual_frame].cx);
}

int Sprite::get_y ()
{
  return ActorGraphic::get_y()-(frames[actual_frame].cy);
}

Mask* Sprite::get_mask ()
{
  return frames[actual_frame].mask;
};

Sprite* Sprite::clone (Actor* propietario) const
{
  // Al clonar usamos el constructor de copia de la clase.
  return (new Sprite (*this, propietario));
};

void Sprite::draw (int x, int y, BITMAP* bmp)
{
  if (mirror)
  {
    draw_sprite_h_flip (bmp, frames[actual_frame].bmp, 
                        x - frames[actual_frame].cx,
                        y - frames[actual_frame].cy);
  }
  else
  {
    rotate_scaled_sprite (bmp, frames[actual_frame].bmp, x - frames[actual_frame].cx, y - frames[actual_frame].cy, ftofix(0.0), ftofix(2.0));
    //draw_sprite (bmp, frames[actual_frame].bmp, 
    //             x - frames[actual_frame].cx,
    //             y - frames[actual_frame].cy);
  }
};

void Sprite::setMirror (bool paramMirror)
{
  mirror = paramMirror;
};

bool Sprite::getMirror ()
{
    return mirror;
};

void Sprite::notMirror ()
{
    mirror = !mirror;
};

std::string Sprite::getString () const
{
    ostringstream cadena;

    // Se incluye la estructura del padre.
    // cadena  << ActorGraphic::getString ();

    // Se incluyen las propiedades de Sprite.
    cadena  << "Sprite >> NumFrames: " << frames.size () \
            << " >> Frame actual: " << actual_frame \
            << " >> Tick actual: " << actual_tick \
            << " >> Ángulo: " << mirror << endl;

    // Se incluyen los valores de los Frames.
    for (unsigned int i=0; i<frames.size (); i++)
    {
        cadena << "Frame " << i << " {" << frames[i].print () << "}\n";
    }

    return (cadena.str());
};



Menu& Sprite::getMenu () const
{
    Menu* ptr_menu = new Menu ();
    ptr_menu->add ((char*)(new std::string(owner->getNombre()))->c_str());  // Se necesita copiar la cadena.
    ptr_menu->add((char*)"");                                               // Separador.
    ptr_menu->add(const_cast<char*>("&Editar SPRITE"), D_EXIT);             // Algunos items inútiles de prueba.
    ptr_menu->add(const_cast<char*>("&Repartir SPRITE"), D_SELECTED);
    ptr_menu->add(const_cast<char*>("&Duplicar SPRITE"), D_EXIT);
    return *ptr_menu;
};

Formulario& Sprite::getFormulario () const
{
    Formulario* ptr_formulario = new Formulario ();
    ptr_formulario->add (Formulario::BOX, 90, 90, 400, 200);
    ptr_formulario->add (Formulario::LABEL, "Esto es una etiqueta de formulario.", 100, 100);
    ptr_formulario->add (Formulario::LABEL, "Esta es otra.", 100, 110);
    ptr_formulario->add (Formulario::LABEL, "Y una más.", 100, 120);
    ptr_formulario->add (Formulario::SLIDER, 100, 150, 190, 15);
    return *ptr_formulario;
};

