#ifndef _TIME_H
#define _TIME_H

#include <iostream>
#include <string>
using namespace std;


class Time
{
public:
    void SetTime(int Year,int Month,int Day,int Hour,int Min,int Second);
    void NextSec();
    int GetTime();
private:
    int m_sYear;
    int m_sMonth;
    int m_sDay;
    int m_sHour;
    int m_sMin;
    int m_sSecond;
};

#endif
