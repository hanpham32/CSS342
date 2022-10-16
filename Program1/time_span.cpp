#include "time_span.h"
#include <iostream>
#include <math.h>

TimeSpan::TimeSpan() : hours_(0), minutes_(0), seconds_(0)
{
}

TimeSpan::TimeSpan(double seconds) : hours_(0), minutes_(0)
{
    int total_seconds = CalculateTotalSeconds(0, 0, seconds);
    seconds_ = seconds;
    ParseTimeSpan(*this, total_seconds);
}

TimeSpan::TimeSpan(double minutes, double seconds) : hours_(0)
{
    int total_seconds = CalculateTotalSeconds(0, minutes, seconds);
    seconds_ = seconds;
    minutes_ = minutes;
    ParseTimeSpan(*this, total_seconds);
}

TimeSpan::TimeSpan(double hours, double minutes, double seconds)
{
    int total_seconds = CalculateTotalSeconds(hours, minutes, seconds);
    hours_ = hours;
    minutes_ = minutes;
    seconds_ = seconds;

    ParseTimeSpan(*this, total_seconds);
}

int TimeSpan::hours() const
{
    return hours_;
}

int TimeSpan::minutes() const
{
    return minutes_;
}

int TimeSpan::seconds() const
{
    return seconds_;
}

void TimeSpan::set_time(int hours, int minutes, int seconds)
{
    int total_seconds = CalculateTotalSeconds(hours, minutes, seconds);
    set_hours(hours);
    set_minutes(minutes);
    set_seconds(seconds);
    ParseTimeSpan(*this, total_seconds);
}

void TimeSpan::set_hours(int hours)
{
    hours_ = hours;
}

void TimeSpan::set_minutes(int minutes)
{
    minutes_ = minutes;
}

void TimeSpan::set_seconds(int seconds)
{
    seconds_ = seconds;
}

ostream &operator<<(ostream &os, const TimeSpan ts)
{
    return os << "Hours: " << ts.hours() << ", Minutes: " << ts.minutes() << ", Seconds: " << ts.seconds();
}

istream &operator>>(istream &is, TimeSpan ts)
{
    int hours, minutes, seconds;
    cout << "Please input hour(s): " << endl;
    cin >> hours;
    cout << "Please input minutes(s): " << endl;
    cin >> minutes;
    cout << "Please input seconds(s): " << endl;
    cin >> seconds;
    int total_seconds = ts.CalculateTotalSeconds(hours, minutes, seconds);
    ts.ParseTimeSpan(ts, total_seconds);
    return is;
}

bool TimeSpan::operator==(const TimeSpan &ts) const
{
    if ((hours() == ts.hours()) && (minutes() == ts.minutes()) && (seconds() == ts.seconds()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool TimeSpan::operator!=(const TimeSpan &ts) const
{
    if ((hours() == ts.hours()) && (minutes() == ts.minutes()) && (seconds() == ts.seconds()))
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool TimeSpan::operator<(const TimeSpan &ts) const
{
    float n1, n2;
    n1 = hours() * 3600 + minutes() * 60 + seconds();
    n2 = ts.hours() * 3600 + ts.minutes() * 60 + ts.seconds();
    if (n1 > n2)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool TimeSpan::operator>(const TimeSpan &ts) const
{
    float n1, n2;
    n1 = hours() * 3600 + minutes() * 60 + seconds();
    n2 = ts.hours() * 3600 + ts.minutes() * 60 + ts.seconds();
    if (n1 > n2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool TimeSpan::operator<=(const TimeSpan &ts) const
{
    float n1, n2;
    n1 = hours() * 3600 + minutes() * 60 + seconds();
    n2 = ts.hours() * 3600 + ts.minutes() * 60 + ts.seconds();
    if ((n1 < n2) || (n1 == n2))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool TimeSpan::operator>=(const TimeSpan &ts) const
{
    float n1, n2;
    n1 = hours() * 3600 + minutes() * 60 + seconds();
    n2 = ts.hours() * 3600 + ts.minutes() * 60 + ts.seconds();
    if ((n1 > n2) || (n1 == n2))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void TimeSpan::operator=(const TimeSpan &ts)
{
    set_hours(ts.hours());
    set_minutes(ts.minutes());
    set_seconds(ts.seconds());
}

TimeSpan TimeSpan::operator+=(const TimeSpan &ts)
{
    set_hours(hours() + ts.hours());
    set_minutes(minutes() + ts.minutes());
    set_seconds(seconds() + ts.seconds());
    int total_seconds = CalculateTotalSeconds(hours(), minutes(), seconds());
    ParseTimeSpan(*this, total_seconds);
    return *this;
}

TimeSpan TimeSpan::operator-=(const TimeSpan &ts)
{
    set_hours(hours() - ts.hours());
    set_minutes(minutes() - ts.seconds());
    set_seconds(seconds() - ts.seconds());
    int total_seconds = CalculateTotalSeconds(hours(), minutes(), seconds());
    ParseTimeSpan(*this, total_seconds);
    return *this;
}

TimeSpan TimeSpan::operator+(TimeSpan &ts)
{
    TimeSpan result = *this;
    result += ts;
    int total_seconds = CalculateTotalSeconds(result.hours(), result.minutes(), result.seconds());
    ParseTimeSpan(result, total_seconds);
    return result;
}

TimeSpan TimeSpan::operator-(TimeSpan &ts)
{
    TimeSpan result = *this;
    result -= ts;
    int total_seconds = CalculateTotalSeconds(result.hours(), result.minutes(), result.seconds());
    ParseTimeSpan(result, total_seconds);
    return result;
}

double TimeSpan::CalculateTotalSeconds(double hours, double minutes, double seconds)
{
    double total_seconds = 0;
    total_seconds += (hours * 3600);
    total_seconds += (minutes * 60);
    total_seconds += seconds;
    total_seconds = round(total_seconds);
    return total_seconds;
}

void TimeSpan::ParseTimeSpan(TimeSpan &ts, int total_seconds)
{
    if (total_seconds == 0)
    {
        ts.set_seconds(0);
        ts.set_minutes(0);
        ts.set_hours(0);
    }
    if ((total_seconds >= 3600) || (total_seconds <= -3600))
    {
        ts.set_hours(total_seconds / 3600); // 278106 / 3600 + 77.251666
        total_seconds = fmod(total_seconds, 3600);
    }
    if ((total_seconds >= 60) || (total_seconds <= -60))
    {
        ts.set_minutes(total_seconds / 60);
        total_seconds = fmod(total_seconds, 60);
    }
    ts.set_seconds(total_seconds);
}