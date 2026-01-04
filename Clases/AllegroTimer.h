#ifndef _ALLEGROTIMER_H_
#define _ALLEGROTIMER_H_

#include "ITimer.h"
#include <allegro.h>

/// @brief Timer para Allegro4.
class AllegroTimer : public ITimer {
private:
    static volatile int tick;
    static void tick_count();

public:
    AllegroTimer();
    ~AllegroTimer();
    void install (void) override;
    void init (void) override;
    bool isCicloLogico () override { return (actual_tick <= tick); };
    bool isCicloGrafico () override { return (actual_tick >= tick); };
    bool isSkipFrame () override { return (frame_skip > max_frame_skip); };
    void incTickActual () override { actual_tick++; };
    void updateFrame () override {
        if ( isSkipFrame() ) actual_tick = tick;
        graphic_tick++;
        frame_skip = 0;
    };
    void incFrame () override { frame_skip++; };
    int getGraphicTick() override {return graphic_tick; };
    int getFrameSkip() override {return frame_skip; };
    void resetGraphicTick () override { graphic_tick = 0; };
    bool isOneSecond () override { return (tick - old_tick >= 70); };
    void resetOldTick () override { old_tick = tick; };
};

#endif ///_ALLEGROTIMER_H_