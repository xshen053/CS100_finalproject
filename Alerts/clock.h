#include"time.h"
#include<ctime>
#ifndef _CLOCK_H
#define _CLOCK_H

class Clock
{
    
public:
    void GetNowTime(int Year,int Month,int Day,int Hour,int Min,int Second);
    void RingTime(int Year,int Month,int Day,int Hour,int Min,int Second);
    void ShowTime();
    void Tick();
    void Start();
private:
    Time m_tNowTime;
    Time m_tRingTime;
};

#endif
