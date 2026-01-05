// Interfaz para observadores de cambios en un Control.

#ifndef ICONTROLLISTENER_H
#define ICONTROLLISTENER_H

namespace jmr {
    class Control;
}

class IControlListener {
public:
    virtual void controlChanged(jmr::Control* control) = 0;
    virtual ~IControlListener() {}
};

#endif