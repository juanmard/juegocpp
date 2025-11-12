#ifndef CONTROL_H
#define CONTROL_H

#include "Comando.h"

enum class TipoControl {
    BOX,
    TEXT_AREA,
    BOTON,
    SLIDER,
    CAJA_TEXTO,
    LABEL,
    CHECKBOX,
    RADIOBUTTON
};

class Control {
public:
    TipoControl tipo;
    int x, y, w, h;
    int fg, bg;
    int key;
    int flags;
    Comando* comando;
    void* data;

    Control(TipoControl t_, int x_, int y_, int w_, int h_,
            int fg_, int bg_, int key_, int flags_,
            Comando* cmd = nullptr, void* d = nullptr);
};

#endif // CONTROL_H
