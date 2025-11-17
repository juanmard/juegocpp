#include "SliderCtrl.h"

void SliderCtrl::controlChanged(Control* control) {
        switch (control->tipo){
            case TipoControl::SLIDER:
                // std::cout << "SliderCtrl ha cambiado su valor." << std::endl;
                this->setValue(reinterpret_cast<SliderCtrl *>(control)->pos);
                renderer->setSliderValue(this, pos);
                // std::cout << "--- " << pos << " --- " << this->nombre << std::endl;
                break;
            case TipoControl::VECTOR:
            {
                // std::cout << "VectorCtrl ha cambiado su valor." << std::endl;
                VectorCtrl *vct = reinterpret_cast<VectorCtrl *>(control);
                this->setValue(vct->x);
                renderer->setSliderValue(this, pos);
            }
            break;

            default:
                break;
        }
    }
