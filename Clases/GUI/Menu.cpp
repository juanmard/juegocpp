#include "Menu.h"

void Menu::mostrar(IRenderer& renderer, IInput& input) {
    bool salir = false;

    auto negro = renderer.makeColor(0, 0, 0);
    auto blanco = renderer.makeColor(255, 255, 255);
    auto gris = renderer.makeColor(128, 128, 128);
    auto rojo = renderer.makeColor(255, 0, 0);

    while (!salir) {
        renderer.limpiarPantalla(gris);
        renderer.dibujarTexto(titulo.c_str(), 20, 20, blanco);

        for (size_t i = 0; i < items.size(); ++i) {
            int y = 60 + i * 20;
            std::string texto = std::to_string(i + 1) + ". " + items[i].nombre;
            renderer.dibujarTexto(texto.c_str(), 40, y, items[i].estado ? blanco : negro);
        }
        renderer.dibujarTexto("Presione ESC para salir", 20, 400, rojo);

        renderer.refrescarPantalla();
        int index=10;
        IInput::Key tecla = input.getKey();
        switch (tecla) {
            case IInput::Key::ESC:
                salir = true;
                break;
            case IInput::Key::Key_1: index = 0; break;
            case IInput::Key::Key_2: index = 1; break;
            case IInput::Key::Key_3: index = 2; break;
            case IInput::Key::Key_4: index = 3; break;
            case IInput::Key::Key_5: index = 4; break;
            default:
                break;
        }
        if (index < 10 && items[index].comando) {
            items[index].comando->ejecutar();
            index = 10;
        }
        input.esperar(500);
    }
}

// void Menu::mostrar(int x, int y) {
//     if (!renderer) return;
//     int selected = renderer->mostrarMenu(*this, x, y);
//     if (selected >= 0 && (size_t)selected < items.size()) {
//         if (items[selected].comando && items[selected].estado) {
//             items[selected].comando->ejecutar();
//         }
//     }
// }

void Menu::mostrar(int x, int y) {
    if (renderer) {
        renderer->mostrarMenu(*this, x, y);
    }
}

void Menu::setRenderer(IRenderer* r) {
    renderer = r;
}
