//
// Created by mi on 01.04.2020.
//

#ifndef LINAL_POINT_H
#define LINAL_POINT_H


#include <iostream>
#include <cmath>


class Point{
private:
    double x, y;
public:
    Point();

    Point(double x, double y);

    double getX() const;
    double getY() const ;
// повернуть точку отнсительно точки (px, py) на угол angle в градусах
    void rotate(double ang, double px, double py);

    void operator =(const Point& p);

    bool operator ==(const Point& p);

    Point operator +(const Point& p);

    Point operator -(const Point& p);

    Point operator *(double a);

    friend Point operator *(double a, Point& p);
};

Point operator *(double a, Point& p);


#endif //LINAL_POINT_H
