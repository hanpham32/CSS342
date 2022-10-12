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

        friend ostream& operator << (ostream& os, const TimeSpan ts);
        
        //Unary operators overload
        TimeSpan operator + (TimeSpan& st);
        TimeSpan operator - (TimeSpan& st);

        //Relational operators overload
        bool operator==(const TimeSpan& ts) const;
        bool operator!=(const TimeSpan& ts) const;
        bool operator < (const TimeSpan& ts);
        bool operator > (const TimeSpan& ts);
        bool operator <= (const TimeSpan& ts);
        bool operator >= (const TimeSpan& ts);

        //Assignment operators overload
        void operator=(const TimeSpan& ts);

        void operator-=(TimeSpan& st);
        void operator+=(TimeSpan& st);

        
    private:
        int hours_;
        int minutes_;
        int seconds_;
        void ParseTimeSpan(float hours, float minutes, float seconds);
        float CalculateTotalSeconds(float hours, float minutes, float seconds);
        void setHours(int hours);
        void setMinutes(int minutes);
        void setSeconds(int seconds);
};
#endif