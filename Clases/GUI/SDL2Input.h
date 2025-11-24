#ifndef SDL2INPUT_H
#define SDL2INPUT_H

#include "Control.h"
#include "IInput.h"
#include <SDL2/SDL.h>

class SDL2Input : public IInput {
public:
    SDL2Input();
    ~SDL2Input();

    int obtenerCodigoTecla() override;
    Key getKey() override;

    void esperar(int ms) override;

    bool clicDerecho() override;
    bool clicIzquierdo() override;

    void obtenerPosicionMouse(int& x, int& y) override;

    // Procesar eventos SDL, debe llamarse en el bucle principal
    void procesarEventos(InputEvent& ev);

private:
    int lastKeyCode;
    IInput::Key lastKey;
    bool rightClick;
    bool leftClick;
};

#endif
