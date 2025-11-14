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
    // Se comenta para ir directamente a la segunda prueba.
    // menuPrincipal.mostrar(renderer, input);
    renderer.limpiarPantalla(gris);
    while (input.obtenerCodigoTecla() != ESC_KEY_CODE) {
        if (input.clicDerecho()){
            menuPrincipal.mostrar (mouse_x, mouse_y);
        }
        if (input.clicIzquierdo()){
            renderer.limpiarPantalla(gris);
            Dialog dlg;
            dlg.setRenderer(&renderer);
            auto blanco = renderer.makeColor(200, 200, 200);
            auto rojo = renderer.makeColor(255, 0, 0);
            auto azul = renderer.makeColor(0, 0, 255);
            SliderCtrl sliderTest(20, 200, 400, 50, azul, blanco, 0, 0);
            
            // @warning Esta forma de «enlazar» el comando con el control no funciona.
            //          El cambio de valores en el control de Allegro no se transfiere al objeto instanciado.
            //
            //ComandoTest testCmd(&sliderTest);
            //sliderTest.setComando (&testCmd);

            CommandSalir salirCmd;
            CommandOtro otroCmd;
            dlg.agregarControl(Control(TipoControl::SLIDER,    20,  20, 400, 50, rojo, blanco, 0, 0, &salirCmd));
            dlg.agregarControl(Control(TipoControl::BOX,       20,  80, 400, 50, rojo, blanco, 0, 0, &salirCmd));
            dlg.agregarControl(Control(TipoControl::BUTTON,    20, 140, 400, 50, rojo, blanco, 0, 0, &salirCmd));
            dlg.agregarControl(sliderTest);
            dlg.agregarControl(Control(TipoControl::LABEL,     20, 260, 400, 50, rojo, blanco, 0, 0, &salirCmd));
            dlg.agregarControl(Control(TipoControl::BOX,       20, 320, 400, 50, rojo, blanco, 0, 0, &salirCmd));
            dlg.agregarControl(Control(TipoControl::TEXTBOX,   20, 380, 400, 50, rojo, blanco, 0, 0, &salirCmd));
            
            // @note ¡Comprobado! En estas dos líneas sí funciona... y es que, al parecer, al agregar el control al diálogo
            //       se agrega una copia del control, no teniendo la misma referencia que el control que se inicializó.
            //       Si se inicializa con el control (copia) que se encuentra en el array, todo funciona.
            //
            ComandoTest testCmd(reinterpret_cast<SliderCtrl *>(&dlg.controls[3]));
            dlg.controls[3].comando = &testCmd;
            
            int resultado = dlg.mostrar();
        }
    }
    return D_CLOSE;
}
END_OF_MAIN();
