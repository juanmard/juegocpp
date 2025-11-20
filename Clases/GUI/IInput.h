#ifndef IINPUT_H
#define IINPUT_H

constexpr int ESC_KEY_CODE = 59;
constexpr int KEY_1_CODE = 28;

enum class Key {
    NONE,
    LSHIFT,
    RSHIFT,
    LCONTROL,
    RCONTROL,
    ALT,
    ALTGR
};

class IInput {
public:
    // Devuelve el código de la tecla pulsada, o 0 si no hay.
    virtual int obtenerCodigoTecla() = 0;
    virtual Key getKey() = 0;

    // Opcional, para esperar o pausar.
    virtual void esperar(int ms) = 0;

    virtual bool clicDerecho() = 0;
    virtual bool clicIzquierdo() = 0;
    virtual ~IInput() {}
};

#endif