#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    const int TOTAL_PRIMES = 50;
    const int NUM_FOR_LINE = 10;

    int count =0;
    int number = 2;

    while(count <= TOTAL_PRIMES) {
        bool prime = true;
        for(int i = 2; i * i <= number; i++){
            if(number % i==0) {
                prime = false;
                break;
            }
        }

    if(prime) {
        cout << setw(5) << number;
        count++;
    if (count % NUM_FOR_LINE == 0) {
                cout << endl;  
            }
    }
    number++;
    }   

    return 0;

}
