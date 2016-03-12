#ifndef _ACTORMANAGER_H_
#define _ACTORMANAGER_H_

#include <list>
#include <iostream>
#include <string>
#include "Bloque.h"

//using namespace std;
using std::list;
using std::ostream;
using std::istream;
using std::string;

class Actor;
class Game;

/** 
 * \brief   Maneja y controla los actores de la escena.
 * \details Esta clase controla todos los actores y sus estados dentro de la escena.
 */
class ActorManager
{
  public:
                            				ActorManager          (Game *g);
                            				~ActorManager         ();
    void                    			add                   		(Actor *a);
    void                    			del                   		(Actor *a);
    void                    			rewind                		();
    Actor *                 			get_actor             	(int x, int y);
    Actor *                 			next                  		();
    Actor *                 			current               		();
    void                    			update              	  ();
    int                     			num_actors      			();
    list<Actor*>::iterator  get_begin_iterator  ();
    list<Actor*>::iterator  get_end_iterator     ();
    list<Actor *>           		GetActores            	(Bloque &bloque);
    void                    			setVisualizar         	(Actor *paramActor);
    Actor *                 			getActor              	(unsigned int indice);
    string                  			getArmario            	();
	 void										load								(string &file);


  protected:
    void      actualizarVisualizacion ();
    void      avisoActorSinGrafico (Actor *a) const;

  protected:
    Game *                  			game;
    list<Actor*>            		actors;
    list<Actor*>::iterator  actors_iter;
    list<Actor*>            		to_del;
    list<Actor*>            		to_create;
    Actor *                 			actorVisualizado;

  public:
    void                    add_all_to_create   ();
    void                    del_all_to_del      ();

    // Funciones amigas y no-miembro de la clase.
    friend    ostream&  operator<<   (ostream &os, const ActorManager &am);
    friend    istream&  operator>>   (istream &is, ActorManager &am);

};

#endif
