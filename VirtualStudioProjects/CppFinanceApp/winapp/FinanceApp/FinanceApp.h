#ifndef FINANCE_APP_H
#define FINANCE_APP_H

#include <vector>
#include <unordered_map>
#include <string>
#include "Transaction.h"
#include "FileHandler.h"

class FinanceApp {
private:
    std::vector<Transaction> transactions; // store all transactions
    std::unordered_map<std::string, double> categoryTotals;
    std::string filename = "transactions.txt"; // default filename

public:
    FinanceApp();
    void addTransaction(const std::string& desc, double amt, const std::string& cat);
    void removeTransaction(int index);
    double getTotalBalance() const;
    void displayAllTransactions() const;
    void calculateCategoryTotals();
};

#endif // FINANCE_APP_H
