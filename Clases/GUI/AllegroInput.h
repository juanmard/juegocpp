#ifndef ALLEGROINPUT_H
#define ALLEGROINPUT_H

#include "IInput.h"
#include <allegro.h>

class AllegroInput : public IInput {
public:
    AllegroInput() {
        install_mouse();
        install_keyboard();
    }

    int obtenerCodigoTecla() override {
        if (keypressed()) {
            int c = readkey();
            return c >> 8;
        }
        return 0;
    }

    void esperar(int ms) override { rest(ms); }

    bool clicDerecho() override {
        return mouse_b & 2;
    }

    bool clicIzquierdo() override {
        return mouse_b & 1;
    }
};

#endif
