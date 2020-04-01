//
// Created by mi on 01.04.2020.
//

#ifndef LINAL_GVECTOR_H
#define LINAL_GVECTOR_H

#include "point.h"

class GVector{
private:
    double x, y;
public:
    GVector(Point a, Point b);

    GVector(double x, double y);

    double getX();

    double getY();

    GVector& operator +(GVector& v);

    GVector& operator -(GVector& v);

    friend GVector operator *(GVector& v1, double a);

    GVector operator *(double a);

    friend GVector operator /(GVector& v, double a);

    void operator =(GVector& v);
};

GVector operator *(GVector& v1, double a);

GVector operator /(GVector& v, double a);


#endif //LINAL_GVECTOR_H
