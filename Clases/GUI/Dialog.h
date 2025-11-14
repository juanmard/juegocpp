// Dialog.h
#ifndef DIALOG_H
#define DIALOG_H

#include <vector>
#include <memory>
#include "Control.h"
#include "IRenderer.h"

class Dialog {
public:
    // Cambiar el vector para almacenar punteros únicos
    std::vector<std::unique_ptr<Control>> controls;

    // Cambiar a agregar punteros únicos para mantener polimorfismo
    void agregarControl(std::unique_ptr<Control> c) {
        controls.push_back(std::move(c));
    }

    int mostrar();

    void setRenderer(IRenderer* renderer);

private:
    IRenderer* renderer = nullptr;
};

#endif

