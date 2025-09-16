#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    cout<<"Hello!\n";
    cout<<"Hello C++";
    cout<< endl;
    cout<< 3.14;
    cout<< endl<< "Welcome!\n"<<"CS310\n";
    //declare Variables
    char letter; //declare Variable
    letter = 'A'; //assign Value

    bool isTrue = true;
    cout<<"default output for bool values: "
        << isTrue << endl;
    isTrue = false;

    short int age = 0; 
    int members = 10;

    double pi = 3.14;
    cout<<"default floating point value: "
        <<pi << endl;
    cout<<fixed<<setprecision(4)<<pi<<endl;
    cout<< "print false: "
        << boolalpha << isTrue << endl;

    cout<< "# of bytes for an int: "
        << sizeof(int) << '\t' << sizeof(members)
        << endl;

    int op1(2); //initialize opl as 2
    cout<< "initialize as 2: " << op1 << endl;

    string message("Hello"); //more efficient
    string secondMessage = "";
    //standard inout from keyboard
    cin >> secondMessage;
    cout<<"You have inputted " << secondMessage
        << endl;

    int op2 = 0;
    cout<<"Enter two ints: ";
    cin >> op1 >> op2;
    cout<< "sum: "<< op1+op2 << endl;
    cout<<"integer division: "
        <<op1 / op2 << endl;
    cout<<"real value division: "
        <<(double)op1/op2 << endl;
    cout<< "% operator: "<< op1 % op2 << endl;


    return 0;
}