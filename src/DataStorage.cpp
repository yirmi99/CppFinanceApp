#include "DataStorage.h"
#include <iostream>
#include <fstream>

const std::string FILE_PATH = "data/transactions.json";

void DataStorage::saveTransactions(const std::vector<Transaction>& transactions) {
    nlohmann::json jsonData = nlohmann::json::array();
    for (const auto& transaction : transactions) {
        jsonData.push_back(transaction.toJson());
    }

    std::ofstream file(FILE_PATH);
    if (file.is_open()) {
        file << jsonData.dump(4);
        file.close();
        std::cout << "✅ Transactions saved successfully!\n";
    } else {
        std::cerr << "Failed to open file for writing: " << FILE_PATH << std::endl;
    }
}

std::vector<Transaction> DataStorage::loadTransactions() {
    std::vector<Transaction> transactions;
    std::ifstream file(FILE_PATH);

    if (!file.is_open()) {
        std::cerr << "⚠️ No previous transactions found, starting fresh.\n";
        return transactions;  // Return empty list
    }

    try {
        nlohmann::json jsonData;
        file >> jsonData;
        file.close();

        for (const auto& jsonTransaction : jsonData) {
            transactions.push_back(Transaction::fromJson(jsonTransaction));
        }

        std::cout << "Transactions loaded successfully!\n";
    } catch (const std::exception& e) {
        std::cerr << "Error reading transactions file: " << e.what() << "\n";
        transactions.clear();  // Ensure empty list if file is corrupted
    }

    return transactions;
}
