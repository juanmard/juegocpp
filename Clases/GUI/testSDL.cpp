#define SDL_MAIN_HANDLED
#include "SDL2Renderer.h"

int main() {
    SDL2Renderer renderer;

    renderer.limpiarPantalla(renderer.makeColor(0, 0, 0));
    renderer.dibujarCuadrado(100, 100, renderer.makeColor(255, 0, 255));
    renderer.dibujarTexto("Texto con SDL2", 120, 220, renderer.makeColor(255, 255, 255));
    renderer.refrescarPantalla();

    SDL_Delay(3000);
    return 0;
}
