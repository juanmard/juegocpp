/**
 *  \file     Juego2.cpp
 *  \brief    Prueba del "framework" de un juego.
 *
 *  \details  La clase instancia un tipo de juego de prueba con todos los controladores posibles.
 *            La primera versión de la instancia se utiliza para actualizar el juego de plataformas
 *            programado antiguamente en C "puro y duro".
 *
 *  \author   Juan Manuel Rico
 *  \date     Septiembre de 2010
 *  \version  1.00
 *
 *  \todo     Comentar todas estas clases y funciones más detalladamente.
 */

#include "Juego2.h"
#include "Plataforma.h"

/**
 * \brief   Crea el objeto del juego.
 */
Juego2::Juego2 ()
{
}

/**
 * \brief   Se crea el almacén para este juego.
 */
void  Juego2::create_storagemanager ()
{
  // Creamos el almacén de recursos.
  storage_manager = new Almacen("sprites3.dat");
}

/**
 * \brief   Parte inicial del juego.
 * \details Crea actores y controladores para el juego de prueba.
 */
void Juego2::mainGame ()
{
  // Se cambia la paleta de colores.
  // sprites->SetPalette (0);
  set_palette (storage_manager->getPalette ("SPRITES"));

  // Se cargan actores desde fichero de prueba.
  this->actor_manager->load("test.txt");

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
  EditorManager editor(this);

  // Iniciamos el juego.
  update();

  // Mostramos un breve mensaje en consola sobre las teclas.
  cout << "----------------------------------" << endl;
  cout << "----    Teclas básicas        ----" << endl;
  cout << "----------------------------------" << endl << endl;
  cout << " P - Pausa el juego." << endl;
  cout << " E - Entra en modo edición." << endl;
  cout << " S - Se activa el seguimiento del jugador." << endl;
  cout << " T - Realiza una prueba de gráficos." << endl;
  cout << " V - Visualiza los bloques de los actores." << endl;
  cout << " G - Pruebas de GUI'." << endl;
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
      editor.activate ();

      // Se borran las teclas pulsadas para evitar rellamadas.
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
      key[KEY_P] = false;
    }

    // Se hace el seguimiento de la pantalla.
    if (key[KEY_S])
    {
      if ((stage_manager->get_x() != 0) || (stage_manager->get_y() != 0))
      {
        stage_manager->mover_marco (0,0);
        stage_manager->set_seguimiento (NULL);
      }
      else
      {
        stage_manager->set_seguimiento (loro);
      }
      key[KEY_S] = false;
    }

    // Se comprueba la visualización de los bloques.
    if (key[KEY_V])
    {
      stage_manager->set_ver_bloques (!stage_manager->get_ver_bloques ());
      key[KEY_V] = false;
    }

    // Se comprueba la visualización de los bloques.
    if (key[KEY_G])
    {
      // Se crea a parte un Loro de prueba para el editor de Sprites.
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
      key[KEY_ESC] = false;
      key[KEY_G] = false;
    }

    // Parte de código para pruebas del juego.
    if (key[KEY_T])
    {
      // Probamos el nuevo constructor de Bitmap basado en el almacén.
      Actor *camello = new Actor ();
      Bitmap::setAlmacen (storage_manager);
      Bitmap *bmp_camello = new Bitmap (camello, "sprite_107");
      camello->set_x (130);
      camello->set_y (195);
      camello->set_wh (63,44);
      camello->setCodigo (Nombres::camello); // No funciona pues no hemos definido un 'getNombre' virtual específico.
      camello->set_actor_graphic (bmp_camello);
      actor_manager->add(camello);
      cout << "Bitmap: " << bmp_camello->getImagen () << " Nombre: " << storage_manager->getName (bmp_camello->getImagen()) << endl;

      // Se prueba el uso del Bitmap en la Tesela.
      Actor *arbol = new Actor ();
      arbol->set_x (130);
      arbol->set_y (250);
      arbol->set_wh (32,15);
      Mosaico *hojas = new Mosaico (arbol);
      hojas->add_ultima_Tesela (new Tesela (hojas, "pre2_417"));
      hojas->add_ultima_Tesela (new Tesela (hojas, "pre2_416", 12, 20));
      hojas->add_ultima_Tesela (new Tesela (hojas, "pre2_416", 12, -20, true));
      arbol->set_actor_graphic (hojas);
      actor_manager->add(arbol);
      cout << "Mosaico de hojas: " << endl << hojas->getString () << endl;

      // Probamos la generación del mapa de actores.
      Mapa mapa_prb;
      mapa_prb.Read (*actor_manager);
      // cout << mapa_prb.getString ();
    }

    // Se prueba la consola interactiva.
    if (key[KEY_I])
    {
      // \todo Pasar los procesos de la consola interactiva a una clase independiente.
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

      string comando;
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
          actor_manager->getArmario ();
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
    // Prueba de font.
    //
    if (key[KEY_F])
    {
        key[KEY_F] = false;
        FONT *myfont;
        PALETTE palette;

        myfont = load_font("prueba-font.pcx", palette, NULL);
        // set_palette (palette);
        if (!myfont)
            cout << "Couldn't load font!";
        textout_centre_ex(screen, myfont, "¡Esto es mi prueba de letras!",
                           SCREEN_W / 2, SCREEN_H / 2, 5, 223);
        while (!key[KEY_F]);
        destroy_font(myfont);
        key[KEY_F] = false;
    }
  }

    // Cerramos el juego fundiendo en negro.
  fade_out(2);
}

/**
 * \brief   "main" principal que inicia el juego de prueba.
 */
int main ()
{
  Juego2 game;
  srand(time(NULL));
  game.set_name("Juego++ v2.0");
  //game.init(GFX_AUTO, 800,600,8);
  game.init(GFX_SAFE, 800,600,8);
  return 0;
}
END_OF_MAIN ();

