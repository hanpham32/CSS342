#include "time_span.h"
#include <iostream>
#include <math.h>

TimeSpan::TimeSpan() : hours_(0), minutes_(0), seconds_(0)
{
}

TimeSpan::TimeSpan(float seconds) : hours_(0), minutes_(0)
{
    ParseTimeSpan(0,0,seconds);
}

TimeSpan::TimeSpan(float minutes, float seconds) : hours_(0)
{
    ParseTimeSpan(0, minutes, seconds);
}

TimeSpan::TimeSpan(float hours, float minutes, float seconds)
{
    ParseTimeSpan(hours, minutes, seconds);
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

void TimeSpan::ParseTimeSpan(float hours, float minutes, float seconds)
{
    float total_seconds = 0;
    total_seconds += (hours * 3600);
    total_seconds += (minutes * 60);
    total_seconds += seconds;
    // cout << "total_seconds: " << total_seconds << endl;
    if (total_seconds == 0)
    {
        setSeconds(0);
        setMinutes(0);
        setHours(0);
    }
    if ((total_seconds >= 3600) || (total_seconds <= -3600))
    {
        setHours(total_seconds / 3600);
        total_seconds = fmod(total_seconds,3600);
    }
    if ((total_seconds >= 60) || (total_seconds <= -60))
    {
        setMinutes(total_seconds / 60);
        total_seconds = fmod(total_seconds,60);
    }
    setSeconds(total_seconds);
}

ostream& operator << (ostream& os, const TimeSpan ts)
{
    return os << "Hours: " << ts.getHours() << ", Minutes: " << ts.getMinutes() << ", Seconds: " << ts.getSeconds();
}

TimeSpan& TimeSpan::operator=(const TimeSpan& ts)
{
    if (this == &ts)
    {
        return *this;
    } else {
        hours_ = ts.hours_;
        minutes_ = ts.minutes_;
        seconds_ = ts.seconds_;
        return *this;
    }
}

void TimeSpan::operator+(TimeSpan ts)
{
    hours_ += ts.getHours();
    minutes_ += ts.getMinutes();
    seconds_ += ts.getSeconds();
    ParseTimeSpan(hours_, minutes_, seconds_);
}

void TimeSpan::operator+=(TimeSpan& ts)
{

}

void TimeSpan::operator-=(TimeSpan& ts)
{

}