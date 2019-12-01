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

/// Prueba de guichan.
#include <guichan.hpp>
#include <guichan/allegro.hpp>
#include "gui/SpriteGUI.hpp"
#include "gui/EscenarioGUI.hpp"
#include "allegro/SpriteAllegro.h"
#include "gui/ActorGUI.hpp"

void Juego2::prueba_guichan (Sprite* prueba)
{
    // Se inicializa la GUI de allegro,
    // la profundidad del color...
    //int bpp = desktop_color_depth();
    //if (bpp == 0) bpp = 16;
    set_color_depth(8);

    // El formato de cadenas...
    set_uformat (U_UTF8);
    
    // ... el modo gráfico.
    //if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0))
    //{
    //    if (set_gfx_mode(GFX_AUTODETECT, 640, 480, 0, 0))
    //    {
    //        throw GCN_EXCEPTION("Unable to set graphics mode");
    //    }
    //}

    // El doble buffer.
    BITMAP* screenBuffer = create_bitmap (SCREEN_W, SCREEN_H);
    if (screenBuffer == NULL)
    {
        throw GCN_EXCEPTION("Unable to create a screen buffer");
    };

    // El cargador de imágenes, gráficos y tratamiento de la entrada con Allegro.
    gcn::AllegroImageLoader* imageLoader = new gcn::AllegroImageLoader();
    gcn::Image::setImageLoader(imageLoader);
    gcn::AllegroGraphics* graphics = new gcn::AllegroGraphics();
    graphics->setTarget(screenBuffer);
    gcn::AllegroInput* input = new gcn::AllegroInput();

    // La fuente de las letras.
    //gcn::ImageFont* font = new gcn::ImageFont("fixedfont.bmp", " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
    gcn::ImageFont* font = new gcn::ImageFont("rpgfont.bmp", uconvert(" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,!?-+/():;%&'{*#=[]\"ñáéíóú", U_CURRENT, NULL, U_ASCII, 0));
    gcn::Widget::setGlobalFont(font);

    // Se crea la GUI y se añaden a ella los controladores gráficos y de entrada.
    gcn::Gui* gui = new gcn::Gui();
    gui->setGraphics(graphics);
    gui->setInput(input);

    // Se crea el contenedor principal.
    gcn::Container* top = new gcn::Container();
    top->setDimension(gcn::Rectangle(0, 0, 800, 600));
    gui->setTop(top);

    // Los widgets contenidos.
    //gcn::Label* label = new gcn::Label("Prueba de zona con pestañas.");
    gcn::Label* label = new gcn::Label(uconvert("Prueba de zona con pestañas.", U_CURRENT, NULL, U_ASCII, 0));
    top->add (label, 0, 0);

    //gcn::Image* image = gcn::Image::load("gui-chan.bmp");
    //gcn::Icon* icon = new gcn::Icon(image);
    //top->add (icon, 10, 30);
    
    gcn::Button* button = new gcn::Button("Salir");
//    button->setFrameSize(50);
    top->add(button, top->getWidth()-button->getWidth(), top->getHeight()-button->getHeight());
    
    gcn::Window* ventana = new gcn::Window("Prueba");
    ventana->setMovable(true);
    ventana->setVisible(true);
    ventana->setHeight(150);
    ventana->setWidth(300);
    ventana->add(button,30,60);
    top->add(ventana,360,410);
    
    
    //gcn::TextField* textField = new gcn::TextField("Text field");
    //top->add (textField, 250, 10);

    //gcn::TextBox* textBox = new gcn::TextBox("Multiline\nText box");
    //gcn::ScrollArea* textBoxScrollArea = new gcn::ScrollArea(textBox);
    //textBoxScrollArea->setWidth(200);
    //textBoxScrollArea->setHeight(100);
    //textBoxScrollArea->setFrameSize(1);
    //top->add (textBoxScrollArea, 200, 50);
    
    //gcn::ListBox* listBox = new gcn::ListBox(&demoListModel);
    //listBox->setFrameSize(1);
    //top->add (listBox, 200, 200);
    
    //gcn::DropDown* dropDown = new gcn::DropDown(&demoListModel);
    //top->add (dropDown, 500, 10);

    //gcn::CheckBox* checkBox1 = new gcn::CheckBox("Checkbox 1");
    //top->add (checkBox1, 500, 130);
    //gcn::CheckBox* checkBox2 = new gcn::CheckBox("Checkbox 2");
    //top->add (checkBox2, 500, 150);

    //gcn::RadioButton* radioButton1 = new gcn::RadioButton("RadioButton 1", "radiogroup", true);
    //top->add(radioButton1, 500, 200);
    //gcn::RadioButton* radioButton2 = new gcn::RadioButton("RadioButton 2", "radiogroup");
    //top->add(radioButton2, 500, 220);
    //gcn::RadioButton* radioButton3 = new gcn::RadioButton("RadioButton 3", "radiogroup");
    //top->add(radioButton3, 500, 240);
    
    //gcn::Slider* slider = new gcn::Slider(0, 10);
    //slider->setSize(100, 10);
    //top->add(slider, 500, 300);

    //gcn::Window* window = new gcn::Window("I am a window  Drag me");
    //window->setBaseColor(gcn::Color(255, 150, 200, 190));
    //gcn::Image* darkbitsImage = gcn::Image::load("darkbitslogo_by_haiko.bmp");
    //gcn::Icon* darkbitsIcon = new gcn::Icon(darkbitsImage);
    //window->add(darkbitsIcon);
    //window->resizeToContent();
    //top->add (window, 50, 350);
 
 /*     
    // La clase para los controles con lista.
    class DemoListModel : public gcn::ListModel
    {
    public:
        int getNumberOfElements() {return 5;};
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
              default:
                  return std::string("");
            }
        }
    };

    // La variable con la lista.
    DemoListModel demoListModel;
*/

    gcn::TabbedArea* tabbedArea = new gcn::TabbedArea();
    tabbedArea->setSize(400, 200);

    // Pestaña 1.
    gcn::Button* tabOneButton = new gcn::Button("A button in tab 1");
    tabbedArea->addMouseListener(tabOneButton);
    tabbedArea->addKeyListener(tabOneButton);
    tabbedArea->addTab("Tab 1---------", tabOneButton);
    
    // Pestaña 2.
    gcn::CheckBox* tabTwoCheckBox = new gcn::CheckBox("A check box in tab 2");
    tabbedArea->addTab("Tab 2", tabTwoCheckBox);
    //tabbedArea->addMouseListener(tabTwoCheckBox);
    top->addMouseListener(tabTwoCheckBox);

    // Pestaña 3.
    tabbedArea->addTab("Tab 3", new gcn::Label("Pruebaaaa"));
    
    // Pestaña 4.
    gcn::Container* containerTab4 = new gcn::Container();
    containerTab4->setDimension(gcn::Rectangle(0, 0, 300, 100));
    containerTab4->add(new gcn::Label("Cuatro"),100,75);
    containerTab4->add(new gcn::Button("Tres"),100,10);
    containerTab4->add(tabOneButton,30,55);
    containerTab4->resizeToContent();
    tabbedArea->addTab("Tab 4", containerTab4);
    
    // Se agrega al contenedor principal.
    top->add (tabbedArea, 100, 100);

    // Prueba de menú.
    gui::MenuGUI* menu = new gui::MenuGUI();
    gui::Item* item1 = new gui::Item("item1");
    menu->addItem(item1);
    gui::Item* item2 = new gui::Item("item2");
    menu->addItem(item2);
    gui::Item* item3 = new gui::Item("item3");
    menu->addItem(item3);
    menu->setVisible(true);
    containerTab4->addMouseListener(menu);
    containerTab4->add(menu,200,30);
    
    // Prueba de tab solitario.
    gcn::Tab* tabSolo = new gcn::Tab();
    tabSolo->setCaption("Solitario");
    top->add(tabSolo, 20,30);

    // Prueba escenario.
    //gui::EscenarioGUI* escenario = new gui::EscenarioGUI(stage_manager);
    //top->add(escenario);

/*
    gcn::Tab *tab1 = new gcn::Tab ();
    tab1->setCaption("Prb 1");
    gcn::Container *todo = new gcn::Container ();
    gcn::Label* etq1 = new gcn::Label ("una prueba más");
    etq1->setPosition (0,50);
    todo->add (etq1);
    todo->add (new gcn::CheckBox("Otraaa"));
    tabbedArea->addTab(tab1,todo);
    top->add (tab1,100,230);
*/

    // Prueba de Sprite como widget.
    //gui::SpriteGUI* sprite1 = new gui::SpriteGUI (prueba);

    //Ben* ben=new Ben(*storage_manager);
    //gui::SpriteGUI* sprite2 = new gui::SpriteGUI (new allegro::SpriteAllegro (*((Sprite*)ben->get_actor_graphic()),ben));
    //top->add (sprite2, 30,320);

    // Prueba de ActorGUI.
    //gui::ActorGUI* actor1 = new gui::ActorGUI (new Actor());
    //top->add (actor1, 10, 230);

    // Se crea una prueba para el evento de botón.
    /*
    button->setActionEventId("btn1");
    class Escuchador : public gcn::ActionListener
    {
    public:
        Escuchador (gcn::Label* eti):etiqueta(eti){};
        void action (const gcn::ActionEvent& actionEvent)
        {
            etiqueta->setCaption ("Ya me has pulsado...");
            const gcn::Rectangle &caja = etiqueta->getDimension();
            etiqueta->setDimension (gcn::Rectangle(caja.x,caja.y,caja.width+10,caja.height));
        };
    private:
        gcn::Label* etiqueta;
    };
    Escuchador* pepe = new Escuchador(label);
    button->addActionListener(pepe);
    */

    // Se realiza el bucle de mensajes.
    while(!key[KEY_ESC])
    {
        // Se ejecuta la lógica de la GUI.
        gui->logic();

        // Se dibuja la GUI, una vez actualizada la lógica.
        gui->draw();

        // Se dibuja el puntero en el doble buffer.
        draw_sprite(screenBuffer, mouse_sprite, mouse_x, mouse_y);

        // Se actualiza la pantalla con los cambios.
        blit(screenBuffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }
    // limpiar buffer.
    key[KEY_ESC] = false;

    // Se elimina lo creado.
    delete gui;
    delete imageLoader;
    delete input;
    delete graphics;
    destroy_bitmap(screenBuffer);
    delete font;
    delete top;
    delete label;
//    delete icon;
//    delete button;
//    delete textField;
//    delete textBox;
//    delete textBoxScrollArea;
//    delete listBox;
//    delete dropDown;
//    delete checkBox1;
//    delete checkBox2;
//    delete radioButton1;
//    delete radioButton2;
//    delete radioButton3;
//    delete slider;
//    delete window;
//    delete darkbitsIcon;
//    delete darkbitsImage;
    delete tabbedArea;
    delete tabOneButton;
    delete tabTwoCheckBox;
//    delete sprite1;
//    delete sprite2;
};

// Definición del juego.
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
    Mapa mapa;
    std::cout << mapa << std::endl;

    Mosaico *mosaico = new Mosaico();
    Tesela tesela (mosaico);
    std::cout << tesela << std::endl;

    Bitmap prueba_bitmap (new Actor(),new Almacen("sprites3.dat"), "pre2_44");
    std::cout << prueba_bitmap;

  // Se cambia la paleta de colores que se toma del almacén de recursos.
  set_palette (storage_manager->get_palette ("SPRITES"));

  // Se cargan actores desde fichero de prueba.
  // @todo Leer este mismo fichero desde el almacén de recursos.
  // @todo Delegar esta función a la clase Mapa.
  mapa.load (*new std::string("test2.txt"),*actor_manager);
//  this->actor_manager->load("test2.txt");

  // Se crea aparte un actor de tipo loro para pruebas.
  Loro *loro=new Loro(*storage_manager);
  loro->set_x(150);
  loro->set_y(400);
  // Se elimina el loro para mostrar.
  // actor_manager->add(loro);

  // Se añade el control del loro, al manejador de controles.
  control_manager->add_control(loro->get_control());
  
  // Se añade el periférico del loro que realizará el control.
  control_manager->add_peripheral(loro->get_peripheral());


  // Se usa una prueba de Ben.
  Ben *ben = new Ben(*storage_manager);
  ben->set_x(220);
  ben->set_y(200);
  actor_manager->add(ben);
  loro->get_control()->set_owner(ben);  // Se usa el control del loro para probar a Ben.

  // Se crea el 'EditorManager' básico para comenzar con las pruebas.
  EditorManager editor_manager (this);

  // Mostramos un breve mensaje en consola sobre las teclas de prueba.
  std::cout << "----------------------------------" << std::endl;
  std::cout << "----    Teclas básicas        ----" << std::endl;
  std::cout << "----------------------------------" << std::endl << std::endl;
  std::cout << " P - Pausa el juego." << std::endl;
  std::cout << " E - Entra en modo edición." << std::endl;
  std::cout << " S - Se activa el seguimiento del jugador." << std::endl;
  std::cout << " T - Realiza una prueba de gráficos Bitmap." << std::endl;
  std::cout << " V - Visualiza los bloques de los actores." << std::endl;
  std::cout << " G - Pruebas de GUI para Sprites'." << std::endl;
  std::cout << " F - Prueba de letras." << std::endl;
  std::cout << " M - Prueba de mapas de actores." << std::endl;
  std::cout << " I - Consola interactiva." << std::endl;
  std::cout << " ESC - Termina el juego." << std::endl;
  std::cout << "----------------------------------" << std::endl << std::endl;

  // Simulamos la G.
  //key[KEY_G]=true;

  // Bucle principal del juego.
  while (!key[KEY_ESC])
  {
    // Si no está en pausa se actualiza el juego.
    if (!is_paused())
    {
      update ();
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

      // Prueba con sprite de Allegro.
      Sprite *prueba = (Sprite *) loro2->get_actor_graphic();
      allegro::SpriteAllegro* prueba2 = new allegro::SpriteAllegro (*prueba,loro2);

      // Prueba de Guichan integrado en el juego.
      prueba_guichan (prueba2);

      // Se cambia la paleta de colores que la prueba de Guichan cambia.
      set_palette (storage_manager->get_palette ("SPRITES"));

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
      std::cout << "Bitmap: " << bmp_camello->get_imagen () << " Nombre: " << storage_manager->get_name (bmp_camello->get_imagen()) << std::endl;

      // Por otra parte, Se prueba el uso del Bitmap en la Tesela.
      // 1 - Se crea un nuevo actor vacío.
      Actor *arbol = new Actor ();

      // 2 - Se crea el mosaico vacío.
      Mosaico *hojas = new Mosaico (arbol);
      
      // 3 - Se añaden Teselas al mosaico.
      hojas->add_ultima_Tesela (new Tesela (hojas, *new std::string("pre2_417")));
      hojas->add_ultima_Tesela (new Tesela (hojas, *new std::string("pre2_416"), 12, 20));
      hojas->add_ultima_Tesela (new Tesela (hojas, *new std::string("pre2_416"), 12, -20, true));
      
      // 4 - Se completan las propiedades del actor.
      arbol->set_x (130);
      arbol->set_y (250);
      arbol->set_wh (32,15);

      // 5 - Se añade el nuevo actor al controlador de actores para que lo muestre en pantalla.
      actor_manager->add(arbol);

      // 6 - Se descarga la información en pantalla.
      std::cout << "Mosaico de hojas: " << std::endl << hojas->print () << std::endl;

      // Limpieza de teclado.
      key[KEY_T]=false;
    }

    // Pruebas de Mapa de actores.
    // @todo Terminar estas pruebas.
    // @note Pensando que igual estas características deben estar integradas en la clase que
    //       controla los actores (ActorManager).
    if (key[KEY_M])
    {
      // Por otra parte, se prueba el mapa de actores.
      Mapa mapa_prb;
      mapa_prb.read (*actor_manager);
      std::cout << std::endl << mapa_prb << std::endl;

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
          std::cout << "Grabados objetos en fichero \"test.txt\"" << std::endl;
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
            std::cout << "Couldn't load font!";
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
  game.init (GFX_SAFE, 800,600,8);
  return 0;
}
END_OF_MAIN ();

