#include "circle.h"
#include <iostream>
using namespace std;

Circle::Circle()
{
    radius = 0;
}
Circle::Circle(double initialR, Point& c)
{
    radius =initialR>0? initialR : 0;
    center = c;
}

double Circle::getRadius()
{
    return radius;
}

Point Circle::getCenter()
{
    return center;
}

void Circle::setRadius(double newR)
{
    radius = newR > 0 ? newR : radius;
}
void Circle::move(Point& newC)
{
    center = newC;
}
void Circle::move(double deltaX, double deltaY)
{
    double currentX = center.getX();
    double currentY = center.getY();
    center.setX(currentX + deltaX);
    center.setY(currentY + deltaY);

}
void Circle::print()
{
    cout << "Circle at ";
    center.print();
    cout << ", radius: " << radius << endl;
}

bool Circle::operator==(Circle& other)
{
    if (this-> radius == other.radius)
        return true;
    else
        return false;
}
Circle::~Circle()
{
    cout<< "Object deleted";
}