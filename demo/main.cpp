#include <fcpp/fcpp.h>
#include <iostream>
#include "fcpp/request.h"
#include "nlohmann/json.hpp"

int main()
{

    nlohmann::json j;
    j["Cat"] = 6;
   std::string json_market_filter = j.dump();


    Request request("http://31.172.83.181:8080/free/markets/",
                    json_market_filter
                    );

    std::cout << std::endl;
    std::cout << request.get() << std::endl;

return 0;
}
