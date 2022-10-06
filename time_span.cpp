#include "time_span.h"

TimeSpan::TimeSpan()
{
    hours_ = 0;
    minutes_ = 0;
    seconds_ = 0;
}

TimeSpan::TimeSpan(int seconds)
{
    seconds_ = seconds;
}

TimeSpan::TimeSpan(int minutes, int seconds)
{
    minutes_ = minutes;
    seconds_ = seconds;
}

TimeSpan::TimeSpan(int hours, int minutes, int seconds)
{
    hours_ = hours;
    minutes_ = minutes;
    seconds_ = seconds;
}

int TimeSpan::getHours() const
{
    return hours_;
}

int TimeSpan::getMinutes() const
{
    return minutes_;
}

int TimeSpan::getHours() const
{
    return hours_;
}

void TimeSpan::setTime(int hours, int minutes, int seconds)
{

}