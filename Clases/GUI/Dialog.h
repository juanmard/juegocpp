// Dialog.h
#ifndef DIALOG_H
#define DIALOG_H

#include <vector>
#include "Control.h"
#include "IRenderer.h"

class Dialog {
public:
    std::vector<Control> controls;

    // Agrega controles al diálogo
    void agregarControl(const Control& c);

    // Muestra el diálogo usando un renderizador externo
    // El renderizador implementará la interfaz IRenderer
    int mostrar();
    void setRenderer(IRenderer* renderer);

private:
    IRenderer* renderer = nullptr;
};

#endif

