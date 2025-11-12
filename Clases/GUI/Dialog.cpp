#include "Dialog.h"

void Dialog::agregarControl(const Control& c) {
    controls.push_back(c);
}

void Dialog::setRenderer(IRenderer* r) {
    renderer = r;
}

// Mostrar llama al método del renderer asignado
int Dialog::mostrar() {
    if (!renderer) {
        return -1; // o lanzar excepción, no hay renderer asignado
    }
    return renderer->mostrarDialog(*this);
}
