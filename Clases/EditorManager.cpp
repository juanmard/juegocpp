#include "EditorManager.h"

/**
 * \brief   Construye la clase para editar un juego.
 * \details Debe generar otra ventana, obtener la lista de objetos y realizar su propio bucle de estética
 *          para representar los objetos del juego a editar.
 * \todo    Se debe generar la ventana de forma independiente de las bibliotecas (Allegro), para ello crear una
 *          "interfase" con estas funcionalidades, es decir, desligar de esta clase.
 */
EditorManager::EditorManager(Game *g)
{
	// Referencia al juego.
    game = g;

    // Referencia a la GUI.
    gui = new Dialog(this);

    // No hay actor elegido.
    actor_editado = NULL;
}

EditorManager::~EditorManager()
{
}

/**
 * \brief   Activa el modo edición del juego.
 * \details Al activar el modo edición del juego se debe:
 *          - Parar el bucle normal del juego.
 *          - Generar un menu con las propiedades de edición.
 *          - Activar un bucle propio únicamente de la parte gráfica.
 */
void EditorManager::activate ()
{
    // Se para el bucle del juego.
    game->pause ();

    // Se hace visible el menú de edición.
    gui->show ();

    // Se sale del editor y se vuelve al juego.
    gui->mouse_out ();
    game->play ();
}

/**
 * \brief   Edita el objeto actual.
 * \details Centra la pantalla de visualización en el objeto y abre un cuadro de diálogo con las
 *          propiedades del objeto.
 */
void EditorManager::edit ()
{
}

/**
 * \brief   Elige el objeto actual.
 * \details Elige el objeto actual según su índice en la lista.
 */
void EditorManager::set (int indice)
{
}

/**
 * \brief   Devuelve la referencia al juego que se edita.
 * \todo    Eliminar en un futuro. Esto es pasarle lo que debe hacer "EditorManager" a otra clase.
 */
Game *EditorManager::get_game (void)
{
    return game;
}

/**
 * \brief   Devuelve la referencia al juego que se edita.
 * \todo    Eliminar en un futuro. Esto es pasarle lo que debe hacer "EditorManager" a otra clase.
 */
Actor *EditorManager::get_actor (void)
{
    return actor_editado;
}

/**
 * \brief   Redibuja la lista de objetos.
 */
void    EditorManager::redibuja (void)
{
    game->stage_manager->draw ();
}

/**
 * \brief   Resalta el objeto que se encuentra en la posición (x,y).
 */
void    EditorManager::resaltar (int x, int y)
{
    // La pantalla está desplazada 14 pixels hacia abajo.
    Actor *actor = game->actor_manager->get_actor (x,y-14);
    if (actor)
    {
        // Cambiamos el color del marco.
        actor->set_color (!actor->get_color());

        // Redibuja la lista de actores.
        redibuja ();

        // Redibuja la GUI.
        gui->draw ();
    }
}

/**
 * \brief  Activa y desactiva la edición del objeto que se encuentra en la posición (x,y).
 */
void    EditorManager::editar (int x, int y)
{
    // Comprobamos que no está editado nada.
    // - Si está editado se elimina la edición.
    // - Si no está editado se captura el actor bajo la posición (x,y).
    if (actor_editado)
    {
        actor_editado = NULL;
    }
    else
    {
        actor_editado = game->actor_manager->get_actor (x,y-14);
    }
}

/**
 * \brief  Mueve el actor a la posición dada por (x,y).
 */
void    EditorManager::mover (int x, int y)
{
    // Comprobamos que no está editado nada.
    // - Si está actor_editado se mueve.
    // - Si no está actor_editado se ignora.
    if (actor_editado)
    {
        actor_editado->set_x (x);
        actor_editado->set_y (y);
    }
}

/**
 * \brief  Nos dice si está editando un actor.
 */
bool  EditorManager::is_editando ()
{
    if (actor_editado)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/**
 * \brief   Devuelve una referencia al actor situado en el punto x,y de la
 *            pantalla. Normalmente para editarlo.
 *  \todo  Es posible que exista más de un actor en ese punto, luego
 *            debería devolver una lista de actores.
 */
Actor &  EditorManager::getActor (int x, int y)
{
    return *(game->actor_manager->get_actor (x,y-14));
}
