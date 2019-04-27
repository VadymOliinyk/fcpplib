#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include <iostream>

class Request
{
public:
    Request (const std::string &s, const std::string &jf):
        base_url(s),
        json_market_filter(jf){}

    Request() {}
    std::string get();
    std::string get_url();
private:
    std::string base_url;
    std::string json_market_filter;
    std::string end_point;
    std::string body;
    std::string readBuffer;
    void encode_to_url(std::string base_url, std::string json_market_filter);
    void perform();

    static size_t write_callback(char *contents,
                                 size_t size,
                                 size_t nmemb,
                                 void *userp);
};

#endif // REQUEST_H
