///
/// @file Control.cpp
/// @brief Fichero de implementación de la clase "Control".
/// @author Juan Manuel Rico
/// @date Octubre 2015
/// @version 1.0.0
///

#include "Control.h"

void Control::add_action_name (ControllableObject::action_t act, std::string str)
{
    association_t asoc;
    asoc.act = act;
    asoc.name = str;
    asoc.peri = NULL;
    asoc.comp = -1;
    associations.push_back (asoc);
};

void  Control::set_actionperipheral (
      ControllableObject::action_t act,
      Peripheral* peri,
      Peripheral::component_t comp,
      Peripheral::event_t e)
{
  // Con el bucle se busca la acción en la lista de acciones.
  for (associations_iter = associations.begin();
  associations_iter != associations.end();
  associations_iter++)
  {
    // Si la acción es la requerida se asocia el periférico, el componente, el evento
    // y salimos del bucle.
    if (associations_iter->act == act)
    {
      associations_iter->peri = peri;
      associations_iter->comp = comp;
      associations_iter->new_event = e;
      associations_iter->old_event = Peripheral::NO_EVENT;
      return;
    }
  }
};

void Control::add_association (Control::association_t assoc)
{
  associations.push_back (assoc);
};

void Control::set_owner (ControllableObject* co)
{
  owner = co;
};

void Control::update ()
{
  bool do_action_order;
  Peripheral::state_t tmp_state;
  Peripheral::event_t tmp_old_event;

  // El bucle comprueba y actualiza todos los estados de las asociaciones.
  for (associations_iter = associations.begin();
  associations_iter != associations.end();
  associations_iter++)
  {
    // Se lee temporalmente el estado actual del periférico y su componente asociado.
    tmp_state = associations_iter->peri->get_state (associations_iter->comp);
    
    // Se lee temporalmente el evento anterior.
    tmp_old_event = associations_iter->old_event;
    
    // En principio no se ejecutará la acción si no hay nadie que diga lo contrario.
    do_action_order = false;
    
    // Según el evento actual, el anterior y el estado guardado temporalmente, se decide
    // si ejecutar o no la acción del control sobre el objeto propietario del mismo.
    switch (associations_iter->new_event)
    {
      case Peripheral::ON_PRESSING:
          if (tmp_state != INVALID_STATE)
          {
            do_action_order = true;
          }
          break;

      case Peripheral::ON_PRESS:
          if ((tmp_old_event == Peripheral::ON_RELEASE) &&
              (tmp_state != INVALID_STATE))
          {
            associations_iter->old_event = Peripheral::ON_PRESS;
            do_action_order = true;
          }
          else
          {
            if (tmp_state == INVALID_STATE)
            {
              associations_iter->old_event = Peripheral::ON_RELEASE;
            }
          }
          break;

      case Peripheral::ON_RELEASE:
          if ((tmp_old_event == Peripheral::ON_PRESS) &&
              (tmp_state == INVALID_STATE))
          {
            associations_iter->old_event = Peripheral::ON_RELEASE;
            do_action_order = true;
          }
          else
          {
            if (tmp_state != INVALID_STATE)
            {
              associations_iter->old_event = Peripheral::ON_PRESS;
            }
          }
          break;

      case Peripheral::ON_RELEASSING:
          if (tmp_state == INVALID_STATE)
          {
            do_action_order = true;
          }
          break;

      default:
          break;
    }

    // Si finalmente hay orden de realizar una acción, manda ejecutarla al propietario del control.
    if (do_action_order)
    {
      owner->do_action (associations_iter->act, tmp_state);
    }
  }
};

std::string Control::get_name_action (ControllableObject::action_t act)
{
  for (associations_iter = associations.begin();
  associations_iter != associations.end();
  associations_iter++)
  {
    if (associations_iter->act == act)
    {
      return associations_iter->name;
    }
  }
  return "";
};
