#ifndef SLIDERCTRL_H
#define SLIDERCTRL_H

#include "Control.h"

class SliderCtrl : public Control {
public:
    unsigned int pos;   ///< Posición actual del slider.
    unsigned int min;   ///< Valor mínimo.
    unsigned int max;   ///< Valor máximo.

    SliderCtrl(TipoControl t_, int x_, int y_, int w_, int h_, int fg_, int bg_, int key_, int flags_, Comando* cmd = nullptr, void* d = nullptr)
        : Control(t_, x_, y_, w_, h_, fg_, bg_, key_, flags_, cmd, d) {};

    SliderCtrl(TipoControl t_, int x_, int y_) : Control(t_, x_, y_, 100, 50, 0x00ff00, 0xff0000, 0, 0, nullptr, nullptr){};

    // Métodos específicos para "SliderCtrl" pueden añadirse aquí.
    void setValue (int value) {
        // Implementación para establecer el valor del slider
        pos = value;
    }
};

#endif // SLIDERCTRL_H
