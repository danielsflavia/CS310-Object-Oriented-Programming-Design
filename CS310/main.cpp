#include "Course.h"

int main() {
    Course c("CS310", 4);

    cout << "Course Name: " << c.getCourseName() << endl;

    cout << "Initially enrolled students: " << c.getNumStudents() << endl;
    c.printStudents();
    cout << endl;

    // Enroll 4 students
    c.enroll("John");
    c.enroll("Kevin");
    c.enroll("Ava");
    c.enroll("Joe");

    cout << "\nAfter enrolling 4 students:" << endl;
    cout << "Number: " << c.getNumStudents() << endl;
    c.printStudents();

    // Attempt to enroll 5th student (fail)
    cout << "\nAttempting to enroll Anna:" << endl;
    c.enroll("Anna");

    cout << "Number: " << c.getNumStudents() << endl;
    c.printStudents();

    // Drop Kevin
    cout << "\nDropping Kevin:" << endl;
    c.drop("Kevin");

    cout << "Number: " << c.getNumStudents() << endl;
    c.printStudents();
}
