
#include <iostream>
using namespace std;

void printArray(int grades[], int size) 
{
    for(int i=0; i<size; i++)
    {
        cout << grades[i]<< " ";
        // cout<< *(grades+i);
    }

}

int* reverse(const int* original, int size)
{
    int* result = new int[size];
    for(int i=0, j=size -1; i < size; i++, j--)
    {
        result[j] = original[i];
    }
    return result;
}


int main() 
{
    int grades[3] = { 100, 90, 80 };
    int* pInt = grades;
    cout << "1st element: "<< pInt[0] << endl;
    pInt += 2;
    cout << "now pInt points the 3rd element: "
        << *pInt << endl;
    cout << "# of ints between two addresses: "
        << pInt - grades << endl;

    printArray(grades, 3);
    cout << "* over +: " << *grades + 1<< endl;
    cout << "2nd element value: "
        << *(grades + 1) << endl;

    // new: dynamically allocated array
    int size = 5;
    int* p = new int [size];
    for (int i=0; i < size; i++)
    {
        cout << "What's your grade? ";
        cin >> p[i];
    }
    printArray(p, size);


    int* result = reverse(p, size);
    printArray(result, size);
    delete[] result;
    result = nullptr;
    //once it is completed,, release memory
    delete[] p;
    p = nullptr;
    //create dynamic object
    string* dynamicStr = new string();
    //delete an individual variable
    delete dynamicStr;


    return 0;
}