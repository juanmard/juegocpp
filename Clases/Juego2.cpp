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
//#include "ctlSprite.h"
#include "Fruta.h"
#include <locale>

Juego2::Juego2 ()
{
};

void Juego2::create_storagemanager ()
{
  // Creamos el almacén de recursos.
  storage_manager = new StorageManager("sprites3.dat");
  // @todo Comprobar que se ha creado correctamente y no queda como NULL.
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

    // Iniciamos con el editor.
    key[KEY_E] = true;
    
    // Bucle principal del juego.
    while (!key[KEY_ESC])
    {
        // Si se pulsa la 'E', se prueba el editor.
        if (key[KEY_E])
        {
          // Se activa el editor.
          editor_manager.activate ();

          // Se borran las teclas pulsadas para evitar rellamadas cuando se termine el editor.
          key[KEY_E] = false;
          key[KEY_ESC] = false;
        }

        // Si se pulsa la 'P', distintas pruebas de GUI.
        if (key[KEY_P])
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

          // Borramos el buffer de teclado.
          key[KEY_P] = false;
        }

        if (mouse_b & 2) {
          Fruta prueba ( *storage_manager );
          prueba.set_x (100);
          prueba.set_y (200);
          Menu &menu = prueba.getMenu ();
          do_menu (menu, mouse_x, mouse_y);
          menu.add("Otro añadido",0);
          do_menu (menu,mouse_x, mouse_y);
        }
    }

    // Antes de cerrar, hacemos una prueba con el juego en marcha.
    key[KEY_ESC] = false;
    while (!key[KEY_ESC])
    {
      // Se actualiza si no está pausado.
      if (!is_paused()) update();

      // Pausamos y reanudamos con la barra espaciadora.
      if (key[KEY_SPACE]) {
        is_paused() ? play() : pause();
        key[KEY_SPACE] = false;
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
    game.set_name("Juego++ v2.0");
    //game.init(GFX_AUTODETECT_WINDOWED, 800,600,8);
    game.init(GFX_SAFE, 800, 600, 8);
    return 0;
}
END_OF_MAIN ();

