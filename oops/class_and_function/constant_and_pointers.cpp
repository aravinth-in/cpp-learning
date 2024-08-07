#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

class Transaction {
public:
    double amount;
    std::string type; // "credit" or "debit"

    Transaction(double amt, const std::string& t) : amount(amt), type(t) {}
};

class Account {
private:
    std::vector<Transaction> transactions;

public:
    // Constant Member Function:
    // Declaring a member function as const means it cannot modify any member variables of the class.
    double getTotalBalance() const {
        double balance = 0.0;
        for (const auto& transaction : transactions) {
            if (transaction.type == "credit") {
                balance += transaction.amount;
            } else if (transaction.type == "debit") {
                balance -= transaction.amount;
            }
        }
        return balance;
    }

    // Constant Function Parameters:
    // Declaring function parameters as const ensures that they are not modified within the function.
    inline void addTransaction(const double amount, const std::string& type) {
        transactions.emplace_back(amount, type);
    }

    // Constant Return Type:
    // A function can return a constant value, ensuring that the returned value cannot be modified.
    const std::vector<Transaction>& getTransactions() const {
        return transactions;
    }
};

int main() {
    // Constant Variable:
    // Declaring a variable as const makes it immutable, meaning its value cannot be changed after initialization.
    const int maxValue = 100;
    std::cout << "maxValue: " << maxValue << ", Address: " << &maxValue << std::endl;
    // maxValue = 200; // This line will cause a compilation error

    // Non-const Variable
    int currentValue = 200;
    std::cout << "currentValue: " << currentValue << ", Address: " << &currentValue << std::endl;

    // Constant Pointer:
    // The pointer itself is constant, meaning it cannot point to a different address, but the value it points to can be changed.
    int* const ptrToCurrentValue = &currentValue;
    std::cout << "ptrToCurrentValue: " << *ptrToCurrentValue << ", Address: " << ptrToCurrentValue << std::endl;
    int newValue = 400;
    // ptrToCurrentValue = &newValue; // This line will cause a compilation error

    // Pointer to a Constant Value:
    // The pointer can point to different addresses, but the value it points to cannot be changed.
    const int* ptrToMaxValue = &maxValue;
    std::cout << "ptrToMaxValue: " << *ptrToMaxValue << ", Address: " << ptrToMaxValue << std::endl;
    // *ptrToMaxValue = 500; // This line will cause a compilation error 
    ptrToMaxValue = &currentValue;

    // Constant Pointer to a Constant Value:
    // Neither the pointer nor the value it points to can be changed.
    const int* const constPtrToMaxValue = &maxValue;
    std::cout << "constPtrToMaxValue: " << *constPtrToMaxValue << ", Address: " << constPtrToMaxValue << std::endl;
    // *constPtrToMaxValue = 1000; // This line will cause a compilation error
    // constPtrToMaxValue = &currentValue; // This line will cause a compilation error

    // Constant Reference:
    // A reference to a constant value: The value referred to by the reference cannot be changed.
    const int& refToMaxValue = maxValue;
    std::cout << "refToMaxValue: " << refToMaxValue << ", Address: " << &refToMaxValue << std::endl;
    // refToMaxValue = 800; // This line will cause a compilation error

    Account account;
    account.addTransaction(100.0, "credit");
    account.addTransaction(50.0, "debit");

    std::cout << "Total Balance: " << account.getTotalBalance() << std::endl;
    return 0;
}


/*
OUTPUT
maxValue: 100, Address: 0x16d29f2f8
currentValue: 200, Address: 0x16d29f2f4
ptrToCurrentValue: 200, Address: 0x16d29f2f4
ptrToMaxValue: 100, Address: 0x16d29f2f8
constPtrToMaxValue: 100, Address: 0x16d29f2f8
refToMaxValue: 100, Address: 0x16d29f2f8
Total Balance: 50
*/