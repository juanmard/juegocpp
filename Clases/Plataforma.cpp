///
/// @file Plataforma.cpp
/// @brief Fichero de la clase "Plataforma".
/// @author Juan Manuel Rico
/// @date Marzo 2015
/// @version 1.0.0
///

#include "Plataforma.h"
#include <sstream>


namespace fgm {
    
Plataforma::Plataforma (const Plataforma& copia):
Actor(copia),
//origen (copia.getOrigen()),
//destino (copia.getDestino()),
//velocidad (copia.getVelocidad()),
activa (true)
{
    /// Una vez copiada la parte gráfica del actor en la inicialización
    /// la referenciamos en el parámetro 'grafico'.
    /// @note Esto es absolutamente innecesario. La propiedad "Suelo" no es más que una copia
    ///       del gráfico que guarda el actor en "agraph". Lo que sí hay que hacer es actualizar
    ///       el actor propietario en el gráfico. Algo así:
    ///       @code this->agraph->owner = this; @endcode
    ///       De otra forma quedará una incongruencia entre actor, gráfico y propietario del gráfico.
    grafico = dynamic_cast<Suelo *>(copia.get_actor_graphic());
};

Plataforma::Plataforma ()
{
    grafico = new Suelo (this, 2);
    set_actor_graphic (grafico);
    setCodigo (Nombres::plataforma);
    set_x (0);
    set_y (0);
    set_is_detected (true);
    set_collision_method (CollisionManager::PP_COLLISION);
    activa=true;
};

Plataforma::Plataforma (Almacen& almacen):
Actor()
{
    this->agraph = new Suelo (this, almacen, 2);
    setCodigo (Nombres::plataforma);
    set_x (0);
    set_y (0);
    set_is_detected (true);
    set_collision_method (CollisionManager::PP_COLLISION);
};

Plataforma::~Plataforma (void)
{
    // Liberar los gráficos...
};

void Plataforma::hit (Actor* who, int damage)
{
    // Definir antes la zona de influencia con un bloque temporal
    // que rodee a la plataforma.
    this->activa = true;    ///< A modo de prueba.
    switch (who->getCodigo ())
    {
    // Si tropezamos con un ladrillo.
    case Nombres::ladrillo:
        this->activa = true;    ///< A modo de prueba.
        break;

    // Si tropezamos con una pelota.
    case Nombres::pelota:
        break;

    default:
        this->activa = false; ///< A modo de prueba.
        break;
    }
};

Plataforma* Plataforma::clone () const
{
    return (new Plataforma (*this));
};

void Plataforma::getNombre (std::string& strNombre) const
{
    strNombre = Nombres::Imprimir (nombre);
};

std::string Plataforma::getNombre () const
{
//  return Nombres::Imprimir (nombre);
    return "Plataforma";
};

std::string& Plataforma::print () const
{
    std::ostringstream cadena;

    // Vuelca la parte común del actor.
    cadena << Actor::print () << std::endl;

    // Queda la parte propia por ser una plataforma.
    // VOrigen, VDestino, Activa...
    //cadena << velocidad.print () << std::end;

    // Devuelve la cadena en formato "std::string".
    return *new std::string(cadena.str ());
};

std::ifstream& Plataforma::leer (std::ifstream& ifs)
{
    // Lee la parte común del actor.
    std::ifstream& ifs_tmp = Actor::leer(ifs);

    // Forzamos las dimensiones del actor para que se ajusten al gráfico.
    static_cast<Suelo*>(this->agraph)->ajustar ();

    // Lee la parte propia.
    // P.j. Los vectores de origen y destino del movimiento.
    //      y si la plataforma está o no activa.
    // VOrigen  <12, 34>
    // VDestino <12, 50>
    // Activa   false
    //
    return ifs_tmp;
};

void Plataforma::drawControl ()
{
    // En espera de definir estas funciones:
    //      line (origen, destino, color::rojo);
    //      flecha (velocidad, actor.cdg(), color::rojo);
    //      rectangulo (actor.bloque());
    // En DrawableObject.

    // Mientras tanto hacemos una prueba con Allegro.
    //origen.x = origen.y = 0;
    //destino.x = destino.y = 300;
    //velocidad.x = velocidad.y = 10.0 ;

    //line (screen, this->x, this->y, destino.x, destino.y, 123);
};

void Plataforma::draw (StageManager* stageManager)
{
    Actor::draw (stageManager);
    if (this->activa) {
        this->drawControl();
    }
};

}