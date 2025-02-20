#include "CurrencyAPI.h"
#include <iostream>

const std::string API_KEY = "46e5a0c5aad23484fe80b99c";
const std::string BASE_URL = "https://v6.exchangerate-api.com/v6/";

nlohmann::json CurrencyAPI::fetchExchangeRates(const std::string& baseCurrency) {
    std::string url = BASE_URL + API_KEY + "/latest/" + baseCurrency;
    nlohmann::json response = HttpClient::getRequest(url);

    if (response.empty()) {
        std::cerr << "API response is empty!\n";
        return {};
    }

    if (!response.contains("conversion_rates")) {
        std::cerr << "⚠️ Error: No conversion rates found in API response.\n";
        return {};
    }

    std::cout << "Successfully fetched exchange rates!\n";
    return response;
}

double CurrencyAPI::convertCurrency(double amount, const std::string& from, const std::string& to, const nlohmann::json& rates) {
    if (!rates.contains("conversion_rates")) {
        std::cerr << "⚠️ Error: No conversion rates available.\n";
        return 0;
    }

    const auto& conversionRates = rates["conversion_rates"];
    
    if (!conversionRates.contains(to)) {
        std::cerr << "⚠️ Warning: Exchange rate for " << to << " not found!\n";
        return 0;
    }

    double rate = conversionRates[to];
    return amount * rate;
}
