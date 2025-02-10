#include "FileHandler.h"
#include <fstream>
#include <iostream>
#include <sstream>

// save transactions to a file
void FileHandler::saveToFile(const std::vector<Transaction>& transactions, const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "error: unable to open file for writing\n";
        return;
    }

    for (const auto& t : transactions) {
        file << t.getAmount() << "," 
             << t.getCategory() << ","
             << t.getFormattedDate() << ","
             << t.getDate() << "," // save timestamp for restoring date
             << t.getCategory() << "\n";
    }

    file.close();
}

// load transactions from a file
std::vector<Transaction> FileHandler::loadFromFile(const std::string& filename) {
    std::vector<Transaction> transactions;
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "warning: no previous transactions found\n";
        return transactions;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string desc, category, formattedDate;
        double amount;
        std::time_t date;

        // Extract all values properly
        std::getline(ss, desc, ',');
        ss >> amount;
        ss.ignore(); // Ignore comma
        std::getline(ss, category, ',');
        std::getline(ss, formattedDate, ',');
        ss >> date;

        // Ensure extracted values are valid before adding to list
        if (!desc.empty() && !category.empty() && date > 0) {
            transactions.emplace_back(desc, amount, category, date);
        }
    }

    file.close();
    return transactions;
}
