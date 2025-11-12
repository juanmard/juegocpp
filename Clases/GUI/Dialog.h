#ifndef DIALOG_H
#define DIALOG_H

#include <vector>
#include "Control.h"
#include <functional>

class Dialog {
public:
    std::vector<Control> controls;

    void agregarControl(const Control& c);

    int mostrar(); // Implementación Allegro en cpp separado
};

#endif // DIALOG_H
