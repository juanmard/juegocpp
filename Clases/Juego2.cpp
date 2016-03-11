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

/**
 * \brief   Crea el objeto del juego.
 */
Juego2::Juego2 ()
{
}

/**
 * \brief   Se crea el almacén para este juego.
 */
void Juego2::create_storage ()
{
    // Creamos el almacén de recursos.
    almacen = new Almacen("sprites3.dat");
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
  set_palette (almacen->GetPalette ("SPRITES"));

  // Se crea Aladino de prueba.
  Herny *aladino = new Herny(*almacen);
  aladino->set_y (280);
  aladino->set_x (380);
  //control_p1->set_owner(aladino);
  actor_manager->add(aladino);

  // Se crea Herny de prueba.
  Herny *jugador = new Herny();
  jugador->set_y (280);
 // control_p1->set_owner(jugador);
  actor_manager->add(jugador);

  // Se crea la Paleta del juego.
  Paleta *paleta = new Paleta();
//  control_p2->set_owner (paleta);
  actor_manager->add (paleta);

  // Se crea el loro de prueba.
  Loro *loro = new Loro (*almacen);
//  control_p1->set_owner (loro);
  actor_manager->add (loro);

  // Se crea mago de prueba.
  control_p1->add_action_name (Mago::DOWN, "Bajar");
  control_p1->add_action_name (Mago::UP,   "Subir");
  control_p1->add_action_name (Mago::LEFT, "Izquierda");
  control_p1->add_action_name (Mago::RIGHT,"Derecha");
  control_p1->add_action_name (Mago::JUMP, "Saltar");
  control_p1->add_action_name (Mago::SPELL,"Hechizo");
  control_p1->set_actionperipheral (Mago::DOWN,  kboard, KEY_DOWN,  Peripheral::ON_PRESSING);
  control_p1->set_actionperipheral (Mago::UP,    kboard, KEY_UP,    Peripheral::ON_PRESSING);
  control_p1->set_actionperipheral (Mago::LEFT,  kboard, KEY_LEFT,  Peripheral::ON_PRESSING);
  control_p1->set_actionperipheral (Mago::RIGHT, kboard, KEY_RIGHT, Peripheral::ON_PRESSING);
  control_p1->set_actionperipheral (Mago::JUMP,  kboard, KEY_SPACE, Peripheral::ON_PRESSING);
  control_p1->set_actionperipheral (Mago::SPELL, kboard, KEY_A,     Peripheral::ON_PRESSING);
  Mago *mago = new Mago (*almacen);
  control_p1->set_owner (mago);
  actor_manager->add (mago);

  // Se crea la pelota del juego.
  Pelota *pelota = new Pelota(actor_manager);
  pelota->set_y (170);
  actor_manager->add(pelota);
  
  // Añadimos una conjunto de ladrillos de prueba.
  for (int j=0; j<=2; j++)
  {    
    for (int i=1; i<=14; i++)
    {
      actor_manager->add(new Ladrillo(i*40, 40+40*j, *almacen));
    }
  }

  // Se añade un Ladrillo de prueba pero con piel de Suelo.
  Ladrillo *prueba_suelo = new Ladrillo();
  prueba_suelo->set_x(100);
  prueba_suelo->set_y(300);
  prueba_suelo->set_actor_graphic(new Suelo(prueba_suelo,6));
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
      stage_manager->setSeguimiento (mago);
      key[KEY_S] = false;
    }

  }
  fade_out(2);
}

/**
 * \brief   "main" principal que inicia el juego de prueba.
 */
int main ()
{
	Juego2 game;
	srand(time(NULL));
	game.set_name("Test del Marco de Trabajo");
  game.init(GFX_AUTODETECT_WINDOWED, 640,480,8);
  return 0;
}
END_OF_MAIN ();

