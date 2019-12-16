///---------------------------------------------------------
/// @file       Actor.cpp
/// @author     Juan Manuel Rico
/// @date       Diciembre 2010
/// @version    1.1.0
///
/// @brief      Actor del juego.
///---------------------------------------------------------
///

#ifndef _ACTOR_H_
#define _ACTOR_H_

#include "EditableObject.h"
#include "PrintableObject.h"

#include <allegro.h>
#include <vector>
#include "CollisionManager.h"
#include "Game.h"
#include "Nombres.h"
#include "Bloque.h"

namespace fwg {

    /// Clases colaboradoras.
    /// 
    class ActorGraphic;
    class Mask;
    class EditorManager;
    class GUIEscenario;

    /// Elemento básico con dinámica dentro del juego.
    ///
    /// Esta clase tiene como misión definir los elementos con dinámica propia en el juego.
    /// Se encarga de controlar todas las fases: Creación, actualización y destrucción de
    /// los actores que intervienen en el juego (Jugadores, enemigos, plataformas móviles,...)
    ///
    /// @note Se duda si esta clase debe contener o no los objetos "Menu" o "Formulario", ya que
    ///       podrían heredarse como clase de un tipo "EditableObject" que contenga este tipo de
    ///       procedimientos (a modo de "interface" que haga de un Actor un ActorEditable).
    ///
    ///       A modo de prueba creamos la clase abstracta "EditableObject" y hacemos que todos los
    ///       actores sean editables haciendo derivar la clase "Actor" de la clase "EditableObject".
    ///
    /// @note No existe congruencia con el nombre de algunos procedimientos:
    ///       - Existe el procedimiento
    ///         @code
    ///            virtual std::ifstream& leer (std::ifstream& ifs);
    ///         @endcode
    ///       Que se utiliza para leer de un fichero de texto las propiedades de los actores derivados
    ///       (virtual) a través del operador sobrecargado ">>" y sin embargo no existe la función "grabar",
    ///       ya que lo que se utiliza para grabar es la función "getString" (virtual) para volcar los 
    ///       datos del actor en un "stream" perteneciente a un fichero. Se debería crear el procedimiento
    ///       virtual "grabar" (que utilizaría "getString") y así la clase y sus procedimientos serían
    ///       consistentes.
    ///       
    /// @todo Por hacer en esta clase:
    ///         - No hacer heredar de "PrintableObject" ni "EditableObject", puesto que no
    ///           todos los actores tienen estas características. Dejar la herencia para
    ///           más adelante en la definición de un actor menos genérica.
    ///         - Eliminar el tipo de datos de estado (typedef int state_t) y sustituir por
    ///           el estado "State".
    ///         - Eliminar la relación con la clase "Nombres" para poder identificar los
    ///           distintos actores en el juego.
    ///         - Eliminar las variables "estado" y "tiempo_estado", ya que no todos los
    ///           actores necesitan cambiar su estado mediante temporizador. Sustituir su
    ///           funcionalidad por una herencia de "TemporizableObject" en el actor en
    ///           concreto en el que se necesite.
    ///         - Eliminar métods y referencias a Allegro.
    ///         - Eliminar el método "clone" y crear "ClonableObject" para concretar en
    ///           otros actores esta funcionalidad.
    ///         - Eliminar métodos "getMenu", "getFormulario" y "addEnlace" para no mezclar
    ///           funcionalidad de actor con el hecho de poder ser editado mediante un menú
    ///           o un formulario a petición de una GUI externa al juego.
    ///         - Hacer constantes los métodos (getX, getY...) que no modifican las propiedades
    ///           del objeto.
    ///         - Eliminar métodos "getGraphicX" y "getGraphicY". ¿Para qué son necesarios?
    ///         - Derivar la funcionalidad de agrupar actores en equipos o grupos a la clase
    ///           "ActorManager" y no a la clase global del juego. (setTeam)
    ///         - Agregar la dirección en las colisiones (hit) pensando en un juego simple
    ///           de tipo "Pong".
    ///         - Eliminar el método prueba de polimorfismo (pruebaIostream).
    ///         - Eliminar métodos con referencias a Allegro (mover, dimensionar).
    ///         - Eliminar métods de lectura/escritura de flujo amigos en esta clase y dejar
    ///           esta funcionalidad en herencia a "PrintableObject" y "ReadableObject".
    ///         - Eliminar la prueba que se hace con el "Suelo" (leer).
    ///         
    /// @see setTeam, hit, pruebaIostream, mover, dimensionar, leer
    ///
    class Actor : public EditableObject, public PrintableObject
    {
        public:
            /// Definición de los estados básicos en los que se puede encontrar un
            /// actor.
            /// 
            enum State
            {
                ENABLE,     ///< Actor habilitado. El actor se encuentra activo.
                DISABLE,    ///< Actor deshabilitado. El actor existe, pero no se actualiza.
                TO_DELETE   ///< Actor para borrar. El actor será borrado del juego.
            };

