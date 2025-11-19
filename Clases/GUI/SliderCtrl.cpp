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
                break;
            case ControlEvent::DoubleClick:
                std::cout << "SliderCtrl DoubleClick event." << std::endl;
                break;
            case ControlEvent::Wheel:
                std::cout << "SliderCtrl Wheel event." << std::endl;
                break;
            case ControlEvent::WantFocus:
                std::cout << "SliderCtrl WhantFocus event." << std::endl;
                break;
            case ControlEvent::GotFocus:
                std::cout << "SliderCtrl GotFocus event." << std::endl;
                break;
            case ControlEvent::LostFocus:
                std::cout << "SliderCtrl LostFocus event." << std::endl;
                break;
            case ControlEvent::Char:
                std::cout << "SliderCtrl CharEvent event." << std::endl;
                break;
            case ControlEvent::LeftPress:
                std::cout << "SliderCtrl LeftPress event." << std::endl;
                break;
            case ControlEvent::LeftRelease:
                std::cout << "SliderCtrl LeftRelease event." << std::endl;
                break;
            case ControlEvent::RightPress:
                std::cout << "SliderCtrl RightPress event." << std::endl;
                break;
            case ControlEvent::RightRelease:
                std::cout << "SliderCtrl RightRelease event." << std::endl;
                break;
            case ControlEvent::MiddlePress:
                std::cout << "SliderCtrl MiddlePress event." << std::endl;
                break;
            case ControlEvent::MiddleRelease:
                std::cout << "SliderCtrl MiddleRelease event." << std::endl;
                break;
            default:
                break;
    }
    return renderer->defaultSlider(this, ev);
}

