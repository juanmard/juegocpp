#include "Menu.h"
#include "ComandosConcretos.h"
#include "Grafico.h"
#include "AllegroAdapter.h"

int main() {
    AllegroRenderer renderer;
    AllegroInput input;

    Grafico fruta(&renderer);  // Pasa el renderer al gráfico

    Menu menuPrincipal("Menú Principal");

    auto comandoDibujar = std::make_shared<ComandoDibujar>(&fruta);
    menuPrincipal.agregarItem(ItemMenu("Dibujar fruta", true, comandoDibujar));
    menuPrincipal.agregarItem(ItemMenu("Borrar fruta", false, comandoDibujar));

    menuPrincipal.mostrar(renderer, input);

    return 0;
}
END_OF_MAIN();
