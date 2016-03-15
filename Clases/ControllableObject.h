
#ifndef CONTROLLABLEOBJECT_H
#define CONTROLLABLEOBJECT_H

class ControllableObject
{
	public:
		typedef int action_t;

		virtual void do_action  (action_t action, int magnitude);
};

#endif