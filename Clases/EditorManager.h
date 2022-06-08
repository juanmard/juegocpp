///
/// @file EditorManager.h
/// @brief Fichero de definición de la clase "EditorManager".
/// @author Juan Manuel Rico
/// @date Noviembre 2015
/// @version 1.0.0
///

#ifndef _EDITORMANAGER_
#define _EDITORMANAGER_

#include <string>
#include <allegro.h>
#include "Bloque.h"
#include "Almacen.h"

class Game;
class Actor;
class Dialog;

/// Edita las listas de objetos involucrados en un juego.
///
/// Edita las listas de objetos involucrados en un juego y permite modificar, guardar
/// y recuperar dichos objetos. Esta edición puede realizarse en la misma ventana donde
/// se desarrolla el juego o en una ventana aparte. Debe permitir editar todas y cada una
/// de las animaciones de los objetos, así como modificar el estado de los mismos.
/// Aunque se podría incluir en la clase "ActorManager" se decide crear una clase 
/// independiente puesto que la edición no es un proceso normal del juego una vez terminado.
///
class EditorManager
{
private:
    /// @note Estas referencias habría que eliminarlas.
    static int refX, refY;  ///< Constantes estáticas de la clase como referencia.

public:
    Game* game;     ///< Puntero al juego propietario de este controlador.
    Dialog* gui;    ///< Puntero a la gui del controlador (a eliminar).
    Actor* actor;   ///< Puntero al actor que está siendo editado actualmente.

    /// @todo Definir estados del actor en lugar de variables booleanas.
    //  typedef enum {activado, fijado, atrapado} Estado;
    //  Estado estado;
    bool actorActivado;     ///< Indica si el actor que está siendo editado está activo.
    bool actorAtrapado;     ///< Indica si el actor que está siendo editado está atrapado.
    bool actorFijado;       ///< Indica si el actor que está siendo editado está fijo.

public:
    /// Construye la clase para editar un juego.
    ///
    /// Debe generar otra ventana, obtener la lista de objetos y realizar su propio bucle de estética
    /// para representar los objetos del juego a editar.
    /// @param g  Puntero del juego propietario del editor.
    /// @todo Se debe generar la ventana de forma independiente de las bibliotecas (Allegro), para ello crear una
    ///       "interfase" con estas funcionalidades, es decir, desligar de esta clase.
    ///
    EditorManager (Game* g);

    /// Destructor.
    ///
    ~EditorManager ();

    /// Activa el modo edición del juego.
    ///
    /// Al activar el modo edición del juego se debe:
    ///     - Parar el bucle normal del juego.
    ///     - Generar un menu con las propiedades de edición.
    ///     - Activar un bucle propio.
    ///
    void activate ();

    /// Redibuja la lista de objetos.
    ///
    void dibujar_escenario ();

    /// Duplica un actor.
    /// @param actor  Puntero al actor que queremos duplicar.
    /// @note ¿No devuelve al actor?
    ///
    void duplicar_actor (Actor* actor);

    /// Mueve el actor a la posición indicada en coordenadas locales de pantalla.
    /// @param x  Coordenada x de la posición.
    /// @param y  Coordenada y de la posición.
    ///
    /// @todo Sobrecargar el procedimiento para poder indicarle el objeto que se
    ///       toma por referencia, así podemos hacer cosas como:
    ///       @code
    ///         mover_actor (10, 10, objeto_pantalla);
    ///         mover_actor (10, 10, bloque);
    ///       @endcode
    ///
    void mover_actor (int x, int y);

    /// Devuelve la coordenada x del actor.
    /// @note Se supone que existe actor editando, si no fuera así daría error.
    /// @warning Este tipo de procedimeintos deja mucho que desear desde el punto de vista  del POO.
    ///
    int get_actor_x () const;

    /// Devuelve la coordenada y del actor.
    /// @note Se supone que existe actor editando, si no fuera así daría error.
    ///
    int get_actor_y () const;

    /// Modifica la coordenada x del actor.
    /// @note Se supone que existe actor editando, si no fuera así daría error.
    ///
    void set_actor_x (int x);

    /// Modifica la coordenada x del actor.
    /// @note Se supone que existe actor editando, si no fuera así daría error.
    ///
    void set_actor_y (int y);

