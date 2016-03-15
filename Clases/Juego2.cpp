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

#include  "Juego2.h"
#include <guichan.hpp>
#include <guichan/allegro.hpp>

/*
    * List boxes and drop downs need an instance of a list model
    * in order to display a list.
    */
class DemoListModel : public gcn::ListModel
{
public:
    int getNumberOfElements()
    {
        return 5;
    }

    std::string getElementAt(int i)
    {
        switch(i)
        {
            case 0:
                return std::string("zero");
            case 1:
                return std::string("one");
            case 2:
                return std::string("two");
            case 3:
                return std::string("three");
            case 4:
                return std::string("four");
            default: // Just to keep warnings away
                return std::string("");
        }
    }
};

DemoListModel demoListModel;

void Juego2::prueba_guichan ()
{
    BITMAP* screenBuffer;

    gcn::Gui *gui;
    gcn::ImageFont* fontgui;
    gcn::Container* top;
    gcn::Label* label;
    gcn::Icon* icon;
    gcn::Button* button;
    gcn::TextField* textField;
    gcn::TextBox* textBox;
    gcn::ScrollArea* textBoxScrollArea;
    gcn::ListBox* listBox;
    gcn::DropDown* dropDown;
    gcn::CheckBox* checkBox1;
    gcn::CheckBox* checkBox2;
    gcn::RadioButton* radioButton1;
    gcn::RadioButton* radioButton2;
    gcn::RadioButton* radioButton3;
    gcn::Slider* slider;
    gcn::Image *image;
    gcn::Window *window;
    gcn::Image *darkbitsImage;
    gcn::Icon* darkbitsIcon;
    gcn::TabbedArea* tabbedArea;
    gcn::Button* tabOneButton;
    gcn::CheckBox* tabTwoCheckBox;

    // All back ends contain objects to make Guichan work on a
    // specific target - in this case Allegro - and they are a Graphics
    // object to make Guichan able to draw itself using Allegro, an
    // input objec to make Gopenglsdluichan able to get user input using Allegro
    // and an ImageLoader object to make Guichan able to load images
    // using Allegro.
    gcn::AllegroGraphics* graphics;
    gcn::AllegroInput* input;
    gcn::AllegroImageLoader* imageLoader;

    screenBuffer = create_bitmap(SCREEN_W, SCREEN_H);
    if (screenBuffer == NULL)
    {
       throw GCN_EXCEPTION("Unable to create a screen buffer");
    }

    // Now it's time to initialise the Guichan Allegro back end.
    imageLoader = new gcn::AllegroImageLoader();
    // The ImageLoader Guichan should use needs to be passed to the Image object
    // using a static function.
    gcn::Image::setImageLoader(imageLoader);
    graphics = new gcn::AllegroGraphics();
    // Set the target for the graphics object to be the doublebuffer
    // for the screen. Drawing to the screen directly is not a good
    // idea, as it will produce flicker, unless you use page flipping.
    graphics->setTarget(screenBuffer);
    input = new gcn::AllegroInput();

    // Now we create the Gui object to be used with this Allegro application.
    gui = new gcn::Gui();
    // The Gui object needs a Graphics to be able to draw itself and an Input
    // object to be able to check for user input. In this case we provide the
    // Gui object with Allegro implementations of these objects hence making Guichan
    // able to utilise Allegro.
    gui->setGraphics(graphics);
    gui->setInput(input);

    // We first create a container to be used as the top widget.
    // The top widget in Guichan can be any kind of widget, but
    // in order to make the Gui contain more than one widget we
    // make the top widget a container.
    top = new gcn::Container();
    // We set the dimension of the top container to match the screen.
    top->setDimension(gcn::Rectangle(0, 0, SCREEN_W, SCREEN_H));
    // Finally we pass the top widget to the Gui object.
    gui->setTop(top);

    try
    {
        // Now we load the font used in this example.
        //fontgui = new gcn::ImageFont("fixedfont.bmp", " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
        fontgui = new gcn::ImageFont("rpgfont.bmp", " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
        
		// Widgets may have a global font so we don't need to pass the
	    // font object to every created widget. The global font is static.
		gcn::Widget::setGlobalFont(fontgui);

	}
    catch (gcn::Exception e)
    {
        std::cout << "GCN exception: " << e.getMessage() << std::endl;
    }
    catch (std::exception e)
    {
        std::cout << "STD exception: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "Unknown exception" << std::endl;
	}

    // Now we create the widgets
    label = new gcn::Label("Label");
    image = gcn::Image::load("gui-chan.bmp");
    icon = new gcn::Icon(image);
    button = new gcn::Button("Button");
    textField = new gcn::TextField("Text field");
    textBox = new gcn::TextBox("Multiline\nText box");
    textBoxScrollArea = new gcn::ScrollArea(textBox);
    textBoxScrollArea->setWidth(200);
    textBoxScrollArea->setHeight(100);
    textBoxScrollArea->setFrameSize(1);
    listBox = new gcn::ListBox(&demoListModel);
    listBox->setFrameSize(1);
    dropDown = new gcn::DropDown(&demoListModel);
    checkBox1 = new gcn::CheckBox("Checkbox 1");
    checkBox2 = new gcn::CheckBox("Checkbox 2");
    radioButton1 = new gcn::RadioButton("RadioButton 1", "radiogroup", true);
    radioButton2 = new gcn::RadioButton("RadioButton 2", "radiogroup");
    radioButton3 = new gcn::RadioButton("RadioButton 3", "radiogroup");
    slider = new gcn::Slider(0, 10);
    slider->setSize(100, 10);
    
    window = new gcn::Window("I am a window drag me");
    window->setBaseColor(gcn::Color(255, 150, 200));
    darkbitsImage = gcn::Image::load("darkbitslogo_by_haiko.bmp");
    darkbitsIcon = new gcn::Icon(darkbitsImage);
    window->add(darkbitsIcon);
	window->add(textBox,10,10);
    window->resizeToContent();
    
    tabbedArea = new gcn::TabbedArea();
    tabbedArea->setSize(260, 200);
    tabOneButton = new gcn::Button("A button in tab 1");
    tabbedArea->addTab("Tab 1", tabOneButton);
    tabTwoCheckBox = new gcn::CheckBox("A check box in tab 2");
    tabbedArea->addTab("Tab 2", tabTwoCheckBox);

    // Now it's time to add the widgets to the top container
    // so they will be conected to the GUI.
    top->add(label, 10, 10);
    top->add(icon, 10, 30);
    top->add(button, 200, 10);
    top->add(textField, 250, 10);
    top->add(textBoxScrollArea, 200, 50);
    top->add(listBox, 200, 200);
    top->add(dropDown, 500, 10);
    top->add(checkBox1, 500, 130);
    top->add(checkBox2, 500, 150);
    top->add(radioButton1, 500, 200);
    top->add(radioButton2, 500, 220);
    top->add(radioButton3, 500, 240);
    top->add(slider, 500, 300);
    top->add(window, 50, 350);
    top->add(tabbedArea, 400, 350);

    while(!key[KEY_ESC])
    {
        // Now we let the Gui object perform its logic.
        gui->logic();
        // Now we let the Gui object draw itself.
        gui->draw();

        // We draw the mouse pointer manually, as Allegro's mouse
        // drawing code is so wierd.
        draw_sprite(screenBuffer, mouse_sprite, mouse_x, mouse_y);

        // Finally we update the screen.
        blit(screenBuffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }
    key[KEY_ESC]=false;
    set_palette (storage_manager->getPalette ("SPRITES"));
}

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
  /* Creamos el control. */
  Control *control_p1=new Control;

  /* Creamos un periférico y asociamos control y propietario. */
  Keyboard *kboard=new Keyboard;
  control_p1->set_actionperipheral(Loro::DOWN,  kboard, KEY_DOWN,  Peripheral::ON_PRESSING);
  control_p1->set_actionperipheral(Loro::UP,     kboard, KEY_UP,    Peripheral::ON_PRESSING);
  control_p1->set_actionperipheral(Loro::LEFT,  kboard, KEY_LEFT,  Peripheral::ON_PRESSING);
  control_p1->set_actionperipheral(Loro::RIGHT, kboard, KEY_RIGHT, Peripheral::ON_PRESSING);
  control_p1->set_actionperipheral(Loro::JUMP,  kboard,  KEY_A, Peripheral::ON_PRESSING);

  /* Creamos otro control de prueba. */
  Control *control_p2=new Control;
  control_p2->add_action_name(Paleta::LEFT, "Izquierda");
  control_p2->add_action_name(Paleta::RIGHT, "Derecha");
  control_p2->set_actionperipheral(Paleta::LEFT, kboard, KEY_LEFT, Peripheral::ON_PRESSING);
  control_p2->set_actionperipheral(Paleta::RIGHT, kboard, KEY_RIGHT, Peripheral::ON_PRESSING);

  // sprites->SetPalette (0);
  set_palette (storage_manager->getPalette ("SPRITES"));

 /* Eliminamos algunos objetos para probar la lectura y escritura de datos.

  // Se crea Aladino de prueba.
  Herny *aladino = new Herny(*storage_manager);
  aladino->set_y (280);
  aladino->set_x (380);
  //control_p1->set_owner(aladino);
  actor_manager->add(aladino);

  // Se crea Herny de prueba.
  Herny *jugador = new Herny();
  jugador->set_y (180);
 // control_p1->set_owner(jugador);
  actor_manager->add(jugador);

  // Se crea la Paleta del juego.
  Paleta *paleta = new Paleta(*storage_manager);
  actor_manager->add (paleta);

  // Se crea un suelo de prueba.
  Herny *prb = new Herny(*storage_manager);
  prb->set_wh(400,20);
  prb->set_x(-10);
  prb->set_y(600);
  prb->set_actor_graphic(new Suelo (prb,*storage_manager,18));
  actor_manager->add (prb);


  // Se crea el loro de prueba.
  Loro *loro = new Loro (*storage_manager);
//  control_p1->set_owner (loro);
  actor_manager->add (loro);

  // Se crea Ben de prueba.
  // \todo  Pasar esto a la clase 'Ben' como inicialización del objeto.
  control_p1->add_action_name (Ben::DOWN, "Bajar");
  control_p1->add_action_name (Ben::UP,   "Subir");
  control_p1->add_action_name (Ben::LEFT, "Izquierda");
  control_p1->add_action_name (Ben::RIGHT,"Derecha");
  control_p1->add_action_name (Ben::JUMP, "Saltar");
  control_p1->add_action_name (Ben::SPELL,"Hechizo");
  control_p1->set_actionperipheral (Ben::DOWN,  kboard, KEY_DOWN,  Peripheral::ON_PRESSING);
  control_p1->set_actionperipheral (Ben::UP,    kboard, KEY_UP,    Peripheral::ON_PRESSING);
  control_p1->set_actionperipheral (Ben::LEFT,  kboard, KEY_LEFT,  Peripheral::ON_PRESSING);
  control_p1->set_actionperipheral (Ben::RIGHT, kboard, KEY_RIGHT, Peripheral::ON_PRESSING);
  control_p1->set_actionperipheral (Ben::JUMP,  kboard, KEY_SPACE, Peripheral::ON_PRESSING);
  control_p1->set_actionperipheral (Ben::SPELL, kboard, KEY_A,     Peripheral::ON_PRESSING);
  Ben *ben = new Ben (*storage_manager);
  control_p1->set_owner (ben);
  actor_manager->add (ben);

  // Se crea la pelota del juego.
  Pelota *pelota = new Pelota(actor_manager);
  pelota->set_y (170);
  //actor_manager->add(pelota);

  -- Eliminamos objetos de prueba.*/
    
  // Añadimos una conjunto de ladrillos de prueba.
  for (int j=0; j<=2; j++)
  {    
    for (int i=1; i<=14; i++)
    {
      actor_manager->add(new Ladrillo(i*40, 40+40*j, *storage_manager));
    }
  }

  // Se prueba a cargar desde fichero.
  this->actor_manager->load("actores2.txt");

 /* Eliminamos objetos de prueba
  // Se añade una paleta de prueba pero con piel de Suelo.
  Paleta *prueba_suelo = new Paleta();
  prueba_suelo->set_x(100);
  prueba_suelo->set_y(300);
  prueba_suelo->set_actor_graphic(new Suelo(prueba_suelo,*storage_manager,8));
  actor_manager->add(prueba_suelo);
*/
    
  // Se añade el control de prueba creado para el loro, al manejador de controles.
  control_manager->add_control(control_p1);
   //control_manager->add_control(control_p2);
  
  // Se añade el periférico que realizará el control.
  control_manager->add_peripheral(kboard);

  // Se crea el 'EditorManager' básico para comenzar con las pruebas.
  EditorManager   editor(this);

  // Iniciamos el juego.
  update();
  //pause ();

  // Mostramos un breve mensaje en consola sobre las teclas.
  cout << "----------------------------------" << endl;
  cout << "----    Teclas básicas        ----" << endl;
  cout << "----------------------------------" << endl << endl;
  cout << " P - Pausa el juego." << endl;
  cout << " E - Entra en modo edición." << endl;
  cout << " S - Se activa el seguimiento del jugador." << endl;
  cout << " T - Realiza una prueba de gráficos." << endl;
  cout << " V - Visualiza los bloques de los actores." << endl;
  cout << " G - Prueba de GUI con 'GUICHAN'." << endl;
  cout << " I - Consola interactiva." << endl;
  cout << " ESC - Termina el juego." << endl;
  cout << "----------------------------------" << endl << endl;

  // Pruebas de ficheros y la lista de actores ---------------
  string nameFile("actores_prueba.txt");
  streambuf *psbuf, *backup;
  fstream file (nameFile.data(), fstream::in | fstream::out);
    
  backup = cout.rdbuf();    // back up cout's streambuf
  psbuf = file.rdbuf();     // get file's streambuf
  cout.rdbuf(psbuf);         // assign streambuf to cout

  // Al escribir en 'cout' estamos escribiendo en el fichero.
  cout << "--- Lista Actores v2.0 ---" << endl << *actor_manager << endl;

  cout.rdbuf(backup);        // restore cout's original streambuf

  file.close ();

  // Para recuperar la lista de actores también deberíamos usar los operadores de C++
  // file >> actor_manager;
  // ---------------------------------------------------------

    
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
      if ((stage_manager->getX() != 0) || (stage_manager->getY() != 0))
      {
        stage_manager->moverMarco(0,0);
        stage_manager->setSeguimiento (NULL);
      }
      else
      {
        // stage_manager->setSeguimiento (ben);
      }
      key[KEY_S] = false;
    }

    // Se comprueba la visualización de los bloques.
    if (key[KEY_V])
    {
      stage_manager->setVerBloques (!stage_manager->getVerBloques ());
      key[KEY_V] = false;
    }

    // Se comprueba la visualización de los bloques.
    if (key[KEY_G])
    {
      prueba_guichan ();
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
      cout << "----------------- Consola Interactiva -----------------" << endl;

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
        cout << endl << "=> ";
        cin >> comando;
        if (!comando.compare("help"))
        {
          for (int i=0; i<7; i++)
          {
            cout << comandos[i] << " - " << ayuda[i] << endl;
          }
        }
        else if (!comando.compare("nuevo"))
        {
          cout << "[nuevo]=> ";
	    cin >> *actor_manager;
        }
        else if (!comando.compare("grabar"))
        {
          ofstream outfile ("test.txt");
          outfile << "-- Lista de todos los actores --" << endl \
                  << "--------------------------------" << endl;
          outfile << *actor_manager;
          outfile.close();
          cout << "Grabados objetos en fichero \"test.txt\"" << endl;
        }
        else if (!comando.compare("listar"))
        {
          cout << "--------------------------------" << endl \
               << "-- Lista de todos los actores --" << endl \
               << "--------------------------------" << endl \
               << *actor_manager \
               << "--------------------------------" << endl;
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
          cout << endl << "Fin de consola interactiva." << endl;
          salida = true;
        }
        else
        {
          cout << "Comando desconocido. Utilice \"help\" para ver los comandos disponibles." << endl;
        }
      }
      while (!salida);
      key[KEY_I] = false;
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
  game.set_name("Test del juego");
  game.init(GFX_AUTODETECT_WINDOWED, 800,600,8);
  return 0;
}
END_OF_MAIN ();

