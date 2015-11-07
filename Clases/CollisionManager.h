///
/// @file CollisionManager.h
/// @brief Fichero de definición de la clase "CollisionManager".
/// @author Juan Manuel Rico
/// @date Noviembre 2015
/// @version 1.0.0
///

#ifndef _COLLISIONMANAGER_H_
#define _COLLISIONMANAGER_H_

class Game;
class Actor;

/// Clase que recoge las operaciones de colisión del juego entre actores.
/// @todo Incluir las opciones de colisión entre 'Bloques', para por ejemplo,
///       poder realizar colisiones entre actores y escenario.
/// @note Al parecer no se utiliza la intersección por máscara,
///       eliminar el tipo si no es necesario.
///
class CollisionManager
{
public:
    /// Tipos de colisión permitidas.
    typedef enum {
        BOUNDING_BOX,   ///< Colisión por intersección de bloques.
        PP_COLLISION    ///< Colisión por intersección de máscara.
    } collision_method_t;

protected:
    Game* game;     ///< Puntero al juego propietario del controlador.

public:
    /// Constructor.
    /// @param g  Juego propietario del controlador.
    ///
    CollisionManager (Game* g);

    /// Actualiza el estado de las colisiones.
    ///
    /// Se va recorriendo la lista de actores a controlar y se prueba la colisión dos a dos actores.
    /// Si se produce la colisión se envían sendos mensajes de colisión a ambos actores (hit) y a modo
    /// de prueba se cambia el color característico de ambos actores para poder depurar el juego.
    ///
    /// @todo Modelar el tipo de daño de cada actualización. Actualmente se envía una unidad como daño
    ///       a ambos actores.
    void update ();

    /// Se comprueba la intersección por límites entre dos actores.
    /// @param actor1  Puntero al primer actor.
    /// @param actor2  Puntero al segundo actor.
    /// @return Si existe o no intersección entre ambos actores.
    ///
    bool Bounding (Actor* actor1, Actor* actor2);
};

#endif
