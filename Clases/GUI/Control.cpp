#include "Control.h"

namespace jmr {
    Control::Control(TipoControl t_, int x_, int y_, int w_, int h_,
                    int fg_, int bg_, int key_, int flags_,
                    Comando* cmd, void* d)
        : tipo(t_), x(x_), y(y_), w(w_), h(h_), fg(fg_), bg(bg_), key(key_), flags(flags_),
        comando(cmd), data(d) {}

    void Control::setNombre(const std::string& nombre) {
        this->nombre = nombre;
    }

    void Control::setRenderer(IRenderer* r) {
        renderer = r;
    }

    void Control::setInput(IInput* i) {
        input = i;
    }
}