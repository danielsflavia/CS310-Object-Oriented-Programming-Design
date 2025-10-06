// Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

template <typename T>
void copyArray(const T original[], T copy[], int size)
{
	for (int i = 0; i < size; i++)
	{
		copy[i] = original[i];
	}
}

template <typename T>
void printArray(const T array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << ' ';
	}
	cout << endl;
}

void passArgByValue(int array[], int value)
{
	array[0] = 1000;
	value = 1000;
}

void reverse(const int original[], int reversal[], int size)
{
	for(int i=0, j=size-1; i<size; i++, j--)
	{
		reversal[j] = original[i];
	}
}

void reverse(int original[], int size)
{
	for(int i=0, j=size-1; i<size/2; i++, j--)
	{
		int temp= original[i];
		original[j] = original[j];
		original[j] = temp;
	}
}

void printArray(int matrix[][2], int rows)
{
	for(int i=0; i<rows; i++)
	{
		for(int c=0; c<2; c++)
		{
			cout<< matrix[i][c]<<' ';
		}
		cout << endl;
	}
}

int main()
{
  //int array
	const int SIZE = 5;
	int grades[SIZE] = {100, 100, 100, 100,100};

	int test = 0;
	passArgByValue(grades, test);
	cout<< "Expect grades[0]=1000, test=0: "
		<< grades[0] << '\t' << test << endl;

	int results[SIZE];
	reverse(grades, results, SIZE);
	printArray(results, SIZE);

	//overload reverse
	reverse(grades, SIZE);
	printArray(grades, SIZE);

	const int assignments =2;
	int gradeBook[SIZE][assignments] = {};
	/*
			{100,0},
			{50, 0},
			{80, 0},
			{70, 0}						
	};*/
	printArray(gradeBook, SIZE);

	for(int c=0; c<2; c++) {
	double firstColumn = 0;
	for(int r=0; r<SIZE; r++)
	{
		firstColumn += gradeBook[r][c];
	}
	cout << "Average: "<< firstColumn /SIZE << endl;
	}
	/*
	for (int i=0; i<SIZE; i++)
	{
		printArray(gradeBook[i], assignments);
	}
	*/

	//intialize elements with 0
	for (int i = 0;i < SIZE; i++)
	{
		grades[i] = 0;
	}
	cout << "Last element:" << grades[SIZE - 1];
	cout << "\n Starting address: " << grades << endl;
	//copy
	int copy[SIZE];
	//copy = grades; //array name is a constant
	copyArray(grades, copy, SIZE);
	printArray(copy, SIZE);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
