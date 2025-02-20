#include "DownloadThread.h"
#include <iostream>

DownloadThread::DownloadThread() : running(false) {}

DownloadThread::~DownloadThread() {
    stop();
}

void DownloadThread::start(const std::string& baseCurrency, std::function<void(nlohmann::json)> callback) {
    if (running.load()) {
        std::cerr << "⚠️ Download thread already running!\n";
        return;
    }

    running.store(true);
    worker = std::thread([this, baseCurrency, callback]() {
        while (running.load()) {
            std::cout << "🔄 Fetching exchange rates...\n";
            nlohmann::json rates = CurrencyAPI::fetchExchangeRates(baseCurrency);

            if (!rates.empty()) {
                callback(rates);
            } else {
                std::cerr << "❌ Failed to fetch exchange rates!\n";
            }

            std::this_thread::sleep_for(std::chrono::minutes(5));
        }
    });
}

void DownloadThread::stop() {
    running.store(false);
    if (worker.joinable()) {
        worker.join();
    }
}
