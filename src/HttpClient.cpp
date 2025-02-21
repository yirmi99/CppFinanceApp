#include "HttpClient.h"
#include <iostream>

// Function to send a GET request and return JSON response
nlohmann::json HttpClient::getRequest(const std::string& url, const httplib::Headers& headers) {
    httplib::SSLClient client("api.jsonbin.io");
    client.set_follow_location(true);

    std::cout << "🔍 Requesting: " << url << std::endl;
    auto res = client.Get(url.c_str(), headers);

    if (res && res->status == 200) {
        return nlohmann::json::parse(res->body);
    }

    std::cerr << "HTTP Request Failed! Status: " 
              << (res ? std::to_string(res->status) : "No Response") << std::endl;
    return {};
}

// Function to send a PUT request with JSON data (used for updating data)
nlohmann::json HttpClient::putRequest(const std::string& url, const std::string& jsonPayload, const httplib::Headers& headers) {
    httplib::SSLClient client("api.jsonbin.io");
    client.set_follow_location(true);

    std::cout << "Sending backup request to: " << url << std::endl;
    auto res = client.Put(url.c_str(), headers, jsonPayload, "application/json"); 

    if (res && res->status == 200) {
        return nlohmann::json::parse(res->body);
    }

    std::cerr << "Failed to send backup request! Status: "
              << (res ? std::to_string(res->status) : "No Response") << std::endl;
    return {};
}
