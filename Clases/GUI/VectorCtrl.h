#ifndef VECTORCTRL_H
#define VECTORCTRL_H

#include <iostream>
#include "Control.h"
#include "IControlListener.h"
#include "SliderCtrl.h"

class VectorCtrl : public Control, public IControlListener {
public:
    // @todo Sustituir en futuro por una clase (p.j. la clase "Bloque").
    unsigned int x;   ///< Posición - Coordenada x.
    unsigned int y;   ///< Posición - Coordenada y.
    //unsigned int z;   ///< Posición - Coordenada z.
    std::string texto; ///< Texto asociado al vector.

    VectorCtrl(int x_, int y_, int w_, int h_, int fg_, int bg_, int key_, int flags_, Comando* cmd = nullptr, void* d = nullptr)
        : Control(TipoControl::VECTOR, x_, y_, w_, h_, fg_, bg_, key_, flags_, cmd, d), x(0), y(0) {};
        
    VectorCtrl(unsigned int x_, unsigned int y_) : Control(TipoControl::VECTOR, x_, y_, 0, 0, 0, 0, 0, 0), x(0), y(0) {};
    void setComando (Comando* cmd) { comando = cmd; };

    // Métodos específicos para "VectorCtrl".
    void setXY (unsigned int x_, unsigned int y_) {
        bool changed = false;
        if ( x != x_) {
             x = x_;
             changed = true;
        }
        if ( y != y_) {
             y = y_;
             changed = true;
        }
        if (changed) {
            renderer->updateVector(this);
            notifyListeners();
        }
    }

    void controlChanged(Control* control) override;
    int manejarEvento(const InputEvent& ev) override {return 1;};
};

#endif // VECTORCTRL_H
