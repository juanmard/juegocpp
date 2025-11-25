#include <iostream>
#include <string>
#include "SDL2Renderer.h"
#include "SDL2Input.h"
#include "SliderCtrl.h"
#include "IInput.h"

// Comprueba si (x,y) está dentro del rectángulo dado
bool estáDentroCuadrado(int x, int y, int rx, int ry, int rw, int rh) {
    return x >= rx && x <= rx + rw && y >= ry && y <= ry + rh;
}

int SDL_main(int argc, char* argv[]) {
    try {
        SDL2Renderer renderer;
        SDL2Input input;

        const int cuadradoX = 100;
        const int cuadradoY = 100;
        const int ancho = 150;
        const int alto = 150;

        bool rojo = true;
        std::string textoActual = "Cuadrado Rojo";

        std::cout << "Inicio" << std::endl;
        SliderCtrl slider (10, 400);
        slider.setInput((IInput*)&input);
        InputEvent ev;

        bool running = true;
        while (running) {
            // Se procesan eventos y estados.
            input.procesarEventos(ev);
            renderer.defaultSlider(&slider, ev);
            if (input.clicIzquierdo()) {
                int mouseX, mouseY;
                input.obtenerPosicionMouse(mouseX, mouseY);
                std::cout << mouseX << ", " << mouseY << std::endl;
                if (estáDentroCuadrado(mouseX, mouseY, cuadradoX, cuadradoY, ancho, alto)) {
                    rojo = !rojo;
                    textoActual = rojo ? "Cuadrado Rojo" : "Cuadrado Verde";
                }
            }


            renderer.limpiarPantalla(renderer.makeColor(0, 0, 0));
            input.obtenerCodigoTecla ();
            IInput::Key tecla = input.getKey();
            if (tecla == IInput::Key::ENTER)
            {
                renderer.dibujarTexto("Pulsado ENTER", 10, 450, renderer.makeColor(128, 255, 255));
                std::cout << "Pulsado ENTER" << std::endl;
            }

            if (tecla == IInput::Key::ESC) {
                running = false;
                renderer.dibujarTexto("Pulsado ESC", 10, 450, renderer.makeColor(128, 255, 255));
                std::cout << "Pulsado ESC" << std::endl;
            }

            // Se redibujan los elementos.
            renderer.dibujarCuadrado(cuadradoX, cuadradoY, rojo ? renderer.makeColor(255, 0, 0) : renderer.makeColor(0, 255, 0));
            renderer.dibujarTexto(textoActual.c_str(), cuadradoX, cuadradoY + alto + 10, renderer.makeColor(255, 255, 255));
            renderer.dibujarTexto("Haz clic en el cuadrado para cambiar su color.", 10, 10, renderer.makeColor(200, 200, 200)); 
            ev.event = ControlEvent::Draw;
            renderer.defaultSlider(&slider, ev);
            renderer.refrescarPantalla();

            // Se hace una espera.
            input.esperar(16); // Aproximado 60 fps
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}
