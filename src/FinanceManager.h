#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include "DataStorage.h"
#include <vector>
#include <algorithm>

class FinanceManager {
private:
    std::vector<Transaction> transactions;  // Stores all transactions

public:
    // Constructor loads transactions from file
    FinanceManager();

    // Transaction operations
    void addTransaction(const Transaction& transaction);
    bool editTransaction(int index, const Transaction& newTransaction);
    bool deleteTransaction(int index);

    // Filters
    std::vector<Transaction> filterByCategory(const std::string& category) const;
    std::vector<Transaction> filterByDate(const std::string& date) const;
    std::vector<Transaction> filterByAmount(double minAmount, double maxAmount) const;

    // Get all transactions
    const std::vector<Transaction>& getTransactions() const;

    // Save transactions to file
    void saveTransactions() const;
};

#endif // FINANCEMANAGER_H
