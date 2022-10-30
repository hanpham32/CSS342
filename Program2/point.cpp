/*
Project 2 - CSS342
Hannah Pham
10/28/2022
point.cpp
*/

#include "point.h"

Point::Point(int x, int y) : x_(x), y_(y)
{
}

int Point::x() const
{
    return x_;
}

int Point::y() const
{
    return y_;
}

void Point::set_x(int x)
{
    x_ = x;
}

void Point::set_y(int y)
{
    y_ = y;
}

bool Point::operator==(const Point &rhs) const
{
    if ((x() == rhs.x()) && (y() == rhs.y()))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Point::operator!=(const Point &rhs) const
{
    if ((x() == rhs.x()) && (y() == rhs.y()))
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Point::operator=(const Point &rhs)
{
    set_x(rhs.x());
    set_y(rhs.y());
}