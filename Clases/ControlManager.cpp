#include "ControlManager.h"

ControlManager::ControlManager()
{
    for (int i=0;i<MAXPERIPHERALS;i++)
    old_state[i]=false;
}

ControlManager::~ControlManager()
{
    for (peripherals_iter=peripherals.begin();
    peripherals_iter!=peripherals.end();
    peripherals_iter++)
    {
       delete(*peripherals_iter);
    }

    for (controls_iter=controls.begin();
    controls_iter!=controls.end();controls_iter++)
    {
        delete(*controls_iter);
    }
}

int ControlManager::add_control(Control *c)
{
    controls.push_back(c);
    return controls.size()-1;
}

int ControlManager::add_peripheral(Peripheral *p)
{
    peripherals.push_back(p);
    return peripherals.size()-1;
}

Control *ControlManager::get_control(int number)
{
    return controls[number];
}

Peripheral *ControlManager::get_peripheral(int number)
{
    return peripherals[number];
}

ControlManager::change_t ControlManager::get_change()
{
    change_t ret;
    Peripheral::component_t comp;
    int pos=0;

    for (peripherals_iter=peripherals.begin();
    peripherals_iter!=peripherals.end();
    peripherals_iter++)
    {
        pos++;
        comp=(*peripherals_iter)->get_change();
        if (comp!=INVALID_COMPONENT)
        {
            ret.comp=comp;
            ret.p=*peripherals_iter;
            old_state[pos]=true;
        }
        else
            old_state[pos]=false;
    }
    return ret;
}

void ControlManager::update()
{
    for (controls_iter=controls.begin();
    controls_iter!=controls.end(); controls_iter++)
    (*controls_iter)->update();
}