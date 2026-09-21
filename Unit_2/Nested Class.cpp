#include <iostream>                  // Includes the input-output stream library.
#include <string>                    // Includes the string library.
#include <utility>                   // Provides the std::move() function.

// Defines the outer University class.
class University {

public:                              // Makes the nested class publicly accessible.

    // Defines Department as a class inside University.
    class Department {

    private:                         // Makes the following member private.

        std::string name;            // Declares a string variable to store department name.

    public:                          // Makes the following members publicly accessible.

        // Defines a parameterized constructor of Department.
        explicit Department(std::string departmentName)

            // Initializes name using departmentName.
            : name(std::move(departmentName)) {}

        // Defines a function to display the department name.
        void display() const {

            // Displays the department name.
            std::cout << "Department: " << name << '\n';
        }
    };
};

// Main function where program execution begins.
int main() {

    // Creates an object of the nested Department class.
    University::Department department(
        "Artificial Intelligence and Data Science"
    );

    // Calls the display() function of the Department object.
    department.display();

    // Returns 0 to indicate successful program execution.
    return 0;
}
