#include "fcpp/request.h"
#include "curl/curl.h"

std::string Request::get(){
    perform();
    return body;
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
    curl_global_init(CURL_GLOBAL_ALL);
    CURL* easyhandle = curl_easy_init();

    curl_easy_setopt(easyhandle, CURLOPT_URL, url.c_str());
    curl_easy_setopt(easyhandle, CURLOPT_VERBOSE, 1L);
    curl_easy_setopt(easyhandle, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(easyhandle, CURLOPT_WRITEDATA, &readBuffer);
    curl_easy_setopt(easyhandle, CURLOPT_ACCEPT_ENCODING, "gzip,deflate");

    /* store only body of the response */
    curl_easy_setopt(easyhandle, CURLOPT_WRITEDATA, &body);
    curl_easy_perform(easyhandle);

    /* cleanup curl stuff */
    curl_easy_cleanup(easyhandle);
}
