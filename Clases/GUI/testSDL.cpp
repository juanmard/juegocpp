

#include <iostream>
#include <string>
#include "SliderCtrl.h"
#include "IInput.h"

#define SDL2

#ifdef SDL2
    #include "SDL2Renderer.h"
    #include "SDL2Input.h"

    #define _Renderer SDL2Renderer
    #define _Input SDL2Input
    #define _main SDL_main
#endif
#ifdef ALLEGRO4
    #include "AllegroRenderer.h"
    #include "AllegroInput.h"

    #define _Renderer AllegroRenderer
    #define _Input AllegroInput
    #define _main main
#endif


// Comprueba si (x,y) está dentro del rectángulo dado
bool estáDentroCuadrado(int x, int y, int rx, int ry, int rw, int rh) {
    return x >= rx && x <= rx + rw && y >= ry && y <= ry + rh;
}

int _main(int argc, char* argv[]) {
    try {
        _Renderer renderer;
        _Input input;

        const int cuadradoX = 100;
        const int cuadradoY = 100;
        const int ancho = 150;
        const int alto = 150;

        bool rojo = true;
        std::string textoActual = "Cuadrado Rojo";

        std::cout << "Inicio" << std::endl;
        SliderCtrl slider (50, 400, 300, 8, 0, 0, 0, 0);
        slider.setInput((IInput*)&input);
        slider.setRenderer((IRenderer*)&renderer);
        VectorCtrl vector (50, 450, 200, 30, 0, 0, 0, 0);
        vector.setNombre("Vector de prueba.");
        vector.setInput((IInput*)&input);
        vector.setRenderer((IRenderer*)&renderer);
        
        // Prueba.
        vector.setXY(slider.pos,10);
        slider.addListener(&vector);
        vector.addListener(&slider);

        InputEvent ev;

        bool running = true;
        while (running) {
           // Se procesan eventos y estados.
            input.procesarEventos(ev);
            renderer.defaultSlider(&slider, ev);
            renderer.defaultVector(&vector, ev);
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
            //renderer.limpiarPantalla(renderer.makeColor(0, 0, 0));
            renderer.dibujarCuadrado(cuadradoX, cuadradoY, rojo ? renderer.makeColor(255, 0, 0) : renderer.makeColor(0, 255, 0));
            renderer.dibujarTexto(textoActual.c_str(), cuadradoX, cuadradoY + alto + 10, renderer.makeColor(255, 255, 255));
            renderer.dibujarTexto("Haz clic en el cuadrado para cambiar su color.", 10, 10, renderer.makeColor(200, 200, 200)); 
            ev.event = ControlEvent::Draw;
            renderer.defaultSlider(&slider, ev);
            renderer.defaultVector(&vector, ev);
            renderer.refrescarPantalla();

            // Se hace una espera.
            input.esperar(10); // Aproximado 60 fps
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}
#ifdef ALLEGRO4
END_OF_MAIN();
#endif
