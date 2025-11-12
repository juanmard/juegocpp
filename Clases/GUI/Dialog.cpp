#include "Dialog.h"
#include <allegro.h>

static int allegroCallback(int msg, DIALOG *d, int c) {
    Control* ctrl = reinterpret_cast<Control*>(d->dp);
    if (ctrl && ctrl->comando) {
//        return ctrl->comando->ejecutar();
        ctrl->comando->ejecutar();
        return 0;
    }
//    return d_key_proc(d, msg, c);
    return 1;
}

void Dialog::agregarControl(const Control& c) {
    controls.push_back(c);
}

int Dialog::mostrar() {
    DIALOG* allegroDialog = new DIALOG[controls.size() + 1];

    for (size_t i = 0; i < controls.size(); ++i) {
        const Control& c = controls[i];
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

    allegroDialog[controls.size()].proc = NULL;
    allegroDialog[controls.size()].x = allegroDialog[controls.size()].y = 0;
    allegroDialog[controls.size()].w = allegroDialog[controls.size()].h = 0;
    allegroDialog[controls.size()].flags = 0;
    allegroDialog[controls.size()].dp = nullptr;

//    int result = do_dialog(allegroDialog, -1);
    int result = 0;
    do_dialog(allegroDialog, -1);

    delete[] allegroDialog;
    return result;
}
