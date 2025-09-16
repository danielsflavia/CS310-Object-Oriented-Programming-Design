/*
 * Flavia Daniels
 * Programming Exercise with Ziv and Chris
 */
#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter a number between 100 and 999: "<< endl;
    cin >> num;

    int hundreds = num / 100;         // First digit
    int tens = (num / 10) % 10;       // Second digit
    int ones = num % 10;              // Third digit

    // Print digits separated by spaces
    cout << "Digits: " << hundreds << " " << tens << " " << ones << endl;

    // Compute sum
    int sum = hundreds + tens + ones;
    cout << "Sum of digits: " << sum << endl;

    // Check divisibility by 3 using conditional operator
    cout << "Divisible by 3? " 
         << ((sum % 3 == 0) ? "Yes" : "No") << endl;

    return 0;

}