        public:
            /// Estados posibles del actor.
            /// 
            /// @todo Se debe poder heredar, incluir estados desde los hijos. Investigar.
            ///       De esta forma eliminaríamos la clase "Nombres" que no me gusta nada.
            ///       27-nov-09 - No me gusta nada, pero ésta no es una solución para los
            ///       estados de los actores.
            ///
            typedef int state_t;

        protected:
            ActorGraphic* agraph;                                   ///< Parte gráfica del actor.
            Nombres::codigo nombre;                                 ///< Nombre como código para poder comparar mejor en las rutinas.
            int x, y;                                               ///< Posición global en el escenario. @note Pasar a tipo "Bloque" junto con las dimensiones.
            int w, h;                                               ///< Dimensiones del bloque del actor.
            int color;                                              ///< Color representativo del actor. Se utiliza a la hora de mostrar el bloque.
            unsigned int tiempoEstado;                              ///< Tiempo en el que el estado actual se mantiene.
            state_t estado;                                         ///< Estado del actor.
            bool mostrarBloque;                                     ///< Indica si al representar el actor debe representarse el bloque que lo limita.
            int power;                                              ///< Representa la energía del actor en el juego.
            Game::team_t team;                                      ///< Equipo en el que se agrupa el actor.
            bool isDetectable;                                      ///< indica si el actor es detectable dentro del juego.
            CollisionManager::collision_method_t collisionMethod;   ///< Método de colisión que se le aplica al actor.
            ActorGraphic* waitGraph;                                ///< Gráfico de intercambio.

        private:
            State state;    ///< Estado actual del actor.
            
        public:
            /// Constructor por omisión de la clase.
            /// 
            /// @note No asigna gráfico y no se sitúa en el tiempo.
            ///
            Actor ();

            /// Constructor de copia de la clase.
            /// 
            /// @param copia Referencia al actor a copiar.
            /// 
            /// @todo Revisar la implementación del procedimiento.
            ///       ¿Se necesitan copiar todos los parámetros del actor?
            ///       ¿Es necesario este método en una clase tan genérica?
            ///
            Actor (const Actor& copia);

            /// Destruye el actor.
            ///
            /// Si tiene asignado un gráfico debe eliminarlo.
            /// 
            /// @note Se define virtual para que el comportamiento de los
            ///       derivados no tenga porqué ser el mismo.
            ///
            virtual ~Actor ();

            /// Obtiene el estado actual del actor.
            /// 
            /// @return Estado del actor.
            /// 
            State getState () const {return state;};
            
            /// Establece el estado actual del actor.
            /// 
            /// @param newState Nuevo estado a establecer.
            /// 
            void  setState (State newState) {state = newState;};
            
            /// Dibuja el actor en pantalla.
            /// 
            /// @param bmp Bitmap que representa la pantalla en Allegro.
            /// 
            /// @todo Crear una clase "Pantalla" para que la declaración del actor
            ///       no dependa directamente de las bibliotecas de Allegro.
            ///
            /// @note Este procedimiento puede incluirse en una clase más genérica
            ///       que fuera del estilo @code class DrawableObject; @endcode y
            ///       heredar el actor este comportamiento y con él su parte gráfica.
            ///
            /// @warning Este procedimiento al parecer ya no se utiliza, se utiliza
            ///          @code virtual void draw (StageManager* stageManager); @endcode
            ///
            virtual void draw (BITMAP* bmp);

