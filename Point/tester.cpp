#include "point.h"
#include "circle.h"
#include <iostream>
using namespace std;

int main()
{
    Circle c1;
    c1.print();
    c1.setRadius(100);
    c1.move(2,3);
    c1.print();
    Point newCenter(100, 200);
    c1.move(newCenter);
    c1.print();


    Circle* p=new Circle(); //call no-arg constructor
    p-> print();
    cout<< "if thwo circles =? "<< boolalpha
        << (c1 == *p) << endl;
    delete p;

}