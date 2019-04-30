#include "fcpp/parser.h"


vector <Market> get_market_objects(json json_obj) {

    vector<Market> markets;

    for (json::iterator it = json_obj.begin(); it != json_obj.end(); ++it) {
        Market market;
        market.CatID = (*it)["CatID"];
        market.ClosD = (*it)["ClosD"];
        market.com_recip.cr_777555 = (*it)["ComRecip"]["1011849"];
        market.ID = (*it)["ID"];
        markets.push_back(market);
    }
    return markets;
}
