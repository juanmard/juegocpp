#define SDL_MAIN_HANDLED
#include <iostream>
#include <string>
#include "SDL2Renderer.h"
#include "SDL2Input.h"
#include "IInput.h"

// Comprueba si (x,y) está dentro del rectángulo dado
bool estáDentroCuadrado(int x, int y, int rx, int ry, int rw, int rh) {
    return x >= rx && x <= rx + rw && y >= ry && y <= ry + rh;
}

int main() {
    try {
        SDL2Renderer renderer;
        SDL2Input input;

        const int cuadradoX = 100;
        const int cuadradoY = 100;
        const int ancho = 150;
        const int alto = 150;

        bool rojo = true;
        std::string textoActual = "Cuadrado Rojo";

        bool running = true;

        while (running) {
            input.procesarEventos();

            if (input.clicIzquierdo()) {
                int mouseX, mouseY;
                input.obtenerPosicionMouse(mouseX, mouseY);
                if (estáDentroCuadrado(mouseX, mouseY, cuadradoX, cuadradoY, ancho, alto)) {
                    rojo = !rojo;
                    textoActual = rojo ? "Cuadrado Rojo" : "Cuadrado Verde";
                }
            }

            renderer.limpiarPantalla(renderer.makeColor(0, 0, 0));

            renderer.dibujarCuadrado(cuadradoX, cuadradoY,
                rojo ? renderer.makeColor(255, 0, 0) : renderer.makeColor(0, 255, 0));

            renderer.dibujarTexto(textoActual.c_str(), cuadradoX, cuadradoY + alto + 10,
                renderer.makeColor(255, 255, 255));

            renderer.refrescarPantalla();

            if (input.getKey() == IInput::Key::ESC) {
                running = false;
            }

            input.esperar(16); // Aproximado 60 fps
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}
