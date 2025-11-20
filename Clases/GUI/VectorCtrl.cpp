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

int VectorCtrl::manejarEvento(const InputEvent& ev) {
    switch (ev.event) {
        case ControlEvent::Draw:
            std::cout << "VectorCtrl Draw event." << std::endl;
            renderer->limpiarControl(this);
            break;
        case ControlEvent::DoubleClick:
            std::cout << "VectorCtrl DoubleClick event." << std::endl;
            renderer->dibujarCuadrado(x, y, renderer->makeColor(0, 255, 0));
            break;
        case ControlEvent::Wheel:
            std::cout << "VectorCtrl Wheel event." << std::endl;
            if (input->getKey() == Key::LSHIFT || input->getKey() == Key::RSHIFT) setXY (x, y + ev.c);
            else if (input->getKey() == Key::LCONTROL || input->getKey() == Key::RCONTROL) setXY (x + ev.c*10, y + ev.c*10);
            else setXY (x + ev.c, y);
            break;
        case ControlEvent::WantFocus:
            std::cout << "VectorCtrl WhantFocus event." << std::endl;
            break;
        case ControlEvent::GotFocus:
            std::cout << "VectorCtrl GotFocus event." << std::endl;
            renderer->invertirBackgroundForeground (this);
            break;
        case ControlEvent::LostFocus:
            std::cout << "VectorCtrl LostFocus event." << std::endl;
            renderer->invertirBackgroundForeground (this);
            break;
        case ControlEvent::Char:
            std::cout << "VectorCtrl CharEvent event." << std::endl;
            break;
        case ControlEvent::LeftPress:
            std::cout << "VectorCtrl LeftPress event." << std::endl;
            break;
        case ControlEvent::LeftRelease:
            std::cout << "VectorCtrl LeftRelease event." << std::endl;
            break;
        case ControlEvent::RightPress:
            std::cout << "VectorCtrl RightPress event." << std::endl;
            break;
        case ControlEvent::RightRelease:
            std::cout << "VectorCtrl RightRelease event." << std::endl;
            break;
        case ControlEvent::MiddlePress:
            std::cout << "VectorCtrl MiddlePress event." << std::endl;
            break;
        case ControlEvent::MiddleRelease:
            std::cout << "VectorCtrl MiddleRelease event." << std::endl;
            break;
        default:
            break;
    }
    return renderer->defaultVector(this, ev);
    return 0;
}

