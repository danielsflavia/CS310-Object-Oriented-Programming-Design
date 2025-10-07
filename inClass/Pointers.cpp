#include <iostream>

using namespace std;

void swapByPointer(int* pA, int* pB) {
    int temp = *pA;
    *pA = *pB;
    *pB = temp;
}

int main() {
    int a =5;
    int grades[3]={100,80,50};
    //address operators &
    cout<< "a is at "<< &a << endl;
    cout << "first element of grades is at "
    << grades << '\t'
    << &grades[0] << '\t'
    << endl;
    // declare int pointer to hold int address
    int* pInt=&a;
    //* indirection operator to deference
    cout<<a<< '\t'<< *pInt<<endl;

    *pInt =10;
    cout<< "a is changed to 20, a= "
     << a<< endl;

    // make pInt pointing to the grades array
    pInt = grades;
    cout << "first grade: " << *pInt << endl;

    // null pointer 
    pInt = nullptr; //NULL;

    // try to deference null pointer
    if(pInt!=nullptr)
    cout<< * pInt << endl;

    // type of pointer needs to be matched with the type of var 
    double balance = 100;
    double* pDouble = &balance; 


    int* pA, *pB;
    int c = 2, b = 3;


    swapByPointer(&c, &b);
    cout<< "c and b are swapped, c="
        << c << ",b="<< b<<endl;
        
    pA = &c;
    pB = &b;

    pA = pB;

    cout<< "a,b stayed thr saqme , c= "
        << c << ",b " << b << endl;
    cout << "pA points to " << *pA  
        << ", pB points to "<< *pB << endl;

    cout << grades << '\t' << grades << endl;
    cout<< grades+1
        << '\t'<< *(grades+1)
        << endl;

    pInt = grades;
    pInt++;



    return 0;

    
}