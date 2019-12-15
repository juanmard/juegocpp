///---------------------------------------------------------
/// @file       Actor.cpp
/// @author     Juan Manuel Rico
/// @date       Diciembre 2010
/// @version    1.1.0
///
/// @brief      Actor del juego.
///---------------------------------------------------------
///

#include <sstream>
#include <iostream>
#include <fstream>
#include "Actor.h"
#include "ActorGraphic.h"
#include "StageManager.h"
#include "Dialog.h"

// Prueba a eliminar.
#include "Suelo.h"

namespace fwg
{

    Actor::Actor():
    agraph(NULL),
    tiempoEstado(0),
    estado(0),
    mostrarBloque (false),
    waitGraph(NULL)
    {
    }

    Actor::Actor(const Actor &copia):
    nombre (copia.nombre),
    x(copia.x), y(copia.y),
    w(copia.w), h(copia.h),
    color(copia.color),
    tiempoEstado(copia.tiempoEstado),
    estado(copia.estado),
    mostrarBloque (copia.mostrarBloque),
    power(copia.power),
    team(copia.team),
    isDetectable(copia.isDetectable),
    collisionMethod(copia.collisionMethod),
    waitGraph(copia.waitGraph)
    {
        // Duplicamos la parte gráfica del actor a copiar y se la asignamos al nuevo.
        // Para ello...
        // 1. Conseguimos la parte gráfica del actor a copiar.
        // 2. Duplicamos la parte gráfica dando como propietario el nuevo actor.
        // 3. Asignamos la parte gráfica duplicada al nuevo actor.
        //ActorGraphic *acopia = copia.get_actor_graphic()->clone (this);
        //if (copia) set_actor_graphic(acopia);
    }

    Actor::~Actor()
    {
        if (agraph) delete agraph;
    }

    void Actor::draw (BITMAP* bmp)
    {
        if (state != DISABLE)
        {
            // Se dibuja si el actor tiene parte gráfica.
            if (agraph) agraph->draw (bmp);
        }
    }

    void Actor::drawBlock (BITMAP* pantalla)
    {
        rect (pantalla, x, y, x+w, y+h, color);
    }

    void Actor::update ()
    {
        // Se comprueba si existe la parte gráfica.
        // Si existe, se actualiza (se animan las partes gráficas que lo necesiten);
        // en otro caso, no se hace nada.
        if (agraph) agraph->update();

        // Se actualizan los gráficos del actor.
        // Si hay un gráfico en espera y está el actual libre, se cambia el gráfico por el nuevo;
        // en otro caso, no se hace nada.
        if ((waitGraph != NULL) && agraph->isFree())
        {
            // @note En este caso se queda el antiguo 'agraph' huérfano.
            //       ¿Incluir en una lista de punteros huérfanos?
            agraph = waitGraph;
            waitGraph = NULL;
        }

        // Actualiza los estados del actor.
        if (tiempoEstado)
        {
            tiempoEstado--;
            if (tiempoEstado == 0)
            {
                actualizarEstado ();
            }
        }
    }

    void Actor::hit (Actor* who, int damage)
    {
    }

    void Actor::setCollisionMethod (CollisionManager::collision_method_t metodo)
    {
        collisionMethod = metodo;
    }

    void Actor::setTeam (Game::team_t equipo)
    {
        team = equipo;
    }

    void Actor::setIsDetected (bool detectable)
    {
        isDetectable = detectable;
    }

    void Actor::actualizarEstado ()
    {
    }

    void Actor::setTiempo (unsigned int tiempo)
    {
        tiempoEstado = tiempo;
    }

    void Actor::init()
    {
        // Se comprueba que el actor tiene parte gráfica.
        if (agraph) agraph->init();
    }

    void Actor::setX (int posX)
    {
        x = posX;
    }

    void Actor::setY (int posY)
    {
        y = posY;
    }

    void Actor::setColor (int colorTmp)
    {
        color = colorTmp;
    }

    void Actor::setWH (int wTmp, int hTmp)
    {
      // Las dimensiones no pueden ser negativas. Las hacemos cero en ese caso.
      /// @note Quizás sea mejor definir las propiedades w y h como "unsigned int".
      if (wTmp < 0) wTmp = 0;
      if (hTmp < 0) hTmp = 0;
      w = wTmp;
      h = hTmp;
    }

