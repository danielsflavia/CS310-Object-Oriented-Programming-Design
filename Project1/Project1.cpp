/*
 * Flavia Daniels
 * Project 1: Personal Fitness Application
 * Description:
 *   This program tracks basic health and fitness information.
 *   It stores and outputs name, gender, age, height, weight, BMI, and details about today’s exercise.
 */

#include <iostream>
#include <string>
#include <iomanip> 

using namespace std;

int main() {
    // Variables
    string name = "Flavia Daniels";    
    char gender = 'F';             
    int age = 20;
    double height = 1.82;            // in meters
    double weight = 73.0;            // in kg
    string exerciseType = "Track and Field practice";
    int exerciseTime = 120;           // in minutes

    // BMI calculation
    double bmi = weight / (height * height);

    // Output
    cout << name << endl;
    cout << gender << ", " << age << ", " << fixed << setprecision(2) << height << " m" << endl;
    cout << "Weight: " << fixed << setprecision(1) << weight 
         << " kg, BMI: " << fixed << setprecision(1) << bmi << " kg/m2" << endl;
    cout << "Exercise: " << exerciseType << " (" << exerciseTime << " mins)" << endl;

    return 0;
}
