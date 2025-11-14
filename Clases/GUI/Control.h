#ifndef CONTROL_H
#define CONTROL_H

#include <algorithm>
#include <vector>
#include "Comando.h"
#include "IControlListener.h"

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
    RADIOBUTTON
};

class Control {
public:
    TipoControl tipo;
    int x, y, w, h;
    int fg, bg;
    int key;
    int flags;
    Comando* comando;
    void* data;

    Control(TipoControl t_, int x_, int y_, int w_, int h_,
            int fg_, int bg_, int key_, int flags_,
            Comando* cmd = nullptr, void* d = nullptr);

protected:
    std::vector<IControlListener*> listeners;
public:
    virtual ~Control() {}
    void addListener(IControlListener* listener) {
        listeners.push_back(listener);
    }
    void removeListener(IControlListener* listener) {
        listeners.erase(std::remove(listeners.begin(), listeners.end(), listener), listeners.end());
    }
protected:
    void notifyListeners() {
        for (auto* listener : listeners) {
            listener->controlChanged(this);
        }
    }
};

#endif // CONTROL_H
