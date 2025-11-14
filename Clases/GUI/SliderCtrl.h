#ifndef SLIDERCTRL_H
#define SLIDERCTRL_H

#include <iostream>
#include "Control.h"
#include "IControlListener.h"

class SliderCtrl : public Control, public IControlListener {
public:
    unsigned int pos;   ///< Posición actual del slider.
    unsigned int min;   ///< Valor mínimo.
    unsigned int max;   ///< Valor máximo.

    SliderCtrl(int x_, int y_, int w_, int h_, int fg_, int bg_, int key_, int flags_, Comando* cmd = nullptr, void* d = nullptr)
        : Control(TipoControl::SLIDER, x_, y_, w_, h_, fg_, bg_, key_, flags_, cmd, d) {};
        
    SliderCtrl(int x_, int y_) : Control(TipoControl::SLIDER, x_, y_, 0, 0, 0, 0, 0, 0) { pos = 5; };
    void setComando (Comando* cmd) { comando = cmd; };

    // Métodos específicos para "SliderCtrl".
    void setValue (int value) {
        if (pos != value) {
            pos = value;
            notifyListeners();
        }

    }

    void controlChanged(Control* control) override {
        this->setValue(reinterpret_cast<SliderCtrl *>(control)->pos);
        renderer->setSliderValue(this, pos);
        std::cout << "--- " << pos << " --- " << this->nombre << std::endl;
    }
};

#endif // SLIDERCTRL_H
