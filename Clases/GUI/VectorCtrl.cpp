#include "VectorCtrl.h"
#include "SliderCtrl.h"

/// @details A modo de prueba, cuando cambia un «Slider» se modifica la posición x del vector.
///
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
            renderer->limpiarControl(this);
            break;
        case ControlEvent::DoubleClick:
            if (modoEdicion) {
                renderer->editarTexto(this);
                modoEdicion = false;
            } else {
                renderer->limpiarControl(this);
                texto = std::to_string(x) + ", " + std::to_string(y);
                renderer->editarTexto(this);
                modoEdicion = true;
            }
            break;
        case ControlEvent::Wheel:
            if (input->getKey() == IInput::Key::LSHIFT || input->getKey() == IInput::Key::RSHIFT) setXY (x, y);
            else if (input->getKey() == IInput::Key::LCONTROL || input->getKey() == IInput::Key::RCONTROL) setXY (x , y);
            else setXY (x, y);
            break;
        case ControlEvent::WantFocus:
            std::cout << "VectorCtrl WhantFocus event." << std::endl;
            break;
        case ControlEvent::GotFocus:
            renderer->invertirBackgroundForeground (this);
            break;
        case ControlEvent::LostFocus:
            renderer->invertirBackgroundForeground (this);
            break;

        case ControlEvent::Char:
        case ControlEvent::Key:
        case ControlEvent::UChar:
        case ControlEvent::XChar:
        {
            std::cout << "VectorCtrl Char event." << std::endl;
            auto &data = std::get<KeyData>(ev.data);
            std::cout << "Char 2: " << data.key << std::endl;

            if (input->getKey() == IInput::Key::ENTER) {
                std::cout << "ENTER" << std::endl;
                InputEvent nuevo = ev;
                nuevo.event = ControlEvent::DoubleClick;
                nuevo.data = data;
                modoEdicion = true;
                manejarEvento(nuevo);
            }
        }
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
}

