#include "StageCtrl.h"

void StageCtrl::controlChanged(Control* control) {
        switch (control->tipo){
            // case TipoControl::SLIDER:
            // {
            //     // std::cout << "SliderCtrl ha cambiado su valor." << std::endl;
            //     if (auto sldc = dynamic_cast<StageCtrl*>(control)) {
            //         if (setValue (sldc->pos)) renderer->setSliderValue(this, pos - min);
            //     }
            // }
            // break;
            // case TipoControl::VECTOR:
            // {
            //     if (auto vct = dynamic_cast<VectorCtrl *>(control)) {
            //         // std::cout << "VectorCtrl ha cambiado su valor." << std::endl;
            //         if (setValue(vct->x)) renderer->setSliderValue(this, pos - min);
            //     }
            // }
            // break;

            default:
                break;
        }
}

/// @brief Maneja los eventos del escenario (stage).
/// @param ev Evento a procesar
/// @return Valor entregado por Allegro4.
///
/// @todo Independizar estos controles del resultado de Allegro4.
///
int StageCtrl::manejarEvento(const InputEvent& ev) {
    switch (ev.event) {
        case ControlEvent::Draw:
            std::cout << "StageCtrl Draw event." << std::endl;
            dibujarMarco();
            break;
        case ControlEvent::DoubleClick:
            std::cout << "StageCtrl DoubleClick event." << std::endl;
            renderer->dibujarCuadrado (100,100,renderer->makeColor(0,20,200));
            break;
        case ControlEvent::Wheel:
            std::cout << "StageCtrl Wheel event." << std::endl;
            break;
        case ControlEvent::WantFocus:
            std::cout << "StageCtrl WhantFocus event." << std::endl;
            break;
        case ControlEvent::GotFocus:
            std::cout << "StageCtrl GotFocus event." << std::endl;
            break;
        case ControlEvent::LostFocus:
            std::cout << "StageCtrl LostFocus event." << std::endl;
            break;
        case ControlEvent::Char:
            std::cout << "StageCtrl CharEvent event." << std::endl;
            break;
        case ControlEvent::LeftPress:
            std::cout << "StageCtrl LeftPress event." << std::endl;
            break;
        case ControlEvent::LeftRelease:
            std::cout << "StageCtrl LeftRelease event." << std::endl;
            break;
        case ControlEvent::RightPress:
            std::cout << "StageCtrl RightPress event." << std::endl;
            break;
        case ControlEvent::RightRelease:
            std::cout << "StageCtrl RightRelease event." << std::endl;
            break;
        case ControlEvent::MiddlePress:
            std::cout << "StageCtrl MiddlePress event." << std::endl;
            break;
        case ControlEvent::MiddleRelease:
            std::cout << "StageCtrl MiddleRelease event." << std::endl;
            break;
        default:
            break;
    }
    // /// @todo Definir un "defaultStage" para el renderer.
    return renderer->defaultControl(static_cast<Control*>(this), ev);
}

/// @brief Dibuja el marco del escenario.
///
/// @todo Hacer un método para IRenderer que sea:
///       @code
///         renderer->dibujarLimites (const Bloque limites, bool relleno);
///       @code
///
void StageCtrl::dibujarMarco (void) {
    if (renderer) {
        renderer->dibujarFrontera (x, y, width, height, renderer->makeColor(255, 0, 0));
    }
}