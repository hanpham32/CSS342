#include "time_span.h"
#include <iostream>

TimeSpan::TimeSpan()
{
    hours_ = 0;
    minutes_ = 0;
    seconds_ = 0;
}

TimeSpan::TimeSpan(int seconds)
{
    seconds_ = seconds;
    minutes_ = 0;
    hours_ = 0;
    ParseTimeSpan();
}

TimeSpan::TimeSpan(int minutes, int seconds)
{
    hours_ = 0;
    minutes_ = minutes;
    seconds_ = seconds;
    ParseTimeSpan();
}

TimeSpan::TimeSpan(int hours, int minutes, int seconds)
{
    hours_ = hours;
    minutes_ = minutes;
    seconds_ = seconds;
    ParseTimeSpan();
}

int TimeSpan::getHours() const
{
    return hours_;
}

int TimeSpan::getMinutes() const
{
    return minutes_;
}

int TimeSpan::getSeconds() const
{
    return seconds_;
}

void TimeSpan::setHours(int hours)
{
    hours_ = hours;
}

void TimeSpan::setMinutes(int minutes)
{
    minutes_ = minutes;
}

void TimeSpan::setSeconds(int seconds)
{
    seconds_ = seconds;
}

void TimeSpan::ParseTimeSpan()
{
    int total_seconds = 0;
    total_seconds += (hours_ * 3600);
    total_seconds += (minutes_ * 60);
    total_seconds += seconds_;
    setHours(total_seconds % 60);
    total_seconds = total_seconds % 60;
    setMinutes(total_seconds % 60);
    total_seconds = total_seconds % 60;
    setSeconds(total_seconds);
}

ostream& operator << (ostream& os, const TimeSpan ts)
{
    if ((ts.getHours() > 0))
    {
        os << "Hours: " << ts.getHours() << ", Minutes: " << ts.getMinutes() << ", Seconds: " << ts.getSeconds();
    } else if ((ts.getMinutes() > 0))
    {
        os << "Minutes: " << ts.getMinutes() << ", Seconds: " << ts.getSeconds();
    } else if ((ts.getSeconds() > 0))
    {
        os << "Seconds: " << ts.getSeconds();
    } else 
    {
        os << "0";
    }
    return os;
}