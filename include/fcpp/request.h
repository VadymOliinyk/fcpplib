#ifndef REQUEST_H
#define REQUEST_H

//#include <curl/curl.h>
#include <string>
#include <iostream>

class Request
{
public:
    Request (const std::string &s): url(s){}
    Request() {}
    std::string get();

private:
    std::string url;
    static size_t write_callback(char *contents,
                         size_t size,
                         size_t nmemb,
                         void *userp);
};




#endif // REQUEST_H
