#include "SliderCtrl.h"

void SliderCtrl::controlChanged(Control* control) {
        switch (control->tipo){
            case TipoControl::SLIDER:
            {
                // std::cout << "SliderCtrl ha cambiado su valor." << std::endl;
                if (auto sldc = dynamic_cast<SliderCtrl*>(control)) {
                    if (setValue (sldc->pos)) renderer->setSliderValue(this, pos - min);
                    // std::cout << "--- " << pos << " --- " << this->nombre << std::endl;
                }
            }
            break;
            case TipoControl::VECTOR:
            {
                if (auto vct = dynamic_cast<VectorCtrl *>(control)) {
                    // std::cout << "VectorCtrl ha cambiado su valor." << std::endl;
                    if (setValue(vct->x)) renderer->setSliderValue(this, pos - min);
                }
            }
            break;

            default:
                break;
        }
}

int SliderCtrl::manejarEvento(const InputEvent& ev) {
    switch (ev.event) {
            case ControlEvent::Draw:
                std::cout << "SliderCtrl Draw event." << std::endl;
                return renderer->defaultSlider();
                break;
            case ControlEvent::DoubleClick:
                std::cout << "SliderCtrl DoubleClick event." << std::endl;
                break;
            default:
                break;
    }
    return 1;
}

