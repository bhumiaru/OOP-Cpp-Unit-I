#include <iostream>          // Includes input/output library
using namespace std;         // Uses standard namespace

int add(int, int);           // Declares add function

int main() {                 // Main function starts
    int a = 10, b = 20;      // Declares and initializes variables
    cout << "Sum = " << add(a, b) << endl;  // Calls add and displays result
    return 0;                // Ends program successfully
}

int add(int x, int y) {      // Defines add function
    return x + y;            // Returns sum of x and y
}

