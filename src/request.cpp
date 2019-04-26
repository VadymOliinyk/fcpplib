#include "fcpp/request.h"
#include "curl/curl.h"

size_t Request::write_callback(char *contents,
                               size_t size,
                               size_t nmemb,
                               void *userp){
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string Request::get()
{
    curl_global_init(CURL_GLOBAL_ALL);

     CURL* easyhandle = curl_easy_init();
     std::string readBuffer;

     curl_easy_setopt(easyhandle, CURLOPT_URL, "http://31.172.83.181:8080/free/comps/1");
     curl_easy_setopt(easyhandle, CURLOPT_VERBOSE, 1L);
     curl_easy_setopt(easyhandle, CURLOPT_WRITEFUNCTION, write_callback);
     curl_easy_setopt(easyhandle, CURLOPT_WRITEDATA, &readBuffer);
     curl_easy_setopt(easyhandle, CURLOPT_ACCEPT_ENCODING, "gzip,deflate");
     curl_easy_perform(easyhandle);

     std::cout << readBuffer << std::endl;

     return readBuffer;

}
