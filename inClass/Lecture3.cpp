#include <iostream>
#include <string> // for getline
using namespace std;

int main()
{
    int x, y;
    cout<<(x =2) << endl;
    y = x;
    y *= 2 + x;
    cout << "y expect as 8: " << y << endl;

    int counter = 0;
    counter++;
    cout<< "Expect 1: " << counter << endl;
    --counter; 
    cout << "Decrease by 1: " << counter << endl;

    int size = 2* (counter++);
    cout << "post increment: " <<size<< ", counter increased: "
        << counter << endl;

    size = static_cast<int>(1.23);
    cout << "size expect as 1: " << size << endl;

    int absResult = size >= 0 ? size : -1 * size;
    // if(size<0) absResult=1*size;

    string message;
    cout << "Enter a greeting: ";
    getline(cin, message);
    cout<< message << endl;
    cout<< "Enter your age: ";
    int age;
    cin >> age;
    cout<< "Extraction successful? " << boolalpha 
        << cin.fail() << endl;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cout << "Age is " << age << endl;

    //try second input
    cin >> age;
    cout << "Will age get. a new value? "
        << age << endl;
    

}