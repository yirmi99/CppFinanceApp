#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <vector>
#include <string>
#include "Transaction.h"

class FileHandler {
public:
    static void saveToFile(const std::vector<Transaction>& transactions, const std::string& filename);
    static std::vector<Transaction> loadFromFile(const std::string& filename);
};

#endif // FILE_HANDLER_H
