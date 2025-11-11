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
            // Dibuja texto en coordenadas.
            auto amarillo = renderer->makeColor(255, 255, 0);
            renderer->dibujarTexto("Dibujando la fruta...", 20, 200, amarillo);
            renderer->refrescarPantalla();
        }
    }

    void dibujarCuadrado() {
        std::cout << "Dibujando cuadrado...\n";
        if (renderer) {
            // Dibuja cuadrado.
            auto rojo = renderer->makeColor(255, 0, 0);
            renderer->dibujarCuadrado (60, 150, rojo);
            renderer->refrescarPantalla();
        }
    }

};

#endif
