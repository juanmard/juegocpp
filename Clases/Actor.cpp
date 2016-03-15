#include "Actor.h"

/**
 * Crea e l actor.
 * Predeterminadamente no asigna gr�fico y no se sit�a en el tiempo. 
 */

Actor::Actor()
{
    agraph = NULL;
    estado = actuar;
    tiempo_estado = 0;
}

/**
 * Destruye el actor.
 * Si tiene asignado un gr�fico lo elimina.
 */
Actor::~Actor()
{
    if (agraph) delete agraph;
}

/**
 * Visualiza el aspecto gr�fico del actor.
 * Delega esta funci�n en el objeto gr�fico.
 */
void Actor::draw(BITMAP *bmp)
{
    agraph->draw(bmp);
}

/**
 * Visualiza las dimensiones del actor mediante un rect�ngulo.
 * Utiliza la propiedad 'color' para ello.
 */
void Actor::draw_block (BITMAP *pantalla)
{
    rect (pantalla,x,y,x+w,y+h,color);
}

void Actor::hit (Actor *who, int damage)
{
};

void Actor::set_collision_method (CollisionManager::collision_method_t metodo)
{
    collision_method = metodo;
};

void Actor::set_team (Game::team_t equipo)
{
    team = equipo;
};

void Actor::set_is_detected (bool detectable)
{
    is_detectable = detectable;
};

void Actor::ActualizarEstado ()
{
}

void Actor::CambiarEstado ()
{
}

void Actor::set_tiempo (unsigned int tiempo)
{
    tiempo_estado = tiempo;
}

void Actor::update()
{
    // Actualiza la parte gr�fica.
    agraph->update();

    // Actualiza los estados del actor.
    if (tiempo_estado)
    {
        tiempo_estado--;
        if (tiempo_estado == 0)
        {
                CambiarEstado ();
        }
        ActualizarEstado ();
    }
}

void Actor::init()
{
    agraph->init();
}


void Actor::set_x(int pos_x)
{
    x=pos_x;
}

void Actor::set_color (int color_tmp)
{
    color = color_tmp;
}

void Actor::set_y(int pos_y)
{
    y=pos_y;
}

void Actor::set_wh (int w_tmp, int h_tmp)
{
    w = w_tmp;
    h = h_tmp;
}

void Actor::set_actor_graphic(ActorGraphic *ag)
{
    agraph=ag;
}

int Actor::get_color (void)
{
    return color;
}

int Actor::get_x()
{
    return x;
}

int Actor::get_y()
{
    return y;
}

int Actor::get_w()
{
    return w;
}

int Actor::get_h()
{
    return h;
}

int Actor::get_graph_x()
{
    return agraph->get_x();
}

int Actor::get_graph_y()
{
    return agraph->get_y();
}

/**
 * \brief   M�todo para obtener el c�digo del nombre.
 * \param   Nombres::codigo     C�digo del nombre a devolver.
 */
Nombres::codigo Actor::get_name (void)
{
    return nombre;
};

/**
 * \brief   M�todo para modificar el nombre.
 * \param   new_name    Nombre nuevo para sustituir.
 */
void Actor::set_name (Nombres::codigo new_name)
{
    nombre = new_name;
};

/**
 * \brief   M�todo para obtener el estado actual del actor.
 */
Actor::estado_t  Actor::get_Estado (void)
{
    return estado;
}
