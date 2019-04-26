#include <fcpp/fcpp.h>
#include <iostream>
#include <cpr/cpr.h>
#include "fcpp/markets.h"
#include "fcpp/request.h"

int main()
{
    Request request("https://www.google.com/");
    auto r = request.get();


return 0;
}
