# include "time.h"

void Time::SetTime(int aYear,int aMonth,int aDay,int aHour,int aMin,int aSecond)
{
    m_sYear = aYear;
    m_sMonth = aMonth;
    m_sDay = aDay;
    m_sHour = aHour;
    m_sMin = aMin;
    m_sSecond = aSecond;
}

void Time::NextSec()
{
    if(m_sSecond < 59)
        m_sSecond++;
    else if(m_sMin < 59)
    {
        m_sSecond = 0;
        m_sMin++;
    }
    else if(m_sHour < 23)
    {
        m_sMin=0;
        m_sHour++;
    }
    else if(m_sDay < 30)
    {
        m_sHour=0;
        m_sDay++;
    }
    else if(m_sMonth < 12)
    {
        m_sDay = 0;
        m_sMonth++;
    }
    else
        m_sMonth = 0;

}

int Time::GetTime()
{
    return m_sHour*10000+m_sMin*100+m_sSecond;
}
