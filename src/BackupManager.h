#ifndef BACKUPMANAGER_H
#define BACKUPMANAGER_H

#include "HttpClient.h"
#include "DataStorage.h"
#include <thread>
#include <atomic>
#include <vector>

class BackupManager {
private:
    static std::thread backupThread;
    static std::atomic<bool> running;

public:
    static void startBackup();
    static void stopBackup();
    static void backupToServer();
    static void restoreFromServer(std::vector<Transaction>& transactions);
};

#endif // BACKUPMANAGER_H
