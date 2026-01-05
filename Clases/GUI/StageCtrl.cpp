#include "StageCtrl.h"
#include "Actor.h"
#include "ActorManager.h"
#include "SliderCtrl.h"

void StageCtrl::controlChanged(Control* control) {
        switch (control->tipo){
            case TipoControl::SLIDER:
            {
                if (auto sldc = dynamic_cast<SliderCtrl*>(control)) {
                    Actor* act = editor_manager->game->actor_manager->get_actor(1);
                    if (act)
                    {
                        act->set_x(2*sldc->pos);
                    }
                }
            }
            break;
            case TipoControl::VECTOR:
            {
                if (auto vct = dynamic_cast<VectorCtrl *>(control)) {
                    Actor* act = editor_manager->game->actor_manager->get_actor(1);
                    if (act && (editor_manager->estado == EstadoActor::atrapado))
                    {
                        act->set_x(vct->x);
                        act->set_y(vct->y);
                        // Se provoca la actualización del control.
                        const InputEvent ev { ControlEvent::Draw, MouseMoveData{0, 0, 0.0f, 0.0f} };
                        this->manejarEvento (ev);
                    }
                }
            }
            break;
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
            editor_manager->dibujar_escenario();
            if (drawEjes) {
                // @warning No llega a dibujarlos porque el "editor_manager" trabaja con un buffer intermedio.
                //          Para que funcione, el "editor_manager" debe independizarse de "Allegro4".
                // editor_manager->dibujar_ejes();
                this->renderer->dibujarEjes ();
            }
            dibujarMarco();
            break;
        case ControlEvent::DoubleClick:
        {
            auto& move = std::get<MouseMoveData>(ev.data);
            // std::cout << "StageCtrl DoubleClick event." << std::endl;
            // std::cout << "Escenario: " << editor_manager->get_escenario_xy () << std::endl;
            // std::cout << "Mouse: " << move.x << ", " << move.y << std::endl;
            // std::cout << "Control: " << x << ", " << y << std::endl;
            // std::cout << "Referencia: " << editor_manager->refX << ", " << editor_manager->refY << std::endl;
            editor_manager->mover_escenario (x, y);
            editor_manager->dibujar_escenario();
        }
        break;

        case ControlEvent::Wheel:
            std::cout << "StageCtrl Wheel event." << std::endl;
            break;
        case ControlEvent::WantFocus:
            std::cout << "StageCtrl WhantFocus event." << std::endl;
            break;
        case ControlEvent::GotFocus:
            std::cout << "StageCtrl GotFocus event." << std::endl;
            renderer->invertirBackgroundForeground (this);
            break;
        case ControlEvent::LostFocus:
            std::cout << "StageCtrl LostFocus event." << std::endl;
            renderer->invertirBackgroundForeground (this);
            break;
        case ControlEvent::Char:
            std::cout << "StageCtrl CharEvent event." << std::endl;
            break;
        case ControlEvent::LeftPress:
            {
                // std::cout << "StageCtrl LeftPress event." << std::endl;
                auto& move = std::get<MouseMoveData>(ev.data);
                Actor* act = editor_manager->actor;
                if (act) {
                    editor_manager->estado = EstadoActor::atrapado;
                    act->set_color (15);
                    editor_manager->refX = editor_manager->get_escenario_x() + move.x - x - act->get_x();
                    editor_manager->refY = editor_manager->get_escenario_y() + move.y - y - act->get_y();
                    this->notifyListeners();
                }
            }
            break;
        case ControlEvent::LeftRelease:
            // std::cout << "StageCtrl LeftRelease event." << std::endl;
            if (editor_manager->actor) {
                editor_manager->estado = EstadoActor::libre;
                editor_manager->actor->set_color (5);
            }
            break;
        case ControlEvent::RightPress:
            std::cout << "StageCtrl RightPress event." << std::endl;
            if (editor_manager->actor) {
                editor_manager->duplicar_actor (editor_manager->actor);
            }
            break;
        case ControlEvent::RightRelease:
            std::cout << "StageCtrl RightRelease event." << std::endl;
            break;
        case ControlEvent::MiddlePress:
            {
                // std::cout << "StageCtrl MiddlePress event." << std::endl;
                auto& move = std::get<MouseMoveData>(ev.data);
                editor_manager->refX = editor_manager->get_escenario_x() + move.x - x;
                editor_manager->refY = editor_manager->get_escenario_y() + move.y - y;
                dragEscenario = true;
            }
            break;
        case ControlEvent::MiddleRelease:
            // std::cout << "StageCtrl MiddleRelease event." << std::endl;
            dragEscenario = false;
            break;
        case ControlEvent::MouseMove: 
        {
//                std::cout << "StageCtrl MouseMove event." << std::endl;
            auto& move = std::get<MouseMoveData>(ev.data);

            // std::cout << "Mouse:     " << move.x << ", " << move.y << std::endl;
            // std::cout << "Escenario: " << editor_manager->get_escenario_x() << ", " << editor_manager->get_escenario_y() << std::endl;
            // std::cout << "Control:   " << x << ", " << y << std::endl;
            // std::cout << "Ref:       " << editor_manager->refX << ", " << editor_manager->refY << std::endl << std::endl;

            // Si se mueve el ratón estando el escenario en modo «drag», sólo se mueve el escenario.
            // En otro caso se mira el estado del actor.
            if (dragEscenario) {
                editor_manager->mover_escenario( editor_manager->refX - move.x + x,
                                                 editor_manager->refY - move.y + y);
            } else {
                switch (editor_manager->estado) {
                case EstadoActor::activado:
                    break;
                case EstadoActor::atrapado:
                    editor_manager->mover_actor (editor_manager->get_escenario_x() - x + move.x - editor_manager->refX,
                                                 editor_manager->get_escenario_y() - y + move.y - editor_manager->refY);
                    break;
                case EstadoActor::libre:
                    {
                        Actor* actor = editor_manager->get_actor (editor_manager->get_escenario_x() - x + move.x,
                                                                  editor_manager->get_escenario_y() - y + move.y);
                        // std::cout << "Actor: " << (actor ? actor->get_nombre() : "null") << std::endl;
                        // Si el actor bajo el ratón es distinto del guardado...
                        if (actor != editor_manager->actor) {
                            // Si el guardado existe...
                            if (editor_manager->actor) {
                                // Se devuelve el color al guardado y se libera...
                                editor_manager->actor->set_color (~(editor_manager->actor->get_color()));
                                editor_manager->liberar_actor ();
                            }

                            // Si bajo el ratón existe el actor...
                            if (actor) {
                                // Se cambia el color y se guarda.
                                actor->set_color (~(actor->get_color()));
                                editor_manager->actor = actor;
                                notifyListeners();
                            }
                        }
                    }
                    break;
                default:
                    break;
                }
            }

            // Se actualiza el escenario.
            editor_manager->dibujar_escenario ();
        }
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
        renderer->dibujarFrontera (this);
    }
}
