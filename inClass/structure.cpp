#include <iostream>
#include <string>
using namespace std;

struct Student 
{
    int id;
    string name;
    string major;
    double gpa;
};

void printStudent(const Student& stu)
{
    cout<< stu.name<< ", id: "<< stu.id<< ", majoring in "<< stu.major<<", GPA: "
    << stu.gpa<< endl;
}
void UpdateGPA(Student& stu, double newGPA)
{
    stu.gpa = newGPA;
}
int main()
{
    Student jenna = {1, "Jenna", "CS", 4.0};
    cout<<"id: "<< jenna.id << endl;
    cout<<"var jenna is at "<< &jenna<< endl;
    cout << "1st field, id is at "<< &(jenna.id)<< endl;
    cout<< "2nd field, name is at "<< &jenna.name<< endl;
    printStudent(jenna);
    UpdateGPA(jenna, 3.8);
    printStudent(jenna);    


}