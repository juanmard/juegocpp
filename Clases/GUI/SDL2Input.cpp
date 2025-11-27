#include "SDL2Input.h"

SDL2Input::SDL2Input()
    : lastKeyCode(0), lastKey(Key::NONE), rightClick(false), leftClick(false) {}

SDL2Input::~SDL2Input() {}

int SDL2Input::obtenerCodigoTecla() {
    int key = lastKeyCode;
    lastKeyCode = 0; // Reset para no repetir
    return key;
}

IInput::Key SDL2Input::getKey() {
    Key k = lastKey;
    lastKey = IInput::Key::NONE; // Reiniciar
    return k;
}

void SDL2Input::esperar(int ms) {
    SDL_Delay(ms);
}

bool SDL2Input::clicDerecho() {
    bool c = rightClick;
    rightClick = false; // Reset
    return c;
}

bool SDL2Input::clicIzquierdo() {
    bool c = leftClick;
    leftClick = false; // Reset
    return c;
}

void SDL2Input::procesarEventos(InputEvent &ev) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_KEYDOWN:
            lastKeyCode = event.key.keysym.sym;
            // Mapear a Key enum simple (ampliar según necesidad)
            switch (event.key.keysym.sym) {
            case SDLK_a: lastKey = Key::Key_A; break;
            case SDLK_b: lastKey = Key::Key_B; break;
            case SDLK_c: lastKey = Key::Key_C; break;
            case SDLK_0: lastKey = Key::Key_0; break;
            case SDLK_1: lastKey = Key::Key_1; break;
            case SDLK_2: lastKey = Key::Key_2; break;
            case SDLK_3: lastKey = Key::Key_3; break;
            case SDLK_4: lastKey = Key::Key_4; break;
            case SDLK_5: lastKey = Key::Key_5; break;
            case SDLK_6: lastKey = Key::Key_6; break;
            case SDLK_7: lastKey = Key::Key_7; break;
            case SDLK_8: lastKey = Key::Key_8; break;
            case SDLK_9: lastKey = Key::Key_9; break;
            case SDLK_ESCAPE: lastKey = Key::ESC; break;
            case SDLK_RETURN: lastKey = Key::ENTER; break;
            case SDLK_LSHIFT: lastKey = Key::LSHIFT; break;
            case SDLK_RSHIFT: lastKey = Key::RSHIFT; break;
            case SDLK_LCTRL: lastKey = Key::LCONTROL; break;
            case SDLK_RCTRL: lastKey = Key::RCONTROL; break;
            case SDLK_LALT: lastKey = Key::ALT; break;
            case SDLK_MODE: lastKey = Key::ALTGR; break;
            default: lastKey = Key::NONE; break;
            }
            break;

        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button == SDL_BUTTON_LEFT) {
                // SDL_Log ("LeftPress");
                ev.event = ControlEvent::LeftPress;
                leftClick = true;
            } else if (event.button.button == SDL_BUTTON_RIGHT){
                // SDL_Log ("RightPress");
                ev.event = ControlEvent::RightPress;
                rightClick = true;
            }
            if (event.button.clicks == 2){
                ev.event = ControlEvent::DoubleClick;
                // SDL_Log ("DoubleClick");
            }
            break;

        case SDL_MOUSEBUTTONUP:
            if (event.button.button == SDL_BUTTON_LEFT) {
                // SDL_Log ("LeftRelease");
                ev.event = ControlEvent::LeftRelease;
                leftClick = false;
            } else if (event.button.button == SDL_BUTTON_RIGHT){
                // SDL_Log ("RightRelease");
                ev.event = ControlEvent::RightRelease;
                rightClick = false;
            }
            break;

        case SDL_MOUSEMOTION:
            ev.event = ControlEvent::MouseMove;
            // SDL_Log ("MouseMove");
            break;

        case SDL_MOUSEWHEEL:
            ev.event = ControlEvent::Wheel;
            ev.c = event.wheel.y;
            //SDL_Log ("MouseWheel");
            //SDL_Log ((std::to_string (event.wheel.direction) + ", x: " + std::to_string(event.wheel.x) + ", y: " + std::to_string(event.wheel.y)).c_str()); 
            break;

        case SDL_QUIT:
            exit(0);
            break;
        }
    }
}

void SDL2Input::obtenerPosicionMouse(int& x, int& y) {
    SDL_GetMouseState(&x, &y);
}
