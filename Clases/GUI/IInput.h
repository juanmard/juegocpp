#ifndef IINPUT_H
#define IINPUT_H

class InputEvent;

class IInput {
public:
    enum class Key {
        NONE,
        Key_A, Key_B, Key_C, Key_D, Key_E, Key_F,
        Key_0, Key_1, Key_2, Key_3, Key_4, Key_5, Key_6, Key_7, Key_8, Key_9,
        ESPACE, ESC, ENTER,
        LSHIFT, RSHIFT, LCONTROL, RCONTROL, ALT, ALTGR
    };

public:
    // Devuelve el código de la tecla pulsada.
    virtual int obtenerCodigoTecla() = 0;
    virtual Key getKey() = 0;

    // Opcional, para esperar o pausar.
    virtual void esperar(int ms) = 0;

    virtual bool clicDerecho() = 0;
    virtual bool clicIzquierdo() = 0;

    /// Obtener posición del mouse (coordenadas en pantalla).
    virtual void obtenerPosicionMouse(int& x, int& y) = 0;

    virtual void procesarEventos(InputEvent &ev) = 0;
    virtual ~IInput() {}
};

#endif