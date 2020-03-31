#include <iostream>
#include <cmath>

using namespace std;


class Point{
private:
    double x, y;
public:
    Point(){
        x = 0;
        y = 0;
    }

    Point(double x, double y){
        this->x = x;
        this->y = y;
    }

    double getX() const {return x;}

    double getY() const {return y;}

// повернуть точку отнсительно точки (px, py) на угол angle в градусах
    void rotate(double ang, double px, double py){
        double alpha = ang * 3.1415926535 / 180, fi, a, b, c;
        a = abs(x - px);
        b = abs(y - py);
        c = sqrt(a * a + b * b);
        fi = asin(b / c);
        x = px + c * cos(alpha + fi);
        y = py + c * sin(alpha + fi);
    }

    void operator =(const Point& p){
        x = p.getX();
        y = p.getY();
    }

    bool operator ==(const Point& p){
        return (x == p.getX())&&(y == p.getY());
    }

    Point operator +(const Point& p){
        return Point(x + p.getX(), y + p.getY());
    }

    Point operator -(const Point& p){
        return Point(x - p.getX(), y - p.getY());
    }

    Point operator *(double a){
        return Point(a * x, a * y);
    }

    friend Point operator *(double a, Point& p);
};

Point operator *(double a, Point& p){
    return Point(a * p.getX(), a * p.getY());
}

class GVector{
private:
    double x, y;
public:
    GVector(Point a, Point b){
        x = a.getX() - b.getX();
        y = a.getY() - b.getY();
    }

    GVector(double x, double y) {
        this->x = x;
        this->y = y;
    }

    double getX(){
        return x;
    }

    double getY(){
        return y;
    }

    GVector& operator +(GVector& v){
        GVector a(x + v.getX(), y + v.getY());
        GVector &ref = a;
        return ref;
    }

    GVector& operator -(GVector& v){
        GVector a(x - v.getX(), y - v.getY());
        GVector &ref = a;
        return ref;
    }

    friend GVector operator *(GVector& v1, double a);

    GVector operator *(double a) {
        return GVector(x * a, y * a);
    }

    friend GVector operator /(GVector& v, double a);

    void operator =(GVector& v){
        x = v.getX();
        y = v.getY();
    }
};

GVector operator *(GVector& v1, double a){
    return GVector(v1.getX() * a, v1.getY() * a);
}

GVector operator /(GVector& v, double a){
    return GVector(v.getX()/a, v.getY()/a);
}


class Line{
private:
    Point p;// точка начала
    GVector v;//направляющий вектор
public:
    Line(Point x, GVector n): p(x), v(n){}

    //проверить, принадлежит ли точка прямой с точностью sigma
    bool if_p_belongs(Point x, double sigma){
        return (abs((x.getX()-p.getX())/v.getX() - (x.getY()-p.getY())/v.getY()) <= sigma);
    }
};

int main()
{
    Point x(1, 2), y(2, 3);
    GVector v1(1, 2), v2(x, y);
    cout << v2.getX() << ' ' << v2.getY() << endl;
    v1 = v1 + v2;
    cout << v1.getX() << ' ' << v1.getY() << endl;
    Line l(y, v1);
    cout << l.if_p_belongs(x, 0.0001);
    return 0;
}
