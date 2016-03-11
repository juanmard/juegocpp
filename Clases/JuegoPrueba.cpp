/*! \file JuegoPrueba.cpp
 *  \brief Prueba del "framework" de un juego.
 *
 *  La clase instancia un tipo de juego de prueba con todos los controladores posibles.
 *  La primera versión de la instancia se utiliza para actualizar el juego de plataformas
 *  programado antiguamente en C "puro y duro".
 *
 *  \author Juan Manuel Rico
 *  \date    Julio de 2009
 *  \version 1.00
 *
 *  \todo Comentar todas estas clases y funciones más detalladamente.
 */

#include "JuegoPrueba.h"
#include <allegro.h>
#include "Control.h"
#include "AirCraft.h"
#include "Keyboard.h"
#include "Paleta.h"
#include "Sprite.h"
#include "ActorManager.h"
#include "Herny.h"
#include "Pelota.h"
#include "Ladrillo.h"
#include "ControlManager.h"
#include "EditorManager.h"


void JuegoPrueba::main()
{
	PALETTE tmp;

    /* Creamos el control. */
    Control *control_p1=new Control;
    control_p1->add_action_name(AirCraft::DOWN, "Bajar");
    control_p1->add_action_name(AirCraft::UP, "Subir");
    control_p1->add_action_name(AirCraft::LEFT, "Izquierda");
    control_p1->add_action_name(AirCraft::RIGHT,"Derecha");

    /* Creamos un periférico y asociamos control y propietario. */
    Keyboard *kboard=new Keyboard;
    control_p1->set_actionperipheral(AirCraft::DOWN, kboard, KEY_DOWN, Peripheral::ON_PRESSING);
    control_p1->set_actionperipheral(AirCraft::UP, kboard, KEY_UP, Peripheral::ON_PRESSING);
    control_p1->set_actionperipheral(AirCraft::LEFT, kboard, KEY_LEFT, Peripheral::ON_PRESSING);
    control_p1->set_actionperipheral(AirCraft::RIGHT, kboard ,KEY_RIGHT, Peripheral::ON_PRESSING);

    /* Creamos otro control de prueba. */
    Control *control_p2=new Control;
    control_p2->add_action_name(Paleta::LEFT, "Izquierda");
    control_p2->add_action_name(Paleta::RIGHT, "Derecha");
    control_p2->set_actionperipheral(Paleta::LEFT, kboard, KEY_LEFT, Peripheral::ON_PRESSING);
    control_p2->set_actionperipheral(Paleta::RIGHT, kboard, KEY_RIGHT, Peripheral::ON_PRESSING);

	AirCraft *a=new AirCraft;
	AirCraft *b=new AirCraft;
	BITMAP *bmp, *bmp2, *bmp3;

    DatFile *sprites = new DatFile("sprites.dat");
    bmp = load_bitmap("nave.pcx", tmp);
	bmp2 = load_bitmap("nave2.pcx", tmp);
	bmp3 = load_bitmap("nave3.pcx", tmp);

    sprites->SetPalette (0);
 	// TODO: Comprobar que existe el fichero y que el "bmp" se ha cargado correctamente.
	// if (bmp != NULL) { };
    //	 cout << "BMP cargado: " << bmp << endl;

    // Se genera un Sprite de preuba.
    Sprite *sp=new Sprite(a);
    sp->add_frame(sprites->GetBitmap(12), 0, 0, 10);
    sp->add_frame(sprites->GetBitmap(20), 0, 0, 30);
    sp->add_frame(sprites->GetBitmap(21), 0, 0, 10);
    sp->add_frame(sprites->GetBitmap(22), 0, 0, 10);
    a->set_x(SCREEN_W/2);
    a->set_y(SCREEN_H/2);
    a->set_actor_graphic (sp);
	a->set_is_detected(true);
    a->set_team(ENEMY);
    a->set_collision_method(CollisionManager::PP_COLLISION);
    a->set_wh (10,20);
    actor_manager->add(a);

    Herny *jugador = new Herny();
    jugador->set_y (280);
    control_p1->set_owner(jugador);
    actor_manager->add(jugador);

    Paleta *paleta = new Paleta();
    control_p2->set_owner(paleta);
    actor_manager->add(paleta);

    Pelota *pelota = new Pelota(actor_manager);
    pelota->set_y (170);
    actor_manager->add(pelota);

    Ladrillo *ladrillo2 = new Ladrillo(10,0);

    ladrillo2->set_color (34);
    this->actor_manager->add (ladrillo2);


    /**
     * \brief   Añadimos una fila de ladrillos de prueba.
     */
    for (int j=0; j<=2; j++)
    {    
        for (int i=1; i<=14; i++)
        {
            actor_manager->add(new Ladrillo(i*40,40+40*j));
        }
    }

    // Añadimos actor de prueba con el mensaje EVERSOFT.
    Bitmap *bitm2=new Bitmap(b, sprites->GetBitmap("EVERSOFT"));
	b->set_x(110);
	b->set_y(210);
    b->set_actor_graphic(bitm2);
	b->set_is_detected(true);
    b->set_team(ENEMY);
    b->set_collision_method(CollisionManager::PP_COLLISION);
    b->set_wh (40,30);
    actor_manager->add(b);

    // Añadimos el demonio de prueba.
    AirCraft *c = new AirCraft();
	c->set_x(210);
	c->set_y(210);
    c->set_actor_graphic(new Bitmap(c, sprites->GetBitmap("demon")));
	c->set_is_detected(true);
    //c->set_team(ENEMY);
    c->set_collision_method(CollisionManager::PP_COLLISION);
    c->set_wh (50,60);
    actor_manager->add(c);

    // Se añade un Ladrillo de prueba pero con piel de Suelo.
    Ladrillo *prueba_suelo=new Ladrillo();
	prueba_suelo->set_x(100);
	prueba_suelo->set_y(300);
    prueba_suelo->set_actor_graphic(new Suelo(prueba_suelo,6));
    //prueba_suelo->set_wh (200,20);
    actor_manager->add(prueba_suelo);


    // Se añade el control de prueba creado al manejador de controles.
    // control_manager->add_control(control_p1);
    control_manager->add_control(control_p2);

    // Se añede el periférico que realizará el control.
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

        // Se prueba el editor.
        if (key[KEY_E])
        {
            // Se activa el editor.
            editor.activate ();

            // Se borran las teclas pulsadas para evitar rellamadas.
            key[KEY_E]=false;
            key[KEY_ESC]=false;
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
            key[KEY_P]=false;
        }
    }

    // Destruye los bitmaps.
    // \warning Debe estar en el destructor.
    destroy_bitmap(bmp);
}

/**
 * \brief   "main" principal que inicia el juego.   
 */
int main()
{
	JuegoPrueba game;
	srand(time(NULL));
	game.set_name("Test del Marco de Trabajo");
	//game.init(GFX_AUTODETECT, 640,480,16);   //Full-Screen
	/**
     * \todo    Mantener estos cuatro parámetros como propiedades de "Game" y así poder ser
     *          consultadas por otras clases (pj. EditorManager).
     */
    game.init(GFX_AUTODETECT_WINDOWED, 640,480,8);
    return 0;
}
END_OF_MAIN ();
