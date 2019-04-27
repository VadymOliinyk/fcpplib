#ifndef REQUEST_H
#define REQUEST_H

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
    std::string body;
    std::string readBuffer;
    void perform();

    static size_t write_callback(char *contents,
                                 size_t size,
                                 size_t nmemb,
                                 void *userp);
};

#endif // REQUEST_H
