#include <iostream>                  // Includes the input-output stream library.
#include <string>                    // Includes the string library.
#include <utility>                   // Provides the std::move() function.

// Defines the Vehicle base class.
class Vehicle {

protected:                           // Makes the following members accessible to derived classes.

    // Stores the vehicle registration number.
    std::string registrationNumber;

    // Stores the rental rate per day.
    double ratePerDay;

public:                              // Makes the following members publicly accessible.

    // Defines a parameterized constructor of Vehicle.
    Vehicle(std::string registration, double rate)

        // Initializes registrationNumber using registration.
        : registrationNumber(std::move(registration)),

          // Initializes ratePerDay using rate.
          ratePerDay(rate) {}

    // Defines a virtual function to calculate rental amount.
    virtual double calculateRent(int days) const {

        // Calculates rent using rate per day multiplied by number of days.
        return ratePerDay * days;
    }

    // Defines a virtual function to display vehicle details.
    virtual void display() const {

        // Displays the vehicle registration number.
        std::cout << "Registration: " << registrationNumber << '\n';

        // Displays the rental rate per day.
        std::cout << "Rate per day: " << ratePerDay << '\n';
    }

    // Defines a virtual destructor.
    virtual ~Vehicle() = default;
};

// Defines Car class derived from Vehicle.
class Car : public Vehicle {

private:                             // Makes the following member private.

    // Stores the number of doors in the car.
    int numberOfDoors;

public:                              // Makes the following members publicly accessible.

    // Defines a parameterized constructor of Car.
    Car(std::string registration, double rate, int doors)

        // Calls the constructor of the Vehicle base class.
        : Vehicle(std::move(registration), rate),

          // Initializes numberOfDoors using doors.
          numberOfDoors(doors) {}

    // Overrides the display() function of Vehicle.
    void display() const override {

        // Calls the display() function of the Vehicle class.
        Vehicle::display();

        // Displays the number of doors.
        std::cout << "Doors: " << numberOfDoors << '\n';
    }
};

// Defines Bike class derived from Vehicle.
class Bike : public Vehicle {

private:                             // Makes the following member private.

    // Stores the engine capacity of the bike.
    int engineCapacity;

public:                              // Makes the following members publicly accessible.

    // Defines a parameterized constructor of Bike.
    Bike(std::string registration, double rate, int capacity)

        // Calls the constructor of the Vehicle base class.
        : Vehicle(std::move(registration), rate),

          // Initializes engineCapacity using capacity.
          engineCapacity(capacity) {}

    // Overrides the calculateRent() function of Vehicle.
    double calculateRent(int days) const override {

        // Calculates bike rent with a 10 percent reduction.
        return ratePerDay * days * 0.9;
    }

    // Overrides the display() function of Vehicle.
    void display() const override {

        // Calls the display() function of the Vehicle class.
        Vehicle::display();

        // Displays the engine capacity of the bike.
        std::cout << "Engine Capacity: "
                  << engineCapacity
                  << " cc\n";
    }
};

// Main function where program execution begins.
int main() {

    // Creates a Car object with registration number, rate and number of doors.
    Car car("MH12AB1234", 2000.0, 5);

    // Creates a Bike object with registration number, rate and engine capacity.
    Bike bike("MH12CD5678", 800.0, 150);

    // Displays the Car Details heading.
    std::cout << "Car Details\n";

    // Calls the display() function of the Car object.
    car.display();

    // Calculates and displays the rent for the car for 3 days.
    std::cout << "Rent for 3 days: "
              << car.calculateRent(3)
              << "\n\n";

    // Displays the Bike Details heading.
    std::cout << "Bike Details\n";

    // Calls the display() function of the Bike object.
    bike.display();

    // Calculates and displays the rent for the bike for 3 days.
    std::cout << "Rent for 3 days: "
              << bike.calculateRent(3)
              << '\n';

    // Returns 0 to indicate successful program execution.
    return 0;
}
