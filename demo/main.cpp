#include <fcpp/fcpp.h>
#include <iostream>
#include "fcpp/request.h"
#include "nlohmann/json.hpp"
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "fcpp/market.h"
#include "fcpp/parser.h"

using namespace std;
using namespace nlohmann;

int main()
{
    string line;
    ifstream tempo_json;
    tempo_json.open("tempo.json");
    json j;
    tempo_json >> j;

    auto market_obs = get_market_objects(j);

    cout << market_obs.size() << endl;
    cout << "CatID : " << market_obs[0].CatID << endl;
    cout << "ClosD : " << market_obs[0].ClosD  << endl;
    cout << "com_recip" << endl;
    cout << "    cr_777555 : " << market_obs[0].com_recip.cr_777555   << endl ;
    cout << "ID : " << market_obs[0].ID << endl;
    cout << "ID : " << market_obs[1].ID << endl;
    cout << "ID : " << market_obs[2].ID << endl;



    cout  << endl << endl;


    return 0;
}
