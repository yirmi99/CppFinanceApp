#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#define CPPHTTPLIB_OPENSSL_SUPPORT

#include "../shared/HttpSrc/httplib.h"
#include "../shared/HttpSrc/json.hpp"
#include <string>

class HttpClient {
public:
    static nlohmann::json getRequest(const std::string& url, const httplib::Headers& headers = {});
    static nlohmann::json putRequest(const std::string& url, const std::string& jsonPayload, const httplib::Headers& headers = {});
};

#endif // HTTPCLIENT_H
