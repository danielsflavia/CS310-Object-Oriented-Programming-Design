/*
 * Flavia Daniels
 * Project 6: Fitness Tracker Using Structures
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

// Represents one day of fitness information
struct FitnessRecord {
    double weight;
    string exerciseType;
    int exerciseTime;
};

// Represents user info + dynamic array of records
struct User {
    string name;
    char gender;
    int age;
    double height;

    FitnessRecord* history;  // dynamic array of records
    int count;               // number of used elements
    int capacity;           
};

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

// getInput for string (non-empty)
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


void resizeArray(FitnessRecord*& arr, int oldCapacity, int newCapacity) {
    FitnessRecord* newArr = new FitnessRecord[newCapacity];
    for (int i = 0; i < oldCapacity; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
}


void getBasicInfo(User& user);
void printMenu();
int getOption();
void inputData(User& user);
void printRecentData(const User& user);
void printHistoryData(const User& user);
double calculateBMI(double weight, double height);
int calculateTotalExercise(const User& user);


int main() {
    User user;

    // initialize dynamic array
    user.capacity = 7;
    user.count = 0;
    user.history = new FitnessRecord[user.capacity];

    getBasicInfo(user);

    int option;
    do {
        printMenu();
        option = getOption();

        switch (option) {
            case 1: inputData(user); break;
            case 2: printRecentData(user); break;
            case 3: printHistoryData(user); break;
            case 4: cout << "Exiting the Program." << endl; break;
        }
    } while (option != 4);

    delete[] user.history;
    return 0;
}


void getBasicInfo(User& user) {
    user.name = getInput<string>("Enter your full name: ", "", "");
    user.gender = getInput<char>("Enter your gender (M/F): ", 'A', 'z');

    while (user.gender != 'M' && user.gender != 'F' &&
           user.gender != 'm' && user.gender != 'f') {
        cout << "Invalid input. Please enter M or F: ";
        cin >> user.gender;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (user.gender == 'm') user.gender = 'M';
    if (user.gender == 'f') user.gender = 'F';

    user.age = getInput<int>("Enter your age (years): ", 1, 120);
    user.height = getInput<double>("Enter your height (meters): ", 0.5, 3.0);
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

void inputData(User& user) {
    // Resize if full
    if (user.count == user.capacity) {
        int oldCap = user.capacity;
        int newCap = oldCap * 2;
        resizeArray(user.history, oldCap, newCap);
        user.capacity = newCap;
    }

    FitnessRecord& r = user.history[user.count];

    r.weight = getInput<double>("Enter your weight today (kg): ", 1.0, 500.0);
    r.exerciseType = getInput<string>("Enter your exercise type today: ", "", "");
    r.exerciseTime = getInput<int>("Enter your exercise time today (mins): ", 0, 1440);

    user.count++;
    cout << "Data is recorded successfully" << endl;
}

void printRecentData(const User& user) {
    if (user.count == 0) {
        cout << "There is no fitness data to print." << endl;
        return;
    }

    const FitnessRecord& r = user.history[user.count - 1];
    double bmi = calculateBMI(r.weight, user.height);

    cout << "\nUser Information: " << endl;
    cout << user.name << endl;
    cout << user.gender << ", " << user.age << ", " << fixed << setprecision(2) 
         << user.height << " m" << endl;
    cout << "Weight: " << fixed << setprecision(1) << r.weight
         << " kg, BMI: " << bmi << " kg/m2" << endl;
    cout << "Exercise: " << r.exerciseType << " (" << r.exerciseTime << " mins)" << endl;
}

void printHistoryData(const User& user) {
    if (user.count == 0) {
        cout << "There is no fitness data to print." << endl;
        return;
    }

    cout << "\nUser Information: " << endl;
    cout << user.name << endl;
    cout << user.gender << ", " << user.age << ", " << fixed << setprecision(2) 
         << user.height << " m" << endl;

    cout << "\nFitness History (Most Recent to Oldest):\n" << endl;

    for (int i = user.count - 1; i >= 0; i--) {
        const FitnessRecord& r = user.history[i];
        double bmi = calculateBMI(r.weight, user.height);

        cout << "Day " << (user.count - i) << ":\n";
        cout << "  Weight: " << fixed << setprecision(1) << r.weight
             << " kg, BMI: " << bmi << " kg/m2" << endl;
        cout << "  Exercise: " << r.exerciseType 
             << " (" << r.exerciseTime << " mins)\n";
        cout << "-------------------------------------" << endl;
    }

    double firstBMI = calculateBMI(user.history[0].weight, user.height);
    double lastBMI = calculateBMI(user.history[user.count - 1].weight, user.height);
    double change = lastBMI - firstBMI;
    int total = calculateTotalExercise(user);

    cout << "\nProgress Summary:\n";
    cout << "  BMI Change: " << change << " ("
         << (change > 0 ? "increase" : (change < 0 ? "decrease" : "no change"))
         << ")\n";
    cout << "  Total Exercise Time: " << total << " mins\n";
}

double calculateBMI(double weight, double height) {
    return weight / (height * height);
}

int calculateTotalExercise(const User& user) {
    int total = 0;
    for (int i = 0; i < user.count; i++)
        total += user.history[i].exerciseTime;
    return total;
}
