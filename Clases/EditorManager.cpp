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
    editando = NULL;
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
    return editando;
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
    editando = game->actor_manager->get_actor (x,y-14);
    if (editando)
    {   
        editando->set_color (!editando->get_color());
    }
    redibuja ();
}
