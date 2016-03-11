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
#include  <allegro.h>
#include  "Control.h"
#include  "AirCraft.h"
#include  "Keyboard.h"
#include  "Paleta.h"
#include  "Sprite.h"
#include  "ActorManager.h"
#include  "Herny.h"
#include  "Pelota.h"
#include  "Ladrillo.h"
#include  "ControlManager.h"
#include  "EditorManager.h"
#include  "StageManager.h"
#include  "Almacen.h"
#include  "Loro.h"
#include  "Mago.h"
#include  "Ben.h"
#include <iostream>

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
void Juego2::main()
{
  PALETTE tmp;

  /* Creamos el control. */
  Control *control_p1=new Control;

  /* Creamos un periférico y asociamos control y propietario. */
  Keyboard *kboard=new Keyboard;
  control_p1->set_actionperipheral(Loro::DOWN,  kboard, KEY_DOWN,  Peripheral::ON_PRESSING);
  control_p1->set_actionperipheral(Loro::UP,    kboard, KEY_UP,    Peripheral::ON_PRESSING);
  control_p1->set_actionperipheral(Loro::LEFT,  kboard, KEY_LEFT,  Peripheral::ON_PRESSING);
  control_p1->set_actionperipheral(Loro::RIGHT, kboard, KEY_RIGHT, Peripheral::ON_PRESSING);
  control_p1->set_actionperipheral(Loro::JUMP,  kboard, KEY_A, Peripheral::ON_PRESSING);

  /* Creamos otro control de prueba. */
  Control *control_p2=new Control;
  control_p2->add_action_name(Paleta::LEFT, "Izquierda");
  control_p2->add_action_name(Paleta::RIGHT, "Derecha");
  control_p2->set_actionperipheral(Paleta::LEFT, kboard, KEY_LEFT, Peripheral::ON_PRESSING);
  control_p2->set_actionperipheral(Paleta::RIGHT, kboard, KEY_RIGHT, Peripheral::ON_PRESSING);

  // sprites->SetPalette (0);
  set_palette (storage_manager->GetPalette ("SPRITES"));

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
  
  // Añadimos una conjunto de ladrillos de prueba.
  for (int j=0; j<=2; j++)
  {    
    for (int i=1; i<=14; i++)
    {
      actor_manager->add(new Ladrillo(i*40, 40+40*j, *storage_manager));
    }
  }

  // Se añade una paleta de prueba pero con piel de Suelo.
  Paleta *prueba_suelo = new Paleta();
  prueba_suelo->set_x(100);
  prueba_suelo->set_y(300);
  prueba_suelo->set_actor_graphic(new Suelo(prueba_suelo,*storage_manager,8));
  actor_manager->add(prueba_suelo);

  // Se añade el control de prueba creado para el loro, al manejador de controles.
  control_manager->add_control(control_p1);
  //control_manager->add_control(control_p2);

  // Se añade el periférico que realizará el control.
  control_manager->add_peripheral(kboard);

  // Se crea el 'EditorManager' básico para comenzar con las pruebas.
  EditorManager   editor(this);

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
        stage_manager->setSeguimiento (ben);
      }
      key[KEY_S] = false;
    }

    // Se comprueba la visualización de los bloques.
    if (key[KEY_V])
    {
      stage_manager->setVerBloques (!stage_manager->getVerBloques ());
      key[KEY_V] = false;
    }

    // Parte de código para pruebas del juego.
    if (key[KEY_T])
    {
      Mapa mapa_prb;
      mapa_prb.Read (*actor_manager);
      cout << mapa_prb.getString ();
      key[KEY_T] = false;
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
  game.init(GFX_AUTODETECT_WINDOWED, 640,480,8);
  return 0;
}
END_OF_MAIN ();

