///
/// @file Paleta.cpp
/// @brief Fichero de implementación de la clase "Paleta".
/// @author Juan Manuel Rico
/// @date Octubre 2015
/// @version 1.0.0
///

#include "Paleta.h"
#include "Nombres.h"

Paleta::Paleta()
{
  piel = new Suelo (this, 2);
  set_actor_graphic (piel);
  setCodigo (Nombres::paleta);
  set_x (0);
  set_y (SCREEN_H - 70);
  set_is_detected (true);
  set_collision_method (CollisionManager::PP_COLLISION);
};

Paleta::Paleta (const Paleta &copia):
ControllableActor (copia)
{
  // Una vez copiada la parte gráfica del actor en la inicialización
  // la referenciamos en el parámetro 'piel'.
  piel = dynamic_cast<Suelo *>(agraph);
};

Paleta::Paleta (Almacen &almacen)
{
  piel = new Suelo (this, almacen, 2);
  set_actor_graphic (piel);
  setCodigo (Nombres::paleta);
  set_x (0);
  set_y (SCREEN_H - 70);
  set_is_detected (true);
  set_collision_method (CollisionManager::PP_COLLISION);
};

Paleta::~Paleta(void)
{
};

void Paleta::do_action (ControllableObject::action_t act, int magnitude)
{
  switch (act)
  {
    case LEFT:
        x -= 3;
        break;

    case RIGHT:
        x += 3;
        break;
  }
  if (x < 0) x = 0;
  if (x > SCREEN_W -get_w ()) x = SCREEN_W - get_w ();
};

void Paleta::hit (Actor *who, int damage)
{
  switch (who->getCodigo ())
  {
    // Si tropezamos con un ladrillo. Aumentamos el tamaño.
    case Nombres::ladrillo:
        if (piel->getSize () < 8)
        {
          piel->setSize (piel->getSize () + 1);
          this->set_wh (32*piel->getSize () + 20,15);
        }
        break;

    // Si tropezamos con una pelota. Disminuímos el tamaño.
    case Nombres::pelota:
        if (piel->getSize () > 2)
        {
          piel->setSize(piel->getSize () - 1);
          set_wh (32*piel->getSize () + 20, 15);
        }
        break;

    default:
        break;
  }
};

Paleta* Paleta::clone () const
{
  return (new Paleta (*this));
};

void Paleta::getNombre (std::string &strNombre) const
{
  strNombre = Nombres::Imprimir (nombre);
};

std::string Paleta::getNombre () const
{
//  return Nombres::Imprimir (nombre);
  return "Paleta";
};
