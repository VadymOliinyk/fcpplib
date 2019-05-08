#include <iostream>
#include <iomanip>
#include <fstream>

#include "nlohmann/json.hpp"

#include "fairlay/request.h"
#include <fairlay/fairlay.h>
#include "fairlay/parser.h"

using namespace std;
using namespace nlohmann;


int main()
{
//    ifstream tempo_json;
//    tempo_json.open("tempo.json");
//    json j;
//    tempo_json >> j;

    json j_market_filter;
    j_market_filter["Cat"] = 32;
    j_market_filter["SoftChangedAfter"] = "2019-05-07T08:23:30";
    j_market_filter["OnlyActive"] = true;
    j_market_filter["FromID"] = 0;
    j_market_filter["ToID"] = 5;
    j_market_filter["MaxMargin"] = 105.0;

    fairlay::Request request("http://31.172.83.181:8080/free/markets/", j_market_filter.dump());

//    cout << j_market_filter << endl << endl;
//    cout << setw(4) << resp << endl;

    auto j_output = json::parse( request.get().c_str());
    std::cout << j_output.dump(4)  << std::endl;



    auto markets = fairlay::get_market_objects(j_output);

    cout << markets.size() << endl;
    // cout << "CatID : " << markets[0].CatID << endl;
    // cout << "ClosD : " << markets[0].ClosD  << endl;
    // cout << "com_recip" << endl;
    // cout << "    cr_777555 : " << markets[0].com_recip.cr_777555 << endl ;
    // cout << "ID : " << markets[0].ID << endl;
    // cout << "ID : " << markets[1].ID << endl;
    // cout << "ID : " << markets[2].ID << endl;


    return 0;
}
