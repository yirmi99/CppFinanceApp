#ifndef DOWNLOAD_THREAD_H
#define DOWNLOAD_THREAD_H

#include "CurrencyAPI.h"
#include <thread>
#include <atomic>
#include <functional>

class DownloadThread {
private:
    std::thread worker;  
    std::atomic<bool> running; 

public:
    DownloadThread();
    ~DownloadThread();

    void start(const std::string& baseCurrency, std::function<void(nlohmann::json)> callback);
    void stop();
};

#endif // DOWNLOAD_THREAD_H
