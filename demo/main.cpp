#include <fcpp/fcpp.h>
#include <iostream>
#include "fcpp/request.h"
#include "nlohmann/json.hpp"
#include <iomanip>
int main()
{

    nlohmann::json j;
//    j["Cat"] = 12;
    j["SoftChangedAfter"] = "2019-04-27T08:23:30";
    j["OnlyActive"] = true;
    j["FromID"] = 0;
    j["ToID"] = 5;
    j["MaxMargin"] = 101.0;

   std::string json_market_filter = j.dump();


    Request request("http://31.172.83.181:8080/free/markets/",
                    json_market_filter
                    );

//    nlohmann::json j_output;
    auto j_output = nlohmann::json::parse( request.get().c_str());
    std::cout << j_output.dump(4) << std::endl;
    std::cout << std::endl;
//    std::cout << request.get() << std::endl;

return 0;
}
