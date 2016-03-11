#ifndef ACTOR_H
#define ACTOR_H

#include <allegro.h>
// Se incluyen las cabeceras puesto que se necesita hacer referencia a tipos y
//  estructuras internas de las clases.
#include "CollisionManager.h"
#include "Game.h"
#include "Nombres.h"
#include "Bloque.h"

class ActorGraphic;
class Mask;

/** 
 * \brief   Elemento básico con dinámica dentro del juego.
 * \details Esta clase tiene como misión definir los elementos con dinámica propia en el juego.
 *          Se encarga de controlar todas las fases: Creación, actualización y destrucción de 
 *          los actores que intervienen en el juego (Jugadores, enemigos, plataformas móviles,...)
 *
 */
class Actor
{
public:
    /**
     * \brief   Estados posibles del actor.
     * \todo    Se debe poder heredar, incluir estados desde los hijos. Investigar.
     *          De esta forma eliminaríamos la clase "Nombres" que no me gusta nada.
     *          27-nov-09 - No me gusta nada, pero ésta no es una solución para los estados de los actores.
     */
    typedef int estado_t;
    enum estados{
        actuar,     /* El actor está actuando y quiere seguir actuando. */
        eliminar,   /* El actor quiere ser eliminado de la obra. */
        salir,      /* El actor quiere salir del escenario (no se elimina). */ 
        crear       /* El actor quiere crear otro actor (debería estar en su clase "GeneratorActor"). */ 
    };

public:
                        Actor               (const Actor &copia);
                        Actor               ();
        /// Operador de asignación.
        Actor&    operator=           (const Actor &copia);

        /// Destructor.
        virtual             ~Actor              ();
        virtual void        draw                (BITMAP *bmp);
        virtual void        update              ();
        virtual Actor *     clone               () const;
    
        /* \warning: Estos dos estados deben ser incluídos en uno. */
        virtual void            CambiarEstado       ();
        virtual void            ActualizarEstado    ();
        virtual void            init                ();
        void                    draw_block          (BITMAP *pantalla);
        int                     get_x               ();
        int                     get_y               ();
        int                     get_w               ();
        int                     get_h               ();
        void                    set_x               (int pos_x);
        void                    set_y               (int pos_y);
        void                    set_wh              (int w_tmp, int h_tmp);
        void                    set_color           (int color_tmp);
        int                     get_color           (void);
        void                    set_actor_graphic   (ActorGraphic *ag);
        ActorGraphic *          get_actor_graphic   () const;
        int                     get_graph_x         ();
        int                     get_graph_y         ();
        Mask *                  get_graph_mask          (void);
        void                    set_is_detected         (bool tf);
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
        bool                                    isIntersectado          (Bloque bloque);
        void                                    draw                    (StageManager *stageManager);
        void                                    draw_block              (StageManager *stageManager);
        Bloque &                                getBloque               ();

    protected:
        int             x, y;
        int             w, h;
        int             color;
        unsigned int    tiempo_estado;
        estado_t        estado;
        
        /**
         * Código del nombre del actor.
         */
        Nombres::codigo     nombre;
        ActorGraphic *      agraph;
        int                 power;
        Game::team_t        team;
        bool                is_detectable;
        CollisionManager::collision_method_t collision_method;
};

#endif
