#include "Menu.h"
#include "ComandosConcretos.h"
#include "Grafico.h"
#include "AllegroRenderer.h"
#include "AllegroInput.h"
#include "Control.h"
#include "Dialog.h"

int main() {
    AllegroRenderer renderer;
    AllegroInput input;

    Menu menuPrincipal("Menú Principal");
    menuPrincipal.setRenderer(&renderer);
    Grafico fruta(&renderer);

    auto comandoDibujar = std::make_shared<ComandoDibujar>(&fruta);
    auto cmd = std::make_shared<ComandoEjemplo>();
    auto comandoCuadrado = std::make_shared<ComandoCuadrado>(&fruta);

    menuPrincipal.agregarItem(ItemMenu("Dibujar fruta", true, comandoDibujar));
    menuPrincipal.agregarItem(ItemMenu("Borrar fruta", true, cmd));
    menuPrincipal.agregarItem(ItemMenu("Clonar fruta", false, cmd));
    menuPrincipal.agregarItem(ItemMenu("Cuadrado", true, comandoCuadrado));

    auto gris = renderer.makeColor(128, 128, 128);
    renderer.limpiarPantalla(gris);
    show_mouse(screen);
    menuPrincipal.mostrar(renderer, input);
    renderer.limpiarPantalla(gris);
    while (input.obtenerCodigoTecla() != ESC_KEY_CODE) {
        if (input.clicDerecho()){
            menuPrincipal.mostrar (mouse_x, mouse_y);
        }
        if (input.clicIzquierdo()){
            renderer.limpiarPantalla(gris);
            Dialog dlg;
            AllegroRenderer allegroRenderer;
            dlg.setRenderer(&allegroRenderer);
            CommandSalir salirCmd;
            CommandOtro otroCmd;
            dlg.agregarControl(Control(16, 24, 612, 300, 254, 50, 0, 0, &salirCmd));
            dlg.agregarControl(Control(0, 0, 640, 15, 7, 15, 0, 0, &otroCmd));
            int resultado = dlg.mostrar();
        }
    }
    return 0;
}
END_OF_MAIN();
