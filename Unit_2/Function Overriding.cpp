#include <iostream>                  // Includes the input-output stream library.

// Defines the Vehicle base class.
class Vehicle {

public:                              // Makes the following members publicly accessible.

    // Declares a virtual function named move().
    virtual void move() const {

        // Displays the movement message for a general vehicle.
        std::cout << "Vehicle is moving\n";
    }

    // Virtual destructor of Vehicle.
    virtual ~Vehicle() = default;
};

// Defines Car as a derived class of Vehicle.
class Car : public Vehicle {

public:                              // Makes the following members publicly accessible.

    // Overrides the move() function of Vehicle.
    void move() const override {

        // Displays the movement message for a car.
        std::cout << "Car moves on roads\n";
    }
};

// Defines Boat as a derived class of Vehicle.
class Boat : public Vehicle {

public:                              // Makes the following members publicly accessible.

    // Overrides the move() function of Vehicle.
    void move() const override {

        // Displays the movement message for a boat.
        std::cout << "Boat moves on water\n";
    }
};

// Main function where program execution starts.
int main() {

    // Creates a Car object.
    Car car;

    // Creates a Boat object.
    Boat boat;

    // Calls the Car version of move().
    car.move();

    // Calls the Boat version of move().
    boat.move();

    // Returns 0 for successful execution.
    return 0;
}