            /// Dibuja un rectángulo según las dimensiones del actor.
            ///
            /// Se utiliza la propiedad "color" del actor.
            /// 
            /// @param pantalla Bitmap que representa la pantalla en Allegro.
            /// 
            /// @note Esta es otro procedimiento candidato a incluirse en la clase
            ///       "DrawableObject" del que heredaría el actor la propiedad "color"
            ///       y sus procedimientos asociados.
            /// @note No se necesita definir como "virtual" pues su comportamiento es
            ///       el mismo para todos los actores, aunque si se incluye en la clase
            ///       "DrawableObject" sí necesitaría serlo.
            ///
            void drawBlock (BITMAP* pantalla);

            /// Se actualiza la parte gráfica y física del actor.
            ///
            virtual void update ();

            /// Clona un actor.
            /// 
            /// @return Referencia al nuevo actor clonado.
            /// 
            /// @note Se define virtual para que los actores que deriven de la clase definan
            ///       este procedimiento y se clonen correctamente.
            ///       
            /// @note Habría que aclarar qué partes de un actor son clonables y qué partes no.
            ///       Por ejemplo, no sería conveniente duplicar gráficos estáticos en cada actor,
            ///       sino utilizar referencias a los gráficos ya cargados en memoria.
            ///       
            /// @note Se podría afinar más y declarar los actores "objetos clonables" si se crea
            ///       la clase "ClonableObject" y se hace derivar de ella esta clase.
            ///
            virtual Actor* clone () const;

            /// Modifica una cadena con la posición del actor en formato vector.
            /// 
            /// @param posicion Cadena pasada por parámetro para ser modificada
            ///        con la posición del actor.
            ///        
            /// @todo Estudiar el código y su necesidad en esta clase.
            ///       Lo lógico es devolver una cadena para poder usarla en
            ///       concatenaciones del tipo:
            ///       @code
            ///         std::string& getXY ();
            ///         cout << actor.getXY ();
            ///       @endcode
            ///
            /// @note No necesitan ser un procedimiento virtual ya que es el
            ///       mismo comportamiento para todos los actores.
            ///       
            /// @note Método candidato a ser eliminado y dejar esta funcionalidad
            ///       a la herencia en una posible clase "PrintableObject".
            ///
            void getXY (std::string& posicion) const;

            /// Modifica una cadena con ancho y alto del actor en formato vector.
            /// 
            /// @param dimensiones Cadena pasada por parámetro para ser modificada
            ///        con las dimensiones del actor.
            ///        
            /// @todo Estudiar el código y su necesidad en esta clase.
            ///       Lo lógico es devolver una cadena para poder usarla en
            ///       concatenaciones del tipo:
            ///       @code
            ///         std::string& getWH ();
            ///         cout << actor.getWH ();
            ///       @endcode
            ///
            /// @note No necesitan ser un procedimiento virtual ya que es el
            ///       mismo comportamiento para todos los actores.
            ///
            /// @note Método candidato a ser eliminado y dejar esta funcionalidad
            ///       a la herencia en una posible clase "PrintableObject".
            ///       
            void getWH (std::string& dimensiones) const;

            /// Modifica una cadena con el estado actual del actor.
            ///
            /// @param estado Cadena pasada por parámetro para ser modificada
            ///        con el estado actual del actor.
            ///        
            /// @todo Estudiar el código y su necesidad en esta clase.
            ///       Lo lógico es devolver una cadena para poder usarla en
            ///       concatenaciones del tipo:
            ///       @code
            ///         std::string& getEstado ();
            ///         cout << actor.getEstado ();
            ///       @endcode
            ///
            virtual void getEstado (std::string& estado) const;

            /// Modifica una cadena con el nombre del actor.
            /// 
            /// @return Cadena con el nombre del actor.
            ///
            virtual std::string& getNombre () const;

            /// Obtiene el nombre del actor.
            /// 
            /// @return Cadena con el nombre.
            /// 
            /// @note Buscar en el código y eliminar las llamadas a la antigua
            ///       "getNombre" y sustituirlas por esta.
            ///       
            /// @todo Hacer que se devuelva una referencia a la cadena, en lugar de un
            ///       objeto cadena.
            ///
            virtual std::string get_nombre () const;

