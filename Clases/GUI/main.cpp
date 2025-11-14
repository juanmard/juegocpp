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
            SliderCtrl sliderTest2(20, 20, 400, 50, rojo, blanco, 0, 0);
            
            // @warning Esta forma de «enlazar» el comando con el control no funciona.
            //          El cambio de valores en el control de Allegro no se transfiere al objeto instanciado.
            //
            //ComandoTest testCmd(&sliderTest);
            //sliderTest.setComando (&testCmd);

            CommandSalir salirCmd;
            CommandOtro otroCmd;
            dlg.agregarControl(std::make_unique<SliderCtrl>(sliderTest2));
            dlg.agregarControl(std::make_unique<Control>(TipoControl::BOX,       20,  80, 400, 50, rojo, blanco, 0, 0, &salirCmd));
            dlg.agregarControl(std::make_unique<Control>(TipoControl::BUTTON,    20, 140, 400, 50, rojo, blanco, 0, 0, &salirCmd));
            dlg.agregarControl(std::make_unique<SliderCtrl>(sliderTest));
            dlg.agregarControl(std::make_unique<Control>(TipoControl::LABEL,     20, 260, 400, 50, rojo, blanco, 0, 0, &salirCmd));
            dlg.agregarControl(std::make_unique<Control>(TipoControl::BOX,       20, 320, 400, 50, rojo, blanco, 0, 0, &salirCmd));
            dlg.agregarControl(std::make_unique<Control>(TipoControl::TEXTBOX,   20, 380, 400, 50, rojo, blanco, 0, 0, &salirCmd));
            
            // @note ¡Comprobado! En estas dos líneas sí funciona... y es que, al parecer, al agregar el control al diálogo
            //       se agrega una copia del control, no teniendo la misma referencia que el control que se inicializó.
            //       Si se inicializa con el control (copia) que se encuentra en el array, todo funciona.
            //
            SliderCtrl *sld1 = dynamic_cast<SliderCtrl*>(dlg.controls[3].get());
            if (!sld1) {
                std::cerr << "Error: El control sld1 no es un SliderCtrl." << std::endl;
                return D_CLOSE;
            }
            ComandoTest testCmd(sld1);
            sld1->comando = &testCmd;
            sld1->setNombre("Slider Azul");
            sld1->setRenderer(&renderer);
            
            // Prueba de listeners.
            // @note Si funciona, un cambio en el slider 1 (azul), debería cambiar el 2 (rojo),
            //       ya que el rojo está escuchando al azul.
            SliderCtrl *sld2 = dynamic_cast<SliderCtrl*>(dlg.controls[0].get());
            if (!sld2) {
                std::cerr << "Error: El control sdl2 no es un SliderCtrl." << std::endl;
                return D_CLOSE;
            }
            ComandoTest testCmd2(sld2);
            sld2->comando = &testCmd2;
            sld2->setNombre("Slider Rojo");
            sld2->setRenderer(&renderer);
            
            // Añadir listener: sld2 escucha a sld1.
            sld1->addListener (sld2);
            //sld2->addListener (sld1);

            int resultado = dlg.mostrar();
        }
    }
    return D_CLOSE;
}
END_OF_MAIN();
