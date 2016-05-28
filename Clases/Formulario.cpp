///
/// @file Formulario.cpp
/// @brief Fichero de implementación de la clase "Formulario".
/// @author Juan Manuel Rico
/// @date Octubre 2015
/// @version 1.0.0
///

#include "Formulario.h"
#include "Bitmap.h"

DIALOG Formulario::fin_formulario = {NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL};

Formulario::Formulario ():
root(0)
{
    controles.push_back (fin_formulario);
};

Formulario::~Formulario ()
{
};

void Formulario::add (const int x, const int y, const Bitmap* picture)
{
    DIALOG* ctl = new DIALOG();

    ctl->proc = d_bitmap_proc;
    ctl->fg = 67;
    ctl->bg = 243;
    ctl->x = x;
    ctl->y = y;
    ctl->w = picture->get_w();
    ctl->h = picture->get_h();
    ctl->dp = picture->get_imagen();

    controles.pop_back ();
    controles.push_back (*ctl);
    controles.push_back (fin_formulario);
};
    
void Formulario::add (control_t tipo, BITMAP* picture, int x, int y)
{
    DIALOG* ctl = new DIALOG();

    switch (tipo)
    {
    case PICTURE:
        ctl->proc = d_bitmap_proc;
        break;
        
    default:
        break;
    }

    ctl->fg = 67;
    ctl->bg = 243;
    ctl->x = x;
    ctl->y = y;
    ctl->w = picture->w;
    ctl->h = picture->h;
    ctl->dp = picture;

    controles.pop_back ();
    controles.push_back (*ctl);
    controles.push_back (fin_formulario);

};

void Formulario::add (control_t tipo, int x, int y, int w, int h)
{
    DIALOG* ctl = new DIALOG();

    switch (tipo)
    {
    case BOX:
        ctl->proc = d_box_proc;
        break;

    case SLIDER:
        ctl->proc = d_slider_proc;
        ctl->d1 = 100;
        ctl->d2 = 10;
        break;
        
    default:
        break;
    }

    ctl->fg = 67;
    ctl->bg = 243;
    ctl->x = x;
    ctl->y = y;
    ctl->w = w;
    ctl->h = h;

    controles.pop_back ();
    controles.push_back (*ctl);
    controles.push_back (fin_formulario);
};

void Formulario::add (const int x, const int y, const std::string& texto)
{
    this->add (LABEL, texto, x, y);
};

void Formulario::add (const control_t tipo, const std::string& texto, const int x, const int y)
{
    DIALOG* ctl = new DIALOG();

    switch (tipo)
    {
    case LABEL:
        ctl->proc = d_text_proc;
        ctl->dp = (void*) (new std::string(texto))->c_str(); //Se necesita copiar la cadena.
        break;
        
    default:
        break;
    }

    ctl->fg = 67;
    ctl->bg = 243;
    ctl->x = x;
    ctl->y = y;

    controles.pop_back ();
    controles.push_back (*ctl);
    controles.push_back (fin_formulario);
};

void Formulario::show ()
{
    do_dialog (&controles[0],-1);
};
