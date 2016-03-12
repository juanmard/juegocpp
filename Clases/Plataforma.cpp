///
/// @file Plataforma.h
/// @brief Fichero cabecera de la clase "Plataforma".
/// @author Juan Manuel Rico
/// @date Marzo 2015
/// @version 1.0.0
///

#include "Plataforma.h"
#include <sstream>

Plataforma::Plataforma (const Plataforma& copia):
Actor(copia)
{
    /// Una vez copiada la parte gráfica del actor en la inicialización
    /// la referenciamos en el parámetro 'grafico'.
    /// @note Esto es absolutamente innecesario. 
    grafico = dynamic_cast<Suelo *>(this->agraph);
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
    switch (who->getCodigo ())
    {
    // Si tropezamos con un ladrillo.
    case Nombres::ladrillo:
        break;

    // Si tropezamos con una pelota.
    case Nombres::pelota:
        break;

    default:
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

std::string Plataforma::getString () const
{
    std::ostringstream cadena;

    // Vuelca la parte común del actor.
    cadena << Actor::getString() << std::endl;

    // Queda la parte propia por ser una plataforma.
    // VOrigen, VDestino, Activa...

    // Devuelve la cadena en formato "std::string".
    return cadena.str ();
};

std::ifstream& Plataforma::leer (std::ifstream& ifs)
{
    // Lee la parte común del actor.
    return Actor::leer(ifs);

    // Lee la parte propia.
    // P.j. Los vectores de origen y destino del movimiento.
    //      y si la plataforma está o no activa.
    // VOrigen  <12, 34>
    // VDestino <12, 50>
    // Activa   false
    //
    //return ifs;
};

