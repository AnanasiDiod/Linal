//
// Created by mi on 01.04.2020.
//

#include "Line.h"

bool Line::if_p_belongs(Point x, double sigma){
    return (abs((x.getX()-p.getX())/v.getX() - (x.getY()-p.getY())/v.getY()) <= sigma);
}