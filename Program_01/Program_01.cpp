#include <iostream> // #include adds a library, iostream is used for input and output

using namespace std; // using allows us to use standard C++ commands like cout

int main() { // int means the function returns an integer, main is where the program starts

    int roll = 101; // int stores a whole number, roll is the variable name, 101 is its value

    char grade = 'A'; // char stores one character, grade is the variable name, 'A' is its value

    float fee = 12500.50; // float stores decimal numbers, fee is the variable name, 12500.50 is its value

    cout << "Roll No: " << roll << endl;
    // cout displays output
    // << sends information to the screen
    // "Roll No: " is the text displayed
    // roll displays the value stored in roll
    // endl moves to the next line

    cout << "Grade: " << grade << endl;
    // Displays the text "Grade: " and the value of grade

    cout << "Fee: " << fee << endl;
    // Displays the text "Fee: " and the value of fee

    return 0; // return ends the program, 0 means the program ran successfully
}

