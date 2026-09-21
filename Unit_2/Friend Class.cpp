#include <iostream>                  // Includes the input-output stream library.

// Defines the Account class.
class Account {

private:                             // Makes the following members accessible only inside Account.

    double balance;                  // Declares a variable to store the account balance.

    // Declares Auditor as a friend class.
    friend class Auditor;

public:                              // Makes the following members publicly accessible.

    // Defines a parameterized constructor of Account.
    explicit Account(double initialBalance)

        // Initializes balance using initialBalance.
        : balance(initialBalance) {}
};

// Defines the Auditor class.
class Auditor {

public:                              // Makes the following members publicly accessible.

    // Defines a function to inspect an Account object.
    void inspect(const Account& account) const {

        // Accesses the private balance because Auditor is a friend class.
        std::cout << "Account Balance: " << account.balance << '\n';
    }
};

// Main function where program execution begins.
int main() {

    // Creates an Account object with an initial balance of 5000.
    Account account(5000.0);

    // Creates an object of the Auditor class.
    Auditor auditor;

    // Calls the inspect() function and passes the account object.
    auditor.inspect(account);

    // Returns 0 to indicate successful program execution.
    return 0;
}
