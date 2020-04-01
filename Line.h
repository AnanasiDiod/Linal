//
// Created by mi on 01.04.2020.
//

#ifndef LINAL_LINE_H
#define LINAL_LINE_H

#include "GVector.h"

class Line{
private:
    Point p;// точка начала
    GVector v;//направляющий вектор
public:
    Line(Point x, GVector n): p(x), v(n){}

    //проверить, принадлежит ли точка прямой с точностью sigma
    bool if_p_belongs(Point x, double sigma);
};


#endif //LINAL_LINE_H
