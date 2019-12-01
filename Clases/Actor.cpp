///
/// @file     Actor.cpp
/// @brief    Fichero con el código de implementación de la clase Actor.
/// @author   Juan Manuel Rico
/// @date     Diciembre 2010
/// @version  1.0.0
///

#include <sstream>
#include <iostream>
#include <fstream>
#include "Actor.h"
#include "ActorGraphic.h"
#include "StageManager.h"
#include "Dialog.h"
#include "ActorGUI2.h"

#include "Suelo.h"      ///< A modo de prueba. Eliminar.

/// @todo Generar un espacio de nombres para el juego (game).
///namespace game
///{

ActorGUI2* Actor::gui = NULL;

Actor::Actor():
agraph(NULL),
tiempo_estado(0),
estado(0),
mostrarBloque (false),
wait_graph(NULL)
{
};

Actor::Actor(const Actor &copia):
//~ agraph(copia.agraph),
nombre (copia.nombre),
x(copia.x), y(copia.y),
w(copia.w), h(copia.h),
color(copia.color),
tiempo_estado(copia.tiempo_estado),
estado(copia.estado),
mostrarBloque (copia.mostrarBloque),
power(copia.power),
team(copia.team),
is_detectable(copia.is_detectable),
collision_method(copia.collision_method),
wait_graph(copia.wait_graph)
{
    // Duplicamos la parte gráfica del actor a copiar y se la asignamos al nuevo.
    // Para ello...
    // 1. Conseguimos la parte gráfica del actor a copiar.
    // 2. Duplicamos la parte gráfica dando como propietario el nuevo actor.
    // 3. Asignamos la parte gráfica duplicada al nuevo actor.
    //ActorGraphic *acopia = copia.get_actor_graphic()->clone (this);
    //if (copia) set_actor_graphic(acopia);
};

Actor::~Actor()
{
    if (agraph) delete agraph;
};

void Actor::draw (BITMAP *bmp)
{
    if (state != DISABLE) {
        // Se dibuja si el actor tiene parte gráfica.
        if (agraph) agraph->draw (bmp);
    }
};

void Actor::draw_block (BITMAP *pantalla)
{
    rect (pantalla,x,y,x+w,y+h,color);
};

void Actor::update ()
{
    // Se comprueba si existe la parte gráfica.
    // Si existe, se actualiza (se animan las partes gráficas que lo necesiten);
    // en otro caso, no se hace nada.
    if (agraph) agraph->update();

    // Se actualizan los gráficos del actor.
    // Si hay un gráfico en espera y está el actual libre, se cambia el gráfico por el nuevo;
    // en otro caso, no se hace nada.
    if ((wait_graph != NULL) && agraph->is_free())
    {
        // @note En este caso se queda el antiguo 'agraph' huérfano.
        //       ¿Incluir en una lista de punteros huérfanos?
        agraph = wait_graph;
        wait_graph = NULL;
    };

    // Actualiza los estados del actor.
    if (tiempo_estado)
    {
        tiempo_estado--;
        if (tiempo_estado == 0)
        {
            actualizar_estado ();
        }
    }
};

void Actor::hit (Actor *who, int damage)
{
};

void Actor::set_collision_method (CollisionManager::collision_method_t metodo)
{
    collision_method = metodo;
};

void Actor::set_team (Game::team_t equipo)
{
    team = equipo;
};

void Actor::set_is_detected (bool detectable)
{
    is_detectable = detectable;
};

void Actor::actualizar_estado ()
{
};

void Actor::set_tiempo (unsigned int tiempo)
{
    tiempo_estado = tiempo;
};

void Actor::init()
{
    // Se comprueba que el actor tiene parte gráfica.
    if (agraph) agraph->init();
};

void Actor::set_x(int pos_x)
{
    x=pos_x;
};

void Actor::set_y (int pos_y)
{
    y=pos_y;
};

void Actor::set_color (int color_tmp)
{
    color = color_tmp;
};

void Actor::set_wh (int w_tmp, int h_tmp)
{
  // Las dimensiones no pueden ser negativas. Las hacemos cero en ese caso.
  /// @note Quizás sea mejor definir las propiedades w y h como "unsigned int".
  if (w_tmp < 0) w_tmp = 0;
  if (h_tmp < 0) h_tmp = 0;
  w = w_tmp;
  h = h_tmp;
};

