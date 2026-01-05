#ifndef CONTROL_H
#define CONTROL_H

#include <algorithm>
#include <vector>
#include <string>
#include <variant>      // Necesita C++:17. Se usa para generar un "union" más seguro ante los datos enviados con el evento.
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
    VECTOR,
    STAGE
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

/// Pruebas para integrar datos en la estructura del evento.
/// Se definen los tipos de pulsdadores en el ratón.
enum class MouseButton { Left, Middle, Right, None };

/// Estructuras de datos para eventos.
/// Estructra ante un "click" de ratón.
struct MouseClickData {
    int x, y;
    MouseButton button;
    int clicks;    // 1 = click, 2 = doble click, etc.
};

/// Estructura enviada en el movimiento del cursor del ratón.
struct MouseMoveData {
    int x, y;           ///< Posición del ratón en ventana donde se produce el evento.
    float velx, vely;   ///< Velocidad respecto al último movimiento.
};

/// Estructura ante un evento de teclado.
struct KeyData {
    int key;       // código de tecla
    int modifiers; // Ctrl, Shift, etc.
};

// Datos del evento posible.
using EventData = std::variant<std::monostate, MouseClickData, MouseMoveData, KeyData>;

// Estructura que representa un evento de entrada
struct InputEvent {
    ControlEvent event;
    EventData data;
};

namespace jmr {
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
        std::vector<IControlListener*> listeners;

        void notifyListeners() {
            for (auto* listener : listeners) {
                listener->controlChanged(this);
            }
        }
    };
}

#endif // CONTROL_H
