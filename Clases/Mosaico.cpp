///
/// @file Mosaico.cpp
/// @brief Fichero de implementación de la clase "Mosaico".
/// @author Juan Manuel Rico
/// @date Noviembre 2015
/// @version
///      - 1.0.0 Noviembre 2015
///

#include <sstream>
#include "Mosaico.h"

Mosaico::Mosaico ():
ActorGraphic()
{
};

Mosaico::Mosaico (const Mosaico& copia, Actor* propietario):
ActorGraphic (propietario)
{
    /// Se genera una nueva lista y se copian las teleslas con el nuevo propietario.
    /// @todo Encapsular esto en una clase propia de lista de Teselas.
    std::list<Tesela*>::const_iterator tmp_iter;
    std::list<Tesela*>::const_iterator inicio;
    std::list<Tesela*>::const_iterator fin;

    // Se definen los iteradores.
    inicio = copia.teselas.begin();
    fin = copia.teselas.end();

    // Se recorre toda la lista de Teselas y se genera la nueva lista con el 
    // nuevo mosaico propietario (this).
    for (tmp_iter=inicio; tmp_iter!=fin; tmp_iter++)
    {
        add_ultima_Tesela (new Tesela(**tmp_iter,this));
    }
};

Mosaico::Mosaico (Actor* actor):
ActorGraphic (actor)
{
    // Asignamos al actor que hemos definido como propietario
    // a este mismo mosaico.
    actor->set_actor_graphic ((Mosaico*) this);
};

void Mosaico::add_ultima_Tesela (Tesela* nueva)
{
    teselas.push_back (nueva);
};

void Mosaico::add_primera_Tesela (Tesela* nueva)
{
    teselas.push_front (nueva);
};

void Mosaico::del_primera_Tesela (void)
{
    teselas.erase (teselas.begin());
};

void Mosaico::draw (BITMAP* pantalla)
{
    std::list<Tesela*>::iterator it;

    // Dibuja todas las teselas del mosaico.
    for (it=teselas.begin(); it!=teselas.end(); it++)
    {
        (*it)->draw (pantalla);
    }
};

void Mosaico::draw (int x, int y, BITMAP* pantalla)
{
    std::list<Tesela*>::iterator it;

    // Dibuja todas las teselas del mosaico.
    for (it=teselas.begin(); it!=teselas.end(); it++)
    {
        (*it)->draw (x, y, pantalla);
    }
};

void Mosaico::move_Tesela (int inc_x, int inc_y, Tesela* elegida)
{
    elegida->set_x (elegida->get_x() + inc_x);
    elegida->set_y (elegida->get_y() + inc_y);
};

Tesela* Mosaico::last_Tesela () const
{
    return teselas.back();
};

void Mosaico::swap_Tesela (Tesela* tesela_1, Tesela* tesela_2)
{
    //teselas.swap ();
};

Mosaico* Mosaico::clone (Actor* propietario) const
{
    return (new Mosaico(*this,propietario));
};

std::string& Mosaico::print () const
{
  std::ostringstream oss;
  std::list<Tesela*>::const_iterator it;
  int i;

  oss << "Mosaico >> " << std::endl;
  for (i=0, it=teselas.begin(); it!=teselas.end(); it++, i++)
  {
    oss << "Tesela " << i << " " << (*it)->print () << std::endl;
  }
  return *new std::string (oss.str ());
};

void Mosaico::clear ()
{
    this->teselas.clear();
};
