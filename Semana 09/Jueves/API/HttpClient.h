#pragma once
#include <string>
#include <curl/curl.h>

class HttpClient {
public:
    HttpClient();
    ~HttpClient();
    std::string get(const std::string& url);
private:
    CURL* curl;
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output);
};
