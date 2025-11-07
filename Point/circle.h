#pragma once
#include "point.h"

class Circle
{
private: 
    double radius;
    Point center;
public:
    Circle();
    Circle(double initialR,Point& c);
    double getRadius();
    Point getCenter();
    void setRadius(double newR);
    void move(Point& newC);
    void move(double deltaX, double deltaY);
    void print();
    bool operator ==(Circle& other);
    ~Circle(); //destructor
};