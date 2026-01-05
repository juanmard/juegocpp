#include "Dialog.h"

namespace jmr {
    void Dialog::setRenderer (IRenderer* r) {
        renderer = r;
    }

    void Dialog::setInput (IInput* i) {
        input = i;
    }

    int Dialog::mostrar() {
        if (!renderer) { return -1; }
        return renderer->mostrarDialog(*this);
    }
}