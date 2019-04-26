#include "testmessanger.h"
#include <iostream>




TestMessanger::TestMessanger()
{
    msg_tmp = "msg temp";

}

void TestMessanger::printmsg()
{
    std::cout << msg_tmp << std::endl;
}
