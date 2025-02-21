#include "BackupManager.h"
#include <iostream>

const std::string BACKUP_URL = "";
const std::string API_KEY = "";

std::thread BackupManager::backupThread;
std::atomic<bool> BackupManager::running(false);

void BackupManager::startBackup() {
    if (running.load()) {
        std::cerr << "⚠️ Backup thread already running!\n";
        return;
    }

    running.store(true);
    backupThread = std::thread([]() {
        while (running.load()) {
            backupToServer();
            std::this_thread::sleep_for(std::chrono::minutes(10));
        }
    });
}

void BackupManager::stopBackup() {
    running.store(false);
    if (backupThread.joinable()) {
        backupThread.join();
    }
}

void BackupManager::backupToServer() {
    std::vector<Transaction> transactions = DataStorage::loadTransactions();
    if (transactions.empty()) {
        std::cerr << "⚠️ No transactions to backup!\n";
        return;
    }

    nlohmann::json jsonBackup;
    jsonBackup["transactions"] = nlohmann::json::array();

    for (const auto& transaction : transactions) {
        jsonBackup["transactions"].push_back(transaction.toJson());
    }

    httplib::Headers headers = {
        {"Content-Type", "application/json"},
        {"X-Master-Key", "YOUR_X_MASTER_KEY_HERE"}
    };

    try {
        nlohmann::json response = HttpClient::putRequest(BACKUP_URL, jsonBackup.dump(), headers);

        std::cout << "🔍 Server Response: " << response.dump(4) << std::endl;

        if (!response.empty() && response.contains("record")) {
            std::cout << "Transactions backed up successfully!\n";
        } else {
            std::cerr << "failed to backup transactions! Response: " << response.dump(4) << "\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "JSON Parsing Error: " << e.what() << "\n";
    }
}

void BackupManager::restoreFromServer(std::vector<Transaction>& transactions) {
    std::string restore_url = BACKUP_URL + "/latest";

    httplib::Headers headers = {
        {"X-Master-Key", API_KEY}
    };

    try {
        nlohmann::json response = HttpClient::getRequest(restore_url, headers);

        std::cout << "Server Response: " << response.dump(4) << std::endl;

        if (response.empty() || !response.contains("record") || !response["record"].contains("transactions")) {
            std::cerr << "Failed to restore transactions from server!\n";
            return;
        }

        transactions.clear();
        for (const auto& jsonTransaction : response["record"]["transactions"]) {
            transactions.push_back(Transaction::fromJson(jsonTransaction));
        }

        std::cout << "transactions restored from server!\n";
    } catch (const std::exception& e) {
        std::cerr << "Error restoring transactions: " << e.what() << "\n";
    }
}
