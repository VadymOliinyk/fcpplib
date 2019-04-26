#include <fcpp/fcpp.h>
#include <iostream>

#include "fcpp/markets.h"

int main()
{
    Markets markets;
    std::cout << markets.get_all() << std::endl;

return 0;
}