    void Actor::setActorGraphic (ActorGraphic* ag)
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
            if (agraph->isFree ())
            {
                agraph = ag;
            }
            else
            {
                waitGraph = ag;
            }
        }
    }

    ActorGraphic* Actor::getActorGraphic () const
    {
        return agraph;
    }

    int Actor::getColor (void)
    {
        return color;
    }

    int Actor::getX ()
    {
        return x;
    }

    int Actor::getY ()
    {
        return y;
    }

    int Actor::getW ()
    {
        return w;
    }

    int Actor::getH ()
    {
        return h;
    }

    int Actor::getGraphX ()
    {
        return agraph->getX ();
    }

    int Actor::getGraphY ()
    {
        return agraph->getY ();
    }

    Nombres::codigo Actor::getCodigo ()
    {
        return nombre;
    }

    void Actor::setCodigo (Nombres::codigo codigo)
    {
        nombre = codigo;
    }

    Actor::state_t Actor::getEstado ()
    {
        return estado;
    }

    Actor* Actor::clone () const
    {
        return NULL;
    }

    /// @todo  Desarrollar el código.
    bool Actor::isIntersectado (const Bloque& bloque)
    {
      /// @todo  Desarrollar el código.
      return (true);
    }

    void Actor::draw (StageManager* stageManager)
    {
        if (state != DISABLE)
        {
            // Se calcula la posición relativa del actor al escenario.
            int relx = x - stageManager->get_x();
            int rely = y - stageManager->get_y();

            // Se dibuja en el escenario en la posición calculada.
            if (agraph) agraph->draw (relx,rely,stageManager->getBuffer());
        }
    }

    void Actor::drawBlock (StageManager* stageManager)
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
    }


    Bloque& Actor::getBloque ()
    {
      Bloque *tmp = new Bloque (x, y, w, h);
      return *tmp;
    }

    void Actor::getXY (std::string& posicion) const
    {
      std::stringstream  ss;
    //  ss << "<" << x << ", " << y << ">";
      ss << x << ", " << y;
      posicion = ss.str();
    }

    void  Actor::getWH (std::string& dimensiones) const
    {
      std::stringstream  ss;
    //  ss << "<" << w << ", " << h << ">";
      ss << w << ", " << h;
      dimensiones = ss.str();
    }

    void  Actor::getEstado (std::string& estado) const
    {
        estado = "sin estado";
    }

    std::string& Actor::getNombre () const
    {
        return *new std::string("sin nombre");
    }

    std::string Actor::get_nombre () const
    {
        return "sin nombre";
    }

    void Actor::setMostrarBloque (bool mostrar)
    {
        mostrarBloque = mostrar;
    }

    bool Actor::getMostrarBloque () const
    {
        return mostrarBloque;
    }

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
    }

    void  Actor::mensajeErrorGrafico () const
    {
        std::cout << "ERROR: Actor \"" << getNombre() << "\" sin componente gráfica." << std::endl;
    }

    /// @note A eliminar de la clase.
    alg4::Menu& Actor::getMenu () const
    {
        return *new alg4::Menu();
    }

    /// @note A eliminar de la clase.
    alg4::Formulario& Actor::getFormulario () const
    {
        return *new alg4::Formulario();
    }

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
    }

    std::istream& Actor::pruebaIostream (std::istream& is, Actor& a)
    {
        std::cout << "prueba_actor";
        return is;
    }

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
            //ActorGraphic &grafico = GraphicManager::crearGrafico (comando);
            ActorGraphic& grafico = *new Suelo();
            ifs.ignore (100,'{');
            ifs >> grafico;
            ifs.ignore (100,'}');
            ifs.ignore (100,'}');

            // Enlazamos el actor con el gráfico y
            // el gráfico con el actor (su propietario).
            this->setActorGraphic (&grafico);
            this->agraph->setOwner(*this);
        }
        return ifs;
    }

    std::ifstream& operator>> (std::ifstream& ifs, Actor& actor)
    {
        return actor.leer(ifs);
    }

}


