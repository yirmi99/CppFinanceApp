#include "HttpClient.h"
#include <iostream>

// Function to send a GET request and return JSON response
nlohmann::json HttpClient::getRequest(const std::string& url) {
    httplib::SSLClient client("v6.exchangerate-api.com");  // Use SSLClient for HTTPS
    client.set_follow_location(true); // Allow redirections

    std::cout << "🔍 Requesting: " << url << std::endl;
    auto res = client.Get(url.c_str());

    if (res && res->status == 200) {
        return nlohmann::json::parse(res->body);
    }

    std::cerr << "HTTP Request Failed! URL: " << url << " | Status: "
              << (res ? std::to_string(res->status) : "No Response") << std::endl;
    return {};
}
