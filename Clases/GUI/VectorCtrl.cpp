#include "VectorCtrl.h"
#include "SliderCtrl.h"

void VectorCtrl::controlChanged(Control* control) {
        switch (control->tipo){
            case TipoControl::SLIDER:
                // std::cout << "VectorCtrl ha cambiado su valor." << std::endl;
                this->setXY(reinterpret_cast<SliderCtrl *>(control)->pos, this->y);
                break;
            default:
                break;
        }
        renderer->updateVector(this);
}
