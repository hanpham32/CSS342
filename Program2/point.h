/*
Project 2 - CSS342
Hannah Pham
10/28/2022
point.h
*/

#ifndef POINT_H_
#define POINT_H_

class Point
{
public:
    Point(int x, int y);

    int x() const;
    int y() const;

    bool operator==(const Point &rhs) const;
    bool operator!=(const Point &rhs) const;
    void operator=(const Point &rhs);

    void set_x(int x);
    void set_y(int y);

private:
    int x_;
    int y_;
};

#endif