#ifndef GRAFICO_H
#define GRAFICO_H

#include <iostream>

class Grafico {
    IRenderer* renderer;  // Puntero al renderer para dibujar en pantalla
public:
    Grafico(IRenderer* r = nullptr) : renderer(r) {}

    void setRenderer(IRenderer* r) {
        renderer = r;
    }

    void dibujar() {
        std::cout << "Dibujando la fruta...\n";
        if (renderer) {
            // Dibuja texto en coordenadas (20, 100) con color blanco.
            auto blanco = renderer->makeColor(255, 255, 255);
            renderer->dibujarTexto("Dibujando la fruta...", 20, 100, blanco);
            renderer->refrescarPantalla();
        }
    }
};

#endif
