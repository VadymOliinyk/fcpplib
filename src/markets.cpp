#include "fcpp/markets.h"
#include "cpr/cpr.h"
#include <iostream>

std::string Markets::get_all() {
        auto r = cpr::Get(cpr::Url{"http://31.172.83.181:8080/free/comps/1"});
 //                         cpr::Parameters);

        std::cout << r.text << std::endl;
        std::cout << r.url << std::endl;
        std::cout << r.status_code << std::endl;
        return r.text;
}
