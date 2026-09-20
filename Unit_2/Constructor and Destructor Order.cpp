#include <iostream>                  // Includes the input-output stream library.

// Defines the Base class.
class Base {

public:                              // Makes the following members publicly accessible.

    // Base class constructor.
    Base() {

        // Displays a message when the Base constructor executes.
        std::cout << "Base constructor\n";
    }

    // Base class destructor.
    ~Base() {

        // Displays a message when the Base destructor executes.
        std::cout << "Base destructor\n";
    }
};

// Defines Derived class which inherits from Base.
class Derived : public Base {

public:                              // Makes the following members publicly accessible.

    // Derived class constructor.
    Derived() {

        // Displays a message when the Derived constructor executes.
        std::cout << "Derived constructor\n";
    }

    // Derived class destructor.
    ~Derived() {

        // Displays a message when the Derived destructor executes.
        std::cout << "Derived destructor\n";
    }
};

// Main function where program execution starts.
int main() {

    // Creates an object of the Derived class.
    Derived object;

    // Returns 0 to indicate successful execution.
    return 0;
}
