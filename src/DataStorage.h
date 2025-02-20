#ifndef DATASTORAGE_H
#define DATASTORAGE_H

#include "../shared/HttpSrc/json.hpp"
#include <vector>
#include <string>

struct Transaction {
    std::string date;
    std::string category;
    double amount;

    static Transaction fromJson(const nlohmann::json& json) {
        return {json.value("date", ""), json.value("category", ""), json.value("amount", 0.0)};
    }

    nlohmann::json toJson() const {
        return {{"date", date}, {"category", category}, {"amount", amount}};
    }
};

class DataStorage {
public:
    static void saveTransactions(const std::vector<Transaction>& transactions);
    static std::vector<Transaction> loadTransactions();
};

#endif // DATASTORAGE_H
