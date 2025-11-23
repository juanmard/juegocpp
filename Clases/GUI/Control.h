#ifndef CONTROL_H
#define CONTROL_H

#include <algorithm>
#include <vector>
#include <string>
#include "Comando.h"
#include "IControlListener.h"
#include "IRenderer.h"
#include "IInput.h"

enum class TipoControl {
    BOX,
    TEXT_AREA,
    MENU,
    TEXTBOX,
    BOTON,
    SLIDER,
    CAJA_TEXTO,
    LABEL,
    CHECKBOX,
    BUTTON,
    RADIOBUTTON,
    VECTOR
};

// Enumeración genérica de eventos para el GUI
enum class ControlEvent {
    Start,
    End,
    Draw,
    Click,
    DoubleClick,
    Key,
    Char,
    UChar,
    XChar,
    WantFocus,
    GotFocus,
    LostFocus,
    GotMouse,
    LostMouse,
    Idle,
    Radio,
    Wheel,
    LeftPress,
    LeftRelease,
    MiddlePress,
    MiddleRelease,
    RightPress,
    RightRelease,
    WantMouse,
    MouseMove,
    Unknown
};

// Estructura que representa un evento de entrada
struct InputEvent {
    ControlEvent event;
    int c;              // valor asociado (ej. delta rueda o tecla)
    int modifiers;      // bitmask para Ctrl, Shift, etc.
};

class Control {
public:
    IRenderer* renderer = nullptr;  // ¿Hacer este puntero estático para que sea común a todos los controles?
    IInput* input = nullptr;

    std::string nombre;
    TipoControl tipo;
    int x, y, w, h;
    int fg, bg;
    int key;
    int flags;
    Comando* comando = nullptr;
    void* data;

    Control(TipoControl t_, int x_, int y_, int w_, int h_,
            int fg_, int bg_, int key_, int flags_,
            Comando* cmd = nullptr, void* d = nullptr);

protected:
    std::vector<IControlListener*> listeners;
public:
    virtual ~Control() {}
    virtual int manejarEvento(const InputEvent& ev) { return 0; };

    void addListener(IControlListener* listener) {
        listeners.push_back(listener);
    }
    void removeListener(IControlListener* listener) {
        listeners.erase(std::remove(listeners.begin(), listeners.end(), listener), listeners.end());
    }


    void setNombre(const std::string& nombre);
    void setRenderer(IRenderer* r);
    void setInput(IInput* i);

protected:
    void notifyListeners() {
        for (auto* listener : listeners) {
            listener->controlChanged(this);
        }
    }
};

#endif // CONTROL_H
