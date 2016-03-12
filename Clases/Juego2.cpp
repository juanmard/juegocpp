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

Juego2::Juego2 ()
{
};

void Juego2::create_storage_manager ()
{
  // Creamos el almacén de recursos.
  storage_manager = new Almacen("sprites3.dat");
};

void Juego2::mainGame ()
{
    // Pruebas de clases.
    Vector2Df vector(1.0f,4.5f);
    std::string cadena1, cadena2=" prueba...";
    cadena1 << vector;
    std::ostringstream canalCadena;
    std::cout << cadena1;
    canalCadena << cadena1;
    canalCadena << cadena2;
    canalCadena << vector;
    std::cout << canalCadena.str() << std::endl;
    std::cout << vector << std::endl;

    Plataforma prueba(*storage_manager);
    std::cout << prueba << std::endl;

    Bloque prueba2 (1,2,3,4);
    std::cout << prueba2;

    std::fstream pruebatxt("prueba_objeto.txt",std::fstream::in | std::fstream::out | std::fstream::app);
    pruebatxt << canalCadena.str() <<std::endl;
    pruebatxt << vector << std::endl;
    pruebatxt << prueba2 << std::endl;
    pruebatxt.close ();

  // Se cambia la paleta de colores que se toma del almacén de recursos.
  set_palette (storage_manager->getPalette ("SPRITES"));

  // Se cargan actores desde fichero de prueba.
  // @todo Leer este mismo fichero desde el almacén de recursos.
  this->actor_manager->load("test2.txt");

  // Se crea aparte un actor de tipo loro para pruebas.
  Loro *loro=new Loro(*storage_manager);
  loro->set_x(150);
  loro->set_y(400);
  actor_manager->add(loro);

  // Se añade el control del loro, al manejador de controles.
  control_manager->add_control(loro->get_control());
  
  // Se añade el periférico del loro que realizará el control.
  control_manager->add_peripheral(loro->get_peripheral());

  // Se crea el 'EditorManager' básico para comenzar con las pruebas.
  EditorManager editor_manager (this);

  // Mostramos un breve mensaje en consola sobre las teclas de prueba.
  cout << "----------------------------------" << endl;
  cout << "----    Teclas básicas        ----" << endl;
  cout << "----------------------------------" << endl << endl;
  cout << " P - Pausa el juego." << endl;
  cout << " E - Entra en modo edición." << endl;
  cout << " S - Se activa el seguimiento del jugador." << endl;
  cout << " T - Realiza una prueba de gráficos Bitmap." << endl;
  cout << " V - Visualiza los bloques de los actores." << endl;
  cout << " G - Pruebas de GUI para Sprites'." << endl;
  cout << " F - Prueba de letras." << endl;
  cout << " M - Prueba de mapas de actores." << endl;
  cout << " I - Consola interactiva." << endl;
  cout << " ESC - Termina el juego." << endl;
  cout << "----------------------------------" << endl << endl;

  // Bucle principal del juego.
  while (!key[KEY_ESC])
  {
    // Si no está en pausa se actualiza el juego.
    if (!is_paused())
    {
      update();
    }

    // Si se pulsa la 'E', se prueba el editor.
    if (key[KEY_E])
    {
      // Se activa el editor.
      editor_manager.activate ();

      // Se borran las teclas pulsadas para evitar rellamadas cuando se termine el editor.
      key[KEY_E] = false;
      key[KEY_ESC] = false;
    }

    // Se pausa y despausa el juego a modo de prueba.
    if (key[KEY_P])
    {
      if (is_paused ())
      {
        play ();
      }
      else
      {
        pause ();
      }

      // Limpieza teclado.
      key[KEY_P] = false;
    }

    // Se hace el seguimiento de la pantalla.
    if (key[KEY_S])
    {
      // Si el escenario está en modo seguimiento, se deja de seguir y se pone el escenario en el lugar original;
      // en otro caso, a modo de prueba se hace el seguimiento al loro.
      if ( stage_manager->is_seguimiento () )
      {
        stage_manager->mover_marco (0,0);
        stage_manager->set_seguimiento (NULL);
      }
      else
      {
        stage_manager->set_seguimiento (loro);
      }

      // Limpieza teclado.
      key[KEY_S] = false;
    }

    // Conmuta entre visualizar o no los bloques que definen a los actores.
    if (key[KEY_V])
    {
      stage_manager->set_ver_bloques (!stage_manager->get_ver_bloques ());

      // Limpieza de teclado.
      key[KEY_V] = false;
    }

    // Se crea un personaje de prueba para la animación y control.
    if (key[KEY_G])
    {
      // Se crea un Loro de prueba para el editor de Sprites.
      Loro *loro2=new Loro(*storage_manager);
      loro2->set_x(100);
      loro2->set_y(300);
      actor_manager->add(loro2);
      control_manager->add_control(loro2->get_control());

      // Prueba con sprite.
      Sprite *prueba = (Sprite *) loro2->get_actor_graphic();
      Menu &menu = prueba->getMenu ();
      do_menu(menu, mouse_x, mouse_y);

      Formulario &form = prueba->getFormulario ();
      form.show ();

      // Limpieza de teclado.
      key[KEY_ESC] = false;
      key[KEY_G] = false;
    }

    // Pruebas de Bitmap.
    if (key[KEY_T])
    {
      // Probamos el nuevo constructor de Bitmap basado en el almacén.
      // 1 - Se crea un actor vacío.
      Actor *camello = new Actor ();

      // 2 - Se le dice a la clase Bitmap de dónde obtener los gráficos.
      Bitmap::set_almacen (storage_manager);

      // 3 - Se crea un gráfico indicando simplemente el gráfico y a qué actor se le desea asignar.
      Bitmap *bmp_camello = new Bitmap (camello, "sprite_107");

      // 4 - Se completan el resto de propiedades del actor.
      camello->set_x (130);
      camello->set_y (195);
      camello->set_wh (63,44);
      camello->setCodigo (Nombres::camello); // No funciona pues no hemos definido un 'getNombre' virtual específico.
      camello->set_actor_graphic (bmp_camello);

      // 5 - Se agrega el nuevo actor al controlador de actores.
      actor_manager->add(camello);

      // 6 - Se descarga la información en pantalla.
      cout << "Bitmap: " << bmp_camello->get_imagen () << " Nombre: " << storage_manager->getName (bmp_camello->get_imagen()) << endl;

      // Por otra parte, Se prueba el uso del Bitmap en la Tesela.
      // 1 - Se crea un nuevo actor vacío.
      Actor *arbol = new Actor ();

      // 2 - Se crea el mosaico vacío.
      Mosaico *hojas = new Mosaico (arbol);
      
      // 3 - Se añaden Teselas al mosaico.
      hojas->add_ultima_Tesela (new Tesela (hojas, "pre2_417"));
      hojas->add_ultima_Tesela (new Tesela (hojas, "pre2_416", 12, 20));
      hojas->add_ultima_Tesela (new Tesela (hojas, "pre2_416", 12, -20, true));
      
      // 4 - Se completan las propiedades del actor.
      arbol->set_x (130);
      arbol->set_y (250);
      arbol->set_wh (32,15);

      // 5 - Se añade el nuevo actor al controlador de actores para que lo muestre en pantalla.
      actor_manager->add(arbol);

      // 6 - Se descarga la información en pantalla.
      cout << "Mosaico de hojas: " << endl << hojas->print () << endl;

      // Limpieza de teclado.
      key[KEY_T]=false;
    }

    // Pruebas de Mapa de actores.
    // @todo Terminar estas pruebas.
    // @note Pensando que igual estas características deben estar integradas en la clase que
    //       controla los actores (ActorManager).
    if (key[KEY_M])
    {
      // Por otra parte, se prueba del mapa de actores.
      Mapa mapa_prb;
      mapa_prb.Read (*actor_manager);
      // cout << mapa_prb.getString ();
      // cout << mapa_prb << endl;

      // Limpieza de teclado.
      key[KEY_M]=false;
    }

    // Se prueba la consola interactiva.
    if (key[KEY_I])
    {
      // @todo Pasar los procesos de la consola interactiva a una clase independiente.
      std::cout << "----------------- Consola Interactiva -----------------" << std::endl;

      char comandos[7][8]={
          "help",
          "nuevo",
          "listar",
          "grabar",
          "armario",
          "pausa",
          "quit"
          };
      char ayuda[7][60]={
          "Obtiene ayuda de los comandos.",
          "Crea nuevo actor. Ej: nombre {x,y} {w,h}",
          "Muestra una lista de todos los actores.",
          "Graba los actores en un fichero \"test.txt\".",
          "Lista todos los objetos gráficos definidos en el juego.",
          "Pausa y activa el juego.",
          "Sale de la consola interactiva."
          };

      std::string comando;
      bool salida = false;
      do
      {
        comando.clear ();
        std::cout << std::endl << "=> ";
        std::cin >> comando;
        if (!comando.compare("help"))
        {
          for (int i=0; i<7; i++)
          {
            std::cout << comandos[i] << " - " << ayuda[i] << std::endl;
          }
        }
        else if (!comando.compare("nuevo"))
        {
          std::cout << "[nuevo]=> ";
          std::cin >> *actor_manager;
        }
        else if (!comando.compare("grabar"))
        {
          std::ofstream outfile ("test.txt");
          outfile << *actor_manager;
          outfile.close();
          cout << "Grabados objetos en fichero \"test.txt\"" << endl;
        }
        else if (!comando.compare("listar"))
        {
          std::cout << "--------------------------------" << std::endl \
                    << "-- Lista de todos los actores --" << std::endl \
                    << "--------------------------------" << std::endl \
                    << *actor_manager \
                    << "--------------------------------" << std::endl;
        }
        else if (!comando.compare("armario"))
        {
          actor_manager->get_armario ();
        }
        else if (!comando.compare("pausa"))
        {
          pause ();
        }
        else if (!comando.compare("quit"))
        {
          std::cout << std::endl << "Fin de consola interactiva." << std::endl;
          salida = true;
        }
        else
        {
          std::cout << "Comando desconocido. Utilice \"help\" para ver los comandos disponibles." << std::endl;
        }
      }
      while (!salida);
      key[KEY_I] = false;
    }

    // Prueba de fuentes de letras.
    if (key[KEY_F])
    {
        key[KEY_F] = false;
        FONT *myfont;
        PALETTE palette;

        myfont = load_font("prueba-font.pcx", palette, NULL);
        // set_palette (palette);
        if (!myfont)
        {
            cout << "Couldn't load font!";
        }
        textout_centre_ex(screen, myfont, "¡Esto es mi prueba de letras!", SCREEN_W / 2, SCREEN_H / 2, 5, 223);
        while (!key[KEY_F]);
        destroy_font(myfont);
        key[KEY_F] = false;
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

  srand (time(NULL));
  game.set_name("Juego++ v2.0");
  //game.init(GFX_AUTODETECT_WINDOWED, 800,600,8);
  game.init(GFX_SAFE, 800,600,8);
  return 0;
}
END_OF_MAIN ();

