#ifndef CONTROLMANAGER_H
#define CONTROLMANAGER_H

#include <vector>
#include "Control.h"
#include "Peripheral.h"

#define MAXPERIPHERALS 5

using std::vector;

class ControlManager
{
    public:
        ControlManager();
        ~ControlManager();

        typedef struct
        {
            Peripheral *p;
            Peripheral::component_t comp;
        } change_t;
    
        change_t        get_change      ();
        int             add_control     (Control *ctrl);
        int             add_peripheral  (Peripheral *periph);
        Control *       get_control     (int number);
        Peripheral *    get_peripheral  (int number);
        void            update          ();

    protected:
        vector<Control*> controls;
        vector<Control*>::iterator controls_iter;
        
        vector<Peripheral*> peripherals;
        vector<Peripheral*>::iterator peripherals_iter;
        
        int old_state[MAXPERIPHERALS];
};

#endif