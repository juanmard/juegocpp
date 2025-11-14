#include "Dialog.h"

void Dialog::setRenderer(IRenderer* r) {
renderer = r;
}

int Dialog::mostrar() {
if (!renderer) { return -1; }
return renderer->mostrarDialog(*this);
}