#include <iostream>                  // Includes the input-output stream library.
#include <string>                    // Includes the string library.
#include <utility>                   // Provides the std::move() function.

// Defines the Person base class.
class Person {

protected:                           // Makes the following members accessible to derived classes.

    std::string name;                // Declares a string variable to store the person's name.

public:                              // Makes the following members publicly accessible.

    // Defines a parameterized constructor of Person.
    explicit Person(std::string personName)

        // Initializes name using the value of personName.
        : name(std::move(personName)) {}

    // Defines a function to display the person's name.
    void displayName() const {

        // Displays the name stored in the name variable.
        std::cout << "Name: " << name << '\n';
    }
};

// Defines Student class that virtually inherits from Person.
class Student : virtual public Person {

public:                              // Makes the following members publicly accessible.

    // Defines the default constructor of Student.
    Student()

        // Calls the Person constructor with "Unknown".
        : Person("Unknown") {}
};

// Defines Employee class that virtually inherits from Person.
class Employee : virtual public Person {

public:                              // Makes the following members publicly accessible.

    // Defines the default constructor of Employee.
    Employee()

        // Calls the Person constructor with "Unknown".
        : Person("Unknown") {}
};

// Defines TeachingAssistant class derived from Student and Employee.
class TeachingAssistant : public Student, public Employee {

public:                              // Makes the following members publicly accessible.

    // Defines a parameterized constructor of TeachingAssistant.
    explicit TeachingAssistant(std::string assistantName)

        // Initializes the single shared Person virtual base.
        : Person(std::move(assistantName)),

          // Calls the Student constructor.
          Student(),

          // Calls the Employee constructor.
          Employee() {}
};

// Main function where program execution begins.
int main() {

    // Creates a TeachingAssistant object with the name Riya.
    TeachingAssistant assistant("Riya");

    // Calls the displayName() function of the shared Person object.
    assistant.displayName();

    // Returns 0 to indicate successful program execution.
    return 0;
}
