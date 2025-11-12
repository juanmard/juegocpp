#include "Menu.h"
#include "ComandosConcretos.h"
#include "Grafico.h"
#include "AllegroRenderer.h"
#include "AllegroInput.h"
#include "Control.h"
#include "Dialog.h"
#include "SliderCtrl.h"

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
            dlg.setRenderer(&renderer);
            CommandSalir salirCmd;
            CommandOtro otroCmd;
            ComandoTest testCmd(new SliderCtrl (TipoControl::SLIDER, 100,100));
            auto blanco = renderer.makeColor(200, 200, 200);
            auto rojo = renderer.makeColor(255, 0, 0);
            dlg.agregarControl(Control(TipoControl::BOX,       20,  20, 400, 50, rojo, blanco, 0, 0, &salirCmd));
            dlg.agregarControl(Control(TipoControl::SLIDER,    20,  80, 400, 50, rojo, blanco, 0, 0, &otroCmd));
            dlg.agregarControl(Control(TipoControl::BOX,       20, 140, 400, 50, rojo, blanco, 0, 0, &otroCmd));
            dlg.agregarControl(SliderCtrl(TipoControl::SLIDER, 20, 200, 400, 50, rojo, blanco, 0, 0, &testCmd));
            dlg.agregarControl(Control(TipoControl::TEXT_AREA, 20, 260, 400, 50, rojo, blanco, 0, 0, &testCmd));
            dlg.agregarControl(Control(TipoControl::BOX,       20, 320, 400, 50, rojo, blanco, 0, 0, &otroCmd));
            int resultado = dlg.mostrar();
        }
    }
    return D_CLOSE;
}
END_OF_MAIN();
