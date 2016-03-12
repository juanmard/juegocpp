#include "EditorManager.h"
#include "ActorManager.h"
#include "Dialog.h"
#include "StageManager.h"

// Eliminar en un futuro, sólo para pruebas.
#include "AirCraft.h"
#include "DatFile.h"
#include "Bitmap.h"

int EditorManager::refX = 0;
int EditorManager::refY = 0;

/**
 * \brief   Construye la clase para editar un juego.
 * \details Debe generar otra ventana, obtener la lista de objetos y realizar su propio bucle de estética
 *          para representar los objetos del juego a editar.
 * \todo    Se debe generar la ventana de forma independiente de las bibliotecas (Allegro), para ello crear una
 *          "interfase" con estas funcionalidades, es decir, desligar de esta clase.
 */
EditorManager::EditorManager(Game *g):
game (g),
actorAtrapado (NULL),
actorActivado (NULL),
actorFijado (false)
{
  // Referencia a la GUI.
  gui = new Dialog(this);
}

/**
 * \brief   Destructor por omisión.
 */
EditorManager::~EditorManager()
{
}

/**
 * \brief   Activa el modo edición del juego.
 * \details Al activar el modo edición del juego se debe:
 *          - Parar el bucle normal del juego.
 *          - Generar un menu con las propiedades de edición.
 *          - Activar un bucle propio.
 */
void  EditorManager::activate ()
{
  // Se para el bucle del juego.
  game->pause ();
 
  // Guardamos el ribete actual del juego.
  //Bloque ribete_ant (game->stage_manager->getRibete ());
  Bloque ribete_ant (0, 0, SCREEN_W, SCREEN_H-100);

  // Le decimos al escenario que queremos ver los bloques de los actores.
  game->stage_manager->setVerBloques (true);

  // Se hace visible el menú de edición.
  gui->show ();

  // Cuando se termina de editar:
  game->stage_manager->setVerBloques (false);     //  1 - Ocultamos los bloques.
  game->stage_manager->setRibete (ribete_ant);    //  2 - Se recupera el ribete.
  gui->mouse_out ();                              //  3 - Ocultamos el ratón.
  borrarPantalla ();                              //  4 - Borramos la pantalla.
  game->play ();                                  //  5 - Se vuelve al juego.
}

/**
 * \brief   Redibuja la lista de objetos.
 */
void  EditorManager::dibujarEscenario ()
{
  game->stage_manager->draw ();
}

/**
 * \brief  Mueve el actor a la posición dada por (x,y) en coordenadas locales de pantalla.
 */
void  EditorManager::moverActor (int x, int y)
{
  // Comprobamos que no está editado nada.
  // - Si está actorAtrapado se mueve.
  // - Si no está actorAtrapado se ignora.
  if (actorAtrapado)
  {
    actorAtrapado->set_x (x);
    actorAtrapado->set_y (y);
  }
}

/**
 * \brief   Devuelve la propiedad X del actor.
 * \details Se supone que existe actor editando, si no fuera así daría error.
 */
int  EditorManager::getActorX () const
{
  return actorAtrapado->get_x ();
}

/**
 * \brief   Devuelve la propiedad Y del actor.
 * \details Se supone que existe actor editando, si no fuera así daría error.
 */
int  EditorManager::getActorY () const
{
  return actorAtrapado->get_y ();
}

/**
 * \brief   Modifica la propiedad X del actor.
 * \details Supone que existe actor editando, si no fuera así daría error.
 */
void  EditorManager::setActorX (int x)
{
  actorAtrapado->set_x (x);
}

/**
 * \brief   Modifica la propiedad Y del actor.
 * \details Supone que existe actor editando, si no fuera así daría error.
 */
void  EditorManager::setActorY (int y)
{
  actorAtrapado->set_y (y);
}

/**
 * \brief   Duplica el actor pasado como puntero.
 */
void  EditorManager::duplicarActor (Actor *actor)
{
  // Se comprueba que la referencia existe.
  if (actor)
  {
    // Se crea un nuevo actor en memoria basándose en el elegido.
    Actor *nuevo = actor->clone ();

    // Si se ha creado correctamente...
    if (nuevo)
    {
      // Se desplaza para visualizarlo.
      nuevo->set_x (nuevo->get_x () - 10);
      nuevo->set_y (nuevo->get_y () - 10);

      // Se añade a la lista de actores.
      game->actor_manager->add (nuevo);

      // Se actualiza la lista de actores creados para hacerlos visibles.
      // \todo Hacer friend estos procedimientos para usarlos sólo desde los "Manager"
      game->actor_manager->add_all_to_create ();
    }
  }
}

