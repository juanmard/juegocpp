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

    void obtenerPosicionMouse(int& x, int& y) override {
        x = mouse_x;
        y = mouse_y;
    };

    void esperar(int ms) override { rest(ms); }

    bool clicDerecho() override {
        return mouse_b & 2;
    }

    bool clicIzquierdo() override {
        return mouse_b & 1;
    }
    
    void procesarEventos(InputEvent &ev) override {};
    
    virtual Key getKey() override {
        if (key[KEY_A]) return Key::Key_A;
        if (key[KEY_B]) return Key::Key_B;
        if (key[KEY_C]) return Key::Key_C;
        if (key[KEY_D]) return Key::Key_D;
        if (key[KEY_E]) return Key::Key_E;
        if (key[KEY_F]) return Key::Key_F;
        if (key[KEY_1]) return Key::Key_1;
        if (key[KEY_2]) return Key::Key_2;
        if (key[KEY_3]) return Key::Key_3;
        if (key[KEY_4]) return Key::Key_4;
        if (key[KEY_5]) return Key::Key_5;
        if (key[KEY_6]) return Key::Key_6;
        if (key[KEY_ESC]) return Key::ESC;
        if (key[KEY_ENTER]) return Key::ENTER;
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
