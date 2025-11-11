#include "Menu.h"
#include "ComandosConcretos.h"
#include "Grafico.h"
#include "AllegroAdapter.h"

int main() {
    AllegroRenderer renderer;
    AllegroInput input;

    Grafico fruta(&renderer);  // Pasa el renderer al gráfico
    Menu menuPrincipal("Menú Principal");
 
    menuPrincipal.setRenderer(&renderer);

    auto comandoDibujar = std::make_shared<ComandoDibujar>(&fruta);
    auto cmd = std::make_shared<ComandoEjemplo>();
    menuPrincipal.agregarItem(ItemMenu("Dibujar fruta", true, comandoDibujar));
    menuPrincipal.agregarItem(ItemMenu("Borrar fruta", true, cmd));
    menuPrincipal.agregarItem(ItemMenu("Clonar fruta", false, cmd));

    auto gris = renderer.makeColor(128, 128, 128);
    renderer.limpiarPantalla(gris);
    show_mouse(screen);
    menuPrincipal.mostrar(renderer, input);
    renderer.limpiarPantalla(gris);
    while (input.obtenerCodigoTecla() != ESC_KEY_CODE) {
        if (input.clicDerecho()){
            menuPrincipal.mostrar (mouse_x, mouse_y);
        }
    }
    return 0;
}
END_OF_MAIN();
