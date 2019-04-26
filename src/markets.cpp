#include "fcpp/markets.h"
#include "cpr/cpr.h"
#include <iostream>

std::string Markets::get_all() {
        auto r = cpr::Get(cpr::Url{"https://jsonplaceholder.typicode.com/posts"});
        return r.text;
}
