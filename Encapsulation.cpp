#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolderName;
    int accountNumber;
    double balance;

public:
    // Constructor to initialize values
    BankAccount(string name, int accNo, double initialBalance) {
        accountHolderName = name;
        accountNumber = accNo;
        balance = initialBalance;
    }

    // Public method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: ₹" << amount << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Public method to withdraw money
    void withdraw(double amount) {
        if (amount <= balance && amount > 0) {
            balance -= amount;
            cout << "Withdrawn: ₹" << amount << endl;
        } else {
            cout << "Insufficient balance or invalid amount." << endl;
        }
    }

    // Public method to check balance
    double getBalance() {
        return balance;
    }

    // Public method to get account details
    void displayAccountDetails() {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: ₹" << balance << endl;
    }
};

int main() {
    BankAccount user1("Rajat", 123456789, 10000.0);

    user1.displayAccountDetails();
    user1.deposit(2500.0);
    user1.withdraw(4000.0);
    cout << "Remaining Balance: ₹" << user1.getBalance() << endl;

    return 0;
}
