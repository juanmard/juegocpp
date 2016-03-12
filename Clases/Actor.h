/**
 *  \file     Actor.h
 *  \brief    Fichero con el código de definición de la clase Actor.
 *
 *  \author   Juan Manuel Rico
 *  \date     Diciembre 2010
 *  \version  1.00
 *
 */
#ifndef _ACTOR_H_
#define _ACTOR_H_

#include <allegro.h>
// Se incluyen las cabeceras puesto que se necesita hacer referencia a tipos y
//  estructuras internas de las clases.
#include "CollisionManager.h"
#include "Game.h"
#include "Nombres.h"
#include "Bloque.h"
#include "Menu.h"
#include <vector>
#include "EditorManager.h"
#include "GUIEscenario.h"

class ActorGraphic;
class Mask;
class ActorGUI;

/** 
 * \brief   Elemento básico con dinámica dentro del juego.
 * \details Esta clase tiene como misión definir los elementos con dinámica propia en el juego.
 *          Se encarga de controlar todas las fases: Creación, actualización y destrucción de 
 *          los actores que intervienen en el juego (Jugadores, enemigos, plataformas móviles,...)
 *
 */
class Actor
{
  friend class ActorGUI;

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
    void                getXY               (string &posicion) const;
    void                getWH               (string &dimensiones) const;
    virtual void        getEstado           (string &estado) const;
    virtual void        getNombre           (string &nombre) const;
    virtual Menu &      getMenu             () const;
    string              getString           () const;
    virtual string      getNombre           () const;
    void                addEnlace           (DIALOG *enlace);

    /* \warning: Estos dos estados deben ser incluidos en uno. */
    virtual void                            CambiarEstado           ();
    virtual void                            ActualizarEstado        ();
    virtual void                            init                    ();
    void                                    draw_block              (BITMAP *pantalla);
    int                                     get_x                   ();
    int                                     get_y                   ();
    int                                     get_w                   ();
    int                                     get_h                   ();
    void                                    set_x                   (int pos_x);
    void                                    set_y                   (int pos_y);
    void                                    set_wh                  (int w_tmp, int h_tmp);
    void                                    set_color               (int color_tmp);
    int                                     get_color               ();
    void                                    set_actor_graphic       (ActorGraphic *ag);
    ActorGraphic *                          get_actor_graphic       () const;
    int                                     get_graph_x             ();
    int                                     get_graph_y             ();
    Mask *                                  get_graph_mask          ();
    void                                    set_is_detected         (bool tf);
    bool                                    get_is_detected         ();
    void                                    set_power               (int pow);
    int                                     get_power               ();
    void                                    set_collision_method    (CollisionManager::collision_method_t cm);
    CollisionManager::collision_method_t    get_collision_method    ();
    void                                    set_team                (Game::team_t tm);
    Game::team_t                            get_team                ();
    void                                    set_tiempo              (unsigned int tiempo);
    Actor::estado_t                         get_Estado              ();
    Nombres::codigo                         getCodigo               ();
    void                                    setCodigo               (Nombres::codigo nuevo_nombre);
    bool                                    isIntersectado          (Bloque bloque);
    void                                    draw                    (StageManager *stageManager);
    void                                    draw_block              (StageManager *stageManager);
    Bloque &                                getBloque               ();
    void                                    setMostrarBloque        (bool mostrar);
    virtual  void                           addGUI                  (vector<DIALOG> &gui_padre);
    virtual  void                           drawGUI                 ();
    virtual  ActorGUI *                     getGUI                  ();
	virtual void                            hit                     (Actor *who, int damage);
	virtual	void							leerActor				(char *[]);

  private:
    void                                    mensajeErrorGrafico     () const;
    // Generamos una sola GUI para todos los actores.
    static ActorGUI *                       gui;

  private:
    void                                    mensajeErrorGrafico     () const;

  protected:
    Nombres::codigo                         nombre;
    int                                     x, y;
    int                                     w, h;
    int                                     color;
    unsigned int                            tiempo_estado;
    estado_t                                estado;
    bool                                    mostrarBloque;
    ActorGraphic *                          agraph;
    int                                     power;
    Game::team_t                            team;
    bool                                    is_detectable;
    CollisionManager::collision_method_t    collision_method;

  // Métodos amigos no-miembros de la clase.
  friend  ostream&    operator<<    (ostream &os, const Actor &a);
  friend  istream&    operator>>    (istream &is, Actor &a);
};

#endif
