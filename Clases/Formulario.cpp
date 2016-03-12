///
/// @file Formulario.cpp
/// @brief Fichero de implementación de la clase "Formulario".
/// @author Juan Manuel Rico
/// @date Octubre 2015
/// @version 1.0.0
///

#include "Formulario.h"

DIALOG Formulario::fin_formulario = {NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL};

Formulario::Formulario ():
root(0)
{
    controles.push_back (fin_formulario);
};

Formulario::~Formulario ()
{
};

void Formulario::add (control_t tipo, int x, int y, int w, int h)
{
    DIALOG *ctl = new DIALOG();

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
    }

    ctl->fg = 67;
    ctl->bg = 243;
    ctl->x = x;
    ctl->y = y;
    ctl->w = w;
    ctl->h = h;

    controles.pop_back();
    controles.push_back (*ctl);
    controles.push_back (fin_formulario);
};

void Formulario::add (control_t tipo, std::string texto, int x, int y)
{
    DIALOG *ctl = new DIALOG();

    switch (tipo)
    {
    case LABEL:
        ctl->proc = d_text_proc;
        ctl->dp = (void*) (new std::string(texto))->c_str(); //Se necesita copiar la cadena.
        break;
    }

    ctl->fg = 67;
    ctl->bg = 243;
    ctl->x = x;
    ctl->y = y;

    controles.pop_back();
    controles.push_back (*ctl);
    controles.push_back (fin_formulario);
};

void Formulario::show ()
{
    do_dialog (&controles[0],-1);
};
