
#include "Actor.h"
#include "ActorManager.h"
#include <algorithm>

ActorManager::ActorManager(Game *g)
{
	game = g;
}

/**
 * \brief   Devuelve el actor cuyas coordenadas en pantalla son (x,y).
 * \todo    Preveer que en un futuro debe devolver una lista de actores.
 */
Actor * ActorManager::get_actor (int x, int y)
{
	Actor *encontrado = NULL;
    actors_iter = actors.begin();
    // Comprobar el bucle, es posible que el primero no lo compruebe si es el único de la lista.
    while (encontrado == NULL && actors_iter != actors.end()) 
    {
        if ( !(  (x <= (*actors_iter)->get_x())
             || (y <= (*actors_iter)->get_y())
             || (x >= ((*actors_iter)->get_x() + (*actors_iter)->get_w()))
             || (y >= ((*actors_iter)->get_y() + (*actors_iter)->get_h()))
             ))
        {
            encontrado = *actors_iter;
        }
        else
        {
    	    actors_iter++;
        }
    }
    return encontrado;
}

ActorManager::~ActorManager()
{
	for (actors_iter=actors.begin(); actors_iter!=actors.end();	actors_iter++)
	delete (*actors_iter);
}

void ActorManager::add(Actor *a)
{
	to_create.push_back(a);
}

void ActorManager::del(Actor *a)
{
    to_del.push_back(a);
}


void ActorManager::del_all_to_del()
{
    if (to_del.size()==0) return;

    list<Actor*>::iterator tmp_iter;
    list<Actor*>::iterator tmp_actors_iter;

    for (tmp_iter=to_del.begin(); tmp_iter!=to_del.end(); tmp_iter++)
    {
        tmp_actors_iter=find(actors.begin(), actors.end(), *tmp_iter);
        if (tmp_actors_iter!=actors.end())
        {
            actors.erase(tmp_actors_iter);
            delete (*tmp_iter);
        }
    }
    to_del.clear();
}

void ActorManager::add_all_to_create()
{
    if (to_create.size()==0) return;

    list<Actor *>::iterator tmp_iter;

    for (tmp_iter=to_create.begin(); tmp_iter!=to_create.end(); tmp_iter++)
    {
        actors.push_back(*tmp_iter);
        (*tmp_iter)->init();
    }
    to_create.clear();
}

void ActorManager::rewind()
{
	actors_iter = actors.begin();
}

Actor *ActorManager::next()
{
	Actor *tmp_a = NULL;

	if (actors_iter != actors.end())
	{
		tmp_a = *actors_iter;
		actors_iter++;
	}
	return tmp_a;
}

Actor *ActorManager::current()
{
	if (actors_iter==actors.end()) return NULL;
	else
	return *actors_iter;
}

int ActorManager::num_actors()
{
	return actors.size();
}

void ActorManager::update()
{
    list<Actor*>::iterator tmp_iter;

     /*
      * TODO: Hacer un "move_all_to_stage" para pasar los actores en bambalinas a escena y así
      *        eliminar las dos funciones "add_all_to_create" y "del_all_to_del" por separado. 
      */

     /* Agrega al escenario a todos los actores en espera. */
    add_all_to_create();

    /* Actualiza ahora los actores en escena. */
    for (tmp_iter=actors.begin(); tmp_iter!=actors.end(); tmp_iter++)
    {
        (*tmp_iter)->update();

        /* Se comprueba el estado del actor tras actualizar. */
        switch ((*tmp_iter)->get_Estado())
        {
        case Actor::eliminar:
                /* Si quiere ser eliminado se añade a la lista para eliminarlo. */
                del ((*tmp_iter));
                break;

        case Actor::crear:
                /**
                 * Si quiere crear algún objeto se le pregunta por el hijo y se añade
                 * a la lista.
                 * \warning    No se comprueba que el actor pueda hacer esto. Es decir,
                 *             no se comprueba que sea de la clase "GeneratorActor".
                 *             En teoría si puede mandar ese mensaje es que es de esta clase.
                 */
                Actor *tmp = (*tmp_iter);
                //add (tmp->get_hijo());

                /* Se cambia el estado del padre para que siga actuando. */
                /* \todo Incluir un set_estado */
                //(*tmp_iter)->set_estado = Actor::actuar;
                break;
        }
    }
    
    /* Elimina todos los actores en espera. */
    /* TODO: La llamada a esta función no tiene sentido si ya están los actores en escena. */
    del_all_to_del();
}

list<Actor*>::iterator ActorManager::get_begin_iterator()
{
    return actors.begin();
}

list<Actor*>::iterator ActorManager::get_end_iterator()
{
    return actors.end();
}
