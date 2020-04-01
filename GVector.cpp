//
// Created by mi on 01.04.2020.
//

#include "GVector.h"
#include "point.h"

GVector::GVector(Point a, Point b){
x = a.getX() - b.getX();
y = a.getY() - b.getY();
}

GVector::GVector(double x, double y) {
    this->x = x;
    this->y = y;
}

double GVector::getX(){
    return x;
}

double GVector::getY(){
    return y;
}

GVector& GVector::operator +(GVector& v){
    GVector a(x + v.getX(), y + v.getY());
    GVector &ref = a;
    return ref;
}

GVector& GVector::operator -(GVector& v){
    GVector a(x - v.getX(), y - v.getY());
    GVector &ref = a;
    return ref;
}

GVector GVector::operator *(double a) {
    return GVector(x * a, y * a);
}

void GVector::operator =(GVector& v){
    x = v.getX();
    y = v.getY();
}

GVector operator *(GVector& v1, double a){
    return GVector(v1.getX() * a, v1.getY() * a);
}

GVector operator /(GVector& v, double a){
    return GVector(v.getX()/a, v.getY()/a);
}