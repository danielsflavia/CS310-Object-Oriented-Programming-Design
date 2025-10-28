#include <iostream>
using namespace std;


void initialize(int* array, int size, int value)
{
    for (int i=0; i< size; i++)
    {
        array[i] = value;
    }
}

void print(int* array, int size) 
{
    for (int i=0; i< size; i++)
    {
        cout << array[i] << ' ';
    }
    cout << endl; 
}
int* appendElement(int array[], int& size, int value)
{
    int* newArray = new int [size+1];
    for(int i=0; i<size; i++)
    {
        newArray[i]= array[i];
    }
    newArray[size] = value;
    size++;
    delete[] array;
    return newArray;
}
int* insertElement(int* array, int& size, int value, int index)
{
    if(index<0 || index> size)
    {
        return array;
    }

    int* newArray= new int[size+1];
    for(int i=0; i<index; i++)
    {
        newArray[i]= array[i];
    }
    newArray[index] = value;
    for (int i= index; i<size; i++)
    {
        newArray[i + 1]= array[i];
    }
    delete[] array;
    size++;
    return newArray;

}
int* deleteElement(int* array, int& size, int index)
{
    if(index<0|| index>= size)
    {
        return array;
    }
    if(size==1)
    {
        delete[] array;
        return nullptr;
    }

    int* newArray = new int[size-1];
    for(int i=0; i<index; i++)
    {
        newArray[i]=array[i];
    }
    for(int i=index+1; i<size; i++)
    {
        newArray[i-1]=array[i];
    }
    delete[] array;
    size--;
    return newArray;

}

int main() 
{
    cout<< "enter list size: ";
    int size;
    cin >> size;
    int* A = new int[size];
    int value=0;
    cout<< "Intiital value for all elements int he list ";
    cin >> value;
    initialize(A, size, value);
    cout<< "all elements initialized as " << value << endl;
    print(A, size);
    int newValue =0;

}