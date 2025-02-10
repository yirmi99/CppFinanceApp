#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <ctime>

class Transaction {
private:
    std::string description;
    double amount;
    std::string category;
    std::time_t date;

public:
    Transaction(std::string desc, double amt, std::string cat, std::time_t dt);

    double getAmount() const;
    std::string getCategory() const;
    std::time_t getDate() const;
    std::string getFormattedDate() const;
    void display() const;
};

#endif // TRANSACTION_H
