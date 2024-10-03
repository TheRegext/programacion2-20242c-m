#include <iostream>
#include "HttpClient.h"

HttpClient::HttpClient() {
    curl_global_init(CURL_GLOBAL_DEFAULT);  // Inicializar cURL
    curl = curl_easy_init();
}

HttpClient::~HttpClient() {
    if (curl) {
        curl_easy_cleanup(curl);  // Limpiar cURL
    }
    curl_global_cleanup();  // Limpiar globalmente cURL
}

std::string HttpClient::get(const std::string& url) {
    std::string response;
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());  // Configurar URL
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);  // Configurar callback para escribir datos
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);  // Almacenar la respuesta

        // Desactivar la verificaci¢n SSL para pruebas
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

        CURLcode res = curl_easy_perform(curl);  // Realizar la solicitud GET
        if (res != CURLE_OK) {
            std::cerr << "Error en curl_easy_perform(): " << curl_easy_strerror(res) << std::endl;
        }
    }
    return response;
}

size_t HttpClient::WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}
