///
/// @file Formulario.cpp
/// @brief Fichero de implementación de la clase "Formulario".
/// @author Juan Manuel Rico
/// @date Octubre 2015
/// @version 1.0.0
///

#include "Formulario.h"
#include "Bitmap.h"

namespace alg4 {

DIALOG Formulario::fin_formulario = {NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL};

Formulario::Formulario ():
root(0)
{
    controles.push_back (fin_formulario);
};

Formulario::~Formulario ()
{
};

void Formulario::add (const int x, const int y, const fwg::Bitmap* picture)
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
    // Este es el control del bucle básico y automático.
    // do_dialog (&controles[0],-1);
    
    // Para mayor control se genera manualmente el bucle.
    /* Este es el control básico que sustituye a "do_dialog".
    DIALOG_PLAYER *player = init_dialog(&controles[0], -1);
    while (update_dialog(player));
    //return shutdown_dialog(player);
    shutdown_dialog(player);
    */
    

    // Este es control de bucle modificado.
    int DONE=0;
    BITMAP* buf = create_bitmap (controles[0].w,controles[0].h);
    show_mouse (NULL);
    gui_set_screen (buf);
    DIALOG_PLAYER* player = init_dialog (&controles[0], -1);
    while (!DONE)
    {
     // Se llama a la lógica del formulario.
     this->logica ();
     
     clear_to_color (buf, makecol(0, 0, 255));
     broadcast_dialog_message (MSG_DRAW, 0);
     //dialog_message (&controles[0], MSG_DRAW, 0, &obj);
     //object_message(&controles[4], MSG_DRAW, 0);
     update_dialog (player);
     
     // Se dibuja una diana en la posición del ratón.
     circle (buf, mouse_x, mouse_y, 5, makecol (0, 0, 0));
     line (buf, mouse_x-10, mouse_y, mouse_x+10, mouse_y, makecol (0, 0, 0));
     line (buf, mouse_x, mouse_y-10, mouse_x, mouse_y+10, makecol (0, 0, 0));

     // Se vuelca el buffer modificado en la pantalla.
     blit (buf, screen, 0, 0, 100, 100, buf->w, buf->h);
     
     // Se comprueba teclado.
     if(key[KEY_ESC]) 
     {
        // Se marca salir del bucle.
        DONE=1;
        // Se limpia tecla.
        key[KEY_ESC]=0;
     }
    }
    
    // Se elimina el diálogo.
    destroy_bitmap (buf);
    shutdown_dialog (player);
};

void Formulario::logica ()
{
    // Recorrer todos los controles y ejecutar la lógica de cada uno de ellos.
    // Tal y como están definidos ahora para allegro...
    // @todo Crear controles genéricos que sustituyan a los de allegro.
    //
    /*
    unsigned int i = 0;
    while (controles[i].proc != NULL)
    {
        // Como prueba los mostraremos en pantalla... y haremos click en el slider.
        if (i==4) {controles[i].proc(MSG_WHEEL, &controles[i], -2);};
        controles[i].proc(MSG_DRAW, &controles[i], 0);
        controles[5].h = controles[4].d2;
        i++;
    };
    */
    
    controles[5].h = controles[4].d2;
    
    // lógica de prueba.
    if (key[KEY_P])
    {
        textout_ex (screen,font,"Prueba de lógica en formulario.",10,10,makecol(255,255,0),-1);
        controles[4].d2 = controles[4].d1;
    };
};

}