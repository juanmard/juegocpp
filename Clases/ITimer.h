#ifndef _ITIMER_H_
#define _ITIMER_H_

class ITimer {
public:
    int actual_tick;
    int old_tick;
    int graphic_tick;
    int frame_skip;
    int max_frame_skip;

public:
    virtual ~ITimer() {}
    virtual void install () = 0;
    virtual void init () = 0;
    virtual bool isCicloLogico () = 0;
    virtual bool isCicloGrafico () = 0;
    virtual bool isSkipFrame () = 0;
    virtual void incTickActual () = 0;
    virtual void updateFrame () = 0;
    virtual void incFrame () = 0;
    virtual int getGraphicTick () = 0;
    virtual int getFrameSkip () = 0;
    virtual void resetGraphicTick () = 0;
    virtual bool isOneSecond () = 0;
    virtual void resetOldTick () = 0;
};

#endif ///_ITIMER_H_