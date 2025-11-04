/*
 * Flavia Daniels
 * Project 5: Fitness Tracker with Dynamic Arrays
 * Description:
 *   This program tracks and stores an unlimited number of days of fitness data.
 *   It records and displays name, gender, age, height, weight, BMI, exercise type, and exercise time.
 *   The program uses functions, dynamic arrays, and no structures or vectors.
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

// Function Template getInput
template <typename T>
T getInput(const string& prompt, T minVal, T maxVal) {
    T value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value < minVal || value > maxVal) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid value." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

// getInput for string. ensures that the user provides a non-empty string
template <>
string getInput<string>(const string& prompt, string minVal, string maxVal) {
    string value;
    cout << prompt;
    getline(cin, value);
    while (value.empty()) {
        cout << "Invalid input. Please enter a non-empty string." << endl;
        cout << prompt;
        getline(cin, value);
    }
    return value;
}

// Function Template resizeArray

template <typename T>
void resizeArray(T*& arr, int oldCapacity, int newCapacity) {
    T* newArr = new T[newCapacity];
    for (int i = 0; i < oldCapacity; ++i) {
        newArr[i] = arr[i];
    }
    delete[] arr;  // deletes the old array
    arr = newArr;  // updates pointer to the new array
}

// Function declarations
void getBasicInfo(string& name, char& gender, int& age, double& height);
void printMenu();
int getOption();
void inputData(double*& weights, string*& exercises, int*& times, int& count, int& capacity);
void printRecentData(const string& name, char gender, int age, double height,
                     const double weights[], const string exercises[], const int times[], int count);
void printHistoryData(const string& name, char gender, int age, double height,
                      const double weights[], const string exercises[], const int times[], int count);
double calculateBMI(double weight, double height);
int calculateTotalExercise(const int times[], int count);

// main
int main() {
    int capacity = 7;  // initial capacity for dynamic arrays
    int count = 0;  // current number of fitness records

    // Dynamic array
    double* weights = new double[capacity];
    string* exercises = new string[capacity];
    int* times = new int[capacity];

    string name;
    char gender;
    int age;
    double height;

    // gets user basic info
    getBasicInfo(name, gender, age, height);

    //menu
    int option;
    do {
        printMenu();
        option = getOption();

        switch (option) {
            case 1:
                inputData(weights, exercises, times, count, capacity);
                break;
            case 2:
                printRecentData(name, gender, age, height, weights, exercises, times, count);
                break;
            case 3:
                printHistoryData(name, gender, age, height, weights, exercises, times, count);
                break;
            case 4:
                cout << "Exiting the Program." << endl;
                break;
        }
    } while (option != 4);

    // free dynamically allocated memory
    delete[] weights;
    delete[] exercises;
    delete[] times;

    return 0;
}

// Function definitions 

void getBasicInfo(string& name, char& gender, int& age, double& height) {
    name = getInput<string>("Enter your full name: ", "", "");
    gender = getInput<char>("Enter your gender (M/F): ", 'A', 'z');
    while (gender != 'M' && gender != 'F' && gender != 'm' && gender != 'f') {
        cout << "Invalid input. Please enter M or F: ";
        cin >> gender;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (gender == 'm') gender = 'M';
    if (gender == 'f') gender = 'F';

    age = getInput<int>("Enter your age (years): ", 1, 120);
    height = getInput<double>("Enter your height (meters): ", 0.5, 3.0);
}

void printMenu() {
    cout << "\n--- Fitness Menu ---" << endl;
    cout << "1. Add Data" << endl;
    cout << "2. Recent Data" << endl;
    cout << "3. History Data" << endl;
    cout << "4. Exit" << endl;
}

int getOption() {
    int option;
    while (true) {
        cout << "Select an option: ";
        cin >> option;
        if (cin.fail() || option < 1 || option > 4) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "The selected option is invalid." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return option;
        }
    }
}

void inputData(double*& weights, string*& exercises, int*& times, int& count, int& capacity) {
    double newWeight = getInput<double>("Enter your weight today (kg): ", 1.0, 500.0);
    string newExercise = getInput<string>("Enter your exercise type today: ", "", "");
    int newTime = getInput<int>("Enter your exercise time today (mins): ", 0, 1440);

    // Resize if full
    if (count == capacity) {    
        int oldCapacity = capacity;
        int newCapacity = capacity * 2;

        // Resize using old capacity → new capacity
        resizeArray(weights, oldCapacity, newCapacity);
        resizeArray(exercises, oldCapacity, newCapacity);
        resizeArray(times, oldCapacity, newCapacity);

        // Update capacity only once 
        capacity = newCapacity;
    }

    weights[count] = newWeight;
    exercises[count] = newExercise;
    times[count] = newTime;
    count++;

    cout << "Data is recorded successfully" << endl;
}

void printRecentData(const string& name, char gender, int age, double height,
                     const double weights[], const string exercises[], const int times[], int count) {
    if (count == 0) {
        cout << "There is no fitness data to print." << endl; //If no data is available, displays a message instead.
        return;
    }

    double bmi = calculateBMI(weights[count - 1], height);

    cout << "\nUser Information: " << endl;
    cout << name << endl;
    cout << gender << ", " << age << ", " << fixed << setprecision(2) << height << " m" << endl;
    cout << "Weight: " << fixed << setprecision(1) << weights[count - 1]
         << " kg, BMI: " << fixed << setprecision(1) << bmi << " kg/m2" << endl;
    cout << "Exercise: " << exercises[count - 1]
         << " (" << times[count - 1] << " mins)" << endl;
}

// Prints all fitness records from most recent to oldest
void printHistoryData(const string& name, char gender, int age, double height,
                      const double weights[], const string exercises[], const int times[], int count) {
    if (count == 0) {
        cout << "There is no fitness data to print." << endl;
        return;
    }

    cout << "\nUser Information: " << endl;
    cout << name << endl;
    cout << gender << ", " << age << ", " << fixed << setprecision(2) << height << " m" << endl;

    cout << "\nFitness History (Most Recent to Oldest):\n" << endl;

    for (int i = count - 1; i >= 0; i--) {
        double bmi = calculateBMI(weights[i], height);
        cout << "Day " << (count - i) << ":" << endl;
        cout << "  Weight: " << fixed << setprecision(1) << weights[i]
             << " kg, BMI: " << fixed << setprecision(1) << bmi << " kg/m2" << endl;
        cout << "  Exercise: " << exercises[i]
             << " (" << times[i] << " mins)" << endl;
        cout << "-------------------------------------" << endl;
    }

    // Calculates progress summary
    double firstBMI = calculateBMI(weights[0], height);
    double lastBMI = calculateBMI(weights[count - 1], height);
    double bmiChange = lastBMI - firstBMI;
    int totalExercise = calculateTotalExercise(times, count);

    cout << fixed << setprecision(1);
    cout << "\nProgress Summary:" << endl;
    cout << "  BMI Change: " << bmiChange << " ("
         << (bmiChange > 0 ? "increase" : (bmiChange < 0 ? "decrease" : "no change")) << ")" << endl;
    cout << "  Total Exercise Time: " << totalExercise << " mins" << endl;
}

double calculateBMI(double weight, double height) {
    return weight / (height * height);
}

int calculateTotalExercise(const int times[], int count) {
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += times[i];
    }
    return total;
}
