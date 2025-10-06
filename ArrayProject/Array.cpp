#include <iostream>
#include <iomanip> 
using namespace std;

const int COLUMNS = 3;

// Initialize matrix with user input
void initializeMatrix(int matrix[][COLUMNS], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            cout << "Enter an int: ";
            cin >> matrix[i][j];
        }
    }
}

// Calculate column sums
void calculateColumnSums(const int matrix[][COLUMNS], int rows, int columnSums[]) {
    for (int j = 0; j < COLUMNS; j++) {
        columnSums[j] = 0;
        for (int i = 0; i < rows; i++) {
            columnSums[j] += matrix[i][j];
        }
    }
}

// Find max value in an array
int maxValue(const int myArray[], int size) {
    int max = myArray[0];
    for (int i = 1; i < size; i++) {
        if (myArray[i] > max)
            max = myArray[i];
    }
    return max;
}

// Find indexes of a given value
int findIndexesOfValue(const int myArray[], int size, int value, int indexes[]) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (myArray[i] == value) {
            indexes[count] = i;
            count++;
        }
    }
    return count;
}

// Print 2D matrix in tabular format
void printMatrix(const int matrix[][COLUMNS], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// Print array elements in one line
void printArray(const int myArray[], int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(5) << myArray[i];
    }
    cout << endl;
}

// Main function to test all parts
int main() {
    const int ROWS = 2;
    int matrix[ROWS][COLUMNS];
    int columnSums[COLUMNS];
    int indexes[COLUMNS];

    initializeMatrix(matrix, ROWS);

    cout << "The matrix is:" << endl;
    printMatrix(matrix, ROWS);

    calculateColumnSums(matrix, ROWS, columnSums);

    cout << "The column sums:" << endl;
    printArray(columnSums, COLUMNS);

    int largest = maxValue(columnSums, COLUMNS);
    cout << "The largest column sum: " << largest << endl;

    int count = findIndexesOfValue(columnSums, COLUMNS, largest, indexes);
    cout << count << " column(s) having the largest sum, column index(es):" << endl;

    printArray(indexes, count);

    return 0;
}
