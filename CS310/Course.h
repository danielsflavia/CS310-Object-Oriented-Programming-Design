#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
using namespace std;

class Course {
private:
    string name;
    string* students;
    int numStudents;
    int capacity;

public:
    Course(const string& name, int capacity);

    // Deep copy constructor
    Course(const Course& other);

    // Deep copy assignment operator
    Course& operator=(const Course& other);

    // Destructor
    ~Course();

    string getCourseName() const;
    void enroll(const string& studentName);
    void drop(const string& studentName);
    void printStudents() const;
    int getNumStudents() const;
};

#endif
