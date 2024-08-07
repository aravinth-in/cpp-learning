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
    // An inline function is a function definition, usually small, that is suggested to the compiler to insert the function's body 
    // directly at the point of each call to reduce function call overhead.
    inline void addTransaction(double amount, const std::string& type) {
        transactions.emplace_back(amount, type);
    }

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

    // Lambda function to print all transactions
    void printTransactions() const {
        auto print = [](const Transaction& t) {
            std::cout << "Type: " << t.type << ", Amount: " << t.amount << std::endl;
        };
        std::for_each(transactions.begin(), transactions.end(), print);
    }

    // Lambda function to filter transactions by type
    std::vector<Transaction> filterTransactions(const std::string& type) const {
        std::vector<Transaction> filtered;
        auto filter = [&filtered, &type](const Transaction& t) {
            if (t.type == type) {
                filtered.push_back(t);
            }
        };
        std::for_each(transactions.begin(), transactions.end(), filter);
        return filtered;
    }
};


int main() {
    Account account;

    account.addTransaction(100.0, "credit");
    account.addTransaction(50.0, "debit");
    account.addTransaction(200.0, "credit");
    account.addTransaction(30.0, "debit");

    std::cout << "All Transactions:" << std::endl;
    account.printTransactions();

    std::cout << "Total Balance: " << account.getTotalBalance() << std::endl;

    std::cout << "Credit Transactions:" << std::endl;
    auto credits = account.filterTransactions("credit");
    for (const auto& t : credits) {
        std::cout << "Type: " << t.type << ", Amount: " << t.amount << std::endl;
    }

    return 0;
}


/*
OUTPUT
All Transactions:
Type: credit, Amount: 100
Type: debit, Amount: 50
Type: credit, Amount: 200
Type: debit, Amount: 30
Total Balance: 220
Credit Transactions:
Type: credit, Amount: 100
Type: credit, Amount: 200
*/