            /// Obtiene un menú con las acciones posibles según el tipo de actor que lo solicite.
            /// 
            /// @return Referencia al menú creado.
            /// 
            /// @note Se hace virtual para que los actores derivados puedan incluir sus propias opciones.
            /// 
            /// @note Eliminar este método y crear una herencia para este tipo de acciones que
            ///       están más relacionadas con la GUI de edición del juego, que en el juego
            ///       mismo. Crear una clase que sea del estilo "EditableObject" e incluya esta
            ///       funcionalidad.
            ///
            virtual alg4::Menu& getMenu () const;

            /// Obtiene un formulario donde modificar los valores del actor.
            /// 
            /// @return Referencia al formulario.
            /// 
            /// @note Se hace virtual para que los actores derivados puedan incluir sus propias variables.
            /// 
            /// @note Esto debería ir en otra clase heredada para ser utilizada en alllegro 4.
            /// 
            virtual alg4::Formulario& getFormulario () const;

            /// Obtiene una cadena representativa con las propiedades completas del actor.
            /// 
            /// Se define como virtual para permitir que los actores derivados puedan definir
            /// su propia cadena. Se utiliza para escribir en ficheros y mostrar valores en pantalla.
            /// 
            /// @return Cadena representativa del actor.
            /// 
            /// @todo Eliminar de esta clase y trasladarla por herencia a las clases "PrintableObject"
            ///       y "RedeableObject".
            ///
            virtual std::string& print () const;

            /// Prueba para añadir un enlace a la GUI.
            /// 
            /// @todo Eliminar de esta clase. Esto pertenece a la GUI y debería estar en dicha clase.
            ///
            void addEnlace (DIALOG* enlace);

            /// Actualiza el estado en función del estado actual del actor.
            /// 
            /// @note Es virtual para que sea definida según el actor del que se trate.
            ///       Es una forma de simular las transiciones epsilon temporizadas del
            ///       autómata.
            ///       
            /// @warning ¿No es lo mismo que hace el método "update"?
            ///
            virtual void actualizarEstado ();

            /// Inicializa la parte gráfica del actor.
            ///
            virtual void init ();

            /// Devuelve la componente X de la posición global del actor.
            /// 
            /// @return Componente X global de la posición.
            ///
            int getX ();

            /// Devuelve la componente Y de la posición global del actor.
            /// 
            /// @return Componente Y global de la posición.
            ///
            int getY ();

            /// Devuelve el ancho de las dimensiones del actor.
            /// 
            /// @return Ancho del actor.
            ///
            int getW ();

            /// Devuelve el alto de las dimensiones del actor.
            /// 
            /// @return Alto del actor.
            ///
            int getH ();

            /// Actualiza la posición x del actor.
            /// 
            /// @param posX Nueva posición global X en pantalla.
            ///
            void setX (int posX);

            /// Actualiza la posición Y del actor.
            /// 
            /// @param posY Nueva posición global y en pantalla.
            ///
            void setY (int posY);

            /// Actualiza las dimensiones del actor en el escenario.
            /// 
            /// @param wTmp Nuevo ancho del actor (width).
            /// @param hTmp Nueva altura del jugador (high).
            ///
            void setWH (int wTmp, int hTmp);

            /// Actualiza el color de referencia del actor.
            /// 
            /// @param colorTmp Nuevo color del actor.
            ///
            void setColor (int colorTmp);

            /// Devuelve el valor del color de referencia del actor.
            /// 
            /// @return Valor del color actual.
            ///
            int getColor ();

            /// Actualiza la parte gráfica del actor.
            /// 
            /// @param ag Referencia a la nueva parte gráfica.
            ///
            /// @todo Debería añadirse una opción en la que no se cambiara la animación hasta que no
            ///       se terminara alguna animación marcada como necesaria.
            ///       Se debería dejar el cambio pendiente en una variable hasta el fin de la animación.
            ///
            void setActorGraphic (ActorGraphic* ag);

            /// Devuelve una referencia a la parte gráfica del actor.
            /// 
            /// @return Referencia a la parte gráfica del actor.
            ///
            ActorGraphic* getActorGraphic () const;

            /// Devuelve la posición X del componente gráfico del actor.
            /// 
            /// @return Valor de la posición X.
            /// 
            /// @note Estudiar para qué casos son necesarios este valor y ver si se puede
            ///       incluir en la parte gráfica del actor.
            ///
            int getGraphX ();

