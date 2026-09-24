#include <iostream>
using namespace std;

class Demo {
public:
    // Constructor
    Demo() {
        cout << "Constructor called" << endl;
    }
    
    // Destructor
    ~Demo() {
        cout << "Destructor called" << endl;
    }
};

int main() {
    Demo d; // Object created here
    
    return 0; // Object 'd' goes out of scope and is destroyed here
}
