/*
 * Flavia Daniels
 * Project 2: Upgraded Personal Fitness Application
 * Description:
 *   This program tracks basic health and fitness information.
 *   It stores and outputs name, gender, age, height, weight, BMI, and details about today’s exercise.
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <limits> 

using namespace std;



int main() {
    // Variables
    string name;
    char gender;
    int age;
    double height;
    double weight;
    string exerciseType;
    int exerciseTime;

    cout << "Enter your full name: ";
    getline(cin, name);

    cout << "Enter your gender (M/F): ";
    cin >> gender;
    while (gender != 'M' && gender != 'F' && gender != 'm' && gender != 'f') {
        cout << "Invalid input. Please enter M or F: ";
        cin >> gender;
    }
    if (gender == 'm') gender = 'M';
    if (gender == 'f') gender = 'F';

    cout << "Enter your age (years): ";
    cin >> age;
    while (cin.fail()|| age <= 0 || age > 120) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Please enter a number: ";
        cin >> age;
    }

    cout << "Enter your height (meters): ";
    cin >> height;
    while (cin.fail()|| height < 0.5 || height > 3.0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Please enter a number: ";
        cin >> height;
    }

    cout << "Enter your weight today (kg): ";
    cin >> weight;
    while (cin.fail()|| weight <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Please enter a number: ";
        cin >> weight;
    }

    cin.ignore(); 
    cout << "Enter your exercise type today: ";
    getline(cin, exerciseType);

    cout << "Enter your exercise time today (minutes): ";
    cin >> exerciseTime;
    while (cin.fail()|| exerciseTime < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Please enter a number: ";
        cin >> exerciseTime;
    }

    // BMI calculation
    double bmi = weight / (height * height);

    // Output
    cout << "\n--- User Information ---" << endl;
    cout << name << endl;
    cout << gender << ", " << age << ", " << fixed << setprecision(2) << height << " m" << endl;
    cout << "Weight: " << fixed << setprecision(1) << weight
         << " kg, BMI: " << fixed << setprecision(1) << bmi << " kg/m2" << endl;
    cout << "Exercise: " << exerciseType << " (" << exerciseTime << " mins)" << endl;

    return 0;
}
