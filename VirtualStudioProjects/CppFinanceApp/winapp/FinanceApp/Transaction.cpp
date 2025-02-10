#include "Transaction.h"
#include <iostream>
#include <iomanip>
#include <sstream>

// constructor to initialize transaction details
Transaction::Transaction(std::string desc, double amt, std::string cat, std::time_t dt) 
    : description(desc), amount(amt), category(cat), date(dt) {}

// return transaction amount
double Transaction::getAmount() const {
    return amount;
}

// return transaction category
std::string Transaction::getCategory() const {
    return category;
}

// return transaction date as time_t
std::time_t Transaction::getDate() const {
    return date;
}

// format date as a readable string
std::string Transaction::getFormattedDate() const {
    std::tm* tm = std::localtime(&date);
    std::ostringstream oss;
    oss << std::put_time(tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

// display transaction details
void Transaction::display() const {
    std::cout << description << " | " 
              << amount << " | " 
              << category << " | " 
              << getFormattedDate() << "\n";
}