    /// Devuelve el primer actor de la lista cuyo bloque se encuentra dentro de la posición dada.
    /// @param x  Coordena x de la posición en coordenadas de juego.
    /// @param y  Coordena y de la posición en coordenadas de juego.
    ///
    /// @todo En el caso del editor lo más correcto y visual sería comprobar la máscara
    ///       del gráfico que representa al actor para diferenciar el fondo.
    ///       En este caso también se puede debería obtener una lista de actores por solape.
    ///
    Actor* get_actor (int x, int y) const;

    /// Devuelve el nombre del actor dado como índice.
    /// @param indice  Índice dentro de la lista de actores.
    /// @return Referencia a la cadena de caracteres creada con el nombre del actor.
    ///
    std::string& get_nombre_actor (int indice) const;

    /// Mueve el escenario a otra posición.
    /// @param x  Coordenada x de la posición nueva.
    /// @param y  Coordenada y de la posición nueva.
    ///
    void mover_escenario (int x, int y);

    /// Obtiene el número de trajes de que se dispone en el juego.
    ///
    /// Este procedimiento es útil para cambiar los trajes de los actores al editarlos.
    ///
    unsigned int get_num_trajes () const;

    /// Cambia el traje de un actor dado por el índice.
    /// @param indice  Índice del actor en la lista de actores controlables.
    /// @note Un traje para el actor es la representación gráfica del mismo.
    /// @todo Indicar qué tipo de actor y qué traje se desea cambiar.
    ///
    void cambiar_traje (int indice);

    /// Obtiene la coordenada x de la posición del escenario.
    /// @return Coordenada x de la posición deseada en coordenadas del juego.
    /// @note El escenario es la representación gráfica de los actores en el juego.
    ///       Esta representación no tiene porqué coincidir con el tamaño completo de
    ///       la pantalla, es por eso que se representa con un objeto distinto.
    ///
    int get_escenario_x () const;

    /// Obtiene la coordenada y de la posición del escenario.
    /// @return Coordenada y de la posición deseada en coordenadas del juego.
    ///
    int get_escenario_y () const;

    /// Realiza un único ciclo de acciones sobre el juego actualizando los estados.
    ///
    void step () const;

    /// Obtiene el buffer de pantalla.
    /// @return Puntero a la zona de memoria del buffer de allegro.
    /// @warning Este procedimiento nos obliga a no independizar la clase de las
    ///          bibliotecas de Allegro. Buscar la forma de sustituirla por otra.
    ///
    BITMAP* get_buffer ();

    /// Actualiza el escenario.
    ///
    /// Actualiza toda la representación gráfica del escenario. Necesario cuando
    /// desplazamos o editamos actores del juego.
    ///
    void actualizar_escenario ();

    /// Dibuja un rectángulo del color indicado.
    ///
    /// El propósito de este procedimiento es poder comprobar el comportamiento del juego.
    /// @param cuadro  Rectángulo definido por posición y dimensiones.
    /// @param color  Color deseado del rectángulo.
    ///
    /// @note Quizás sea más conveniente definir este procedimiento en la clase Bloque o en
    ///       otra clase que lo heredara.
    ///
    void dibujar_cuadrado (Bloque cuadro, int color);

    /// Obtiene el número de actores actualmente en la lista.
    /// @return Número de actores actuales en la lista de actores controlables.
    ///
    unsigned int get_num_actores () const;

    /// Cambia el marco que se muestra en pantalla (ribete) del escenario.
    /// @param bloque Bloque que representa posición y dimensiones del ribete.
    ///
    /// @todo Indicar también el color que se debe utilizar para representarlo.
    ///
    void set_ribete (Bloque bloque) const;

    /// Borra la pantalla con un color gris.
    ///
    void borrar_pantalla () const;

    /// Centra el actor pasado como índice en el escenario.
    /// @param indice  Índice que identifica al actor en la lista de actores controlables.
    ///
    void centrar_actor (int indice) const;

    /// Cambia el color del ribete del escenario.
    /// @param color  Color deseado para el ribete.
    ///
    void set_color_ribete (int color);

    /// Obtiene la posición del escenario en forma de cadena.
    /// @return Cadena donde se vuelca la posición actual del escenario.
    ///
    std::string& get_escenario_xy () const;

    /// Obtiene una referencia al almacén de recursos.
    ///
    /// El almacén de recursos es donde se deben guardar los trajes, los sonidos y algún que
    /// otro fichero necesario para el juego.
    /// @return Referencia al almacén de recursos.
    ///
    Almacen& get_almacen () const;

