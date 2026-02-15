#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class BankAccount {
private:
    string owner;
    double balance;

public:
    BankAccount() {
        owner = "None";
        balance = 0.0;
    }

    BankAccount(string name, double startBalance) {
        owner = name;
        balance = startBalance;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Deposit must be greater than 0.\n";
            return;
        }
        balance += amount;
        cout << "Deposit successful.\n";
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Withdraw amount must be greater than 0.\n";
            return;
        }
        if (amount > balance) {
            cout << "Not enough funds.\n";
            return;
        }
        balance -= amount;
        cout << "Withdraw successful.\n";
    }

    void showInfo() const {
        cout << "\n--- Account Info ---\n";
        cout << "Owner: " << owner << "\n";
        cout << "Balance: $" << fixed << setprecision(2) << balance << "\n";
    }
};

int main() {
    cout << "=== Bank Account Simulator ===\n";

    string name;
    double startBalance;

    cout << "Enter account owner name: ";
    getline(cin, name);

    cout << "Enter starting balance: ";
    cin >> startBalance;

    if (startBalance < 0) startBalance = 0;

    BankAccount account(name, startBalance);

    int choice;
    double amount;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1) Deposit\n";
        cout << "2) Withdraw\n";
        cout << "3) View Account Info\n";
        cout << "4) Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter deposit amount: ";
            cin >> amount;
            account.deposit(amount);
        } 
        else if (choice == 2) {
            cout << "Enter withdraw amount: ";
            cin >> amount;
            account.withdraw(amount);
        } 
        else if (choice == 3) {
            account.showInfo();
        } 
        else if (choice == 4) {
            cout << "Goodbye!\n";
        } 
        else {
            cout << "Invalid option. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
