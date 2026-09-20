#include <iostream>                 // Provides std::cout

class Academic {                    // First base class

protected:
    int academicMarks;              // Store academic marks

public:

    explicit Academic(int marks)    // Academic constructor
        : academicMarks(marks)      // Initialize marks
    {}

    void showAcademic() const {     // Display academic marks

        std::cout << "Academic Marks: "
                  << academicMarks
                  << '\n';
    }
};

class Sports {                      // Second base class

protected:
    int sportsMarks;                // Store sports marks

public:

    explicit Sports(int marks)      // Sports constructor
        : sportsMarks(marks)        // Initialize sports marks
    {}

    void showSports() const {       // Display sports marks

        std::cout << "Sports Marks: "
                  << sportsMarks
                  << '\n';
    }
};

class Student : public Academic, public Sports {
    // Student inherits from TWO classes
    // Academic = first base class
    // Sports = second base class

public:

    Student(int academic, int sports) // Student constructor

        : Academic(academic),         // Call Academic constructor
          Sports(sports)               // Call Sports constructor
    {}

    void showTotal() const {           // Calculate total marks

        std::cout << "Total Marks: "
                  << academicMarks + sportsMarks // Add both marks
                  << '\n';
    }
};

int main() {                           // Program starts

    Student student(80, 15);           // Create Student
                                       // Academic = 80
                                       // Sports = 15

    student.showAcademic();            // Call Academic function

    student.showSports();              // Call Sports function

    student.showTotal();               // Display total = 95

    return 0;                          // End program
}
