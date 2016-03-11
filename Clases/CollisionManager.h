#ifndef  _COLLISIONMANAGER_H_
#define  _COLLISIONMANAGER_H_

class Game;
class Actor;

/**
 * \brief   Clase que recoge las operaciones de colisión del juego entre actores.
 * \todo    Incluir las opciones de colisión entre 'Bloques', para por ejemplo,
 *          poder realizar colisiones entre actores y escenario.
 */
class CollisionManager
{
  public:
    typedef enum {BOUNDING_BOX, PP_COLLISION} collision_method_t;

            CollisionManager    (Game *g);
    void    update              ();
    bool    Bounding            (Actor *actor1, Actor *actor2);

  protected:
    Game *game;
};

#endif
