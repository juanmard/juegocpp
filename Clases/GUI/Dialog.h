// Dialog.h
#ifndef DIALOG_H
#define DIALOG_H

#include <vector>
#include <memory>
#include "Control.h"
#include "IRenderer.h"
#include "IInput.h"

namespace jmr {
    class Dialog {
    public:
        // Cambiar el vector para almacenar punteros únicos
        std::vector<std::unique_ptr<Control>> controls;

        // Cambiar a agregar punteros únicos para mantener polimorfismo
        void agregarControl(std::unique_ptr<Control> c) {
            controls.push_back(std::move(c));
        }

        int mostrar();

        void setRenderer(IRenderer*);
        void setInput (IInput*);

    private:
        IRenderer* renderer = nullptr;
        IInput* input = nullptr;
    };
}
#endif