/**
 * \brief   Devuelve el actor que se encuentra en la posición dada.
 * \param   x   Posición x en coordenadas de juego.
 * \param   y   Posición y en coordenadas de juego.
 */
Actor *  EditorManager::getActor (int x, int y) const
{
  return game->actor_manager->get_actor (x, y);
}

/**
 * \brief   Devuelve el nombre del actor dado como índice.
 * \param   indice    Índice dentro de la lista de actores.
 * \return  Devuelve la cadena de caracteres que contiene el nombre del actor.
 */
string  EditorManager::getNombreActor (int indice) const
{
  Actor *actor = game->actor_manager->getActor (indice);
  if (actor)
  {
    string  strNombre;
    actor->getNombre(strNombre);
    return strNombre.c_str();
  }
  else
  {
    return const_cast<char *>("sin nombre");
  }
}

/**
 * \brief  Mueve el escenario a la posición dada por (x,y).
 */
void  EditorManager::moverEscenario (int x, int y)
{
  game->stage_manager->moverMarco (x, y);
}

/**
 * \brief  Obtiene la posición x del escenario.
 */
int  EditorManager::getEscenarioX () const
{
  return game->stage_manager->getX ();
}

/**
 * \brief  Obtiene la posición y del escenario.
 */
int  EditorManager::getEscenarioY () const
{
  return game->stage_manager->getY ();
}

/**
 * \brief   Realiza un ciclo de acciones sobre el juego actualizando los estados.
 */
void  EditorManager::step () const
{
  //game->stage_manager->setRibete (Bloque (10,10,640,190));
  //game->actor_manager->update ();
  game->update ();
  gui->draw ();
}

/**
 * \brief   Obtiene el buffer de pantalla.
 */
BITMAP *  EditorManager::getBuffer ()
{
  return game->stage_manager->getBuffer ();
}

/**
 * \brief   Actualiza el escenario.
 */
void  EditorManager::ActualizarEscenario ()
{
  return game->stage_manager->rellenarBuffer ();
}

/**
 * \brief   Obtiene el número de actores actualmente en la lista.
 */
int  EditorManager::getNumActores () const
{
  return game->actor_manager->num_actors ();
}

/**
 * \brief   Cambia el marco que se muestra en pantalla (ribete) del escenario.
 * \todo    Indicar también el color que se utiliza.
 */
void  EditorManager::setRibete (Bloque bloque) const
{
  return game->stage_manager->setRibete(bloque);
}

/**
 * \brief   Borra la pantalla de un color gris.
 */
void  EditorManager::borrarPantalla () const
{
  clear_to_color(screen, makecol (128, 128, 128));
}

/**
 * \brief   Centra el actor pasado como índice en el escenario.
 */
void  EditorManager::centrarActor (int indice) const
{
  // Se toma el actor de la lista dado por el índice.
  Actor * actor = game->actor_manager->getActor (indice);

  // Si el actor existe.
  if (actor)
  {
    // \warning   Esto se hace todas las veces que se centra el actor
    //            y sólo es necesario hacerlo una vez. Igualar las dimensiones
    //            de 'marco' y 'ribete' antes de entrar en edición.
    // Se toman los bloques del marco y el ribete.
    Bloque &  marco = game->stage_manager->getMarco ();
    Bloque &  ribete = game->stage_manager->getRibete ();
    // Se igualan las dimensiones del marco a las del ribete.
    // De esta forma queda el actor en el centro de la pantalla.
    marco.setWH (ribete.getW (), ribete.getH ());
    // Se centra el marco alrededor del actor.
    marco.centrar (actor->getBloque());
    // Se le indica a la gui que edite el actor.
    gui->setActor (actor);
    // Se le indica a la gui que actualice las nuevas propiedades.
    gui->draw ();
  }
};

/**
 * \brief   Centra el actor pasado como índice en el escenario.
 */
void  EditorManager::setColorRibete (int color)
{
  game->stage_manager->setColorRibete (color);
}

/**
 * \brief   Obtiene la posición del escenario y la vuelca en la cadena.
 * \param   posicion    Cadena donde se guarda la posición del escenario.
 */
void  EditorManager::getEscenarioXY (string &posicion) const
{
  Bloque marco (game->stage_manager->getMarco ());
  stringstream  ss;
  ss << "(" << marco.getX () << ", " << marco.getY () << ")";
  posicion = ss.str ();
}

