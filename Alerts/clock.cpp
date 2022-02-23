# include "clock.h"
# include <windows.h>
# include "alert.h"
void Clock::GetNowTime(int Year,int Month,int Day,int Hour,int Min,int Second)
{
    m_tNowTime.SetTime(Year,Month,Day,Hour,Min,Second);
    cout<<"Time right now ："<<Year<<"-"<<Month<<"-"<<Day<<" "
        <<Hour<<":"<<Min<<":"<<Second<<endl;
}
void Clock::RingTime(int Year,int Month,int Day,int Hour,int Min,int Second)
{
    m_tRingTime.SetTime(Year,Month,Day,Hour,Min,Second);
    cout<<"Ring time is ："<<Year<<"-"<<Month<<"-"<<Day<<" "
        <<Hour<<":"<<Min<<":"<<Second<<endl;
}
void Clock::Tick()
{
    Sleep(1000);
    m_tNowTime.NextSec();
}

void Clock::ShowTime(){
    cout<<m_tNowTime.GetTime()<<endl;
}
void Clock::Start()
{
    int i = 0;
    do{
        Tick();
        if(m_tNowTime.GetTime() < m_tRingTime.GetTime())
        {
            ShowTime();
        }else 
        {
            cout<<'\a';
            i++;
            if(i == 0)
            {
                cout<<"\n alert! alert!\n"<<endl;
            }else if(i == 10)
            {               
                cout<<"\n your are done!! \n"<<endl;
                break;
            }

        }           
    }while(1);
}
