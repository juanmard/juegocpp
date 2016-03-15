
#ifndef PERIPHERAL_H
#define PERIPHERAL_H

#include <string>
using namespace std;

#define INVALID_STATE -2
#define INVALID_COMPONENT -2

class Peripheral
{
	public:
		typedef enum event_t
		{
			NO_EVENT,
			ON_PRESS,
			ON_RELEASE,
			ON_PRESSING,
			ON_RELEASSING,
		};

		typedef int state_t;
		typedef int component_t;

		Peripheral();
		virtual state_t get_state(component_t comp);
		virtual component_t get_change();
		virtual string get_component_name(component_t comp);
		virtual void reset();
};
#endif