void Actor::set_actor_graphic (ActorGraphic* ag)
{
    // Se comprueba la parte gráfica del actor.
    // Si no existe parte gráfica del actor, se cambia directamente el gráfico;
    // en otro caso, hay que comprobar antes si el gráfico existente está libre.
    if (true)
//    if (!agraph)
    {
        agraph = ag;
    }
    else
    {
        // Se necesita preguntar al gráfico si está libre y puede sustituirse.
        // Si está libre de uso se lleva a cabo el cambio,
        // en otro caso se activa la necesidad de cambio que se producirá al actualizarse
        // el actor cuando se compruebe que está libre.
        if (agraph->is_free ())
        {
            agraph = ag;
        }
        else
        {
            wait_graph = ag;
        }
    }
};

ActorGraphic* Actor::get_actor_graphic () const
{
  return agraph;
};

int Actor::get_color (void)
{
    return color;
};

ActorGUI2* Actor::getGUI ()
{
    return gui;
};

int Actor::get_x()
{
    return x;
};

int Actor::get_y()
{
    return y;
};

int Actor::get_w()
{
    return w;
};

int Actor::get_h()
{
    return h;
};

int Actor::get_graph_x ()
{
    return agraph->get_x ();
};

int Actor::get_graph_y ()
{
    return agraph->get_y ();
};

Nombres::codigo Actor::getCodigo ()
{
    return nombre;
};

void Actor::setCodigo (Nombres::codigo codigo)
{
    nombre = codigo;
};

Actor::state_t Actor::get_Estado ()
{
    return estado;
};

Actor* Actor::clone () const
{
    return NULL;
};

/// @todo  Desarrollar el código.
bool Actor::isIntersectado (const Bloque& bloque)
{
  /// @todo  Desarrollar el código.
  return (true);
};

void Actor::draw (StageManager* stageManager)
{
    if (state != DISABLE) {
        // Se calcula la posición relativa del actor al escenario.
        int relx = x - stageManager->get_x();
        int rely = y - stageManager->get_y();

        // Se dibuja en el escenario en la posición calculada.
        if (agraph) agraph->draw (relx,rely,stageManager->getBuffer());
    }
};

void Actor::draw_block (StageManager* stageManager)
{
  // Si la propiedad del actor indica que mostremos el bloque lo mostramos.
  if (mostrarBloque)
  {
    // Se calcula la posición relativa del actor al escenario.
    int relx = x - stageManager->get_x ();
    int rely = y - stageManager->get_y ();

    // Se dibuja en el escenario en la posición calculada.
    rect (stageManager->getBuffer(), relx, rely, w + relx, h + rely, color);
  }
};

Bloque& Actor::getBloque ()
{
  Bloque *tmp = new Bloque (x, y, w, h);
  return *tmp;
};

void Actor::getXY (std::string& posicion) const
{
  std::stringstream  ss;
//  ss << "<" << x << ", " << y << ">";
  ss << x << ", " << y;
  posicion = ss.str();
};

void  Actor::getWH (std::string& dimensiones) const
{
  std::stringstream  ss;
//  ss << "<" << w << ", " << h << ">";
  ss << w << ", " << h;
  dimensiones = ss.str();
};

void  Actor::getEstado (std::string& estado) const
{
    estado = "sin estado";
};

std::string& Actor::get_nombre () const
{
    return *new std::string("sin nombre");
};

string  Actor::getNombre () const
{
    return "sin nombre";
};

void Actor::set_mostrar_bloque (bool mostrar)
{
    mostrarBloque = mostrar;
};

bool Actor::get_mostrar_bloque () const
{
    return mostrarBloque;
};

Menu& Actor::getMenu () const
{
    Menu *menu = new Menu();
    menu->add(const_cast<char*>("Actor - Mover"),  0, (void *) this, NULL, Actor::Mover);
    menu->add(const_cast<char*>("Actor - Tamaño"), 0, (void *) this, NULL, Actor::Dimensionar);
    return *menu;
};

Formulario& Actor::getFormulario () const
{
    return (*new Formulario());
};

