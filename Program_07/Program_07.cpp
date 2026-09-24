#include <iostream>  // Includes the input/output library, needed for cout

using namespace std;  // Allows us to use cout without writing std::cout

// Defines a class named Student
class Student
{
public:

    // Declares a static variable named count
    // Only one copy of count is shared by all Student objects
    static int count;

    // Constructor of the Student class
    Student()
    {
        // Increases count by 1 whenever a Student object is created
        count++;
    }
};

// Defines and initializes the static variable count
// Initially, count is set to 0
int Student::count = 0;

// Main function: program execution starts here
int main()
{
    // Creates three Student objects
    Student s1, s2, s3;

    // s1 is created -> count = 1
    // s2 is created -> count = 2
    // s3 is created -> count = 3

    // Prints the value of count
    cout << Student::count;

    // Ends the program successfully
    return 0;
}
