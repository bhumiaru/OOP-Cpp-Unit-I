#include <iostream>                  // Includes the input-output stream library.
#include <string>                    // Includes the string class.
#include <utility>                   // Provides std::move().

// Defines the Person base class.
class Person {

protected:                           // Makes the member accessible in derived classes.

    // Stores the person's name.
    std::string name;

public:                              // Makes the following members publicly accessible.

    // Parameterized constructor of Person.
    explicit Person(std::string personName)

        // Initializes name using the supplied personName.
        : name(std::move(personName)) {}
};

// Defines Student as a derived class of Person.
class Student : public Person {

private:                             // Makes the following member private.

    // Stores the student's roll number.
    int rollNumber;

public:                              // Makes the following members publicly accessible.

    // Parameterized constructor of Student.
    Student(std::string studentName, int roll)

        // Calls the parameterized constructor of Person.
        : Person(std::move(studentName)),

          // Initializes rollNumber.
          rollNumber(roll) {}

    // Function to display student details.
    void display() const {

        // Displays the student's name.
        std::cout << "Name: " << name << '\n';

        // Displays the student's roll number.
        std::cout << "Roll Number: " << rollNumber << '\n';
    }
};

// Main function where program execution starts.
int main() {

    // Creates a Student object with name Kiran and roll number 24.
    Student student("Kiran", 24);

    // Calls the display function.
    student.display();

    // Returns 0 for successful execution.
    return 0;
}
