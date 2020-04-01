//
// Created by mi on 01.04.2020.
//

#include "point.h"
Point operator *(double a, Point& p){
    return Point(a * p.getX(), a * p.getY());
}

Point::Point(){
    x = 0;
    y = 0;
}

Point::Point(double x, double y){
    this->x = x;
    this->y = y;
}

double Point::getX() const {return x;}

double Point::getY() const {return y;}

void Point::rotate(double ang, double px, double py){
    double alpha = ang * 3.1415926535 / 180, fi, a, b, c;
    a = abs(x - px);
    b = abs(y - py);
    c = sqrt(a * a + b * b);
    fi = asin(b / c);
    x = px + c * cos(alpha + fi);
    y = py + c * sin(alpha + fi);
}

void Point::operator =(const Point& p){
    x = p.getX();
    y = p.getY();
}

bool Point::operator ==(const Point& p){
    return (x == p.getX())&&(y == p.getY());
}

Point Point::operator +(const Point& p){
    return Point(x + p.getX(), y + p.getY());
}

Point Point::operator -(const Point& p){
    return Point(x - p.getX(), y - p.getY());
}

Point Point::operator *(double a){
    return Point(a * x, a * y);
}