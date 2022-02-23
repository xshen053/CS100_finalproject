 guess I don't need to do this part yet, but for a clock and I randomly done get time, will fix teammate done thier part.

#include<iostream>
#include<windows.h>
#include"clock.h"
using namespace std;
int main()
{
    Clock c;
    cout<<"\n get time from the systerm\n"<<endl;
    cout<<"ring at\n"<<endl;
    c.GetNowTime(2022,1,2,3,4,5,);
    c.RingTime(2022,1,2,3,4,5);
    cout<<"\n ring in : \n"<<endl;
    c.Start();
    return 0;
}
