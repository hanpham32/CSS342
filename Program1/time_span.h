#ifndef TIME_SPAN_H_
#define TIME_SPAN_H_

#include <iostream>
using namespace std;

class TimeSpan
{
    public:
        TimeSpan();
        TimeSpan(int seconds);
        TimeSpan(int minutes, int seconds);
        TimeSpan(int hours, int minutes, int seconds);

        int getHours() const;
        int getMinutes() const;
        int getSeconds() const;

        void ParseTimeSpan();
        void setHours(int hours);
        void setMinutes(int minutes);
        void setSeconds(int seconds);

        friend ostream& operator << (ostream& os, const TimeSpan ts);
        
    private:
        int hours_;
        int minutes_;
        int seconds_;
};
#endif