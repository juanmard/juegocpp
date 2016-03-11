#include "Paleta.h"

/**
 * \brief   Constructor de copia.
 */
Paleta::Paleta (const Paleta &copia):
ControllableActor (copia)
{
  // Una vez copiada la parte gráfica del actor en la inicialización
  // la referenciamos en el parámetro 'piel'.
  piel = dynamic_cast<Suelo *>(agraph);
}

/**
 * \brief   Constructor por omisión.
 */
Paleta::Paleta()
{
  piel = new Suelo (this, 2);
  set_actor_graphic (piel);
  setCodigo (Nombres::paleta);
  set_x (0);
  set_y (SCREEN_H - 70);
  set_is_detected (true);
  set_collision_method (CollisionManager::PP_COLLISION);
}

/**
 * \brief   Constructor por omisión.
 */
Paleta::Paleta (Almacen &almacen)
{
  piel = new Suelo (this, almacen, 2);
  set_actor_graphic (piel);
  setCodigo (Nombres::paleta);
  set_x (0);
  set_y (SCREEN_H - 70);
  set_is_detected (true);
  set_collision_method (CollisionManager::PP_COLLISION);
}

/**
 * \brief   Destructor.
 */
Paleta::~Paleta(void)
{
}

/**
 * \brief   Acciones como actor controlable.
 */
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
}

/**
 * \brief   Acciones ante colisiones.
 */
void  Paleta::hit (Actor *who, int damage)
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
}

/**
 * \brief   Clona el objeto.
 */
Paleta *  Paleta::clone () const
{
  return (new Paleta (*this));
};
