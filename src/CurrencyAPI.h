#ifndef CURRENCY_API_H
#define CURRENCY_API_H

#include "HttpClient.h"
#include "../shared/HttpSrc/json.hpp"
#include <string>

class CurrencyAPI {
public:
    static nlohmann::json fetchExchangeRates(const std::string& baseCurrency);
    static double convertCurrency(double amount, const std::string& from, const std::string& to, const nlohmann::json& rates);
};

#endif // CURRENCY_API_H
