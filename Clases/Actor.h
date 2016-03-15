#ifndef ACTOR_H
#define ACTOR_H

#include <allegro.h>
#include "Game.h"
#include "Mask.h"
#include "ActorGraphic.h"
#include "Nombres.h"

class ActorGraphic;

/** 
 * Elemento b�sico con din�mica dentro del juego.
 * Esta clase tiene como misi�n definir los elementos con din�mica propia en el juego.
 * Se encarga de controlar todas las fases: Creaci�n, actualizaci�n y destrucci�n de los actores que intervienen
 * en el juego (Jugadores, enemigos, plataformas m�viles,...)
 *
 */
class Actor
{
public:
    /**
     * \enum
     * \brief   Estados posibles del actor.
     * \todo    Se debe poder heredar, incluir estados desde los hijos. Investigar.
     *          De esta forma eliminar�amos la clase "Nombres" que no me gusta nada.
     *          27-nov-09 - No me gusta nada, pero �sta no es una soluci�n para los estados de los actores.
     */
    typedef int estado_t;
    enum estados{
        actuar,     /* El actor est� actuando y quiere seguir actuando. */
        eliminar,   /* El actor quiere ser eliminado de la obra. */
        salir,      /* El actor quiere salir del escenario (no se elimina). */ 
        crear       /* El actor quiere crear otro actor (deber�a estar en su clase "GeneratorActor"). */ 
    };

public:
                        Actor               ();
        virtual         ~Actor              ();
        virtual void    draw                (BITMAP *bmp);
        virtual void    update              ();
        /* \warning: Estos dos estados deben ser inclu�dos en uno. */
        virtual void    CambiarEstado       ();
        virtual void    ActualizarEstado    ();
        virtual void    init                ();
        void            draw_block          (BITMAP *pantalla);
        int             get_x               ();
        int             get_y               ();
        int             get_w               ();
        int             get_h               ();
        void            set_x               (int pos_x);
        void            set_y               (int pos_y);
        void            set_wh              (int w_tmp, int h_tmp);
        void            set_color           (int color_tmp);
        int             get_color           (void);
        void            set_actor_graphic   (ActorGraphic *ag);
        int             get_graph_x         ();
        int             get_graph_y         ();
        Mask *          get_graph_mask          (void);
        void                                    set_is_detected         (bool tf);
        bool                                    get_is_detected         (void);
        void                                    set_power               (int pow);
        int                                     get_power               (void);
        void                                    set_collision_method    (CollisionManager::collision_method_t cm);
        CollisionManager::collision_method_t    get_collision_method    (void);
        virtual void                            hit                     (Actor *who, int damage);
        void                                    set_team                (Game::team_t tm);
        Game::team_t                            get_team                (void);
        void                                    set_tiempo              (unsigned int tiempo);
        Actor::estado_t                         get_Estado              (void);
        Nombres::codigo                         get_name                (void);
        void                                    set_name                (Nombres::codigo nuevo_nombre);

    protected:
        int             x, y;
        int             h, w;
        int             color;
        unsigned int    tiempo_estado;
        estado_t        estado;
        
        /**
         * C�digo del nombre del actor.
         */
        Nombres::codigo     nombre;
        ActorGraphic *      agraph;
        int                 power;
        Game::team_t        team;
        bool                is_detectable;
        CollisionManager::collision_method_t collision_method;
};

#endif ACTOR_H
