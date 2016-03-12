#ifndef _PERIPHERAL_H_
#define _PERIPHERAL_H_

#include <string>

//using namespace std;
using std::string;

#define INVALID_STATE       -2
#define INVALID_COMPONENT   -2

/**
 * \brief   Clase periférico del equipo.
 */
class Peripheral
{
  public:
    // Eliminamos el typedef por warning
    //typedef enum event_t
    enum event_t
    {
      NO_EVENT,
      ON_PRESS,
      ON_RELEASE,
      ON_PRESSING,
      ON_RELEASSING,
    };
    typedef int   state_t;
    typedef int   component_t;

                          Peripheral            ();
    virtual state_t       get_state             (component_t comp);
    virtual component_t   get_change            ();
    virtual string        get_component_name    (component_t comp);
    virtual void          reset                 ();
};

#endif
