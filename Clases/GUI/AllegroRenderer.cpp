// AllegroRenderer.cpp
#include "AllegroRenderer.h"
#include <allegro.h>

int AllegroRenderer::allegroCallback(int msg, DIALOG* d, int c) {
    Control* ctrl = reinterpret_cast<Control*>(d->dp);
    if (ctrl && ctrl->comando) {
        ctrl->comando->ejecutar();
        return D_O_K;
    }
    return d_keyboard_proc(msg, d, c);
}

int AllegroRenderer::mostrarDialog(const Dialog& dialog) {
    size_t n = dialog.controls.size();
    DIALOG* allegroDialog = new DIALOG[n + 1];

    for (size_t i = 0; i < n; ++i) {
        const Control& c = dialog.controls[i];
        allegroDialog[i].proc = d_box_proc; //allegroCallback;
        allegroDialog[i].x = c.x;
        allegroDialog[i].y = c.y;
        allegroDialog[i].w = c.w;
        allegroDialog[i].h = c.h;
        allegroDialog[i].fg = c.fg;
        allegroDialog[i].bg = c.bg;
        allegroDialog[i].key = c.key;
        allegroDialog[i].flags = c.flags;
        allegroDialog[i].d1 = 0;
        allegroDialog[i].d2 = 0;
        allegroDialog[i].dp = const_cast<Control*>(&c);
        allegroDialog[i].dp2 = nullptr;
        allegroDialog[i].dp3 = nullptr;
    }

    allegroDialog[n].proc = NULL;  // fin arreglo Allegro
    allegroDialog[n].x = allegroDialog[n].y = 0;
    allegroDialog[n].w = allegroDialog[n].h = 0;
    allegroDialog[n].flags = 0;
    allegroDialog[n].dp = nullptr;

    int result = do_dialog(allegroDialog, -1);
    delete[] allegroDialog;
    return result;
}
