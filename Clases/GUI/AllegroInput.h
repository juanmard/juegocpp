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

    virtual Key getKey() override {
        if (key[KEY_LSHIFT]) return Key::LSHIFT;
        if (key[KEY_RSHIFT]) return Key::RSHIFT;
        if (key[KEY_LCONTROL]) return Key::LCONTROL;
        if (key[KEY_RCONTROL]) return Key::RCONTROL;
        if (key[KEY_ALT]) return Key::ALT;
        if (key[KEY_ALTGR]) return Key::ALTGR;
        return Key::NONE;
    };
};

#endif
