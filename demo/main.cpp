#include <fcpp/fcpp.h>
#include <iostream>
#include "fcpp/request.h"

int main()
{
    Request request("https://jsonplaceholder.typicode.com/posts/1");

    std::cout << request.get() << std::endl;

return 0;
}
