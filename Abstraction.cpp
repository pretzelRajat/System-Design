
#include <iostream>
#include <string>
using namespace std;

class Bank {
private:
    string bank_name;
    string branch_name;
    string user_name;
    bool isActiveCustomer;
    int transactionId;
    int customerId;

public:
    // Constructor
    Bank(string bank1, string branch1, string user1) {
        bank_name = bank1;
        branch_name = branch1;
        user_name = user1;
        isActiveCustomer = true;
        transactionId = 0;
        customerId = 0;
    }

    // Public methods - Abstraction: Only expose what is needed
    void updateTransactionId(int newId) {
        transactionId = newId;
        isActiveCustomer = true;
        cout << bank_name << " " << branch_name << " : Transaction ID updated to " << transactionId << endl;
    }

    void updateCustomerId(int custId) {
        customerId = custId;
        isActiveCustomer = true;
        cout << "Customer ID updated to " << customerId << endl;
    }

    void withdrawAmount(int amount) {
        cout << bank_name << " " << branch_name << " : Amount withdrawn = " << amount << endl;
    }

    void showRemainingBalance(int balance) {
        cout << "Remaining balance: " << balance << endl;
    }
};
int main() {
    Bank b("SBI", "Gwalior", "Rajat");
    b.updateCustomerId(1001);
    b.updateTransactionId(2002);
    b.withdrawAmount(5000);
    b.showRemainingBalance(15000);
    return 0;
}
