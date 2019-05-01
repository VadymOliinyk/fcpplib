#include <fcpp/fcpp.h>
#include <iostream>
#include "fcpp/request.h"
#include "nlohmann/json.hpp"
#include <iomanip>
#include <fstream>
#include <variant>

#include "fcpp/parser.h"

using namespace std;
using namespace nlohmann;


int main()
{
    { std::cout << __cplusplus << std::endl; };
    ifstream tempo_json;
    tempo_json.open("tempo.json");
    json j;
    tempo_json >> j;

    auto markets = get_market_objects(j);

    cout << markets.size() << endl;
    cout << "CatID : " << markets[0].CatID << endl;
    cout << "ClosD : " << markets[0].ClosD  << endl;
    cout << "com_recip" << endl;
    cout << "    cr_777555 : " << markets[0].com_recip.cr_777555 << endl ;
    cout << "ID : " << markets[0].ID << endl;
    cout << "ID : " << markets[1].ID << endl;
    cout << "ID : " << markets[2].ID << endl;


    return 0;
}