            /// Devuelve la posición Y del componente gráfico del actor.
            /// 
            /// @return Valor de la posición Y.
            /// 
            /// @note Estudiar para qué casos son necesarios este valor y ver si se puede
            ///       incluir en la parte gráfica del actor.
            ///
            int getGraphY ();
            
            /// Obtiene la máscara si existe y se usa por la parte gráfica del actor.
            /// 
            /// @warning Esta función no se encuentra implementada.
            ///
            Mask* getGraphMask ();

            /// Modifica el comportamiento del actor en la colisión.
            /// 
            /// @param detectable Si es 'true' hace el actor detectable y si es 'false'
            ///        el actor no es detectable en la colisión.
            ///        
            /// @todo Eliminar este método. Utilizar en su lugar los estados más genéricos
            ///       del actor. Si es necesario incluir un estado que sea "DETECTABLE".
            ///
            void setIsDetected (bool detectable);

            /// Cambia el método de colisión del actor.
            /// 
            /// @param cm Método que se emplea en el actor para detectar una colisión.
            ///
            void setCollisionMethod (CollisionManager::collision_method_t cm);

            /// Cambia el equipo al que pertenece un actor.
            /// 
            /// @param tm Nuevo equipo para el actor.
            /// 
            /// @note Es útil para agrupar actores, pero debería ser una funcionalidad
            ///       para "ActorManager".
            ///
            void setTeam (Game::team_t tm);

            /// Cambia el tiempo de estado para un actor.
            /// 
            /// @param tiempo Nuevo tiempo de estado.
            ///
            void setTiempo (unsigned int tiempo);

            /// Método para obtener el estado del actor.
            /// 
            /// @return Estado actual del actor.
            ///
            state_t getEstado ();

            /// Método para obtener el código del nombre.
            /// 
            /// @return El código asignado al nombre.
            ///
            Nombres::codigo getCodigo ();

            /// Modifica el código asociado al nombre del actor.
            /// 
            /// @param codigo Nuevo código de nombre.
            ///
            void setCodigo (Nombres::codigo codigo);

            /// Comprueba si el actor intersecciona con un bloque.
            /// 
            /// @param bloque Referencia al bloque con el que se desea comprobar la intersección.
            /// 
            /// @return Si se detecta la intersección se devuelve 'true'.
            /// 
            /// @todo Desarrollar el código completo del procedimiento.
            ///
            bool isIntersectado (const Bloque& bloque);

            /// Visualiza el aspecto gráfico del actor en referencia al escenario.
            ///
            /// Calcula las coordenadas relativas y las utiliza para mostrar a los actores correctamente.
            /// 
            /// @param stageManager Referencia al objeto que controla el escenario.
            /// 
            /// @note No se entiende muy bien este procedimiento, quizás no está bien aplicado a esta clase.
            ///       Quizás sería más adecuado englobar en la clase "DrawableObject" e incluir a la clase "Escenario"
            ///       en dicha clase, tomando el escenario como un "todo" que llama a dibujar a sus actores... quizás 
            ///       es esto mismo que tenemos aquí...
            ///       
            /// @warning Quizás sería más eficiente, en lugar de pasar por parámetro contínuamente el puntero del escenario,
            ///          mantener una variable global y estática para todos los actores "Dibujables" (DrawableObject).
            ///          Esto implicaría que dos actores no pueden dibujarse en escenarios distintos pero el juego, en
            ///          principio, únicamente necesita un escenario.
            ///
            virtual void draw (StageManager* stageManager);

            /// Visualiza el bloque de referencia del actor referida al escenario.
            /// 
            /// @param stageManager Referencia al objeto que controla el escenario.
            /// 
            /// @warning Quizás este procedimiento es más adecuado que esté en la clase
            ///          'StageManager' ya que es la que debe saber dibujar cuadrados en el
            ///          escenario.
            ///          
            /// @note Este procedimiento se podría agrupar en el prodecimiento "draw".
            /// 
            ///
            void drawBlock (StageManager* stageManager);

