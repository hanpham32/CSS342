#ifndef TIME_SPAN_H_
#define TIME_SPAN_H_

#include <iostream>
using namespace std;

class TimeSpan
{
public:
    // Constructors
    TimeSpan();
    TimeSpan(double seconds);
    TimeSpan(double minutes, double seconds);
    TimeSpan(double hours, double minutes, double seconds);

    // Accessors
    int hours() const;
    int minutes() const;
    int seconds() const;

    friend ostream &operator<<(ostream &os, const TimeSpan ts);
    friend istream &operator>>(istream &is, TimeSpan &ts);

    // Unary operators overload
    TimeSpan operator+(TimeSpan &st);
    TimeSpan operator-(TimeSpan &st);

    // Relational operators overload
    bool operator==(const TimeSpan &ts) const;
    bool operator!=(const TimeSpan &ts) const;
    bool operator<(const TimeSpan &ts) const;
    bool operator>(const TimeSpan &ts) const;
    bool operator<=(const TimeSpan &ts) const;
    bool operator>=(const TimeSpan &ts) const;

    // Assignment operators overload
    void operator=(const TimeSpan &ts);

    TimeSpan operator-=(const TimeSpan &st);
    TimeSpan operator+=(const TimeSpan &st);

    void set_time(int hours, int minutes, int seconds);
    double CalculateTotalSeconds(double hours, double minutes, double seconds);
    void ParseTimeSpan(TimeSpan &ts, int total_seconds);

private:
    int hours_;
    int minutes_;
    int seconds_;
    void set_hours(int hours);
    void set_minutes(int minutes);
    void set_seconds(int seconds);
};
#endif