std::string& Actor::print () const
{
    std::ostringstream cadena;

    // Se obtienen las propiedades del actor.
    cadena << getNombre() << " {" << std::endl \
           << "    Posición    <" << x << ", " << y << ">" << std::endl \
           << "    Dimensiones <" << w << ", " << h << ">" << std::endl;

    // Si hay parte gráfica, se obtiene la parte gráfica del actor.
    if (agraph)
    {
        cadena << "    Gráfico {" << std::endl \
               <<  agraph->print () \
               << "    }" << std::endl;
    }

    // Se cierra la cadena.
    cadena << "}" << std::endl;

    // Se devuelve una copia de la cadena creada.
    return *new std::string (cadena.str ());
};

void  Actor::mensajeErrorGrafico () const
{
    std::cout << "ERROR: Actor \"" << getNombre() << "\" sin componente gráfica." << std::endl;
};

void  Actor::addGUI (vector<DIALOG> &gui_padre)
{
  gui = new ActorGUI2 (*this, gui_padre);
};

void  Actor::addEnlace (DIALOG* enlace)
{
    gui->addEnlace (enlace);
};

void Actor::drawGUI ()
{
    // Si existe la GUI, solo hay que cambiar el actor.
    // En otro caso, habría que crearla.
    if (gui)
    {
        gui->setActor (*this);
    }
};

//std::ostream& operator<< (std::ostream &os, const Actor &actor)
//{
////    os << "Prueba de cadena desde \"Actor.cpp\"" << endl;
////    os << actor.nombre << " {" << actor.x << "," << actor.y << "}" << " {" << actor.w << "," << actor.h << "}";
//    os << actor.print ();
//    return os;
//};

std::istream& operator>> (std::istream& is, Actor& actor)
{
    // Extrae los valores del flujo formateado.
    //string nombre;

    // TODO: Este nombre habría que convertirlo a tipo "Nombres::codigo"
    //is >> nombre;
    is.ignore (10,'<');
    is >> actor.x;
    is.ignore (10,',');
    is >> actor.y;
    is.ignore (10,'<');
    is >> actor.w;
    is.ignore (10,',');
    is >> actor.h;
    is.ignore (10,'>');
    return is;
};

std::istream& Actor::prueba_iostream (std::istream& is, Actor& a)
{
    std::cout << "prueba_actor";
    return is;
};

std::ifstream& Actor::leer (std::ifstream& ifs)
{
    std::string comando;

    // Lee el comando (Posición) y sus valores.
    ifs >> comando;
    ifs.ignore(20,'<') >> x;
    ifs.ignore(20,',') >> y;
    ifs.ignore(20,'>');

    // Lee el comando (Dimensiones) y sus valores.
    ifs >> comando;
    ifs.ignore(20,'<') >> w;
    ifs.ignore(20,',') >> h;
    ifs.ignore(20,'>');

    // Deja el cursor en el siguiente comando (Gráfico) y alguien que sepa todos
    // los posibles tipos de gráficos (Bitmap, Suelo, Mosaico...)
    // debe crear uno y asignárselo a este actor.
    // Similar al mismo que tuvo que crear un actor de clase "Plataforma" como en el
    // ejemplo.
    // ¿Habría que crear un "GraphicManager"?¿Esta función puede hacerla el "Almacen"?

    // Como prueba... lo hacemos de momento aquí mismo...
    ifs >> comando;
    if (!comando.compare("Gráfico"))
    {
        ifs.ignore (100,'{');
        ifs >> comando;

        // Suponemos que es un suelo el gráfico...
        // ActorGraphic &grafico = GraphicManager::crearGrafico (comando);
        ActorGraphic &grafico = *new Suelo();
        ifs.ignore (100,'{');
        ifs >> grafico;
        ifs.ignore (100,'}');
        ifs.ignore (100,'}');

        // Enlazamos el actor con el gráfico y
        // el gráfico con el actor (su propietario).
        this->set_actor_graphic (&grafico);
        this->agraph->setOwner(*this);
    }
    return ifs;
};

std::ifstream& operator>> (std::ifstream& ifs, Actor& actor)
{
    return actor.leer(ifs);
};


