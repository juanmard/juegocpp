///
/// @file Juego2.cpp
/// @brief Prueba del "framework" de un juego.
///
/// @details  La clase instancia un tipo de juego de prueba con todos los controladores posibles.
///           La primera versión de la instancia se utiliza para actualizar el juego de plataformas
///           programado antiguamente en C "puro y duro".
///
/// @author   Juan Manuel Rico
/// @date     Septiembre de 2010
/// @version  2.00
///
/// @todo     Comentar todas estas clases y funciones más detalladamente.
///

#include "Juego2.h"
#include "Mosaico.h"
#include "Tesela.h"
#include "Fruta.h"
#include <locale>

Juego2::Juego2 ()
{
};

void Juego2::mainGame ()
{
    // Se cambia la paleta de colores que se toma del almacén de recursos.
    set_palette (storage_manager->get_palette ("SPRITES"));

    // Se borra la pantalla.
    clear_to_color (screen, makecol (128, 128, 128));
    show_mouse (screen);

    // Se carga el mapa del juego.
    Mapa mapa;
    std::cout << mapa << std::endl;

    // Se cargan actores desde fichero de prueba.
    mapa.load (*new std::string("test2.txt"),*actor_manager);

    // Se crea el 'EditorManager' básico para comenzar con las pruebas.
    EditorManager editor_manager (this);

    // Bucle principal del juego.
    // Iniciamos con el editor.
    IInput::Key tecla = IInput::Key::Key_E;
    while (tecla != IInput::Key::ESC)
    {
        // Si se pulsa la 'E', se prueba el editor.
        if (tecla == IInput::Key::Key_E)
        {
          // Se activa el editor.
          editor_manager.activate ();

          // Se evitan rebotes de tecla ESC.
          while (input->getKey() == IInput::Key::ESC);
        }

        // Si se pulsa la 'A', distintas pruebas de GUI.
        if (tecla == IInput::Key::Key_A)
        {
          Fruta prueba ( *storage_manager );
          prueba.set_x (100);
          prueba.set_y (100);
          prueba.draw (screen);
          
          Menu &menu = prueba.getMenu ();
          do_menu (menu, mouse_x, mouse_y);

          // Formulario &form = prueba.getFormulario ();
          // form.show ();

          // Borramos la pantalla.
          clear_to_color (screen, makecol (128, 128, 128));

          // Se evitan rebotes de tecla ESC.
          while (input->getKey() == IInput::Key::ESC);
        }

        if (input->clicDerecho()) {
          Fruta prueba ( *storage_manager );
          prueba.set_x (100);
          prueba.set_y (200);
          Menu &menu = prueba.getMenu ();
          do_menu (menu, mouse_x, mouse_y);
          menu.add("Otro añadido",0);
          do_menu (menu,mouse_x, mouse_y);
        }

        // Actualizamos la tecla.
        tecla = input->getKey();
    }

    // Se evitan rebotes de tecla ESC.
    while (input->getKey() == IInput::Key::ESC);

    // Antes de cerrar, hacemos una prueba con el juego en marcha.
    while ( (tecla = input->getKey()) != IInput::Key::ESC)
    {
     // Se actualiza si no está pausado.
      if (!is_paused()) update();

      // Pausamos y reanudamos con la barra espaciadora.
      if (tecla == IInput::Key::ESPACE) {
        is_paused() ? play() : pause();
        while (input->getKey() == IInput::Key::ESPACE);
      }

    }

  // Cerramos el juego fundiendo en negro.
  fade_out(2);
};

/// Procedimiento principal del programa.
///
/// Procedimiento no perteneciente a la clase y que crea
/// el punto de entrada del programa ("main") que inicia el juego de prueba.
///
int main ()
{
    Juego2 game;

    //SetConsoleOutputCP(U_UTF8);
    //SetConsoleCP(U_UTF8);

    srand (time(NULL));
    game.set_name("Juego++ v3.0");
    //game.init(GFX_AUTODETECT_WINDOWED, 800,600,8);
    game.init (800, 600);
    return 0;
}
END_OF_MAIN ();