    /// Indica si el actor actual está activo.
    /// @return Si el actor actual está activo o no.
    ///
    bool is_actor_activo () const;

    /// Indica si existe algún actor atrapado por el ratón.
    /// @return Si el actor actual está atrapado o no.
    ///
    bool is_actor_atrapado () const;

    /// Indica si el actor actual está fijo.
    /// @return Si el actor actual está fijado o no.
    /// @note Este concepto no está claro, parece no ser necesario para editar el actor.
    ///
    bool is_actor_fijo () const;

    /// Atrapa el actor cuyo bloque se encuentre en las coordenadas especificadas.
    /// @param x  Coordenada x de la posición de búsqueda.
    /// @param y  Coordenada y de la posición de búsqueda.
    /// @note Se pueden dar solapes que no se contemplan en el procedimiento.
    ///
    void atrapar_actor (int x, int y);

    /// Activa el actor cuyo bloque se encuentre en las coordenadas especificadas.
    /// @param x  Coordenada x de la posición de búsqueda.
    /// @param y  Coordenada y de la posición de búsqueda.
    /// @note Se pueden dar solapes que no se contemplan en el procedimiento.
    ///
    void activar_actor (int x, int y);

    /// Fija el actor cuyo bloque se encuentre en las coordenadas especificadas.
    /// @param x  Coordenada x de la posición de búsqueda.
    /// @param y  Coordenada y de la posición de búsqueda.
    /// @note Se pueden dar solapes que no se contemplan en el procedimiento.
    ///
    void fijar_actor (int x, int y);

    /// Libera el actor atrapado.
    ///
    void liberar_actor ();

    /// Indica si existe un decorado atrapado por el ratón.
    /// @return Si el decorado está atrapado o no.
    bool is_decorado_atrapado () const;

    /// Mueve el actor según las coordenadas dadas.
    /// @param x  Coordenada x de la nueva posición.
    /// @param y  Coordenada y de la nueva posición.
    /// @todo Eliminar el 2 del nombre cuando se termine la migración a la GUI
    ///       dinámica.
    ///
    void mover_actor_2 (int x, int y);

    /// Mueve el decorado a una nueva posición.
    /// @param x  Coordenada x en coordenadas del juego de la nueva posición.
    /// @param y  Coordenada y en coordenadas del juego de la nueva posición.
    ///
    void mover_decorado (int x, int y);

    /// Actualiza las propiedades y el aspecto del actor editado.
    ///
    void actualizar_actor ();

    /// Actualiza las propiedades y el aspecto del decorado editado.
    ///
    void actualizar_decorado ();

    /// Devuelve la coordenada global x dando la coordenada referida a la
    /// posición del escenario.
    /// @param x  Coordenada x del escenario.
    /// @return Coordenada x en coordenadas del juego (global).
    ///
    /// @warning Este procedimiento se podría evitar o hacer más general incluyéndolo en
    ///          las propiedades de la clase Bloque o de la del Vector2Di.
    ///
    int get_global_x (int x);

    /// Devuelve la coordenada global y dando la coordenada referida a la
    /// posición del escenario.
    /// @param y  Coordenada y del escenario.
    /// @return Coordenada y en coordenadas del juego (global).
    ///
    /// @warning Este procedimiento se podría evitar o hacer más general incluyéndolo en
    ///          las propiedades de la clase Bloque o de la del Vector2Di.
    ///
    int get_global_y (int y);

    /// Devuelve la coordenada local x dando la coordenada referida a la
    /// posición global del juego.
    /// @param x  Coordenada x global del juego.
    /// @return Coordenada x en coordenadas locales.
    ///
    /// @warning Este procedimiento se podría evitar o hacer más general incluyéndolo en
    ///          las propiedades de la clase Bloque o de la del Vector2Di.
    ///
    int get_local_x (int x);

    /// Devuelve la coordenada local y dando la coordenada referida a la
    /// posición global del juego.
    /// @param y  Coordenada y global del juego.
    /// @return Coordenada y en coordenadas locales.
    ///
    /// @warning Este procedimiento se podría evitar o hacer más general incluyéndolo en
    ///          las propiedades de la clase Bloque o de la del Vector2Di.
    ///
    int get_local_y (int y);

};

#endif
