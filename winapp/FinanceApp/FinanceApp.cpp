#include "FinanceApp.h"
#include <iostream>
#include <ctime>

// constructor loads transactions from file// constructor: loads transactions from file
FinanceApp::FinanceApp() {
    transactions.clear(); // Clear previous data
    transactions = FileHandler::loadFromFile(filename);
    calculateCategoryTotals();
}


void FinanceApp::addTransaction(const std::string& desc, double amt, const std::string& cat) {
    std::time_t now = std::time(nullptr);
    Transaction newTransaction(desc, amt, cat, now);
    transactions.push_back(newTransaction);
    categoryTotals[cat] += amt;

    // save to file after adding transaction
    FileHandler::saveToFile(transactions, filename);
}

void FinanceApp::removeTransaction(int index) {
    if (index < 0 || index >= transactions.size()) {
        std::cout << "invalid index\n";
        return;
    }

    categoryTotals[transactions[index].getCategory()] -= transactions[index].getAmount();
    transactions.erase(transactions.begin() + index);

    // save to file after removing transaction
    FileHandler::saveToFile(transactions, filename);
}

// get the total balance (sum of all transactions)
double FinanceApp::getTotalBalance() const {
    double total = 0;
    for (const auto& t : transactions) {
        total += t.getAmount();
    }
    return total;
}

// display all transactions (now formatted properly)
void FinanceApp::displayAllTransactions() const {
    std::cout << "transactions list:\n";
    for (size_t i = 0; i < transactions.size(); ++i) {
        std::cout << i + 1 << ". ";
        transactions[i].display();
    }
}

// recalculate category spending totals
void FinanceApp::calculateCategoryTotals() {
    categoryTotals.clear();
    for (const auto& t : transactions) {
        categoryTotals[t.getCategory()] += t.getAmount();
    }
}