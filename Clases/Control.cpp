#include "Control.h"

void Control::add_action_name(ControllableObject::action_t act, string str)
{
    association_t asoc;
    asoc.act = act;
    asoc.name= str;
    asoc.peri= NULL;
    asoc.comp= -1;
    associations.push_back(asoc);
}

void    Control::set_actionperipheral(ControllableObject::action_t act,
        Peripheral* peri,
        Peripheral::component_t comp,
        Peripheral::event_t e)
{
    for (associations_iter=associations.begin();
    associations_iter!=associations.end();
    associations_iter++)
    {
        if (associations_iter->act == act)
        {
            associations_iter->peri=peri;
            associations_iter->comp=comp;
            associations_iter->new_event=e;
            associations_iter->old_event=Peripheral::NO_EVENT;
            return;
        }
    }
}

void Control::add_association(Control::association_t assoc)
{
    associations.push_back(assoc);
}

void Control::set_owner(ControllableObject* co)
{
    owner=co;
}

void Control::update()
{
    int do_action_order;
    Peripheral::state_t tmp_state;
    Peripheral::event_t tmp_old_event;

    for (associations_iter=associations.begin();
    associations_iter!=associations.end();
    associations_iter++)
    {
        tmp_state=associations_iter->peri->get_state(associations_iter->comp);
        tmp_old_event=associations_iter->old_event;
        do_action_order=false;
        switch(associations_iter->new_event)
        {
            case Peripheral::ON_PRESSING:
                if (tmp_state!=INVALID_STATE)
                {
                    do_action_order=true;
                }
                break;

            case Peripheral::ON_PRESS:
                if ((tmp_old_event==Peripheral::ON_RELEASE) &&
                (tmp_state!=INVALID_STATE))
                {
                    associations_iter->old_event=Peripheral::ON_PRESS;
                    do_action_order=true;
                }
                else
                    if (tmp_state==INVALID_STATE) associations_iter->old_event=Peripheral::ON_RELEASE;
                break;

            case Peripheral::ON_RELEASE:
                if ((tmp_old_event==Peripheral::ON_PRESS) &&
                (tmp_state==INVALID_STATE))
                {
                    associations_iter->old_event=Peripheral::ON_RELEASE;
                    do_action_order=true;
                }
                else
                    if (tmp_state!=INVALID_STATE) associations_iter->old_event=Peripheral::ON_PRESS;
                break;

            case Peripheral::ON_RELEASSING:
                if (tmp_state==INVALID_STATE)
                {
                    do_action_order=true;
                }
                break;

            default:
                break;
        }
        
        if (do_action_order)
        {
            owner->do_action(associations_iter->act, tmp_state);
        }
    }
}

string Control::get_name_action(ControllableObject::action_t act)
{
    for (associations_iter=associations.begin();
    associations_iter!=associations.end();
    associations_iter++)
    {
        if (associations_iter->act == act)
        {
            return associations_iter->name;
        }
    }
    return "";
}
