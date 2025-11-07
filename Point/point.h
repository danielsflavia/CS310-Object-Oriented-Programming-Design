#pragma once

class Point
{
private:
    double x,y;
public:
    Point(); // function prototype
    Point(double initialX, double intitialY);
    double getX();
    double getY();
    void setX(double newX);
    void setY(double newY);
    void print();
};