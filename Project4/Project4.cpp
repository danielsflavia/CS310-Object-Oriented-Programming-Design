/*
 * Flavia Daniels
 * Project 4: Fitness Tracker
 * Description:
 *   This program tracks and stores up to 7 days of fitness data.
 *   It records and displays name, gender, age, height, weight, BMI, exercise type, and exercise time.
 *   The program uses functions, fixed-size arrays, and no global variables.
 */


 #include <iostream>
 #include <string>
 #include <iomanip>
 #include <limits>

 using namespace std;

 // FUcntion Template getInput

 template <typename T>
T getInput(const string& prompt, T minVal, T maxVal) {
    T value;
    while(true){
        cout << prompt;
        cin >> value;
        if(cin.fail() || value < minVal || value > maxVal) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid value." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

template <>
string getInput<string>(const string& prompt, string minVal, string maxVal) {
    string value;
    cout << prompt;
    getline(cin, value);
    while(value.empty()) {
        cout << "Invalid input. Please enter a non-empty string." << endl;
        cout << prompt;
        getline(cin, value);
    }
    return value;
}

struct BasicInfo {
    string name;
    char gender;
    int age;
    double height;
};

struct FitnessData {
    double weight;
    string exerciseType;
    int exerciseTime;
};

// functions declared
BasicInfo getBasicInfo();
void printMenu();
int getOption();
void addData(FitnessData data[], int& count, int maxSize);
void printRecentData(const BasicInfo& info, const FitnessData data[], int count);
void printHistoryData(const BasicInfo& info, const FitnessData data[], int count);
double calculateBMI(double weight, double height);

// main

int main() {
    const int MAX_DAYS = 7;
    FitnessData weekData[MAX_DAYS];
    int count = 0;

    BasicInfo user = getBasicInfo();

    int option;
    do {
        printMenu();
        option = getOption();

        switch(option) {
            case 1:
                addData(weekData, count, MAX_DAYS);
                break;
            case 2:
                printRecentData(user, weekData, count);
                break;
            case 3:
                printHistoryData(user, weekData, count);
                break;
            case 4:
                cout << "Exiting the Program."<< endl;
                break;
        }
    } while (option != 4);
    return 0;
}

// Function definitions

BasicInfo getBasicInfo() {
    BasicInfo info;

    info.name = getInput<string>("Enter your full name: ", "", "");
    info.gender = getInput<char>("Enter your gender (M/F): ", 'A', 'z');
    while (info.gender != 'M' && info.gender != 'F' && info.gender != 'm' && info.gender != 'f') {
        cout << "Invalid input. Please enter M or F: ";
        cin >> info.gender;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (info.gender == 'm') info.gender = 'M';
    if (info.gender == 'f') info.gender = 'F';

    info.age = getInput<int>("Enter your age (years): ", 1, 120);
    info.height = getInput<double>("Enter your height (meters): ", 0.5, 3.0);

    return info;
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


void addData(FitnessData data[], int& count, int maxSize) {
    FitnessData newData;
    newData.weight = getInput<double>("Enter your weight today (kg): ", 1.0, 500.0);
    newData.exerciseType = getInput<string>("Enter your exercise type today: ", "", "");
    newData.exerciseTime = getInput<int>("Enter your exercise time today (mins): ", 0, 1440);

    // Shift data if there is 7 entries
    if (count == maxSize) {
        for (int i = 1; i < maxSize; i++) {
            data[i - 1] = data[i];
        }
        data[maxSize - 1] = newData;
    } else {
        data[count] = newData;
        count++;
    }

    cout << "Data is recorded successfully" << endl;
}

void printRecentData(const BasicInfo& info, const FitnessData data[], int count) {
    if (count == 0) {
        cout << "There is no fitness data to print." << endl;
        return;
    }

    const FitnessData& recent = data[count - 1];
    double bmi = calculateBMI(recent.weight, info.height);

    cout << "\nUser Information: " << endl;
    cout << info.name << endl;
    cout << info.gender << ", " << info.age << ", "
         << fixed << setprecision(2) << info.height << " m" << endl;
    cout << "Weight: " << fixed << setprecision(1) << recent.weight
         << " kg, BMI: " << fixed << setprecision(1) << bmi << " kg/m2" << endl;
    cout << "Exercise: " << recent.exerciseType << " (" << recent.exerciseTime << " mins)" << endl;
}

void printHistoryData(const BasicInfo& info, const FitnessData data[], int count) {
    if (count == 0) {
        cout << "There is no fitness data to print." << endl;
        return;
    }

    cout << "\n-User Information: " << endl;
    cout << info.name << endl;
    cout << info.gender << ", " << info.age << ", "
         << fixed << setprecision(2) << info.height << " m" << endl;

    cout << "\nFitness History (From mots Recent to Oldest):" << endl;
    for (int i = count - 1; i >= 0; i--) {
        double bmi = calculateBMI(data[i].weight, info.height);
        cout << "Day " << (count - i) << ": "
             << "Weight: " << fixed << setprecision(1) << data[i].weight
             << " kg, BMI: " << fixed << setprecision(1) << bmi
             << ", Exercise: " << data[i].exerciseType
             << " (" << data[i].exerciseTime << " mins)" << endl;
    }
}

double calculateBMI(double weight, double height) {
    return weight / (height * height);
}