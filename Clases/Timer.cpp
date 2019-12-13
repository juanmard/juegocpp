///---------------------------------------------------------
/// @file       Timer.cpp
/// @author     Juan Manuel Rico
/// @date       Diciembre 2019
/// @version    1.0.0
///
/// @brief      Timer del juego.
///---------------------------------------------------------

#include "Timer.h"

namespace fwg {
    
    Timer::Timer (unsigned int mseg, unsigned int max_fs)
    {
        ticks_ps = 1000/mseg;
        max_frame_skip = max_fs;
        quantum = mseg;
    }
    
    void Timer::start ()
    {
        actual_tick = getTick();
        old_tick = getTick();
    }
    
    bool Timer::updateLogic ()
    {
        bool result = false;
        if (actual_tick <= getTick())
        {
            actual_tick++;
            result = true;
        }
        return result;
    }

    bool Timer::updateGraphic ()
    {
        bool result = false;
        if ((actual_tick >= getTick()) || (frame_skip > max_frame_skip))
        {
            if (frame_skip > max_frame_skip) actual_tick = getTick();
            graphic_tick++;
            frame_skip = 0;
            result = true;
        }
        else
        {
            frame_skip++;
        }
        return result;
    }
    
    bool Timer::has_new_second () const
    {
        return ((getTick() - old_tick) >= ticks_ps);
    }

    void Timer::reset_second ()
    {
        graphic_tick = 0;
        old_tick = getTick();
    }
    
    unsigned int Timer::get_fps () const
    {
        return graphic_tick;
    }
    
    unsigned int Timer::get_frameskip () const
    {
        return frame_skip;
    }
    
    void Timer::install ()
    {
    }

    unsigned int Timer::getTick () const
    {
        return 0;
    }
}
