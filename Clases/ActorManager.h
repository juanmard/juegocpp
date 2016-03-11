#ifndef ACTORMANAGER_H
#define ACTORMANAGER_H

#include <list>
#include "Escenario.h"

using namespace std;

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
                                  ~ActorManager	        ();
		void	                  add				    (Actor *a);
		void	                  del				    (Actor *a);
		void	                  rewind			    ();
		Actor *	                  get_actor		        (int x, int y);
		Actor *	                  next			        ();
		Actor *	                  current			    ();
		void	                  update			    ();
		int		                  num_actors		    ();
        list<Actor*>::iterator    get_begin_iterator    ();
        list<Actor*>::iterator    get_end_iterator      ();
        list<Actor *>             GetActores            (Escenario::Bloque bloque);

	protected:
		Game *                  game;
		list<Actor*>            actors;
		list<Actor*>::iterator  actors_iter;
        list<Actor*>            to_del;
        list<Actor*>            to_create;

//friend: 
public:
        void                    add_all_to_create   ();
        void                    del_all_to_del      ();
};

#endif
