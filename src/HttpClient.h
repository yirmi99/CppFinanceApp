#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#define CPPHTTPLIB_OPENSSL_SUPPORT

#include "../shared/HttpSrc/httplib.h"
#include "../shared/HttpSrc/json.hpp"
#include <string>

class HttpClient {
public:
    // Sends a GET request and returns a JSON response
    static nlohmann::json getRequest(const std::string& url);
};

#endif // HTTPCLIENT_H
