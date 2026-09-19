#include <iostream>              // Provides std::cout
#include <string>                // Provides std::string
#include <utility>               // Provides std::move()

class Vehicle {                  // Base class

protected:
    std::string registrationNumber; // Store vehicle registration number

public:

    explicit Vehicle(             // Vehicle constructor
        std::string registration)  // Registration parameter

        : registrationNumber(std::move(registration)) // Initialize registration
    {}

    void start() const {          // Function to start vehicle

        std::cout << "Vehicle "
                  << registrationNumber
                  << " started\n";
    }
};

class Car : public Vehicle {      // Car inherits Vehicle

public:

    explicit Car(                 // Car constructor
        std::string registration) // Registration parameter

        : Vehicle(std::move(registration)) // Call Vehicle constructor
    {}

    void openBoot() const {       // Car-specific function

        std::cout << "Car boot opened\n";
    }
};

class Bike : public Vehicle {     // Bike also inherits Vehicle

public:

    explicit Bike(                // Bike constructor
        std::string registration) // Registration parameter

        : Vehicle(std::move(registration)) // Call Vehicle constructor
    {}

    void helmetReminder() const { // Bike-specific function

        std::cout << "Please wear a helmet\n";
    }
};

int main() {                      // Program starts

    Car car("MH12AB1234");        // Create Car object

    Bike bike("MH12CD5678");      // Create Bike object

    car.start();                  // Inherited Vehicle function

    car.openBoot();               // Car function

    bike.start();                 // Inherited Vehicle function

    bike.helmetReminder();        // Bike function

    return 0;                     // End program
}
