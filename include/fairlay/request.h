#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include <iostream>

namespace fairlay {

class Request
{
public:
    Request (const std::string &s, const std::string &jf):
        base_url(s),
        json_market_filter(jf){}

    Request() {}
    /* Returns body of the response */
    std::string get();
private:
    std::string base_url;
    std::string json_market_filter;
    std::string end_point;
    std::string body;
    std::string readBuffer;
    void encode_to_url();
    void perform();

    /* Callback function for libcurl */
    static size_t write_callback(char *contents,
                                 size_t size,
                                 size_t nmemb,
                                 void *userp);
};

} // namespace fairlay

#endif // REQUEST_H