            /// Obtiene el bloque que define la posición y las dimensiones del actor.
            /// 
            /// @todo Integrar la clase 'Bloque' completamente en ésta y en otras clases.
            ///
            Bloque& getBloque ();

            /// Indica si se desea mostrar el bloque (posición y dimensiones) del actor.
            /// 
            /// @param mostrar Si es 'true' se mostrará y si es 'false' no se mostrará.
            /// 
            /// @todo Utilizar la clase Bloque para posición y dimensiones de esta clase Actor.
            /// 
            /// @note Este procedimiento encaja más con los objetos dibujables (DrawableObject).
            ///
            void setMostrarBloque (bool mostrar);

            /// Obtiene el estado de la visualización de bloques en el escenario.
            /// 
            /// @return Si se están monstrando actualmente los bloques de los actores en el escenario.
            ///
            bool getMostrarBloque () const;

            /// Indica que ha habido una colisión con algún otro actor.
            /// 
            /// @param who Actor con el que se ha producido la colisión.
            /// @param damage Daño que provoca dicha colisión.
            /// 
            /// @note Se debería indicar además del daño (energía) de la colisión, la
            ///       dirección efectiva del choque mediante un vector. De esta forma
            ///       se podría calcular mejor la física de la colisión.
            ///
            virtual void hit (Actor* who, int damage);
            
            /// Prueba de polimorfismo con iostream. Se hace con Ladrillo.
            /// 
            /// @param is Entrada de datos para lectura del buffer (Input Stream).
            /// @param a Actor a actualizar con la lectura de datos.
            /// 
            /// @todo Eliminar procedimiento.
            ///       Se ha investidado el polimorfismo con la lectura desde fichero,
            ///       esta prueba está superada y se debería eliminar.
            ///
            virtual std::istream& pruebaIostream (std::istream& is, Actor& a);

            /// Lee desde un fichero las propiedades del actor.
            /// 
            /// @param ifs Entrada de datos de fichero para su lectura (Input File Stream).
            /// 
            /// @return Devuelve la referencia al fichero para poder encadenar lecturas.
            /// 
            /// @note El procedimiento es virtual para que cada actor derivado sepa las propiedades 
            ///       que debe leer y con qué estructura hacerlo.
            ///
            ///       Este es el procedimiento "puente" que se utiliza de forma virutal entre los 
            ///       actores, para poder utilizar el operador sobrecargado ">>" sin preocuparnos de
            ///       sus permisos (friend).
            ///
            virtual std::ifstream&  leer  (std::ifstream& ifs);

        private:
            /// Acciones que puede realizar la clase actor (Mover).
            ///
            /// Prueba para asignar a un menú. Se definen como estáticas pues son
            /// comunes para todos los actores.
            /// 
            /// @note En el procedimiento se debe obtener el objeto que lo produce.
            ///       @code
            ///          Actor *nuevo = menu.getObject ();
            ///          nuevo->MoverActor ();
            ///       @endcode
            ///       Incluso el manejador de los menús puede ser único y distinguir
            ///       la opción según el nombre del item del menú.
            ///       
            /// @todo Eliminar por referencia a GUI y a bibliotecas Allegro.
            ///
            static int mover (void){return D_O_K;};

            /// Acciones que puede realizar la clase actor (Dimensionar).
            ///
            /// Prueba estática para poder asignar a un menú.
            ///
            static int dimensionar (void){return D_O_K;};

            /// Muestra un mensaje de error gráfico en consola.
            /// 
            /// @note Reunir todos los errores en una misma clase.
            ///
            void mensajeErrorGrafico () const;
            
            /// Sobrecarga del operador de lectura.
            /// 
            /// Métodos amigos no-miembros de la clase.
            /// 
            /// @param is Referencia al buffer de entrada (Input Stream).
            /// @param actor Referencia constante al actor que se desea leer y actualizar.
            ///
            friend std::istream& operator>> (std::istream& is, Actor& actor);

            /// Sobrecarga del operador de lectura sobre fichero.
            /// 
            /// @param ifs Fichero de lectura (Input File Stream).
            /// @param actor Actor a leer y actualizar valores.
            /// 
            /// @return Devuelve la referencia al fichero para encadenar lecturas.
            ///
            friend std::ifstream& operator>> (std::ifstream& ifs, Actor& actor);
    };

}

#endif
