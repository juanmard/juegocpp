#ifndef CONTROL_H
#define CONTROL_H

#include "Comando.h"

struct Control {
    int x, y, w, h;
    int fg, bg;
    int key;
    int flags;
    Comando* comando;
    void* data;

    Control(int x_, int y_, int w_, int h_,
            int fg_, int bg_, int key_, int flags_,
            Comando* cmd = nullptr, void* d = nullptr);
};

#endif // CONTROL_H
