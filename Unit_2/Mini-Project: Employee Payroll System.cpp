#include <iostream>                  // Includes the input-output stream library.
#include <string>                    // Includes the string library.
#include <utility>                   // Provides the std::move() function.

// Defines Employee as the abstract base class.
class Employee {

protected:                           // Makes the following members accessible to derived classes.

    // Stores the employee ID.
    int employeeId;

    // Stores the employee name.
    std::string name;

public:                              // Makes the following members publicly accessible.

    // Defines a parameterized constructor of Employee.
    Employee(int id, std::string employeeName)

        // Initializes employeeId using id.
        : employeeId(id),

          // Initializes name using employeeName.
          name(std::move(employeeName)) {}

    // Declares a pure virtual function for calculating salary.
    virtual double calculateSalary() const = 0;

    // Defines a function to display basic employee details.
    void displayBasicDetails() const {

        // Displays the employee ID.
        std::cout << "Employee ID: "
                  << employeeId
                  << '\n';

        // Displays the employee name.
        std::cout << "Name: "
                  << name
                  << '\n';
    }

    // Defines a virtual destructor.
    virtual ~Employee() = default;
};

// Defines PermanentEmployee derived from Employee.
class PermanentEmployee : public Employee {

private:                             // Makes the following members private.

    // Stores the basic salary.
    double basicSalary;

    // Stores the allowance.
    double allowance;

public:                              // Makes the following members publicly accessible.

    // Defines a parameterized constructor of PermanentEmployee.
    PermanentEmployee(
        int id,
        std::string employeeName,
        double basic,
        double extra
    )

        // Calls the constructor of the Employee base class.
        : Employee(id, std::move(employeeName)),

          // Initializes basicSalary using basic.
          basicSalary(basic),

          // Initializes allowance using extra.
          allowance(extra) {}

    // Overrides the calculateSalary() function.
    double calculateSalary() const override {

        // Returns basic salary plus allowance.
        return basicSalary + allowance;
    }
};

// Defines ContractEmployee derived from Employee.
class ContractEmployee : public Employee {

private:                             // Makes the following members private.

    // Stores the hourly salary rate.
    double hourlyRate;

    // Stores the number of hours worked.
    int hoursWorked;

public:                              // Makes the following members publicly accessible.

    // Defines a parameterized constructor of ContractEmployee.
    ContractEmployee(
        int id,
        std::string employeeName,
        double rate,
        int hours
    )

        // Calls the constructor of the Employee base class.
        : Employee(id, std::move(employeeName)),

          // Initializes hourlyRate using rate.
          hourlyRate(rate),

          // Initializes hoursWorked using hours.
          hoursWorked(hours) {}

    // Overrides the calculateSalary() function.
    double calculateSalary() const override {

        // Calculates salary by multiplying hourly rate and hours worked.
        return hourlyRate * hoursWorked;
    }
};

// Defines a function to display an employee pay slip.
void displayPaySlip(const Employee& employee) {

    // Displays the employee's basic details.
    employee.displayBasicDetails();

    // Calculates and displays the employee's salary.
    std::cout << "Salary: "
              << employee.calculateSalary()
              << "\n\n";
}

// Main function where program execution begins.
int main() {

    // Creates a PermanentEmployee object.
    PermanentEmployee permanentEmployee(
        101,
        "Asha",
        40000.0,
        8000.0
    );

    // Creates a ContractEmployee object.
    ContractEmployee contractEmployee(
        102,
        "Vikas",
        500.0,
        80
    );

    // Displays the pay slip of the permanent employee.
    displayPaySlip(permanentEmployee);

    // Displays the pay slip of the contract employee.
    displayPaySlip(contractEmployee);

    // Returns 0 to indicate successful program execution.
    return 0;
}
