#include "VectorCtrl.h"
#include "SliderCtrl.h"

void VectorCtrl::controlChanged(Control* control) {
        switch (control->tipo){
            case TipoControl::SLIDER:
            {
                // std::cout << "VectorCtrl ha cambiado su valor." << std::endl;
                if (auto slider = dynamic_cast<SliderCtrl*>(control)) {
                    setXY(slider->pos, y);
                }
            }
            break;
            default:
                break;
        }
        renderer->updateVector(this);
}
