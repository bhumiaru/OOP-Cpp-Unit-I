#include <iostream>       // Provides std::cout
#include <string>         // Provides std::string
#include <utility>        // Provides std::move()

class Person {            // First/base level

protected:                // Accessible in derived classes
    std::string name;     // Store person's name

public:

    explicit Person(      // Person constructor
        std::string personName) // Receive person's name

        : name(std::move(personName)) // Initialize name
    {}

    void showPerson() const { // Display Person information

        std::cout << "Name: "
                  << name
                  << '\n';
    }
};

class Employee : public Person { // Employee inherits Person
                                 // Second level

protected:
    int employeeId;              // Store employee ID

public:

    Employee(                    // Employee constructor
        std::string employeeName, // Name parameter
        int id)                   // ID parameter

        : Person(std::move(employeeName)), // Call Person constructor
          employeeId(id)                   // Initialize ID
    {}

    void showEmployee() const {            // Display employee information

        std::cout << "Employee ID: "
                  << employeeId
                  << '\n';
    }
};

class Manager : public Employee { // Manager inherits Employee
                                  // Third level

private:
    int teamSize;                 // Store number of team members

public:

    Manager(                      // Manager constructor
        std::string managerName,  // Manager name
        int id,                   // Employee ID
        int size)                 // Team size

        : Employee(std::move(managerName), id), // Call Employee constructor
          teamSize(size)                        // Initialize teamSize
    {}

    void showManager() const {     // Display all Manager information

        showPerson();              // Function inherited from Person

        showEmployee();            // Function inherited from Employee

        std::cout << "Team Size: "
                  << teamSize
                  << '\n';
    }
};

int main() {                       // Starting point

    Manager manager(               // Create Manager object
        "Ravi",                    // Name
        501,                       // Employee ID
        8);                        // Team size

    manager.showManager();         // Display all information

    return 0;                      // End program
}
