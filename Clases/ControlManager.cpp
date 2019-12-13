///---------------------------------------------------------
/// @file       ControlManager.cpp
/// @author     Juan Manuel Rico
/// @date       Octubre 2015
/// @version    1.0.0
///
/// @brief      Controlador de controles.
///---------------------------------------------------------

#include "ControlManager.h"
#include "Control.h"

namespace fwg {

    ControlManager::ControlManager()
    {
        for (int i=0;i<MAXPERIPHERALS;i++)
            oldState[i]=false;
    }

    ControlManager::~ControlManager()
    {
        for (peripheralsIter = peripherals.begin();
             peripheralsIter != peripherals.end();
             peripheralsIter++)
        {
           delete(*peripheralsIter);
        }

        for (controlsIter= controls.begin();
             controlsIter != controls.end();
             controlsIter++)
        {
            delete(*controlsIter);
        }
    }

    int ControlManager::addControl(Control* c)
    {
        controls.push_back(c);
        return controls.size()-1;
    }

    int ControlManager::addPeripheral(Peripheral* p)
    {
        peripherals.push_back(p);
        return peripherals.size()-1;
    }

    Control* ControlManager::getControl(int number)
    {
        return controls[number];
    }

    Peripheral* ControlManager::getPeripheral(int number)
    {
        return peripherals[number];
    }

    ControlManager::Change ControlManager::getChange()
    {
        Change ret;
        Peripheral::Component comp;
        int pos = 0;

        for (peripheralsIter = peripherals.begin();
             peripheralsIter != peripherals.end();
             peripheralsIter++)
        {
            pos++;
            comp = (*peripheralsIter)->getChange();
            if (comp != INVALID_COMPONENT)
            {
                ret.comp = comp;
                ret.p = *peripheralsIter;
                oldState[pos] = true;
            }
            else
            {
                oldState[pos] = false;
            }
        }
        return ret;
    }

    void ControlManager::update()
    {
        for (controlsIter = controls.begin();
             controlsIter != controls.end();
             controlsIter++)
        {
            (*controlsIter)->update();
        }
    }
    
}