#include "FinanceManager.h"
#include <iostream>

//constructor: Loads transactions from file
FinanceManager::FinanceManager() {
    transactions = DataStorage::loadTransactions();
}

// add a new transaction
void FinanceManager::addTransaction(const Transaction& transaction) {
    transactions.push_back(transaction);
    saveTransactions();
    std::cout << "Transaction added successfully!\n";
}

// edit an existing transaction
bool FinanceManager::editTransaction(int index, const Transaction& newTransaction) {
    if (index >= 0 && index < transactions.size()) {
        transactions[index] = newTransaction;
        saveTransactions();
        std::cout << "Transaction edited successfully!\n";
        return true;
    }
    std::cerr << "Error: Invalid transaction index!\n";
    return false;
}

// delete a transaction
bool FinanceManager::deleteTransaction(int index) {
    if (index >= 0 && index < transactions.size()) {
        transactions.erase(transactions.begin() + index);
        saveTransactions();
        std::cout << "Transaction deleted successfully!\n";
        return true;
    }
    std::cerr << "Error: Invalid transaction index!\n";
    return false;
}

// filter transactions by category
std::vector<Transaction> FinanceManager::filterByCategory(const std::string& category) const {
    std::vector<Transaction> result;
    for (const auto& t : transactions) {
        if (t.category == category) {
            result.push_back(t);
        }
    }
    return result;
}

// filter transactions by date
std::vector<Transaction> FinanceManager::filterByDate(const std::string& date) const {
    std::vector<Transaction> result;
    for (const auto& t : transactions) {
        if (t.date == date) {
            result.push_back(t);
        }
    }
    return result;
}

// filter transactions by amount range
std::vector<Transaction> FinanceManager::filterByAmount(double minAmount, double maxAmount) const {
    std::vector<Transaction> result;
    for (const auto& t : transactions) {
        if (t.amount >= minAmount && t.amount <= maxAmount) {
            result.push_back(t);
        }
    }
    return result;
}

// get all transactions
const std::vector<Transaction>& FinanceManager::getTransactions() const {
    return transactions;
}

// save transactions to file
void FinanceManager::saveTransactions() const {
    DataStorage::saveTransactions(transactions);
}