/**
 * \brief   Obtiene el almacén de recursos.
 */
Almacen &  EditorManager::getAlmacen () const
{
  return *(game->storage_manager);
}

/**
 * \brief   Dice si existe algún actor atrapado por el ratón.
 */
bool  EditorManager::isActorAtrapado () const
{
  bool salida = false;
  if (actorAtrapado)
  {
    salida = true;
  }
  return salida;
}

/**
 * \brief   Dice si el actor actual está activo.
 */
bool  EditorManager::isActorActivo () const
{
  bool salida = false;
  if (actorActivado)
  {
    salida = true;
  }
  return salida;
}

/**
 * \brief   Dice si el actor actual está fijo.
 */
bool  EditorManager::isActorFijo () const
{
  return actorFijado;
}

/**
 * \brief   Dice si existe un decorado atrapado por el ratón.
 */
bool  EditorManager::isDecoradoAtrapado () const
{
  return false;
}

/**
 * \brief   Mueve el decorado a las posiciones globales 'x' e 'y'.
 */
void  EditorManager::moverDecorado (int x, int y)
{
}

/**
 * \brief   Actualiza las propiedades y el aspecto del actor editado.
 */
void  EditorManager::actualizarActor ()
{
  // Le pedimos a la gui que actualice el aspecto.
  //gui->actualizarEscenario ();

  // Le pedimos a la gui que actualice las propiedades.
  //gui->actualizarPropiedades ();
}

/**
 * \brief   Actualiza las propiedades y el aspecto del decorado editado.
 */
void  EditorManager::actualizarDecorado ()
{
}

/**
 * \brief   Atrapa el actor cuyo bloque se encuentre en las coordenadas especificadas.
 */
void  EditorManager::atraparActor (int x, int y)
{
  actorAtrapado = getActor (x, y);
  if ( isActorAtrapado () )
  {
    // Se cambia el color del bloque y se muestra.
    actorAtrapado->set_color (makecol(255,0,0));
    actorAtrapado->setMostrarBloque (true);

    // Se guarda la posición relativa del punto de 'atrape'
    // dentro del bloque del actor.
    refX = x - actorAtrapado->get_x();
    refY = y - actorAtrapado->get_y();
  }
}

/**
 * \brief   Libera el actor atrapado.
 */
void  EditorManager::liberarActor ()
{
  if ( isActorAtrapado () )
  {
    actorAtrapado->setMostrarBloque (false);
    actorAtrapado = NULL;
  }
}

/**
 * \brief   Desactiva el actor activado.
 */
void  EditorManager::desactivarActor ()
{
  if ( isActorActivo () )
  {
    actorActivado->setMostrarBloque (false);
    actorActivado = NULL;
  }
}

/**
 * \brief   Activar actor.
 */
void  EditorManager::activarActor (int x, int y)
{
  // Si hay un actor activo, desactivamos.
  if ( isActorActivo () )
  {
    desactivarActor ();
  }

  // Obtenemos el nuevo actor bajo el ratón.
  actorActivado = getActor (x,y);

  // Si existe, mostramos el contorno en color verde y sus valores en la GUI.
  if ( isActorActivo () )
  {
    actorActivado->set_color (makecol(0,255,0));
    actorActivado->setMostrarBloque (true);
    actorActivado->drawGUI ();
  }
};

/**
 * \brief   Fija al actor bajo el cursor.
 */
void  EditorManager::fijarActor (int x, int y)
{
  // Se intenta activar el actor bajo el cursor.
  activarActor (x, y);
  
  // Si se consiguió activar, cambiamos la variable para fijarlo.
  // En otro caso, borramos la variable.
  if ( isActorActivo () )
  {
    actorFijado = true;
    actorActivado->set_color (makecol(128,128,255));
    actorActivado->setMostrarBloque (true);
  }
  else
  {
    actorFijado = false;
    desactivarActor ();
  }
};

/**
 * \brief   Mueve el actor según las coordenadas dadas.
 * \todo    Eliminar el 2 del nombre cuando se termine la migración a la GUI
 *          dinámica.
 */
void EditorManager::moverActor2 (int x, int y)
{
  // Si el actor está atrapado, movemos teniendo encuenta la 
  // referencia al bloque guardada. 
  if ( isActorAtrapado () )
  {
    actorAtrapado->set_x (x - refX);
    actorAtrapado->set_y (y - refY);
  }
};
