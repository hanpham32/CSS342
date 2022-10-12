#ifndef TIME_SPAN_H_
#define TIME_SPAN_H_

#include <iostream>
using namespace std;

class TimeSpan
{
    public:
        TimeSpan();
        TimeSpan(float seconds);
        TimeSpan(float minutes, float seconds);
        TimeSpan(float hours, float minutes, float seconds);

        int getHours() const;
        int getMinutes() const;
        int getSeconds() const;

        void setHours(int hours);
        void setMinutes(int minutes);
        void setSeconds(int seconds);


        friend ostream& operator << (ostream& os, const TimeSpan ts);
        
        TimeSpan& operator=(const TimeSpan& ts);
        //Comparison operators overload
        bool operator==(const TimeSpan& ts) const;
        bool operator!=(const TimeSpan& ts) const;
        bool operator < (const TimeSpan& ts) const;
        bool operator > (const TimeSpan& ts) const;
        bool operator <= (const TimeSpan& ts) const;
        bool operator >= (const TimeSpan& ts) const;

        //Uniary operators overload
        void operator + (TimeSpan st);
        void operator - (TimeSpan& st);

        //Assignment operators overload
        void operator-=(TimeSpan& st);
        void operator+=(TimeSpan& st);

        
    private:
        int hours_;
        int minutes_;
        int seconds_;
        void ParseTimeSpan(float hours, float minutes, float seconds);
};
#endif