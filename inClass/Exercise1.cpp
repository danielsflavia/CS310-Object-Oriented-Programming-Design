#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

    int positiveInt = 0;
    cout << "Enter a value: ";
    cin >> positiveInt;
    int counter = 0;
    for(int divisor=2; divisor<positiveInt;divisor++)
    {
        if(positiveInt%divisor==0)
        {
            counter++;
            if(counter>=1)
                break;
                cout<<positiveInt << " is not a prime" << endl;
        }
    }

    cout << "Your numerical grade: ";
    int grade;
    cin >> grade;
    
    while (cin.fail()||grade<0||grade>100)
    {
        if(cin.fail())
        {
        cin.clear();
        cin.ignore(1000, '\n');
        }
        cout << "Not a valid grade, try again: ";
        cin >> grade;
    }
    char letter;
    if(grade >= 90)
    {
        letter = 'A';
    }
    else if(grade >= 80)
    {
        letter = 'B';
    }
    else if(grade>=70)
    {
        letter = 'C';
    }
    else
    {
        letter = 'F';
    }
    cout << "Your numerial grade is " <<grade
        << ", letter grade is " << letter << endl;

    double gpa = 0;
    switch(letter)
    {
    case 'A': 
        gpa = 4.0;
        break;
    case 'B':
        gpa = 3.0;
        break;
    case 'C':
        gpa = 2.0;
        break;
    default:
        gpa = 0;
        break;
    }

    cout << "your GPA is " << gpa <<endl;

    const double PI = acos(-1);
    int degrees = 30;

    cout << left << setw(15) << "Degrees"
         << setw(15) << "Radians"
         << setw(15) << "Sine" 
         << setw(15) << "Cosine" 
         << setw(15) << "Tangent" << endl;

    cout << string(70, '-') << endl;

    for (int degrees = 30; degrees <= 180; degrees += 30) {
    double radians = degrees * PI / 180;
    double sines = sin(radians);
    double cosines = cos(radians);
    double tangents = tan(radians);
     
    cout << left << setw(15) << fixed << setprecision(4) << degrees
         << setw(15) << radians
         << setw(15) << sines
         << setw(15) << cosines
         << setw(15) << tangents << endl;

         degrees += 30;
         }
    return 0;
}