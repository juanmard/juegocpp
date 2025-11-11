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

        int codigo = input.obtenerCodigoTecla();
        switch (codigo) {
        case ESC_KEY_CODE:
            salir = true;
            break;
        case KEY_1_CODE:
            if (!items.empty() && items[0].comando)
                items[0].comando->ejecutar();
            break;
        case KEY_2_CODE:
            if (!items.empty() && items[1].comando)
                items[1].comando->ejecutar();
            break;
        case KEY_3_CODE:
            if (!items.empty() && items[2].comando)
                items[2].comando->ejecutar();
            break;
        // Otros casos según se necesiten
        default:
            break;
        }
        input.esperar(500);
    }
}

void Menu::mostrar(int x, int y) {
    if (!renderer) return; // no renderer definido
    int selected = renderer->mostrarMenu(*this, x, y);
    if (selected >= 0 && (size_t)selected < items.size()) {
        if (items[selected].comando && items[selected].estado) {
            items[selected].comando->ejecutar();
        }
    }
}

void Menu::setRenderer(IRenderer* r) {
    renderer = r;
}
