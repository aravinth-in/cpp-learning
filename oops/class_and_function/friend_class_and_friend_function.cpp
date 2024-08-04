#include <iostream>
#include <string>
using namespace std;


class Account {
private:
    int accountNumber;
    double balance;
public:
    Account(int accNum, double bal) : accountNumber(accNum), balance(bal) {}

    // Friend function declaration
    // This function can access private and protected members of Engine
    friend void displayAccountDetails(const Account& acc);

    // Friend class declaration
    // This class can access private and protected members of Engine
    friend class Bank;
};


class Customer {
private:
    string name;
    int customerID;
public:
    Customer(string n, int id) : name(n), customerID(id) {}

    // Friend class declaration
    friend class Bank;
};


// The Bank class can access private and protected members of Account and Customer
class Bank {
public:
    void showAccountBalance(const Account& acc) {
        cout << "Account Number: " << acc.accountNumber << ", Balance: $" << acc.balance << endl;
    }

    void showCustomerDetails(const Customer& cust) {
        cout << "Customer Name: " << cust.name << ", Customer ID: " << cust.customerID << endl;
    }

    void transferFunds(Account& from, Account& to, double amount) {
        if (from.balance >= amount) {
            from.balance -= amount;
            to.balance += amount;
            cout << "Transferred $" << amount << " from Account " << from.accountNumber << " to Account " << to.accountNumber << endl;
        } else {
            cout << "Insufficient funds in Account " << from.accountNumber << endl;
        }
    }
};


// Friend function definition
// This function can access the private and protected members of Account
void displayAccountDetails(const Account& acc) {
    cout << "Account Number: " << acc.accountNumber << ", Balance: $" << acc.balance << endl;
}


int main() {
    Account acc1(101, 500.0);
    Account acc2(102, 300.0);

    Customer cust1("Alice", 1);
    Customer cust2("Bob", 2);

    Bank bank;

    displayAccountDetails(acc1);

    bank.showAccountBalance(acc1);
    bank.showCustomerDetails(cust1);

    bank.transferFunds(acc1, acc2, 200.0);

    displayAccountDetails(acc1);
    displayAccountDetails(acc2);

    return 0;
}


/*
OUTPUT
Account Number: 101, Balance: $500
Account Number: 101, Balance: $500
Customer Name: Alice, Customer ID: 1
Transferred $200 from Account 101 to Account 102
Account Number: 101, Balance: $300
Account Number: 102, Balance: $500
*/