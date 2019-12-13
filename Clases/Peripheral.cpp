///---------------------------------------------------------
/// @file       Peripheral.cpp
/// @author     Juan Manuel Rico
/// @date       Octubre 2015
/// @version    1.0.0
///
/// @brief      Define un periférico para el control.
///---------------------------------------------------------

#include "Peripheral.h"

namespace fwg {
    
    Peripheral::Peripheral ()
    {
    }

    Peripheral::~Peripheral ()
    {
    }

    Peripheral::State Peripheral::getState (Component comp)
    {
        return 0;
    }

    Peripheral::Component Peripheral::getChange ()
    {
        return 0;
    }

    std::string Peripheral::getComponentName (Component comp)
    {
        return "";
    }

    void Peripheral::reset ()
    {
    }
}