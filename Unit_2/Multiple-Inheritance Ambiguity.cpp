#include <iostream>                 // Provides std::cout

class Academic {                    // First base class

public:

    void display() const {          // Function named display()

        std::cout << "Academic information\n";
    }
};

class Sports {                      // Second base class

public:

    void display() const {          // SAME function name

        std::cout << "Sports information\n";
    }
};

class Student : public Academic, public Sports {
    // Student inherits display() from BOTH classes
    // Therefore display() becomes ambiguous

public:

    void displayAll() const {       // Function to display both

        Academic::display();        // Call Academic's display()
                                    // :: specifies which class

        Sports::display();          // Call Sports' display()
    }
};

int main() {                        // Program starts

    Student student;                // Create Student object

    student.Academic::display();    // Explicitly call Academic version

    student.Sports::display();      // Explicitly call Sports version

    student.displayAll();           // Call function that calls both

    return 0;                       // End program
}
