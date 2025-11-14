#include "Course.h"

// Constructor
Course::Course(const string& name, int capacity) {
    this->name = name;
    this->capacity = capacity;
    this->numStudents = 0;
    this->students = new string[capacity];
}

// Deep Copy Constructor
Course::Course(const Course& other) {
    name = other.name;
    capacity = other.capacity;
    numStudents = other.numStudents;

    students = new string[capacity];  // allocate new array
    for (int i = 0; i < numStudents; i++) {
        students[i] = other.students[i];   // deep copy student names
    }
}

// Deep Copy Assignment Operator
Course& Course::operator=(const Course& other) {
    if (this == &other) return *this; // self-assignment check

    delete[] students;  // delete old memory

    name = other.name;
    capacity = other.capacity;
    numStudents = other.numStudents;

    students = new string[capacity];
    for (int i = 0; i < numStudents; i++) {
        students[i] = other.students[i];
    }

    return *this;
}

// Destructor
Course::~Course() {
    delete[] students;
}

string Course::getCourseName() const {
    return name;
}

void Course::enroll(const string& studentName) {
    if (numStudents >= capacity) {
        cout << "Cannot enroll " << studentName << ": course full." << endl;
        return;
    }
    students[numStudents++] = studentName;
}

void Course::drop(const string& studentName) {
    int index = -1;

    for (int i = 0; i < numStudents; i++) {
        if (students[i] == studentName) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << studentName << " is not enrolled in the course." << endl;
        return;
    }

    // Shift left to remove the student
    for (int i = index; i < numStudents - 1; i++) {
        students[i] = students[i + 1];
    }

    numStudents--;
}

void Course::printStudents() const {
    if (numStudents == 0) {
        cout << "No students enrolled." << endl;
        return;
    }

    cout << "Students enrolled: ";
    for (int i = 0; i < numStudents; i++) {
        cout << students[i];
        if (i < numStudents - 1) cout << ", ";
    }
    cout << endl;
}

int Course::getNumStudents() const {
    return numStudents;
}
