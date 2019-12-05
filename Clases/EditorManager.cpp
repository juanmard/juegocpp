///
/// @file EditorManager.cpp
/// @brief Fichero de implementación de la clase "EditorManager".
/// @author Juan Manuel Rico
/// @date Noviembre 2015
/// @version 1.0.0
///

#include "EditorManager.h"
#include "Game.h"
#include "Dialog.h"
#include "StageManager.h"

namespace fwg {

int EditorManager::refX = 0;
int EditorManager::refY = 0;

EditorManager::EditorManager (Game* g):
game (g),
actor (NULL),
actorActivado (false),
actorAtrapado (false),
actorFijado (false)
{
  // Referencia a la GUI.
  gui = new alg4::Dialog(this);
};

EditorManager::~EditorManager ()
{
};

void EditorManager::activate ()
{
  // Se para el bucle del juego.
  game->pause ();
 
  // Guardamos el ribete actual del juego.
  // Bloque ribete_ant (game->stageManager->getRibete ());
  Bloque ribete_ant (0, 0, SCREEN_W, SCREEN_H-100);

  // Le decimos al escenario que queremos ver los bloques de los actores.
  game->stageManager->set_ver_bloques (true);

  // Se hace visible el menú de edición.
  gui->show ();

  // Cuando se termina de editar:
  game->stageManager->set_ver_bloques (false);     //  1 - Ocultamos los bloques.
  game->stageManager->set_ribete (ribete_ant);     //  2 - Se recupera el ribete.
  ///gui->mouse_out ();                             //  3 - Ocultamos el ratón.
  borrar_pantalla ();                               //  4 - Borramos la pantalla.
  game->play ();                                    //  5 - Se vuelve al juego.
};

void EditorManager::dibujar_escenario ()
{
  game->stageManager->draw ();
};

void EditorManager::mover_actor (int x, int y)
{
  // Comprobamos que no está editado nada.
  // - Si está actorAtrapado se mueve.
  // - Si no está actorAtrapado se ignora.
  if (actor)
  {
    actor->set_x (x);
    actor->set_y (y);
  }
};

int EditorManager::get_actor_x () const
{
  return actor->get_x ();
};

int EditorManager::get_actor_y () const
{
  return actor->get_y ();
};

void EditorManager::set_actor_x (int x)
{
  actor->set_x (x);
};

void EditorManager::set_actor_y (int y)
{
  actor->set_y (y);
};

void EditorManager::duplicar_actor (Actor* actor)
{
  // Se comprueba que la referencia existe.
  if (actor)
  {
    // Se crea un nuevo actor en memoria basándose en el elegido.
    Actor* nuevo = actor->clone ();

    // Si se ha creado correctamente...
    if (nuevo)
    {
      // Se desplaza para visualizarlo.
      nuevo->set_x (nuevo->get_x () - 10);
      nuevo->set_y (nuevo->get_y () - 10);

      // Se añade a la lista de actores.
      game->actorManager->add (nuevo);

      // Se actualiza la lista de actores creados para hacerlos visibles.
      // \todo Hacer friend estos procedimientos para usarlos sólo desde los "Manager"
      //game->actorManager->add_all_to_create ();
    }
  }
};

Actor* EditorManager::get_actor (int x, int y) const
{
  return game->actorManager->getActor (x, y);
};

std::string& EditorManager::get_nombre_actor (int indice) const
{
  Actor* actor = game->actorManager->getActor (indice);
  if (actor)
  {
    return *new std::string (actor->get_nombre());
  }
  else
  {
    return *new std::string("sin nombre");
  }
};

void EditorManager::mover_escenario (int x, int y)
{
  game->stageManager->mover_marco (x, y);
};

int EditorManager::get_escenario_x () const
{
  return game->stageManager->get_x ();
};

int EditorManager::get_escenario_y () const
{
  return game->stageManager->get_y ();
};

void  EditorManager::step () const
{
  //game->stageManager->setRibete (Bloque (10,10,640,190));
  //game->actorManager->update ();
  game->update ();
  gui->draw ();
};

BITMAP* EditorManager::get_buffer ()
{
  return game->stageManager->getBuffer ();
};

void EditorManager::actualizar_escenario ()
{
  return game->stageManager->rellenar_buffer ();
};

unsigned int EditorManager::get_num_actores () const
{
  return game->actorManager->numActors ();
};

void EditorManager::set_ribete (Bloque bloque) const
{
  return game->stageManager->set_ribete(bloque);
};

void EditorManager::borrar_pantalla () const
{
  clear_to_color (screen, makecol (128, 128, 128));
};

void EditorManager::centrar_actor (int indice) const
{
  // Se toma el actor de la lista dado por el índice.
  Actor* actor = game->actorManager->getActor (indice);

  // Si el actor existe.
  if (actor)
  {
    // \warning   Esto se hace todas las veces que se centra el actor
    //            y sólo es necesario hacerlo una vez. Igualar las dimensiones
    //            de 'marco' y 'ribete' antes de entrar en edición.
    // Se toman los bloques del marco y el ribete.
    Bloque& marco = game->stageManager->get_marco ();
    Bloque& ribete = game->stageManager->get_ribete ();
    // Se igualan las dimensiones del marco a las del ribete.
    // De esta forma queda el actor en el centro de la pantalla.
    marco.set_wh (ribete.get_w (), ribete.get_h ());
    // Se centra el marco alrededor del actor.
    marco.centrar (actor->getBloque());
    // Se le indica a la gui que edite el actor.
    gui->setActor (actor);
    // Se le indica a la gui que actualice las nuevas propiedades.
    gui->draw ();
  }
};

void EditorManager::set_color_ribete (int color)
{
  game->stageManager->set_color_ribete (color);
};

std::string& EditorManager::get_escenario_xy () const
{
  std::ostringstream oss;
  Bloque marco (game->stageManager->get_marco ());
  oss << "(" << marco.get_x () << ", " << marco.get_y () << ")";
  return *new std::string(oss.str ());
};

Almacen& EditorManager::get_almacen () const
{
  return *(game->storageManager);
}

bool EditorManager::is_actor_atrapado () const
{
  return actorAtrapado;
};

bool EditorManager::is_actor_activo () const
{
  return actorActivado;
}

bool EditorManager::is_actor_fijo () const
{
  return actorFijado;
};

bool EditorManager::is_decorado_atrapado () const
{
  return false;
};

void EditorManager::mover_decorado (int x, int y)
{
};

void EditorManager::actualizar_actor ()
{
  // Le pedimos a la gui que actualice el aspecto.
  //gui->actualizarEscenario ();

  // Le pedimos a la gui que actualice las propiedades.
  //gui->actualizarPropiedades ();
};

void EditorManager::actualizar_decorado ()
{
};

void EditorManager::atrapar_actor (int x, int y)
{
  activar_actor (x, y);
  if ( is_actor_activo () )
  {
    // Se cambia el color del bloque y se muestra.
    actor->set_color (makecol(255,0,0));
    actor->set_mostrar_bloque (true);

    // Se guarda la posición relativa del punto de 'atrape'
    // dentro del bloque del actor.
    refX = x - get_local_x (actor->get_x());
    refY = y - get_local_y (actor->get_y());

    // Se pasa a actor atrapado.
    actorActivado = false;
    actorFijado = false;
    actorAtrapado = true;
  }
};

void EditorManager::liberar_actor ()
{
  actor->set_mostrar_bloque (false);
  actor = NULL;
  actorActivado = false;
  actorFijado = false;
  actorAtrapado = false;
};

void EditorManager::activar_actor (int x, int y)
{
  // Si hay un actor activo, liberamos.
  if ( is_actor_activo () )
  {
    liberar_actor ();
  }

  // Obtenemos el nuevo actor bajo el ratón.
  actor = get_actor (get_global_x (x), get_global_y (y));

  // Si existe, mostramos el contorno en color verde y sus valores en la GUI.
  if (actor)
  {
    actor->set_color (makecol(0,255,0));
    actor->set_mostrar_bloque (true);
///    actor->drawGUI ();
    actorActivado = true;
  }
};

void EditorManager::fijar_actor (int x, int y)
{
  // Se intenta activar el actor bajo el cursor.
  activar_actor (x, y);
  
  // Si se consiguió activar, cambiamos la variable para fijarlo.
  // En otro caso, liberamos.
  if ( is_actor_activo () )
  {
    actor->set_color (makecol(255,128,255));
    actor->set_mostrar_bloque (true);
    actorActivado = false;
    actorFijado = true;
  }
  else
  {
    liberar_actor ();
  }
};

void EditorManager::mover_actor_2 (int x, int y)
{
  int posX, posY;

  // Si el actor está atrapado, movemos teniendo en cuenta la 
  // referencia guardada en el momento de la captura.
  if ( is_actor_atrapado () )
  {
    posX = x - refX;
    posY = y - refY;
  }

  // Hay que eliminar el desplazamiento del escenario.
  posX = get_global_x (posX);
  posY = get_global_y (posY);

  // Finalmente, calculadas las coordenadas reales del juego, movemos el actor.
  actor->set_x (posX);
  actor->set_y (posY);
};

int EditorManager::get_global_x (int x)
{
  return ( x + get_escenario_x () );
};

int EditorManager::get_global_y (int y)
{
  return ( y + get_escenario_y () );
};

int EditorManager::get_local_x (int x)
{
  return ( x - get_escenario_x () );
};

int EditorManager::get_local_y (int y)
{
  return ( y - get_escenario_y () );
};

}