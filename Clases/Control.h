#ifndef _CONTROL_H_
#define _CONTROL_H_

#include <list>
#include <string>
#include "Peripheral.h"
#include "ControllableObject.h"

/**
 * \brief   Clase para el control del juego.
 */
class Control
{
  public:
    typedef struct
    {
      ControllableObject::action_t act;
      string name;
      Peripheral *peri;
      Peripheral::component_t comp;
      Peripheral::event_t old_event;
      Peripheral::event_t new_event;
    } association_t;

    void    add_action_name       (ControllableObject::action_t act, string str);
    void    add_association       (association_t asoc);
    void    set_actionperipheral  (ControllableObject::action_t act, Peripheral* peri, Peripheral::component_t comp, Peripheral::event_t e);
    void    set_owner             (ControllableObject*);
    void    update                ();
    string  get_name_action       (ControllableObject::action_t);
    void    reset                 ();

  protected:
    ControllableObject *            owner;
    list<association_t>             associations;
    list<association_t>::iterator   associations_iter;
};

#endif
