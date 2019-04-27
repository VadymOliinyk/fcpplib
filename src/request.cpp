#include "fcpp/request.h"
#include "curl/curl.h"
#include "nlohmann/json.hpp"

std::string Request::get(){
    perform();
    return body;
}

void Request::encode_to_url(){

    CURL *curl = curl_easy_init();

    if(curl) {
        char *output = curl_easy_escape(curl, json_market_filter.c_str(), json_market_filter.size());
        if(output) {

            printf("Encoded: %s\n", output);
            end_point = base_url + output;
            curl_free(output);
        }
    }
}

size_t Request::write_callback(char *contents,
                               size_t size,
                               size_t nmemb,
                               void *userp){
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void Request::perform()
{

    std::cout << base_url << std::endl;
    encode_to_url();
    curl_global_init(CURL_GLOBAL_ALL);

    struct curl_slist *headers=NULL; // init to NULL is important

    headers = curl_slist_append(headers, "Accept: application/json");
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, "charsets: utf-8");

    CURL* easyhandle = curl_easy_init();

    curl_easy_setopt(easyhandle, CURLOPT_URL, end_point.c_str());
    curl_easy_setopt(easyhandle, CURLOPT_VERBOSE, 1L);
    curl_easy_setopt(easyhandle, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(easyhandle, CURLOPT_WRITEDATA, &readBuffer);
    curl_easy_setopt(easyhandle, CURLOPT_ACCEPT_ENCODING, "gzip,deflate");
    curl_easy_setopt(easyhandle, CURLOPT_HTTPHEADER, headers);
    /* store only body of the response */
    curl_easy_setopt(easyhandle, CURLOPT_WRITEDATA, &body);
    curl_easy_perform(easyhandle);

    /* cleanup curl stuff */
    curl_easy_cleanup(easyhandle);
}
